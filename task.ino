#include <Task.h>
#include <TaskScheduler.h>

#include "Echoer.h"
#include "Blinker.h"


void setup()
{
}

// Main program.
void loop()
{
    // Create the tasks.
    Blinker blinker(13, 250);
    Echoer echoer;

    // Initialise the task list and scheduler.
//    Task *tasks[] = { &blinker };
    Task *tasks[] = { &blinker, &echoer };
    TaskScheduler sched(tasks, NUM_TASKS(tasks));

    // Run the scheduler - never returns.
    sched.run();
}
