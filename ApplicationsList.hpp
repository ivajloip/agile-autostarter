#ifndef __application_list_h__

#define __application_list_h__

#include <vector>
#include <string>

#include <AutostartableApplication.hpp>

typedef AutostartableApplication Application;

class ApplicationList {
  std::vector<Application> applications;

public:
  ApplicationList(std::string filename) {
    readApplications(filename);
  }

  bool readApplications(std::string filename);
  bool startAllEnabledApplications();

private:
  bool startSingleApplication(std::string application, std::string args);
};

#endif
