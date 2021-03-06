////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2016 Custom FX. All right reserved.
//
// This file is part of the Custom FX library. This library was developed in 
// order to make Arduino programming as easy as possible. For more information,
// visit our website: http://www.customfx.nl
//
// The Custom FX library is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// The Custom FX library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
// for more details.
//
// You should have received a copy of the GNU General Public License along with
// The Custom FX library. If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef CFX_RGBLEDANIMATIONFADEINOUT_H
#define CFX_RGBLEDANIMATIONFADEINOUT_H

#include <CFX_AnimationBase.hpp>
#include <CFX_LedBase.hpp>
#include <CustomFX.h>

class CFX_RGBLedAnimationFadeInOut: public CFX_AnimationBase
{
  public:
    
    CFX_RGBLedAnimationFadeInOut();
    CFX_RGBLedAnimationFadeInOut(int fadeInTime, int onTime, int fadeOutTime, 
      int offTime, CFX_Color color, CFX_LedBase* output);
    
    void SetTimes(int fadeInTime, int onTime, int fadeOutTime, int offTime);
    void SetColor(CFX_Color color);
    void SetOutputDevice(CFX_LedBase* output);

    virtual bool InitializeAnimation(int timeStep);
    virtual bool UpdateAnimation(int timestep);

  private: // private functions
    void SetStepSizes();
  
  private: // private member variables
    CFX_LedBase* m_output;
    CFX_Color m_color;
    
    int m_fadeInSteps;
    int m_onSteps;
    int m_fadeOutSteps;
    int m_offSteps;
    
    float m_fadeInStepRed;
    float m_fadeInStepGreen;
    float m_fadeInStepBlue;
    float m_fadeOutStepRed;
    float m_fadeOutStepGreen;
    float m_fadeOutStepBlue;
        
    int m_animationStep; // counter to keep track of the current step in the animation
    int m_totalAnimationSteps;
};

#endif // CFX_RGBLEDANIMATIONFADEINOUT_H
