#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller
{
public:
    Controller(Model & model);

    void taskInput(int priority, QString const& description);
    void taskRemove(int priority, QString const& description);
    void taskCheck(int priority, QString const& description, bool checked);

    void saveList(QString const& path);
    void openList(QString const& path);

private:
    Model & model;
};

#endif // CONTROLLER_H
