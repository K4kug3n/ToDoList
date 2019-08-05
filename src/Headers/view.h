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
    void inputUpdate(int priority, QString const& description, bool checked) override;
    void deleteUpdate(int priority, QString const& description) override;
    void checkUpdate(int priority, QString const& description, bool checked) override;

    ~View() override;

private:
    void setupInterface();
    void setupConnections();
    void setupInput();
    void setupDelete();

    MainWindow window;
    Model & model;
    Controller & controller;
};

#endif // VIEW_H
