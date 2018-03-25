//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Box.h - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_BOX_
#define _LOWENGINE_BOX_

#include "../Object.h"

namespace lowengine
{

class Box : public Object
{
  float x, y, z;
public:

  Box() {}
  Box(float x, float y, float z) 
    : x(x),y(y),z(z) { }
  void Draw();

};

}

#endif