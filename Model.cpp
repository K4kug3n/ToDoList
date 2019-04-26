#include "model.h"

#include <algorithm>
#include <iostream>

Model::Model()
{
}

void Model::addTask(Task const& task)
{
    tasks.push_back(task);
    notify_input(task.priority, task.description);
}

void Model::deleteTask(Task const& task)
{
    const auto tasks_it = std::find_if(tasks.begin(), tasks.end(),
                [task](auto t) { return (task.priority == t.priority && task.description == t.description); });
    tasks.erase(tasks_it);


    notify_delete(task.priority, task.description);
}

std::vector<Task> Model::getTasks() const
{
    return tasks;
}

void Model::printTask() const
{
    std::cout << "Tasks : " << std::endl;
    for(auto const& t : tasks)
    {
        std::cout << "\t -" << t.priority << " - " << t.description.toStdString() << std::endl;
    }
}
