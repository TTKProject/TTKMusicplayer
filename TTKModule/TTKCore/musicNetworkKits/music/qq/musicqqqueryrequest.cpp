#include "musicqqqueryrequest.h"

MusicQQQueryRequest::MusicQQQueryRequest(QObject *parent)
    : MusicAbstractQueryRequest(parent)
{
    m_pageSize = 30;
    m_queryServer = QUERY_QQ_INTERFACE;
}

void MusicQQQueryRequest::startToSearch(QueryType type, const QString &text)
{
    if(!m_manager)
    {
        return;
    }

    TTK_LOGGER_INFO(QString("%1 startToSearch %2").arg(getClassName()).arg(text));

    m_currentType = type;
    m_queryText = text.trimmed();

    Q_EMIT clearAllItems();
    m_musicSongInfos.clear();

    startToPage(0);
}

void MusicQQQueryRequest::startToPage(int offset)
{
    if(!m_manager)
    {
        return;
    }

    TTK_LOGGER_INFO(QString("%1 startToPage %2").arg(getClassName()).arg(offset));

    deleteAll();
    m_totalSize = 0;
    m_pageIndex = offset;

    QNetworkRequest request;
    request.setUrl(MusicUtils::Algorithm::mdII(QQ_SONG_SEARCH_URL, false).arg(m_queryText).arg(offset + 1).arg(m_pageSize));
    request.setRawHeader("User-Agent", MusicUtils::Algorithm::mdII(QQ_UA_URL, ALG_UA_KEY, false).toUtf8());
    MusicObject::setSslConfiguration(&request);

    m_reply = m_manager->get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}

