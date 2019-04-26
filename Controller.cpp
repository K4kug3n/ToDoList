#include "controller.h"

#include <iostream>

Controller::Controller(Model & model):
    model{ model }
{
}

void Controller::taskInput(int priority, QString const& description)
{
    model.addTask( Task{ priority, description } );
    std::cout << "Add" << std::endl;
    model.printTask();

}

void Controller::taskRemove(int priority, const QString &description)
{
    model.deleteTask( Task{ priority, description } );
    std::cout << "Delete" << std::endl;
    model.printTask();
}
