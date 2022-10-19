#ifndef MUSICALBUMQUERYWIDGET_H
#define MUSICALBUMQUERYWIDGET_H

/***************************************************************************
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2022 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "musicabstractitemquerywidget.h"

/*! @brief The class of the album music query table widget.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT MusicAlbumQueryTableWidget : public MusicItemQueryTableWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicAlbumQueryTableWidget)
public:
    /*!
     * Object contsructor.
     */
    explicit MusicAlbumQueryTableWidget(QWidget *parent = nullptr);
    ~MusicAlbumQueryTableWidget();

    /*!
     * Set network query input.
     */
    virtual void setQueryInput(MusicAbstractQueryRequest *query) override final;

};


/*! @brief The class of album music query widget.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT MusicAlbumQueryWidget : public MusicAbstractItemQueryWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicAlbumQueryWidget)
public:
    /*!
     * Object contsructor.
     */
    explicit MusicAlbumQueryWidget(QWidget *parent = nullptr);

    /*!
     * Set current name to search founds.
     */
    virtual void setSongName(const QString &name) override final;
    /*!
     * Set current id to search founds.
     */
    virtual void setSongNameById(const QString &id) override final;
    /*!
     * Resize widget bound by resize called.
     */
    void resizeWidget();

public Q_SLOTS:
    /*!
     * Query all quality musics is finished.
     */
    void queryAllFinished();
    /*!
     * Query album musics is finished.
     */
    void queryAlbumFinished();
    /*!
     * Create the current album info item.
     */
    void createAlbumItem(const MusicResultDataItem &item);

private:
    /*!
     * Create init interface lables.
     */
    void createLabels();

};

#endif // MUSICALBUMQUERYWIDGET_H
