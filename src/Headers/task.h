#ifndef TASK_H
#define TASK_H

#include <string>

struct Task
{
    Task(size_t id, int prio, std::string const& descr, bool state):
        id{ id }, priority{ prio }, description{ descr }, checked{ state }
    {
    }

    size_t id;
    int priority;
    std::string description;
    bool checked = false;
};

#endif // TASK_H
