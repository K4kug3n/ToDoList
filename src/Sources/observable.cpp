#include "observable.h"

Observable::Observable()
{
}

void Observable::addObserver(std::weak_ptr<Observer> const& obs)
{
    observers.push_back(obs);
}

void Observable::notifyCheck(int priority, const std::string &description, bool checked)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->checkUpdate(priority, description, checked);
    }
}

void Observable::notifyDelete(int priority, std::string const& description)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->deleteUpdate(priority, description);
    }
}

void Observable::notifyInput(int priority, std::string const& description, bool checked)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->inputUpdate(priority, description, checked);
    }

}

