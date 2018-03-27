//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Sphere.h - 03/27/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_SPHERE_
#define _LOWENGINE_SPHERE_

#include "../Object.h"

namespace lowengine
{

class Sphere : public Object
{
  float x, y, z;
public:

  Sphere() {}
  Sphere(float x, float y, float z)
    : x(x),y(y),z(z) { }
  void Draw();

};

}

#endif