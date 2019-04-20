#include "model.h"

#include <algorithm>

Model::Model()
{

}

void Model::addTask(Task const& task)
{
    tasks.push_back(task);
}

void Model::deleteTask(Task const& task)
{
    const auto tasks_it = std::remove_if(tasks.begin(), tasks.end(),
                [task](auto t) { return (task.priority == t.priority && task.description == t.description); });
            tasks.erase(tasks_it, tasks.end());

}

std::vector<Task> Model::getTasks() const
{
    return tasks;
}
