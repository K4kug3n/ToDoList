#ifndef TASKWRITER_H
#define TASKWRITER_H

#include "pugixml.hpp"

#include <string>

struct Task;

class TaskWriter
{
public:
    TaskWriter();

    void writeTask(Task const& task);
    void saveNextID(size_t id);
    void save(std::string const& path);

private:
    pugi::xml_document doc;
    pugi::xml_node rootNode;
};

#endif // TASKWRITER_H
