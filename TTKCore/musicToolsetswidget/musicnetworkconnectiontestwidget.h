#ifndef MUSICNETWORKCONNECTIONTESTWIDGET_H
#define MUSICNETWORKCONNECTIONTESTWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2014 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicabstractmovewidget.h"

/*! @brief The class of the network connection item Widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_TOOLSET_EXPORT MusicNetworkConnectionItem : public QWidget
{
    Q_OBJECT
public:
    explicit MusicNetworkConnectionItem(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    ~MusicNetworkConnectionItem();

};


namespace Ui {
class MusicNetworkConnectionTestWidget;
}

/*! @brief The class of the network connection test widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_TOOLSET_EXPORT MusicNetworkConnectionTestWidget : public MusicAbstractMoveWidget
{
    Q_OBJECT
public:
    explicit MusicNetworkConnectionTestWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~MusicNetworkConnectionTestWidget();

    static QString getClassName();
    /*!
     * Get class object name.
     */

public Q_SLOTS:
    void show();
    /*!
     * Override show function.
     */

protected:
    Ui::MusicNetworkConnectionTestWidget *ui;
    QList<MusicNetworkConnectionItem*> m_connectionItems;

};

#endif // MUSICNETWORKCONNECTIONTESTWIDGET_H