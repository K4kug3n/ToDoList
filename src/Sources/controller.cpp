#include "controller.h"
#include "taskwriter.h"
#include "readerfunctions.h"

Controller::Controller(Model & model):
    model{ model }
{
}

void Controller::taskInput(int priority, QString const& description)
{
    model.addTask( Task{ priority, description } );
}

void Controller::taskRemove(int priority, const QString &description)
{
    model.deleteTask( Task{ priority, description } );
}

void Controller::taskCheck(int priority, const QString &description, bool checked)
{
    model.checkTask( Task{ priority, description }, checked);
}

void Controller::saveList(QString const& path)
{
    TaskWriter writer;

    for(auto const& task : model.getTasks())
    {
        writer.write(task);
    }

    writer.save(path.toStdString());
}

void Controller::openList(QString const& path)
{
    model.clear();

   for(auto const& task : getTasksFrom(path.toStdString()))
   {
        model.addTask(task);
   }
}
