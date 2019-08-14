#include "view.h"

#include <iostream>
#include <QString>

View::View(Controller & controller):
    controller{ controller }
{
    setupInterface();
    setupConnections();
}

void View::display()
{
    window.show();
}

void View::checkUpdate(size_t id, bool checked)
{
    window.checkTask(id, checked);
}

void View::deleteUpdate(size_t id)
{
    window.deleteTask(id);
}

void View::clearUpdate()
{
    window.clearTasks();
}

void View::inputUpdate(size_t id, int priority, std::string const& description, bool checked)
{
    window.addTask(id, priority, QString::fromStdString(description), checked);
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

    QObject::connect(&window, &MainWindow::removeSignal, [this](size_t id){
        controller.taskRemove(id);
    });

    QObject::connect(&window, &MainWindow::checkSignal, [this](size_t id, bool checked){
        controller.taskCheck(id, checked);
    });

    QObject::connect(&window, &MainWindow::saveSignal, [this](QString const& path){
        controller.saveList(path.toStdString());
    });

    QObject::connect(&window, &MainWindow::openSignal, [this](QString const& path){
        controller.openList(path.toStdString());
    });
}