void MusicQQQueryRequest::startToSingleSearch(const QString &text)
{
    if(!m_manager)
    {
        return;
    }

    TTK_LOGGER_INFO(QString("%1 startToSingleSearch %2").arg(getClassName()).arg(text));

    deleteAll();

    QNetworkRequest request;
    request.setUrl(MusicUtils::Algorithm::mdII(QQ_SONG_INFO_URL, false).arg(text));
    request.setRawHeader("User-Agent", MusicUtils::Algorithm::mdII(QQ_UA_URL, ALG_UA_KEY, false).toUtf8());
    MusicObject::setSslConfiguration(&request);

    QNetworkReply *reply = m_manager->get(request);
    connect(reply, SIGNAL(finished()), SLOT(singleDownLoadFinished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}

void MusicQQQueryRequest::downLoadFinished()
{
    TTK_LOGGER_INFO(QString("%1 downLoadFinished").arg(getClassName()));

    setNetworkAbort(false);

    if(m_reply && m_reply->error() == QNetworkReply::NoError)
    {
        QJson::Parser parser;
        bool ok;
        const QVariant &data = parser.parse(m_reply->readAll(), &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value.contains("data"))
            {
                value = value["data"].toMap();
                value = value["song"].toMap();
                m_totalSize = value["totalnum"].toInt();
                const QVariantList &datas = value["list"].toList();
                for(const QVariant &var : qAsConst(datas))
                {
                    if(var.isNull())
                    {
                        continue;
                    }

                    value = var.toMap();
                    TTK_NETWORK_QUERY_CHECK();

                    MusicObject::MusicSongInformation musicInfo;
                    for(const QVariant &var : value["singer"].toList())
                    {
                        if(var.isNull())
                        {
                            continue;
                        }
                        const QVariantMap &name = var.toMap();
                        musicInfo.m_singerName = MusicUtils::String::illegalCharactersReplaced(name["name"].toString());
                        musicInfo.m_artistId = name["mid"].toString();
                    }
                    musicInfo.m_songName = MusicUtils::String::illegalCharactersReplaced(value["songname"].toString());
                    musicInfo.m_timeLength = MusicTime::msecTime2LabelJustified(value["interval"].toInt() * 1000);

                    m_rawData["sid"] = value["songid"].toString();
                    musicInfo.m_songId = value["songmid"].toString();
                    musicInfo.m_albumId = value["albummid"].toString();

                    musicInfo.m_year = QString();
                    musicInfo.m_discNumber = value["cdIdx"].toString();
                    musicInfo.m_trackNumber = value["belongCD"].toString();

                    if(!m_querySimplify)
                    {
                        musicInfo.m_lrcUrl = MusicUtils::Algorithm::mdII(QQ_SONG_LRC_URL, false).arg(musicInfo.m_songId);
                        musicInfo.m_smallPicUrl = MusicUtils::Algorithm::mdII(QQ_SONG_PIC_URL, false).arg(musicInfo.m_albumId);
                        musicInfo.m_albumName = MusicUtils::String::illegalCharactersReplaced(value["albumname"].toString());

                        TTK_NETWORK_QUERY_CHECK();
                        readFromMusicSongAttribute(&musicInfo, value, m_queryQuality, m_queryAllRecords);
                        TTK_NETWORK_QUERY_CHECK();

                        if(musicInfo.m_songAttrs.isEmpty())
                        {
                            continue;
                        }
                        //
                        MusicSearchedItem item;
                        item.m_songName = musicInfo.m_songName;
                        item.m_singerName = musicInfo.m_singerName;
                        item.m_albumName = musicInfo.m_albumName;
                        item.m_time = musicInfo.m_timeLength;
                        item.m_type = mapQueryServerString();
                        Q_EMIT createSearchedItem(item);
                    }
                    m_musicSongInfos << musicInfo;
                }
            }
        }
    }

    Q_EMIT downLoadDataChanged(QString());
    deleteAll();
}

void MusicQQQueryRequest::singleDownLoadFinished()
{
    TTK_LOGGER_INFO(QString("%1 singleDownLoadFinished").arg(getClassName()));

    Q_EMIT clearAllItems();
    m_musicSongInfos.clear();
    setNetworkAbort(false);

    QNetworkReply *reply = TTKObject_cast(QNetworkReply*, QObject::sender());
    if(reply && reply->error() == QNetworkReply::NoError)
    {
        QJson::Parser parser;
        bool ok;
        const QVariant &data = parser.parse(reply->readAll(), &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value.contains("data") && value["code"].toInt() == 0)
            {
                const QVariantList &datas = value["data"].toList();
                for(const QVariant &var : qAsConst(datas))
                {
                    if(var.isNull())
                    {
                        continue;
                    }

                    value = var.toMap();
                    TTK_NETWORK_QUERY_CHECK();

                    MusicObject::MusicSongInformation musicInfo;
                    for(const QVariant &var : value["singer"].toList())
                    {
                        if(var.isNull())
                        {
                            continue;
                        }
                        const QVariantMap &name = var.toMap();
                        musicInfo.m_singerName = MusicUtils::String::illegalCharactersReplaced(name["name"].toString());
                        musicInfo.m_artistId = name["mid"].toString();
                    }
                    musicInfo.m_songName = MusicUtils::String::illegalCharactersReplaced(value["name"].toString());
                    musicInfo.m_timeLength = MusicTime::msecTime2LabelJustified(value["interval"].toInt() * 1000);

                    m_rawData["sid"] = QString::number(value["id"].toLongLong());
                    musicInfo.m_songId = value["mid"].toString();

                    const QVariantMap &albumMap = value["album"].toMap();
                    musicInfo.m_albumName = MusicUtils::String::illegalCharactersReplaced(albumMap["name"].toString());
                    musicInfo.m_albumId = albumMap["mid"].toString();

                    musicInfo.m_lrcUrl = MusicUtils::Algorithm::mdII(QQ_SONG_LRC_URL, false).arg(musicInfo.m_songId);
                    musicInfo.m_smallPicUrl = MusicUtils::Algorithm::mdII(QQ_SONG_PIC_URL, false).arg(musicInfo.m_albumId);

                    musicInfo.m_year = value["time_public"].toString();
                    musicInfo.m_discNumber = value["cdIdx"].toString();
                    musicInfo.m_trackNumber = value["belongCD"].toString();

                    TTK_NETWORK_QUERY_CHECK();
                    readFromMusicSongAttributePlus(&musicInfo, value["file"].toMap());
                    TTK_NETWORK_QUERY_CHECK();

                    if(!musicInfo.m_songAttrs.isEmpty())
                    {
                        MusicSearchedItem item;
                        item.m_songName = musicInfo.m_songName;
                        item.m_singerName = musicInfo.m_singerName;
                        item.m_albumName = musicInfo.m_albumName;
                        item.m_time = musicInfo.m_timeLength;
                        item.m_type = mapQueryServerString();
                        Q_EMIT createSearchedItem(item);
                        m_musicSongInfos << musicInfo;
                    }
                }
            }
        }
    }

    Q_EMIT downLoadDataChanged(QString());
    deleteAll();
}
