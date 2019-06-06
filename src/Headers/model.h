#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "task.h"
#include "observable.h"

class Model : public Observable
{
public:
    Model();

    void addTask(Task const& task);
    void deleteTask(Task const& task);
    void checkTask(Task const& task, bool checked);
    std::vector<Task> getTasks() const;

private:
    std::vector<Task> tasks;
};

#endif // MODEL_H
