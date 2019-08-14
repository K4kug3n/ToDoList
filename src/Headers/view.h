#ifndef VIEW_H
#define VIEW_H

#include "mainwindow.h"
#include "model.h"
#include "controller.h"
#include "observer.h"

class View : public Observer
{
public:
    View(Controller & controller);

    void display();
    void inputUpdate(size_t id, int priority, std::string const& description, bool checked) override;
    void deleteUpdate(size_t id) override;
    void clearUpdate() override;
    void checkUpdate(size_t id, bool checked) override;

    ~View() override;

private:
    void setupInterface();
    void setupConnections();
    void setupInput();
    void setupDelete();

    MainWindow window;
    Controller & controller;
};

#endif // VIEW_H
