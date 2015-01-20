#pragma once

namespace tiny_render
{
  void line(int x0, int y0, int x1, int y1, TGAImage&, const TGAColor&);
  void line(Vec2i from, Vec2i to, TGAImage&, const TGAColor&);
  void triangle(Vec2i, Vec2i, Vec2i, TGAImage&, const TGAColor&);
  void plot_sun(TGAImage& , const TGAColor&);
}
