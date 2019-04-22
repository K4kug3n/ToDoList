#include <QApplication>

#include "model.h"
#include "controller.h"
#include "view.h"
#include "taskinputpanel.h"

int main(int argc, char *argv[])
{
    QApplication a{argc, argv};

    Model myModel{};
    Controller myController{myModel};
    View myView{myModel, myController};

    myView.display();

    return a.exec();
}
