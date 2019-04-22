#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"
#include <vector>
#include <memory>

class Observable
{
public:
    Observable();

    void addObserver(Observer & obs);
    void notify();

private:
    std::vector< std::shared_ptr<Observer> > observers;
};

#endif // OBSERVABLE_H
