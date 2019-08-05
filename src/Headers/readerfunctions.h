#ifndef READERFUNCTIONS_H
#define READERFUNCTIONS_H

#include "pugixml.hpp"

#include <vector>

struct Task;

Task readTask(pugi::xml_node const& taskNode);
std::vector<Task> readTasks(pugi::xml_document const& doc);

std::vector<Task> getTasksFrom(std::string const& path);

#endif // READERFUNCTIONS_H
