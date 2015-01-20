#include <iostream>
#include <cmath>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"
#include "tiny_render.h"

using namespace tiny_render;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
// Model* model = NULL;
const int width = 800;
const int height = 800;
const char* model_file_name = "./tmp/head.obj";
const char* output_file_name = "./tmp/output.tga";

int main()
{
  Model* model = new Model(model_file_name);
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
  image.flip_vertically();
  image.write_tga_file(output_file_name);
  delete model;

  std::cout << "TGA Image Plotting Finished. Output file: " << output_file_name << std::endl;
  return 0;
}
