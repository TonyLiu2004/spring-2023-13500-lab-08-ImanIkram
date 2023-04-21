#include <iostream>
#include <cmath>
#include "imageio.h"
#include "funcs.h"

//TASK A

void invert (std::string input , int imgage[MAX_H][MAX_W]){
  int h, w;
  readImage(input, imgage, h, w); 

  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = (255-imgage[row][col]);
    }
  }
  
  writeImage("taskA.pgm", out, h, w);
}


//TASK B

void inverthalf(std::string input, int img[MAX_H][MAX_W]){
  int h, w;
  readImage(input, img, h, w); 
  
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
        if (col >= w/2)
            out[row][col] = (255-img[row][col]);
        else 
            out[row][col] = (img[row][col]);

    }
  }
  

  writeImage("taskB.pgm",out, h, w);
}


//TASK C

void box(std::string input, int img[MAX_H][MAX_W]){
  int h, w;
  readImage(input, img, h, w); 

int borderHeight = round((h*25)/100);
int borderWidth = round((w*25)/100);

  for(int row = borderHeight; row < h-borderHeight; row++) {
    for(int col = borderWidth; col < w-borderWidth; col++) {
        img[row][col] = 255;
    }
  }
  
  writeImage("taskC.pgm", img , h, w);
}


//TASK D

void frame(std::string input, int img[MAX_H][MAX_W]){
    int h, w;
    readImage(input, img, h, w);

    int borderHeight = round((h*25)/100);
    int borderWidth = round((w*25)/100);

  for(int row = borderHeight; row < h-borderHeight; row++) {
    for (int col = borderWidth; col < w-borderWidth; col++){
        if (row == borderHeight ||  col == borderWidth || row >= h-borderHeight  || col >= w-borderWidth  || row == h * 3/4  ||col == w * 3/4 )
          img[row][col] = 255;
    }
  }

  writeImage("taskD.pgm", img , h, w); 

}



//TASK E
void scale(std::string input, int img[MAX_H][MAX_W]){
  int h, w;
  readImage(input, img, h, w);

  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
        out[row*2][col*2] = img[row][col];
        out[row*2][col*2 + 1] = img[row][col];
        out[row*2 + 1][col*2] = img[row][col];
        out[row*2 + 1][col*2 + 1] = img[row][col];
    }
  }

  h = h*2;
  w = w*2;
  writeImage("taskE.pgm", out , h, w); 
}


//TASK F
void pixelate(std::string input, int img[MAX_H][MAX_W]){
  int h, w;
  readImage(input, img, h, w);

  int out[MAX_H][MAX_W];
  int avg;

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
        avg = round((img[row][col] + img[row+1][col] + img[row][col+1] + img[row+1][col+1])/4);
        out[row*2][col*2] = avg;
        out[row*2][col*2 + 1] = avg;
        out[row*2 + 1][col*2] = avg;
        out[row*2 + 1][col*2 + 1] = avg;
    }
  }

  writeImage("taskF.pgm", out , h*2, w*2); 
}
