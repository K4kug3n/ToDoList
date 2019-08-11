#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer
{
public:
    Observer();

    virtual void inputUpdate(size_t id, int priority, std::string const& description, bool checked) = 0;
    virtual void deleteUpdate(size_t id) = 0;
    virtual void checkUpdate(size_t id, bool checked) = 0;

    virtual ~Observer();
};

#endif // OBSERVER_H
