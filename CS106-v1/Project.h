#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <map>
#include <vector>
#include <iostream>  // Include iostream for cout and endl
#include "Defect.h"
#include "ProjectStatus.h"

class Project {
public:
    Project() : name(""), status(ProjectStatus::Pending) {}
    Project(const std::string& name) : name(name), status(ProjectStatus::Pending) {}

    void addDefect(const Defect& defect) {
        defects[defect.getId()] = defect;
    }

    void assignDefect(const std::string& defectId, const std::string& employeeUsername) {
        auto defectIt = defects.find(defectId);
        if (defectIt != defects.end()) {
            // Assuming you have a method to set the assigned employee in Defect
            // defectIt->second.setAssignedEmployee(employeeUsername);
            // std::cout << "Defect " << defectId << " assigned to " << employeeUsername << std::endl; // Comment out this line
        }
        else {
            std::cout << "Defect not found" << std::endl;
        }
    }

    void setStatus(ProjectStatus newStatus) {
        status = newStatus;
    }

    void editDefectPriority(const std::string& defectId, PriorityLevel priority) {
        auto it = defects.find(defectId);
        if (it != defects.end()) {
            it->second.setPriority(priority);
        }
    }

    void createReport() const {
        std::cout << "Project: " << name << " - Status: " << static_cast<int>(status) << std::endl;
        for (const auto& pair : defects) {
            std::cout << "  Defect ID: " << pair.second.getId()
                << " - Description: " << pair.second.getDescription()
                << " - Priority: " << static_cast<int>(pair.second.getPriority())
                << std::endl;
        }
    }

    const std::map<std::string, Defect>& getDefects() const {
        return defects;
    }

private:
    std::string name;
    ProjectStatus status;
    std::map<std::string, Defect> defects;
};

#endif // PROJECT_H
