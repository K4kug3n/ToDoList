#include "observable.h"

#include <utility>

Observable::Observable()
{
}

void Observable::addObserver(Observer & obs)
{
    observers.push_back( std::make_shared<Observer>(obs) );
}

void Observable::notify()
{
    for(auto & observer : observers)
    {
        observer->update();
    }
}
