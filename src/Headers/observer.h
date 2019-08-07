#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer
{
public:
    Observer();

    virtual void inputUpdate(int priority, std::string const& description, bool checked) = 0;
    virtual void deleteUpdate(int priority, std::string const& description) = 0;
    virtual void checkUpdate(int priority, std::string const& description, bool checked) = 0;

    virtual ~Observer();
};

#endif // OBSERVER_H
