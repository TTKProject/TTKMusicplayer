#include "settingsdialog.h"
#include "stereoplugin.h"

#include <QSettings>
#include <QAbstractButton>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
#ifdef Q_OS_UNIX
    for(QAbstractButton *button : m_ui.buttonBox->buttons())
    {
        button->setFocusPolicy(Qt::NoFocus);
    }
#endif
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
    m_level = settings.value("Stereo/intensity", 1.0).toDouble();
    m_ui.intensitySlider->setValue(m_level * 100 / 10.0);
}

void SettingsDialog::accept()
{
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
    settings.setValue("Stereo/intensity", m_ui.intensitySlider->value() * 10.0 / 100);
    QDialog::accept();
}

void SettingsDialog::SettingsDialog::reject()
{
    if(StereoPlugin::instance())
        StereoPlugin::instance()->setIntensity(m_level); //restore settings
    QDialog::reject();
}

void SettingsDialog::on_intensitySlider_valueChanged(int value)
{
    double level = value * 10.0 / 100;
    m_ui.intensityLabel->setText(QString(tr("%1")).arg(level));
    if(StereoPlugin::instance())
        StereoPlugin::instance()->setIntensity(level);
}