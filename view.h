#ifndef VIEW_H
#define VIEW_H

#include "mainwindow.h"
#include "model.h"
#include "controller.h"
#include "observer.h"

class View : public Observer
{
public:
    View(Model & model, Controller & controller);

    void display();
    void input_update(int priority, QString const& description) override;
    void delete_update(int priority, QString const& description) override;

    ~View() override;

private:
    void setupInterface();
<<<<<<< HEAD:view.h
    void setupConnections();
=======
    void setupInput();
    void setupDelete();
>>>>>>> f359a0c0026ba333e7db66123c0441d64f65cd1a:View.h

    MainWindow window;
    Model & model;
    Controller & controller;
};

#endif // VIEW_H
