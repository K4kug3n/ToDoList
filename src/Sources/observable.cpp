#include "observable.h"

Observable::Observable()
{
}

void Observable::addObserver(std::weak_ptr<Observer> const& obs)
{
    observers.push_back(obs);
}

void Observable::notifyCheck(size_t id, bool checked)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->checkUpdate(id, checked);
    }
}

void Observable::notifyDelete(size_t id)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->deleteUpdate(id);
    }
}

void Observable::notifyClear()
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->clearUpdate();
    }
}

void Observable::notifyInput(size_t id, int priority, std::string const& description, bool checked)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->inputUpdate(id, priority, description, checked);
    }

}



