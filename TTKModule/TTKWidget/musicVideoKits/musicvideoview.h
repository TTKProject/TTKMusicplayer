#ifndef MUSICVIDEOVIEW_H
#define MUSICVIDEOVIEW_H

/***************************************************************************
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2023 Greedysky Studio

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

#include <QAbstractScrollArea>
#include "musicglobaldefine.h"
#include "musicvideocontrolwidget.h"

class MusicCoreMPlayer;
class MusicBarrageWidget;

/*! @brief The class of the video show widget.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT MusicViewWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicViewWidget)
public:
    /*!
     * Object constructor.
     */
    explicit MusicViewWidget(QWidget *parent = nullptr);
    /*!
     * Object destructor.
     */
    ~MusicViewWidget();

Q_SIGNALS:
    /*!
     * Widget double clicked.
     */
    void fullScreenMode();
    /*!
     * Widget time to play.
     */
    void timeToPlay();

private:
    /*!
     * Override the widget event.
     */
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override final;
    virtual void contextMenuEvent(QContextMenuEvent *event) override final;

    QTimer *m_clickedTimer;
    bool m_leftPressed;

};


/*! @brief The class of the video view widget.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT MusicVideoView : public QAbstractScrollArea
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicVideoView)
public:
    /*!
     * Object constructor.
     */
    explicit MusicVideoView(QWidget *parent = nullptr);
    /*!
     * Object destructor.
     */
    ~MusicVideoView();

    /*!
     * Set video play data.
     */
    void setMedia(const QString &data);
    /*!
     * Resize geometry bound by resize called.
     */
    void resizeGeometry(int width, int height);
    /*!
     * Create right menu.
     */
    void createRightMenu();
    /*!
     * Get control bar widget.
     */
    inline MusicVideoControlWidget *controlBarWidget() const { return m_videoControl; }

Q_SIGNALS:
    /*!
     * Search button clicked.
     */
    void searchButtonClicked();
    /*!
     * Popup button clicked.
     */
    void popupButtonClicked();
    /*!
     * Fullscreen button clicked.
     */
    void fullscreenButtonClicked();
    /*!
     * Download button clicked.
     */
    void downloadButtonClicked();
    /*!
     * Share button clicked.
     */
    void shareButtonClicked();

public Q_SLOTS:
    /*!
     * Player to play.
     */
    void play();

private Q_SLOTS:
    /*!
     * Player to stop.
     */
    void stop();
    /*!
     * Current position changed.
     */
    void positionChanged(qint64 position);
    /*!
     * Current duration changed.
     */
    void durationChanged(qint64 duration);
    /*!
     * Set current play pos.
     */
    void setPosition(int position);
    /*!
     * Current volume changed.
     */
    void volumeChanged(int volume);
    /*!
     * Current media changed.
     */
    void mediaChanged(const QString &data);
    /*!
     * Media aution play error.
     */
    void mediaAutionPlayError(int code);

    /*!
     * Add barrage text to mv.
     */
    void addBarrageChanged(const MusicBarrageRecord &record);
    /*!
     * Open barrage on or not.
     */
    void pushBarrageChanged(bool on);

    /*!
     * Fullscreen action trigger.
     */
    void fullscreenButtonTrigger();

private:
    /*!
     * Override the widget event.
     */
    virtual void contextMenuEvent(QContextMenuEvent *event) override final;

    MusicViewWidget *m_videoWidget;
    MusicCoreMPlayer *m_player;
    MusicVideoControlWidget *m_videoControl;
    MusicBarrageWidget *m_barrageCore;

};

#endif // MUSICVIDEOVIEW_H
