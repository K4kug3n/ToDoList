#include "view.h"

#include <iostream>
#include <QString>

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

void View::checkUpdate(int priority, const std::string &description, bool checked)
{
    window.checkTask(priority, QString::fromStdString(description), checked);
}

void View::deleteUpdate(int priority, std::string const& description)
{
    window.deleteTask(priority, QString::fromStdString(description));
}

void View::inputUpdate(int priority, std::string const& description, bool checked)
{
    window.addTask(priority, QString::fromStdString(description), checked);
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
        controller.taskInput(priority, description.toStdString());
    });

    QObject::connect(&window, &MainWindow::removeSignal, [this](int priority, QString const& description){
        controller.taskRemove(priority, description.toStdString());
    });

    QObject::connect(&window, &MainWindow::checkSignal, [this](int priority, QString const& description, bool checked){
        controller.taskCheck(priority, description.toStdString(), checked);
    });

    QObject::connect(&window, &MainWindow::saveSignal, [this](QString const& path){
        controller.saveList(path.toStdString());
    });

    QObject::connect(&window, &MainWindow::openSignal, [this](QString const& path){
        controller.openList(path.toStdString());
    });
}
