#include <iostream>
#include <cmath>

#include "../bin/include/SDL2/SDL.h"
#include "Matrix.cpp"

#define RUNNING true

float ang = 0;
float ProjMat[2][3] {
  {1,0,0},
  {0,1,0}
};

SDL_Renderer* Render_func(SDL_Renderer* Renderer){
  //SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
  SDL_RenderPresent(Renderer);

  SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
  SDL_RenderClear(Renderer);
  return Renderer;
}

int main(int argc, char** argv){

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow("This is SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 480, SDL_WINDOW_RESIZABLE);
  SDL_Renderer* Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  SDL_Event event;

  int w, h;
  
  Point3D points[8] {
    {-0.5, -0.5, -0.5},
    {0.5, -0.5, -0.5},
    {0.5, 0.5, -0.5},
    {-0.5, 0.5, -0.5},
    {-0.5, -0.5, 0.5},
    {0.5, -0.5, 0.5},
    {0.5, 0.5, 0.5},
    {-0.5, 0.5, 0.5},
  };

  Point3D Proj_points[8] {};

  //Point3D point {100,75,50};
  //Point3D result = matmulPoint3D(std::size(ProjMat), std::size(ProjMat[0]), ProjMat, point);

  //std::cout << "x : " << result.x << std::endl;
  //std::cout << "y : " << result.y << std::endl;
  //std::cout << "z : " << result.z << std::endl;

  while(RUNNING){
    SDL_PollEvent(&event); 
    int i = 0;

    SDL_GetWindowSize(window, &w, &h);
    w = w/2;
    h = h/2;

    float RotMatX[3][3] {
      {1,0,0},
      {0,cosf(ang),-sinf(ang)},
      {0,sinf(ang),cosf(ang)}
    };

    float RotMatY[3][3] {
      {cosf(ang), 0, sinf(ang)},
      {0, 1, 0},
      {-sinf(ang), 0, cosf(ang)}
    };

    float RotMatZ[3][3] {
      {cosf(ang), -sinf(ang), 0},
      {sinf(ang), cosf(ang), 0},
      {0, 0, 1}
    };

    if(event.window.event == SDL_WINDOWEVENT_CLOSE){
      SDL_DestroyWindow(window);
      break;
    }
    for(auto v : points){
      Point3D Rotated = matmulPoint3D(std::size(RotMatX), std::size(RotMatX[0]), RotMatX, v);
      Rotated = matmulPoint3D(std::size(RotMatY), std::size(RotMatY[0]), RotMatY, Rotated);
      Rotated = matmulPoint3D(std::size(RotMatZ), std::size(RotMatZ[0]), RotMatZ, Rotated);
      Point3D projected2D = matmulPoint3D(std::size(ProjMat), std::size(ProjMat[0]), ProjMat, Rotated);
      projected2D = PointScale(projected2D, 100);
      SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
      SDL_RenderDrawPoint(Renderer, projected2D.x + w, projected2D.y + h);
      Proj_points[i] = projected2D;
      i++;
    }
    PointConnect(Renderer, Proj_points, 0, 1, w, h);
    PointConnect(Renderer, Proj_points, 1, 2, w, h);
    PointConnect(Renderer, Proj_points, 2, 3, w, h);
    PointConnect(Renderer, Proj_points, 3, 0, w, h);

    PointConnect(Renderer, Proj_points, 4, 5, w, h);
    PointConnect(Renderer, Proj_points, 5, 6, w, h);
    PointConnect(Renderer, Proj_points, 6, 7, w, h);
    PointConnect(Renderer, Proj_points, 7, 4, w, h);

    PointConnect(Renderer, Proj_points, 0, 4, w, h);
    PointConnect(Renderer, Proj_points, 1, 5, w, h);
    PointConnect(Renderer, Proj_points, 2, 6, w, h);
    PointConnect(Renderer, Proj_points, 3, 7, w, h);

    Render_func(Renderer);
    ang += 0.01f;
  }

  SDL_Quit();
  return 0;
}
