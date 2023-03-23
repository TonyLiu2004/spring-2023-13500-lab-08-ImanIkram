#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main(){

  std::string imgs = "inImage.pgm";
  int image[MAX_H][MAX_W];

  //TASK A
  invert(imgs, image);
  //TASK B
  inverthalf(imgs, image);
  //TASK C
  box(imgs, image);
  //TASK D
  frame(imgs, image);
  //TASK E
  scale(imgs, image);
  //TASK F
  pixelate(imgs, image);

  return 0;
}