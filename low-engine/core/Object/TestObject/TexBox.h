//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  TexBox.h - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_TEXBOX_
#define _LOWENGINE_TEXBOX_

#include <File/Texture.h>
#include "../Object.h"

namespace lowengine
{

class TexBox : public Object
{
  float x, y, z;
  Texture tex;
public:

  TexBox() {}
  TexBox(float x, float y, float z)
    : x(x), y(y), z(z) { }
  void SetTexture(Texture tex) { this->tex = tex; }
  void Draw();

};

}

#endif