#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <map>
#include <string>
#include "User.h"
#include "Defect.h"
#include "Project.h"
#include "Usertype.h"
#include "ProjectStatus.h"
#include "PriorityLevel.h"

class Administrator : public User {
public:
    Administrator(const std::string& uname, const std::string& pword, std::map<std::string, Project>& projects);

    bool addProject(const std::string& projectName, ProjectStatus status);
    bool addDefect(const std::string& projectName, const Defect& defect);
    bool addEmployee(const User& user);
    void assignDefect(const std::string& projectName, const std::string& defectId, const std::string& employeeUsername);
    void editProjectStatus(const std::string& projectName, ProjectStatus status);
    void editDefectPriority(const std::string& projectName, const std::string& defectId, PriorityLevel priority);
    void createReport();

private:
    std::map<std::string, Project>& projects;
    std::map<std::string, User> employees;
};

#endif // ADMINISTRATOR_H
