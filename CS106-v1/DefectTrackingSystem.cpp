#include "DefectTrackingSystem.h"
#include "PriorityLevel.h"
#include "Defect.h"
#include "Project.h"
#include <iostream> // Ensure iostream is included

void DefectTrackingSystem::initializeUsers() {
    // Add pre-installed admin user
    users["Admin"] = User("Admin", "Software1", Usertype::Administrator);

    // Add pre-installed developer user
    users["Bob"] = User("Bob", "Developer1", Usertype::Developer);

    // Add pre-installed project
    projects["Oxy"] = Project("Oxy");

    // Add pre-installed defect to project "Oxy"
    Defect preInstalledDefect("Loop Issue", "Loop Issue in the system", PriorityLevel::Medium);
    projects["Oxy"].addDefect(preInstalledDefect);
    projects["Oxy"].assignDefect(preInstalledDefect.getId(), "Bob");
}

bool DefectTrackingSystem::login(const std::string& username, const std::string& password, Usertype& userType) {
    auto it = users.find(username);
    if (it != users.end() && it->second.getPassword() == password) {
        userType = it->second.getUserType();
        currentUser = &it->second;
        return true;
    }
    return false;
}

void DefectTrackingSystem::logout() {
    currentUser = nullptr;
}

bool DefectTrackingSystem::addDefect(const std::string& projectName, const Defect& defect) {
    auto it = projects.find(projectName);
    if (it == projects.end()) {
        std::cout << "Project not found." << std::endl;
        return false; // Project does not exist
    }
    it->second.addDefect(defect);
    return true;
}

bool DefectTrackingSystem::editDefectPriority(const std::string& projectName, const std::string& defectId, PriorityLevel priority) {
    auto it = projects.find(projectName);
    if (it == projects.end()) {
        std::cout << "Project not found." << std::endl;
        return false; // Project does not exist
    }
    it->second.editDefectPriority(defectId, priority);
    return true;
}
