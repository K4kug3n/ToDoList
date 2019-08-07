#ifndef TASK_H
#define TASK_H

#include <string>

struct Task
{
    int priority;
    std::string description;
    bool checked = false;
    size_t id = 0;
};

#endif // TASK_H
