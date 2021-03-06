#include "musicnetworkthread.h"
#include "musicconnectionpool.h"
#include "musicsettingmanager.h"

#include <QHostInfo>
#ifdef TTK_GREATER_NEW
#  include <QtConcurrent/QtConcurrent>
#else
#  include <QtConcurrentRun>
#endif

MusicNetworkThread::MusicNetworkThread()
    : QObject(nullptr), m_networkState(true)
{
    G_CONNECTION_PTR->setValue(getClassName(), this);
    connect(&m_timer, SIGNAL(timeout()), SLOT(networkStateChanged()));
}

MusicNetworkThread::~MusicNetworkThread()
{
    m_timer.stop();
}

void MusicNetworkThread::start()
{
    TTK_LOGGER_INFO("Load NetworkThread");
    m_timer.start(NETWORK_DETECT_INTERVAL);
}

void MusicNetworkThread::setBlockNetWork(int block)
{
    G_SETTING_PTR->setValue(MusicSettingManager::CloseNetWork, block);
}

void MusicNetworkThread::networkStateChanged()
{
    QtConcurrent::run([&]
    {
        const bool block = G_SETTING_PTR->value(MusicSettingManager::CloseNetWork).toBool();
        const QHostInfo &info = QHostInfo::fromName(NETWORK_REQUEST_ADDRESS);
        m_networkState = !info.addresses().isEmpty();
        m_networkState = block ? false : m_networkState;
        Q_EMIT networkConnectionStateChanged(m_networkState);
    });
}
