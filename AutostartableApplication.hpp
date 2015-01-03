#ifndef __autostartable_application_h__

#define __autostartable_application_h__

#include <iostream>
#include <fstream>

class AutostartableApplication {
  bool enabled;
  bool enabledOnBatteryPower;
  std::string name;
  std::string executable;
  std::string description;
  std::string additionalArguments;

public:
  bool readFromStream(std::istream& in);

  bool writeToStream(std::ostream& out);

  bool isEnabled() {
    return this->enabled;
  }

  void setEnabled(bool enabled) {
    this->enabled = enabled;
  }

  bool isEnabledOnBatteryPower() {
    return this->enabledOnBatteryPower;
  }

  void setEnabledOnBatteryPower(bool enabledOnBatteryPower) {
    this->enabledOnBatteryPower = enabledOnBatteryPower;
  }

  std::string getName() {
    return this->name;
  }

  void setName(std::string name) {
    this->name = name;
  }

  std::string getExecutable() {
    return this->executable;
  }

  void setExecutable(std::string executable) {
    this->executable = executable;
  }

  std::string getDescription() {
    return this->description;
  }

  void setDescription(std::string description) {
    this->description = description;
  }

  std::string getAdditionalArguments() {
    return this->additionalArguments;
  }

  void setAdditionalArguments(std::string additionalArguments) {
    this->additionalArguments = additionalArguments;
  }

private:
  bool readBool(std::istream& in);
  void readString(std::istream& in, std::string& value);

};

#endif
