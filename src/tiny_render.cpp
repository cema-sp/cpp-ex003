#include <iostream>
#include <cmath>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"
#include "tiny_render.h"

namespace tiny_render
{
  void line(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color)
  {
    std::cout << "Line from (" << x0 << "; " << y0 << ") to (" << x1 << "; " << y1 << ")" << std::endl;
    bool steep = false;

    if (std::abs(x1 - x0) < std::abs(y1 - y0))
    {
      std::swap(x0, y0);
      std::swap(x1, y1);
      steep = true;
    }

    if (x0 > x1)
    {
      std::swap(x0, x1);
      std::swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    int derror = std::abs(dy);
    int error = 0;
    int y = y0;

    for (int x = x0; x <= x1; x++)
    {
      if (steep)
      {
        image.set(y, x, color);
      }
      else
      {
        image.set(x, y, color);
      }

      error += derror;

      if (2 * error > dx)
      {
        y += (y1 > y0 ? 1 : -1);
        error -= dx;
      }
    }
  }

  void line(Vec2i from, Vec2i to, TGAImage& image, const TGAColor& color)
  {
    line(from.x, from.y, to.x, to.y, image, color);
  }

  void triangle(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage& image, const TGAColor& color)
  {
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);
  }

  void plot_sun(TGAImage &image, TGAColor color)
  {
    int r = 40;
    for (int i = 0; i < r; i+= 4)
    {
      int x = i;
      int y = r - i;
      line(50 - x, 50 - y, 50 + x, 50 + y, image, color);
    }

    for (int i = r; i >= 0; i-= 4)
    {
      int x = i;
      int y = r - i;
      line(50 - x, 50 + y, 50 + x, 50 - y, image, color);
    }
  }
}
