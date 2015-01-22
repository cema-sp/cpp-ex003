#pragma once

namespace tiny_render
{
  std::vector<Vec2i> line(Vec2i from, Vec2i to);
  void line(Vec2i from, Vec2i to, TGAImage&, const TGAColor&);
  std::vector<Vec2i> line(int x0, int y0, int x1, int y1);
  void line(int x0, int y0, int x1, int y1, TGAImage&, const TGAColor&);
  void plot_points(std::vector<Vec2i> points, TGAImage&, const TGAColor&);
  void triangle(Vec2i, Vec2i, Vec2i, TGAImage&, const TGAColor&);
  Vec2i triangle_center(const Vec2i&, const Vec2i&, const Vec2i&);
  void plot_sun(TGAImage& , const TGAColor&);
}
