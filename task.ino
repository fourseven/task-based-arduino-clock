#include <Task.h>
#include <TaskScheduler.h>

#include <SoftI2C.h>
#include <RTC.h>
#include <DS3232RTC.h>

#include "TimeReader.h"
#include "Clock.h"

void setup()
{
    Serial.begin(9600);
}

// Main program.
void loop()
{
    // Create the tasks.
    TimeReader timeReader(100);
    Clock      clock(&timeReader, 16);

    // Initialise the task list and scheduler.

    Task *tasks[] = {  &timeReader, &clock };
    TaskScheduler sched(tasks, NUM_TASKS(tasks));

    Serial.print("SUP\n");
    // Run the scheduler - never returns.
    sched.run();
}
