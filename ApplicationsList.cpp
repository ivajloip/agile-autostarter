#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <unistd.h>

#include <ApplicationsList.hpp>

bool ApplicationList::readApplications(std::string filename) {
  std::cout << "FOO\n";
  std::ifstream in(filename.c_str(), std::ifstream::in);

  std::string line;
  Application application;

  while(!in.eof()) {
    std::getline(in, line);
    std::istringstream lineAsStream(line);
    application.readFromStream(lineAsStream);
    this->applications.push_back(application);
  }

  return true;
}

bool ApplicationList::startAllEnabledApplications() {
  for (std::vector<Application>::iterator iter = this->applications.begin();
      iter != this->applications.end(); iter++) {
    Application& app = *iter;
    if (app.isEnabled()) {
      bool result =
        startSingleApplication(app.getName(), app.getAdditionalArguments());
      if (!result) {
        return false;
      }
    }
  }

  return true;
}

bool ApplicationList::startSingleApplication(std::string application,
    std::string args) {
  int pid = fork();

  if (pid == 0) {
    // TODO: ipetrov parse args
    execlp(application.c_str(), args.c_str(), NULL);
  }

  return true;
}
