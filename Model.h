#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "commun.h"

class Model
{
public:
    Model();

    void addTask(Task const& task);
    void deleteTask(Task const& task);
    std::vector<Task> getTasks() const;

private:
    std::vector<Task> tasks;
};

#endif // MODEL_H
