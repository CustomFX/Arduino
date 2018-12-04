////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2016-2018 Custom FX. All right reserved.
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

#ifndef CFX_RGBLedMatrix_H
#define CFX_RGBLedMatrix_H

#include <CFX_LedStripBase.hpp>
#include <CFX_LedStrip.hpp>

class CFX_RGBLedMatrix: public CFX_LedStrip
{
  public:
    CFX_RGBLedMatrix(int pinnumber, uint16_t width, uint16_t height, int type = NEO_GRB + NEO_KHZ800);
    
    virtual void SetPixelColor(uint16_t x_pos, uint16_t y_pos, const CFX_Color& color);
    virtual long GetPixelColorLong(uint16_t x_pos, uint16_t y_pos) const;
    
    virtual void SetPixelBrightness(uint16_t x_pos, uint16_t y_pos, uint8_t brightness);
    virtual uint8_t GetPixelBrightness(uint16_t x_pos, uint16_t y_pos) const;

  private:
    uint16_t m_width;
    uint16_t m_height;
};


#endif //CFX_RGBLedMatrix_H