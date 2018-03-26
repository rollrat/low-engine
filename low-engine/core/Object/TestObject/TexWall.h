//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  TexWall.h - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_TEXWALL_
#define _LOWENGINE_TEXWALL_

#include <File/Texture.h>
#include "../Object.h"

namespace lowengine
{

class TexWall : public Object
{
  float x, y, z;
  float width, height;
  float angle;
  Texture tex;
public:

  TexWall() {}
  TexWall(float x, float y, float z, float width, float height, float angle)
    : x(x), y(y), z(z), width(width), height(height), angle(angle) { }
  void SetTexture(Texture tex) { this->tex = tex; }
  void Draw();

};

}

#endif