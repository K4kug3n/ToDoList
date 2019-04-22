#include "view.h"

View::View(Model & model, Controller & controller):
    model{ model },
    controller{ controller }
{
    model.addObserver(*this);
    setup();
}

void View::display()
{   
//    window.addTask(Task{1, "Finish this"});
//    window.addTask(Task{2, "Finish other things"});
//    window.addTask(Task{3, "Finish shitty things"});

    window.show();
}

void View::update()
{
    for(auto const& task : model.getTasks())
    {
        window.addTask(task);
    }
}

View::~View()
{
}

void View::setup()
{
    window.setFixedSize(620, 460);
}
