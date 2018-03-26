//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Mirror.h - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_MIRROR_
#define _LOWENGINE_MIRROR_

#include "../Object.h"

namespace lowengine
{

class Mirror : public Object
{
  float x, y, z;
public:

  Mirror() {}
  Mirror(float x, float y, float z)
    : x(x),y(y),z(z) { }
  void Draw();

};

}

#endif