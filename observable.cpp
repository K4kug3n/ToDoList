#include "observable.h"

Observable::Observable()
{
}

void Observable::addObserver(std::weak_ptr<Observer> const& obs)
{
    observers.push_back(obs);
}

void Observable::notify_delete(int priority, QString const& description)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->delete_update(priority, description);
    }
}

void Observable::notify_input(int priority, QString const& description)
{
    for(auto & weak_obs : observers)
    {
        auto obs_ptr{ weak_obs.lock() };
        obs_ptr->input_update(priority, description);
    }

}
