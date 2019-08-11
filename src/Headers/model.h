#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "task.h"
#include "observable.h"

class Model : public Observable
{
public:
    Model();

    void addTask(int priority, std::string const& description);
    void addTask(size_t id, int priority, std::string const& description, bool checked);
    void deleteTask(size_t id);
    void checkTask(size_t id, bool checked);

    void clear();
    bool empty();

    using iterator = typename std::vector<Task>::iterator;
    iterator begin();
    iterator end();

    using const_iterator = typename std::vector<Task>::const_iterator;
    const_iterator begin() const;
    const_iterator end() const;

    size_t nextID;

private:
    std::vector<Task> tasks;
};

#endif // MODEL_H
