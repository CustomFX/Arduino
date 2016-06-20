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

#include <CFX_RGBLedAnimationFadeToColor.hpp>

CFX_RGBLedAnimationFadeToColor::CFX_RGBLedAnimationFadeToColor()
  : CFX_AnimationBase()
{
  m_output = 0;

  m_colorRed = 0;
  m_colorGreen = 0;
  m_colorBlue = 0;

  m_stepRed = 0;
  m_stepGreen = 0;
  m_stepBlue = 0;
}

CFX_RGBLedAnimationFadeToColor::CFX_RGBLedAnimationFadeToColor(CFX_RGBLed* output)
  : CFX_AnimationBase()
{
  m_output = output;

  m_colorRed = 0;
  m_colorGreen = 0;
  m_colorBlue = 0;

  m_stepRed = 0;
  m_stepGreen = 0;
  m_stepBlue = 0;

}

void CFX_RGBLedAnimationFadeToColor::SetOutputDevice(CFX_RGBLed* output)
{
  m_output = output;
}

void CFX_RGBLedAnimationFadeToColor::FadeToColor(CFX_Color color, int duration)
{
  m_targetColor = color;
  
  int steps = 1;
  if (duration > 0)
  {
    steps = duration / ANIMATION_UPDATE_INTERVAL;
  }
  m_stepRed = (float)(m_targetColor.Red() - m_colorRed) / steps;
  m_stepGreen = (float)(m_targetColor.Green() - m_colorGreen) / steps;
  m_stepBlue = (float)(m_targetColor.Blue() - m_colorBlue) / steps;

  this->Start();
}

void CFX_RGBLedAnimationFadeToColor::UpdateAnimation(int timeStep)
{
  if (m_output)
  {
    if (m_targetColor.Red() != (uint8_t)m_colorRed)
    {
      m_colorRed += m_stepRed;
    }
    
    if (m_targetColor.Green() != (uint8_t)m_colorGreen)
    {
      m_colorGreen += m_stepGreen;
    }

    if (m_targetColor.Blue() != (uint8_t)m_colorBlue)
    {
      m_colorBlue += m_stepBlue;
    }

    m_colorRed = constrain(m_colorRed, 0, 255);
    m_colorGreen = constrain(m_colorGreen, 0, 255);
    m_colorBlue = constrain(m_colorBlue, 0, 255);

    CFX_Color newColor((int)m_colorRed, (int)m_colorGreen, (int)m_colorBlue);
    m_output->SetColor(newColor);
    
    if (newColor == m_targetColor)
    {
      // target reached
      this->Stop();
   }
  }
}