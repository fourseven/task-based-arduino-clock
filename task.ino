#include <Task.h>
#include <TaskScheduler.h>

#include <SoftI2C.h>
#include <RTC.h>
#include <DS3232RTC.h>

#include "TimeDisplay.h"
#include "ClockLED.h"


void setup()
{
    Serial.begin(9600);
}

// Main program.
void loop()
{
    // Create the tasks.
    TimeDisplay timeDisplay(100);
    ClockLED    clockLED(&timeDisplay, 2);

    // Initialise the task list and scheduler.

    Task *tasks[] = {  &timeDisplay, &clockLED };
    TaskScheduler sched(tasks, NUM_TASKS(tasks));

    Serial.print("SUP\n");
    // Run the scheduler - never returns.
    sched.run();
}
