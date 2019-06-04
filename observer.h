#ifndef OBSERVER_H
#define OBSERVER_H

#include <QString>

class Observer
{
public:
    Observer();

    virtual void input_update(int priority, QString const& description) = 0;
    virtual void delete_update(int priority, QString const& description) = 0;

    virtual ~Observer();
};

#endif // OBSERVER_H
