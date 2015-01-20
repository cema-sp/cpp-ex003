#include <iostream>
#include <cmath>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
Model* model = NULL;
const int width = 800;
const int height = 800;

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

int main()
{
  model = new Model("./tmp/head.obj");

  TGAImage image(width, height, TGAImage::RGB);

  for (int i = 0; i < model->nfaces(); i++)
  {
    std::vector<int> face = model->face(i);
    for (int j = 0; j < 3; j++)
    {
      Vec3f v0 = model->vert(face[j]);
      Vec3f v1 = model->vert(face[(j + 1) % 3]);
      int x0 = (v0.x + 1.) * width / 2.;
      int y0 = (v0.y + 1.) * height / 2.;
      int x1 = (v1.x + 1.) * width / 2.;
      int y1 = (v1.y + 1.) * height / 2.;
      line(x0, y0, x1, y1, image, white);
    }
  }
  // image.set(52, 41, red);
  // line(13, 20, 80, 40, image, white);
  plot_sun(image, white);
  image.flip_vertically();
  image.write_tga_file("./tmp/output.tga");
  delete model;

  std::cout << "TGA Image Plotting Finished" << std::endl;
  return 0;
}
