//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Wall.h - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_WALL_
#define _LOWENGINE_WALL_

#include <glut.h>
#include "../Object.h"

namespace lowengine
{

class Wall : public Object
{
  float x, y, z;
  float width, height;
public:

  Wall() {}
  Wall(float x, float y, float z, float width, float height)
    : x(x), y(y), z(z), width(width), height(height) { }
  void Draw();

};

}

#endif