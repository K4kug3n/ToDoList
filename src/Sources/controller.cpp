#include "controller.h"
#include "taskwriter.h"
#include "readerfunctions.h"

Controller::Controller(Model & model):
    model{ model }
{
}

void Controller::taskInput(int priority, std::string const& description)
{
    model.addTask( Task{ priority, description } );
}

void Controller::taskRemove(int priority, const std::string &description)
{
    model.deleteTask( Task{ priority, description } );
}

void Controller::taskCheck(int priority, const std::string &description, bool checked)
{
    model.checkTask( Task{ priority, description }, checked);
}

void Controller::saveList(std::string const& path)
{
    TaskWriter writer;

    for(auto it{ model.begin() }; it != model.end(); it++)
    {
        writer.write(*it);
    }

    writer.save(path);
}

void Controller::openList(std::string const& path)
{
    model.clear();

   for(auto const& task : getTasksFrom(path))
   {
        model.addTask(task);
   }
}
