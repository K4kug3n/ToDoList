#include <QApplication>

#include "model.h"
#include "controller.h"
#include "view.h"

int main(int argc, char *argv[])
{
    QApplication a{argc, argv};

    Model myModel{};
    Controller myController{};
    View myView{};

    myView.display();

    return a.exec();
}
