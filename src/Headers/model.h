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

    void clear();
    bool empty();

    using iterator = typename std::vector<Task>::iterator;
    iterator begin();
    iterator end();

    using const_iterator = typename std::vector<Task>::const_iterator;
    const_iterator begin() const;
    const_iterator end() const;

private:
    std::vector<Task> tasks;
};

#endif // MODEL_H
