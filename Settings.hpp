#ifndef __settings_h__

#define __settings_h__

#include <QString>

class Settings {
  bool askForApplicationsWhenOnBattery;

  bool askForApplicationsWhenOnAC;

  QString autostartApplicationsListPath;

public:

  Settings(std::string confFilepath = "");

  bool saveToDisk(std::string confFilepath = "");

  bool getAskForApplicationsWhenOnBattery() {
    return this->askForApplicationsWhenOnBattery;
  }

  bool getAskForApplicationsWhenOnAC() {
    return this->askForApplicationsWhenOnAC;
  }

  /*
   * Note: The result will be destroyed when the settings object is destroyed.
   */
  QString& getAutostartApplicationsListPath() {
    return this->autostartApplicationsListPath;
  }


private:

  bool initialize(std::string confFilepath);
};

#endif
