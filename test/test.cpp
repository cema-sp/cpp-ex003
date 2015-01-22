#include <iostream>
#include <cmath>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"
#include "tiny_render.h"

using namespace tiny_render;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);
// Model* model = NULL;
const int width = 300;
const int height = 300;
const char* output_file_name = "./tmp/output_test.tga";

int main()
{
  TGAImage image(width, height, TGAImage::RGB);

  Vec2i t0[3] = {Vec2i(10, 70),   Vec2i(50, 160),  Vec2i(70, 80)};
  Vec2i t1[3] = {Vec2i(180, 50),  Vec2i(150, 1),   Vec2i(70, 180)};
  Vec2i t2[3] = {Vec2i(180, 150), Vec2i(120, 160), Vec2i(130, 180)};

  // std::cout << arr_ret(10).size() << std::endl;

  triangle(t0[0], t0[1], t0[2], image, red);
  triangle(t1[0], t1[1], t1[2], image, white);
  triangle(t2[0], t2[1], t2[2], image, green);

  Vec2i tc1 = triangle_center(t0[0], t0[1], t0[2]);
  image.set(tc1.x, tc1.y, green);
  Vec2i tc2 = triangle_center(t1[0], t1[1], t1[2]);
  image.set(tc2.x, tc2.y, green);
  Vec2i tc3 = triangle_center(t2[0], t2[1], t2[2]);
  image.set(tc3.x, tc3.y, green);

  image.flip_vertically();
  image.write_tga_file(output_file_name);

  std::cout << "TGA Image Plotting Finished. Output file: " << output_file_name << std::endl;

  return 0;
}
