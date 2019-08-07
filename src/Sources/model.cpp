#include "model.h"

#include <algorithm>
#include <iostream>

Model::Model()
{
}

void Model::addTask(Task const& task)
{
    tasks.push_back(task);
    notifyInput(task.priority, task.description, task.checked);
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
    auto tasks_it = std::find_if(tasks.begin(), tasks.end(),
                [task](auto t) { return (task.priority == t.priority && task.description == t.description); });
    (*tasks_it).checked = checked;

    notifyCheck(task.priority, task.description, checked);
}

void Model::clear()
{
    for(auto const& task : tasks)
    {
        notifyDelete(task.priority, task.description);
    }

    tasks.clear();
}

bool Model::empty()
{
    return tasks.empty();
}

Model::iterator Model::begin()
{
    return tasks.begin();
}

Model::iterator Model::end()
{
    return tasks.end();
}

Model::const_iterator Model::begin() const
{
    return tasks.cbegin();
}

Model::const_iterator Model::end() const
{
    return tasks.end();
}
