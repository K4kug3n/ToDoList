#include "readerfunctions.h"

#include "task.h"
#include <QString>
#include <string>
#include <iostream>

Task readTask(const pugi::xml_node & taskNode)
{
    size_t id{ taskNode.attribute("id").as_ullong() };
    int priority{ taskNode.attribute("priority").as_int() };
    std::string description{ taskNode.attribute("description").as_string() };
    bool checked{ taskNode.attribute("checked").as_bool() };

    return Task{ id, priority, description, checked };
}

std::vector<Task> readTasks(const pugi::xml_document &doc)
{
    pugi::xml_node tasksNode{ doc.child("Tasks") };
    std::vector<Task> tasks;

    for(pugi::xml_node taskNode{ tasksNode.child("Task") }; taskNode; taskNode = taskNode.next_sibling("Task"))
    {
        tasks.push_back( readTask(taskNode) );
    }

    return tasks;
}

std::vector<Task> getTasksFrom(const std::string &path)
{
    pugi::xml_document doc;
    doc.load_file(path.c_str());

    return readTasks(doc);
}

size_t readNextIDFrom(const std::string &path)
{
    pugi::xml_document doc;
    doc.load_file(path.c_str());

    return doc.child("Tasks").child("NextID").attribute("value").as_ullong();
}
