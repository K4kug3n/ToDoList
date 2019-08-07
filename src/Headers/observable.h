#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"
#include <vector>
#include <memory>

class Observable
{
public:
    Observable();

    void addObserver(std::weak_ptr<Observer> const& obs);
    void notifyInput(int priority, std::string const& description, bool checked);
    void notifyDelete(int priority, std::string const& description);
    void notifyCheck(int priority, std::string const& description, bool checked);

private:
    std::vector< std::weak_ptr<Observer> > observers;
};

#endif // OBSERVABLE_H
