#include <iostream>

#include "../bin/include/SDL2/SDL.h"

struct Point3D {
  float x;
  float y;
  float z;
};

float* Mat_mul(int sizePR, int sizePC, int sizeM, float proj[][3], float mat[], float* result){

  if(sizePC != sizeM){
    std::cerr << "Columns of matrix A must match Rows of matrix B" << std::endl;
  }

  for(int i = 0; i < sizePR; ++i){
    float sum = 0;
    for(int j = 0; j < sizeM; ++j){
      sum += proj[i][j] * mat[j];
    }
    result[i] = sum;
  }

  return result; 
}

Point3D matmulPoint3D(int sizePR, int sizePC, float proj[][3], Point3D mat){
  if(sizePC != 3){
    std::cerr << "Columns of matrix A must match Rows of matrix B" << std::endl;
  }

  float i_result[3] {0,0,0};

  for(int i = 0; i < sizePR; ++i){
    float sum = 0;
    sum += proj[i][0] * mat.x;
    sum += proj[i][1] * mat.y;
    sum += proj[i][2] * mat.z;
    i_result[i] = sum;
  }

  Point3D result {i_result[0], i_result[1], i_result[2]};

  return result;
}

Point3D PointScale(Point3D point, int scale){
  point.x *= scale;
  point.y *= scale;
  point.z *= scale;

  return point;
}

void PointConnect(SDL_Renderer* Renderer, Point3D point[], int a, int b, int w, int h){
  Point3D m = point[a];
  Point3D n = point[b];
  SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
  SDL_RenderDrawLine(Renderer, m.x + w, m.y + h, n.x + w, n.y + h); 
}

