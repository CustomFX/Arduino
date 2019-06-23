#include "CFX_RGBMatrix.hpp"

CFX_RGBMatrix::CFX_RGBMatrix(int pinnumber, uint16_t width, uint16_t height, int type, bool zigzag = false)
  : CFX_LedStrip(pinnumber, width * height, type)
{
  m_width = width;
  m_height = height;
  m_zigzag = zigzag;
}

void CFX_RGBMatrix::SetPixelColor(uint16_t x_pos, uint16_t y_pos, const CFX_Color& color)
{
  if (x_pos >= m_width || y_pos >= m_height)
    return;
  
  CFX_LedStrip::SetPixelColor(CalculatePixel(x_pos, y_pos), color);
}

long CFX_RGBMatrix::GetPixelColorLong(uint16_t x_pos, uint16_t y_pos) const
{
  if (x_pos >= m_width || y_pos >= m_height)
    return 0;

  return CFX_LedStrip::GetPixelColorLong(CalculatePixel(x_pos, y_pos));
}
    
void CFX_RGBMatrix::SetPixelBrightness(uint16_t x_pos, uint16_t y_pos, uint8_t brightness)
{
  if (x_pos >= m_width || y_pos >= m_height)
    return;

  CFX_LedStrip::SetPixelBrightness(CalculatePixel(x_pos, y_pos), brightness);
}

uint8_t CFX_RGBMatrix::GetPixelBrightness(uint16_t x_pos, uint16_t y_pos) const
{
  if (x_pos >= m_width || y_pos >= m_height)
    return 0;

  return CFX_LedStrip::GetPixelBrightness(CalculatePixel(x_pos, y_pos));
}

void CFX_RGBMatrix::AddSprite(CFX_Sprite* sprite)
{
  m_sprites.Add(sprite);
}

void CFX_RGBMatrix::Commit()
{
  if (m_sprites.Size() > 0)
  {
    SetColor(CFX_Color(0, 0, 0)); // clear matrix
    //this->Clear();

    for (uint16_t i = 0; i < m_sprites.Size(); i++)
    {
      CFX_Sprite* sprite = m_sprites.Get(i);
      sprite->Draw(this);
    }
  }
  CFX_LedStrip::Commit();
}

// private:
uint16_t CFX_RGBMatrix::CalculatePixel(uint16_t x_pos, uint16_t y_pos) const
{
  if (m_zigzag)
  {
    if ( y_pos % 2 == 0)
    {
      return y_pos * m_width + m_width - (x_pos + 1);
    }
    else
    {
      return y_pos * m_width + x_pos;
    }
  }
  else
  {
    return y_pos * m_width + x_pos;
  }
}