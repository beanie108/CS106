#include <iostream>
#include <string>
#include "DefectTrackingSystem.h"
#include "Administrator.h"
#include "User.h"
#include "Defect.h"
#include "Project.h"
#include "Usertype.h"
#include "PriorityLevel.h"
#include "ProjectStatus.h"

PriorityLevel getPriorityLevelFromInput(int input) {
    switch (input) {
    case 1:
        return PriorityLevel::Low;
    case 2:
        return PriorityLevel::Medium;
    case 3:
        return PriorityLevel::High;
    default:
        return PriorityLevel::Low;  // Default to Low if invalid input
    }
}

ProjectStatus getProjectStatusFromInput(int input) {
    switch (input) {
    case 1:
        return ProjectStatus::Pending;
    case 2:
        return ProjectStatus::InProgress;
    case 3:
        return ProjectStatus::Completed;
    default:
        return ProjectStatus::Pending;  // Default to Pending if invalid input
    }
}

void showAdminMenu(Administrator& admin) {
    int choice;
    std::string projectName, defectId, description, employeeUsername, uname, pword;
    int priorityInput, statusInput, userTypeInput;
    PriorityLevel priority;
    ProjectStatus status;
    Usertype type;

    do {
        std::cout << "Administrator Menu:\n";
        std::cout << "1. Add Project\n";
        std::cout << "2. Add Defect\n";
        std::cout << "3. Assign Defect\n";
        std::cout << "4. Edit Project Status\n";
        std::cout << "5. Edit Defect Priority\n";
        std::cout << "6. Create Report\n";
        std::cout << "7. Add Employee\n";
        std::cout << "8. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter project name: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, projectName);
            std::cout << "Enter project status (1 for Pending, 2 for In Progress, 3 for Completed): ";
            std::cin >> statusInput;
            status = getProjectStatusFromInput(statusInput);
            if (admin.addProject(projectName, status)) {
                std::cout << "Project added successfully.\n";
            }
            else {
                std::cout << "Failed to add project.\n";
            }
            break;
        case 2:
            std::cout << "Enter project name: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, projectName);
            std::cout << "Enter defect ID: ";
            std::cin >> defectId;
            std::cout << "Enter defect description: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, description);
            std::cout << "Enter defect priority (1 for Low, 2 for Medium, 3 for High): ";
            std::cin >> priorityInput;
            priority = getPriorityLevelFromInput(priorityInput);
            if (admin.addDefect(projectName, Defect(defectId, description, priority))) {
                std::cout << "Defect added successfully.\n";
            }
            else {
                std::cout << "Failed to add defect.\n";
            }
            break;
        case 3:
            std::cout << "Enter project name: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, projectName);
            std::cout << "Enter defect ID: ";
            std::cin >> defectId;
            std::cout << "Enter employee username: ";
            std::cin >> employeeUsername;
            admin.assignDefect(projectName, defectId, employeeUsername);
            break;
        case 4:
            std::cout << "Enter project name: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, projectName);
            std::cout << "Enter new status (1 for Pending, 2 for In Progress, 3 for Completed): ";
            std::cin >> statusInput;
            status = getProjectStatusFromInput(statusInput);
            admin.editProjectStatus(projectName, status);
            break;
        case 5:
            std::cout << "Enter project name: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, projectName);
            std::cout << "Enter defect ID: ";
            std::cin >> defectId;
            std::cout << "Enter new priority (1 for Low, 2 for Medium, 3 for High): ";
            std::cin >> priorityInput;
            priority = getPriorityLevelFromInput(priorityInput);
            admin.editDefectPriority(projectName, defectId, priority);
            break;
        case 6:
            admin.createReport();
            break;
        case 7:
            std::cout << "Enter username: ";
            std::cin >> uname;
            std::cout << "Enter password: ";
            std::cin >> pword;
            std::cout << "Enter user type (1 for Developer, 2 for Tester): ";
            std::cin >> userTypeInput;
            type = static_cast<Usertype>(userTypeInput);
            if (admin.addEmployee(User(uname, pword, type))) {
                std::cout << "Employee added successfully.\n";
            }
            else {
                std::cout << "Failed to add employee.\n";
            }
            break;
        case 8:
            std::cout << "Logging out...\n";
            return;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 8);
}

void showEmployeeMenu(DefectTrackingSystem& system, User& user) {
    int choice;
    std::string projectName, defectId, description;
    int priorityInput;
    PriorityLevel priority;

    do {
        std::cout << "Employee Menu:\n";
        std::cout << "1. Add Defect\n";
        std::cout << "2. Edit Defect Priority\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter project name: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, projectName);
            std::cout << "Enter defect ID: ";
            std::cin >> defectId;
            std::cout << "Enter defect description: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, description);
            std::cout << "Enter defect priority (1 for Low, 2 for Medium, 3 for High): ";
            std::cin >> priorityInput;
            priority = getPriorityLevelFromInput(priorityInput);
            system.addDefect(projectName, Defect(defectId, description, priority));
            std::cout << "Defect added successfully.\n";
            break;
        case 2:
            std::cout << "Enter project name: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, projectName);
            std::cout << "Enter defect ID: ";
            std::cin >> defectId;
            std::cout << "Enter new priority (1 for Low, 2 for Medium, 3 for High): ";
            std::cin >> priorityInput;
            priority = getPriorityLevelFromInput(priorityInput);
            system.editDefectPriority(projectName, defectId, priority);
            std::cout << "Defect priority updated successfully.\n";
            break;
        case 3:
            std::cout << "Logging out...\n";
            return;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);
}

int main() {
    DefectTrackingSystem system;
    system.initializeUsers();

    Usertype userType;
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (system.login(username, password, userType)) {
        if (userType == Usertype::Administrator) {
            Administrator admin(username, password, system.getProjects());
            showAdminMenu(admin);
        }
        else {
            User user(username, password, userType);
            showEmployeeMenu(system, user);
        }
        system.logout();
    }
    else {
        std::cout << "Invalid username or password!" << std::endl;
    }

    return 0;
}
