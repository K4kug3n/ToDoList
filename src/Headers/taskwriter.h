#ifndef TASKWRITER_H
#define TASKWRITER_H

#include "pugixml.hpp"

#include <string>

struct Task;

class TaskWriter
{
public:
    TaskWriter();

    void write(Task const& task);
    void save(std::string const& path);

private:
    pugi::xml_document doc;
    pugi::xml_node rootNode;
};

#endif // TASKWRITER_H
