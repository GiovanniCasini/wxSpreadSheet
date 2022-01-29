#include "AbstractObserver.h"

class Subject{
public:

    virtual ~Subject(){};

    virtual void attach(AbstractObserver* o) = 0;
    virtual void detach(AbstractObserver* o) = 0;
};
