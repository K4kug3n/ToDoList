#include "taskwriter.h"
#include "task.h"

TaskWriter::TaskWriter():
    doc{}
{
    rootNode = doc.append_child("Tasks");
}

void TaskWriter::write(Task const& task)
{
    pugi::xml_node taskNode{ rootNode.append_child("Task") };

    taskNode.append_attribute("priority").set_value(task.priority);
    taskNode.append_attribute("description").set_value(task.description.toStdString().c_str());
    taskNode.append_attribute("checked").set_value(task.checked);
}

void TaskWriter::save(std::string const& path)
{
    doc.save_file( path.c_str() );
}
