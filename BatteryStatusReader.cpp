#include <iostream>

#include <QString>
#include <QSettings>

bool isBatteryDischarging() {
  QSettings settings(QString("/sys/class/power_supply/BAT1/uevent"), QSettings::IniFormat);
  QString status = settings.value("POWER_SUPPLY_STATUS", "None").toString();

  return status.compare(QString("Discharging")) == 0;
}
