#ifndef DEFECTTRACKINGSYSTEM_H
#define DEFECTTRACKINGSYSTEM_H

#include <string>
#include <map>
#include "User.h"
#include "Project.h"
#include "Usertype.h"

class DefectTrackingSystem {
public:
    void initializeUsers();
    bool login(const std::string& username, const std::string& password, Usertype& userType);
    void logout();

    bool addDefect(const std::string& projectName, const Defect& defect);
    bool editDefectPriority(const std::string& projectName, const std::string& defectId, PriorityLevel priority);

    std::map<std::string, Project>& getProjects() { return projects; } // Add this method

private:
    std::map<std::string, User> users;
    std::map<std::string, Project> projects;
    User* currentUser = nullptr;
};

#endif // DEFECTTRACKINGSYSTEM_H
