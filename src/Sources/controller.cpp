#include "controller.h"
#include "taskwriter.h"
#include "readerfunctions.h"

Controller::Controller(Model & model):
    model{ model }
{
}

void Controller::taskInput(int priority, std::string const& description)
{
    model.addTask(priority, description);
}

void Controller::taskRemove(size_t id)
{
    model.deleteTask(id);
}

void Controller::taskCheck(size_t id, bool checked)
{
    model.checkTask(id, checked);
}

void Controller::saveList(std::string const& path)
{
    TaskWriter writer;

    for(auto it{ model.begin() }; it != model.end(); it++)
    {
        writer.writeTask(*it);
    }

    writer.saveNextID(model.nextID);
    writer.save(path);
}

void Controller::openList(std::string const& path)
{
    model.clear();

   for(auto const& task : getTasksFrom(path))
   {
        model.addTask(task.id, task.priority, task.description, task.checked);
   }

   model.nextID = readNextIDFrom(path);
}
