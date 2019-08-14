#include <QApplication>

#include "model.h"
#include "controller.h"
#include "view.h"

#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a{argc, argv};

    Model myModel{};
    Controller myController{ myModel };
    auto ptrView = std::make_shared<View>(myController);

    myModel.addObserver(ptrView);

    ptrView->display();

    return a.exec();
}
