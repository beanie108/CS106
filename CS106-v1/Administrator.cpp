#include "Administrator.h"
#include <iostream> // Ensure iostream is included

Administrator::Administrator(const std::string& uname, const std::string& pword, std::map<std::string, Project>& projects)
    : User(uname, pword, Usertype::Administrator), projects(projects) {}

bool Administrator::addProject(const std::string& projectName, ProjectStatus status) {
    if (projects.find(projectName) != projects.end()) {
        return false; // Project already exists
    }
    projects[projectName] = Project(projectName);
    projects[projectName].setStatus(status);
    return true;
}

bool Administrator::addDefect(const std::string& projectName, const Defect& defect) {
    auto it = projects.find(projectName);
    if (it == projects.end()) {
        return false; // Project does not exist
    }
    it->second.addDefect(defect);
    return true;
}

bool Administrator::addEmployee(const User& user) {
    if (employees.find(user.getUsername()) != employees.end()) {
        return false; // Employee already exists
    }
    employees[user.getUsername()] = user;
    return true;
}

void Administrator::assignDefect(const std::string& projectName, const std::string& defectId, const std::string& employeeUsername) {
    auto projectIt = projects.find(projectName);
    if (projectIt != projects.end()) {
        projectIt->second.assignDefect(defectId, employeeUsername);
        std::cout << "Defect Assigned to " << employeeUsername << std::endl; // Output for the administrator menu
    }
    else {
        std::cout << "Project not found" << std::endl;
    }
}

void Administrator::editProjectStatus(const std::string& projectName, ProjectStatus status) {
    auto projectIt = projects.find(projectName);
    if (projectIt != projects.end()) {
        projectIt->second.setStatus(status);
        std::cout << "Project Status Updated" << std::endl; // Added output message
    }
    else {
        std::cout << "Project not found" << std::endl;
    }
}

void Administrator::editDefectPriority(const std::string& projectName, const std::string& defectId, PriorityLevel priority) {
    auto projectIt = projects.find(projectName);
    if (projectIt != projects.end()) {
        projectIt->second.editDefectPriority(defectId, priority);
        std::cout << "Defect Priority Updated" << std::endl; // Added output message
    }
    else {
        std::cout << "Project not found" << std::endl;
    }
}

void Administrator::createReport() {
    for (const auto& pair : projects) {
        pair.second.createReport();
    }
}
