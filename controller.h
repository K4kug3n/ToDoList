#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller
{
public:
    Controller(Model & model);

    void taskInput(int priority, QString const& description);
    void taskRemove(int priority, QString const& description);
    void saveList();
    void openList();

private:
    Model & model;
};

#endif // CONTROLLER_H
