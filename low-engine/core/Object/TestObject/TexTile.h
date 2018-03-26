//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  TexTile.h - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_TEXTILE_
#define _LOWENGINE_TEXTILE_

#include <File/Texture.h>
#include "../Object.h"

namespace lowengine
{

class TexTile : public Object
{
  float x, y, z;
  float width, height;
  bool pattern = true;
  Texture tex;
public:

  TexTile() {}
  TexTile(float x, float y, float z, float width, float height)
    : x(x), y(y), z(z), width(width), height(height) { }
  void SetTexture(Texture tex) { this->tex = tex; }
  void SetPattern(bool pattern) { this->pattern = pattern; }
  void Draw();

};

}

#endif