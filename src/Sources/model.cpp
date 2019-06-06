#include "model.h"

#include <algorithm>
#include <iostream>

Model::Model()
{
}

void Model::addTask(Task const& task)
{
    tasks.push_back(task);
    notifyInput(task.priority, task.description);
}

void Model::deleteTask(Task const& task)
{
    const auto tasks_it = std::find_if(tasks.begin(), tasks.end(),
                [task](auto t) { return (task.priority == t.priority && task.description == t.description); });
    tasks.erase(tasks_it);


    notifyDelete(task.priority, task.description);
}

void Model::checkTask(const Task &task, bool checked)
{
    const auto tasks_it = std::find_if(tasks.begin(), tasks.end(),
                [task](auto t) { return (task.priority == t.priority && task.description == t.description); });
    (*tasks_it).checked = checked;

    notifyCheck(task.priority, task.description, checked);
}

std::vector<Task> Model::getTasks() const
{
    return tasks;
}
