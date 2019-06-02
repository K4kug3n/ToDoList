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
    void setupConnections();

    MainWindow window;
    Model & model;
    Controller & controller;
};

#endif // VIEW_H
