#include "view.h"

#include <iostream>

View::View(Model & model, Controller & controller):
    model{ model },
    controller{ controller }
{
    setupInterface();
    setupConnections();
}

void View::display()
{   
    window.show();
}

void View::delete_update(int priority, QString const& description)
{
    window.deleteTask(priority, description);
}

void View::input_update(int priority, QString const& description)
{
    window.addTask(priority, description);
}

View::~View()
{
}

void View::setupInterface()
{
    window.setFixedSize(620, 460);
}

void View::setupConnections()
{
    QObject::connect(&window, &MainWindow::inputSignal, [this](int priority, QString const& description){
        controller.taskInput(priority, description);
    });

    QObject::connect(&window, &MainWindow::removeSignal, [this](int priority, QString const& description){
        controller.taskRemove(priority, description);
    });

    QObject::connect(&window, &MainWindow::saveSignal, [this](){
        controller.saveList();
    });

    QObject::connect(&window, &MainWindow::openSignal, [this](){
        controller.openList();
    });
}
