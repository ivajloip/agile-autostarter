#include <fstream>

#include <AutostartableApplication.hpp>

bool AutostartableApplication::readFromStream(std::istream& in) {
  this->enabled = readBool(in);
  this->enabledOnBatteryPower = readBool(in);
  readString(in, this->name);
  readString(in, this->executable);
  readString(in, this->description);
  readString(in, this->additionalArguments);

  return true;
}

bool AutostartableApplication::writeToStream(std::ostream& out) {
  out << this->enabled;
  out << this->enabledOnBatteryPower;
  out << this->name;
  out << this->executable;
  out << this->description;
  out << this->additionalArguments;

  return true;
}

bool AutostartableApplication::readBool(std::istream& in) {
  std::string token;
  std::getline(in, token, ',');
  return token.compare("1") == 0;
}

void AutostartableApplication::readString(std::istream& in, std::string& value) {
  std::getline(in, value, ',');
}
