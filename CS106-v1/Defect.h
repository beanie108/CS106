#ifndef DEFECT_H
#define DEFECT_H

#include <string>
#include "PriorityLevel.h"

class Defect {
public:
    Defect() : id(""), description(""), priority(PriorityLevel::Low) {}
    Defect(const std::string& id, const std::string& description, PriorityLevel priority)
        : id(id), description(description), priority(priority) {}

    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    PriorityLevel getPriority() const { return priority; }
    void setPriority(PriorityLevel newPriority) { priority = newPriority; }
    // Optionally add:
    // void setAssignedEmployee(const std::string& username) { assignedEmployee = username; }

private:
    std::string id;
    std::string description;
    PriorityLevel priority;
    // Optionally add:
    // std::string assignedEmployee;
};

#endif // DEFECT_H
