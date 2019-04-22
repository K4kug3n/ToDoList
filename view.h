#ifndef VIEW_H
#define VIEW_H

#include "mainwindow.h"
#include "commun.h"
#include "model.h"
#include "controller.h"
#include "observer.h"

class View : public Observer
{
public:
    View(Model & model, Controller & controller);

    void display();
    void update() override;

    ~View() override;

private:
    void setup();

    MainWindow window;
    Model & model;
    Controller & controller;
};

#endif // VIEW_H
