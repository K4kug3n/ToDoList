#include "model.h"

#include <algorithm>

Model::Model() : //ADD DEFAULT ID PARAMETER ?
    nextID{ 0 }
{
}

void Model::addTask(int priority, std::string const& description)
{
    addTask(nextID, priority, description, false);
    ++nextID;
}

void Model::addTask(size_t id, int priority, const std::string & description, bool checked)
{
    tasks.push_back( Task{ id, priority, description, checked } );
    notifyInput(id, priority, description, checked);
}

void Model::deleteTask(size_t id)
{
    std::remove_if(tasks.begin(), tasks.end(), [id](Task const& t){
        return t.id == id;
    });

    notifyDelete(id);
}

void Model::checkTask(size_t id, bool checked)
{
    auto tasks_it = std::find_if(tasks.begin(), tasks.end(),
                [id](Task const& t) { return (t.id == id); });
    (*tasks_it).checked = checked;

    notifyCheck(id, checked);
}

void Model::clear()
{
    notifyClear();

    tasks.clear();
    nextID = 0;
}

bool Model::empty()
{
    return tasks.empty();
}

Model::iterator Model::begin()
{
    return tasks.begin();
}

Model::iterator Model::end()
{
    return tasks.end();
}

Model::const_iterator Model::begin() const
{
    return tasks.cbegin();
}

Model::const_iterator Model::end() const
{
    return tasks.end();
}
