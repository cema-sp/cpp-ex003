#include <iostream>
#include <cmath>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"
#include "tiny_render.h"

namespace tiny_render
{
  std::vector<Vec2i> line(Vec2i from, Vec2i to)
  {
    std::cout << "Line from " << from << " to " << to << std::endl;
    bool steep = false;

    if (std::abs(to.x - from.x) < std::abs(to.y - from.y))
    {
      std::swap(from.x, from.y);
      std::swap(to.x, to.y);
      steep = true;
    }

    if (from.x > to.x)
    {
      std::swap(from, to);
    }

    int dx = to.x - from.x;
    int dy = to.y - from.y;
    int derror = std::abs(dy);
    int error = 0;
    int y = from.y;
    std::vector<Vec2i> points(dx+1);

    for (int x = from.x; x <= to.x; x++)
    {
      if (steep)
      {

        points[x-from.x] = Vec2i(y, x);
      }
      else
      {
        points[x-from.x] = Vec2i(x, y);
      }

      error += derror;

      if (2 * error > dx)
      {
        y += (to.y > from.y ? 1 : -1);
        error -= dx;
      }
    }

    return points;
  }

  void line(Vec2i from, Vec2i to, TGAImage& image, const TGAColor& color)
  {
    std::vector<Vec2i> points = line(from, to);
    plot_points(points, image, color);
  }

  std::vector<Vec2i> line(int x0, int y0, int x1, int y1)
  {
    return line(Vec2i(x0, y0), Vec2i(x1, y1));
  }

  void line(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color)
  {
    std::vector<Vec2i> points = line(x0, y0, x1, y1);
    plot_points(points, image, color);
  }

  void plot_points(std::vector<Vec2i> points, TGAImage& image, const TGAColor& color)
  {
    for (auto point: points)
    {
      image.set(point.x, point.y, color);
    }
  }

  void triangle(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage& image, const TGAColor& color)
  {
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);
  }

  Vec2i triangle_center(const Vec2i& t0, const Vec2i& t1, const Vec2i& t2)
  {
    Vec2i c(0, 0);
    float k = 1. / 3;
    c = (t0 + t1 + t2) * k;
    return c;
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
