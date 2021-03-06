////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Custom FX. All right reserved.
//
// Advanced example 02: Two Timers
//
// This example will show you how to use two timers. The first timer will turn 
// the LED on, the second timer will turn the LED off.
//
// This file is part of the Custom FX library. This library was developed in 
// order to make Arduino programming as easy as possible. For more information,
// visit our website: http://www.customfx.nl
//
////////////////////////////////////////////////////////////////////////////////

#include <CustomFX.h>

CFX_Led led1(3);              // Connect Led to pin 3
CFX_Timer on_timer(101);      // create a timer with id 101
CFX_Timer off_timer(102);     // create another timer with id 102

void setup() 
{
  on_timer.SetTimer(1004, true); // This timer will turn the LED on
  off_timer.SetTimer(875, true); // This timer will turn the LED off
}

void handleInput(int id, int command, int value)
{
  if (id == 101)
  {
    if (command == CFX_CMD_TIMER_EVENT)
    {
      led1.SetBrightness(255);
    }
  }
  else if (id == 102)
  {
    if (command == CFX_CMD_TIMER_EVENT)
    {
      led1.SetBrightness(0);
    }
  }
}

void loop() 
{
  CFX_Run();
}
