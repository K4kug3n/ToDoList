#ifndef OBSERVER_H
#define OBSERVER_H

#include <QString>

class Observer
{
public:
    Observer();

    virtual void inputUpdate(int priority, QString const& description) = 0;
    virtual void deleteUpdate(int priority, QString const& description) = 0;
    virtual void checkUpdate(int priority, QString const& description, bool checked) = 0;

    virtual ~Observer();
};

#endif // OBSERVER_H
