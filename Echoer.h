#ifndef Echoer_H
#define Echoer_H

#include <Task.h>

// Task to echo serial input.
class Echoer : public Task
{
public:
    Echoer();
    virtual void run(uint32_t now);
    virtual bool canRun(uint32_t now);
};

#endif
