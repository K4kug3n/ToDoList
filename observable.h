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
    void notify_input(int priority, QString const& description);
    void notify_delete(int priority, QString const& description);

private:
    std::vector< std::weak_ptr<Observer> > observers;
};

#endif // OBSERVABLE_H
