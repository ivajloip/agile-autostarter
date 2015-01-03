#include <string>

#include <QSettings>
#include <QString>
#include <QDebug>


#include <Settings.hpp>


QString APPLICATION_NAME("agileAutostarter");

QString ASK_FOR_APPLICATION_WHEN_ON_BATTERY("askForApplicationsWhenOnBattery");

QString ASK_FOR_APPLICATION_WHEN_ON_AC("askForApplicationsWhenOnAC");

QString AUTOSTART_APPLICATIONS_LIST("autostartApplicationsList");

Settings::Settings(std::string confFilepath) {
  initialize(confFilepath);
}

bool Settings::saveToDisk(std::string confFilepath) {
  return confFilepath.empty();
}

bool Settings::initialize(std::string confFilepath) {
  QSettings* settings = NULL;

  if (confFilepath.empty()) {
    settings = new QSettings(QSettings::IniFormat,
        QSettings::UserScope,
        APPLICATION_NAME,
      QString("config"));
  } else {
    settings = new QSettings(QString(confFilepath.c_str()),
        QSettings::IniFormat);
  }

  this->askForApplicationsWhenOnBattery =
      settings->value(ASK_FOR_APPLICATION_WHEN_ON_BATTERY, QVariant(false)).toBool();
  this->askForApplicationsWhenOnAC =
      settings->value(ASK_FOR_APPLICATION_WHEN_ON_AC, QVariant(false)).toBool();
  this->autostartApplicationsListPath =
      settings->value(AUTOSTART_APPLICATIONS_LIST, "applicationsList").toString();
  qDebug() << settings->fileName();
  qDebug() << askForApplicationsWhenOnBattery;
  //settings.setValue(ASK_FOR_APPLICATION_WHEN_ON_BATTERY, true);
  //settings.sync();

  delete settings;

  return true;
}

