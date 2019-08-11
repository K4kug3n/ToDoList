#include "taskwriter.h"
#include "task.h"

TaskWriter::TaskWriter():
    doc{}
{
    rootNode = doc.append_child("Tasks");
}

void TaskWriter::writeTask(Task const& task)
{
    pugi::xml_node taskNode{ rootNode.append_child("Task") };

    taskNode.append_attribute("id").set_value(task.id);
    taskNode.append_attribute("priority").set_value(task.priority);
    taskNode.append_attribute("description").set_value(task.description.c_str());
    taskNode.append_attribute("checked").set_value(task.checked);
}

void TaskWriter::saveNextID(size_t id)
{
    pugi::xml_node idNode{ rootNode.append_child("NextID") };
    idNode.append_attribute("value").set_value(id);
}

void TaskWriter::save(std::string const& path)
{
    doc.save_file( path.c_str() );
}
