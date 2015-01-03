#include <iostream>

#include <BatteryStatusReader.hpp>
#include <Settings.hpp>
#include <QVariant>
#include <QDebug>

#include <QApplication>

#include <MainWindow.hpp>
#include <ApplicationsList.hpp>

bool startApplications(const QString& autostartApplicationsListPath) {
  ApplicationList applicationsList(autostartApplicationsListPath.toStdString());

  return applicationsList.startAllEnabledApplications();
}

int main(int argc, char *argv[]) {
  Settings settings;
  bool batteryDischarging = isBatteryDischarging();
  if (!batteryDischarging && !settings.getAskForApplicationsWhenOnAC()) {
    std::cout << "Not discharging Auto\n";

    return startApplications(settings.getAutostartApplicationsListPath());
  } else if (batteryDischarging && !settings.getAskForApplicationsWhenOnBattery()) {
    std::cout << "Discharging Auto\n";
    // TODO ipetrov: Implement
    return 0;
  }

  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.show();

  return app.exec();
}
