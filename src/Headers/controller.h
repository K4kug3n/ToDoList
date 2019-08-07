#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller
{
public:
    Controller(Model & model);

    void taskInput(int priority, std::string const& description);
    void taskRemove(int priority, std::string const& description);
    void taskCheck(int priority, std::string const& description, bool checked);

    void saveList(std::string const& path);
    void openList(std::string const& path);

private:
    Model & model;
};

#endif // CONTROLLER_H
