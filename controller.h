#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller
{
public:
    Controller(Model & model);

    void taskInput(int priority, QString const& description);
    void taskRemove(int priority, QString const& description);
<<<<<<< HEAD:controller.h
    void saveList();
    void openList();
=======
>>>>>>> f359a0c0026ba333e7db66123c0441d64f65cd1a:Controller.h

private:
    Model & model;
};

#endif // CONTROLLER_H
