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
    auto ptrView = std::make_shared<View>(myModel, myController);

    myModel.addObserver(ptrView);


//    for(auto i{0}; i < 20; i++)
//    {
//        myModel.addTask( Task{ 1, "Finish this"} );
//    }

    ptrView->display();

    return a.exec();
}
