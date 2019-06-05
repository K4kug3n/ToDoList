#ifndef TASK_H
#define TASK_H

#include <QString>

struct Task
{
    int priority;
    QString description;
    bool checked = false;
};

#endif // TASK_H
