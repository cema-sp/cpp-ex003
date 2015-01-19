#include <iostream>
#include "tgaimage.h"

using namespace std;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

int main()
{
  TGAImage image(100, 100, TGAImage::RGB);
  image.set(52, 41, red);
  image.flip_vertically();
  image.write_tga_file("./output.tga");

  cout << "TGA Image Plotting Finished" << endl;
  return 0;
}

// void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
// {
//   for (float t = 0.; t < 1.; t+=.01)
//   {
//     int x = x0(1.-t) + x1*t;
//     int y = y0(1.-t) + y1*t;
//     image.set(x, y, color);
//   }
// }
