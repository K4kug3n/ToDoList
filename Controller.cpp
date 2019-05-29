#include "controller.h"

Controller::Controller(Model & model):
    model{ model }
{
}

void Controller::taskInput(int priority, QString const& description)
{
    model.addTask( Task{ priority, description } );
}

void Controller::taskRemove(int priority, const QString &description)
{
    model.deleteTask( Task{ priority, description } );
}
