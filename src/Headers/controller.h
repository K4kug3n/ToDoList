#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller
{
public:
    Controller(Model & model);

    void taskInput(int priority, std::string const& description);
    void taskRemove(size_t id);
    void taskCheck(size_t id, bool checked);

    void saveList(std::string const& path);
    void openList(std::string const& path);

private:
    Model & model;
};

#endif // CONTROLLER_H
