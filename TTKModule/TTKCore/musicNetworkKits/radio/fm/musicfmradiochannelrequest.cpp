#include "musicfmradiochannelrequest.h"

#include "qsync/qsyncutils.h"

#include <QNetworkRequest>
#include <QNetworkCookie>
#include <QNetworkAccessManager>

MusicFMRadioChannelRequest::MusicFMRadioChannelRequest(QObject *parent)
    : MusicAbstractFMRadioRequest(parent)
{

}

MusicFMRadioChannelRequest::~MusicFMRadioChannelRequest()
{
    deleteAll();
}

void MusicFMRadioChannelRequest::startToDownload(const QString &id)
{
    Q_UNUSED(id);
    QNetworkRequest request;
    request.setUrl(MusicUtils::Algorithm::mdII(FM_CHANNEL_URL, false).arg(FM_API_KEY));
    MusicObject::setSslConfiguration(&request);

    m_reply = m_manager->get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}

void MusicFMRadioChannelRequest::downLoadFinished()
{
    if(m_reply && m_reply->error() == QNetworkReply::NoError)
    {
        m_channels.clear();
        setHeader("Cookie", m_reply->rawHeader("Set-Cookie"));

        QJson::Parser parser;
        bool ok;
        const QVariant &data = parser.parse(m_reply->readAll(), &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            const QVariantList &groups = value["groups"].toList();
            for(int i=0; i<groups.count(); ++i)
            {
                value = groups[i].toMap();
                const int group = value["group_id"].toInt();
                if(group != 4 && group != 5 && group != 6)
                {
                    continue;
                }

                const QVariantList &channels = value["chls"].toList();
                for(int i=0; i<channels.count(); ++i)
                {
                    value = channels[i].toMap();
                    MusicFMRadioChannelData channel;
                    channel.m_id = value["id"].toString();
                    channel.m_name = value["name"].toString();
                    channel.m_coverUrl = value["cover"].toString();
                    m_channels << channel;
                }
            }
        }
    }

    Q_EMIT downLoadDataChanged(QString());
    deleteAll();
}
