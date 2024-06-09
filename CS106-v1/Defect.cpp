#ifndef DEFECT_H
#define DEFECT_H

#include <string>
#include "PriorityLevel.h"

class Defect {
public:
    Defect() : id(""), description(""), priority(PriorityLevel::Low) {} // Default constructor
    Defect(const std::string& id, const std::string& description, PriorityLevel priority)
        : id(id), description(description), priority(priority) {}

    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    PriorityLevel getPriority() const { return priority; }
    void setPriority(PriorityLevel newPriority) { priority = newPriority; }

private:
    std::string id;
    std::string description;
    PriorityLevel priority;
};

#endif // DEFECT_H
