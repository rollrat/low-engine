//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Text.h - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_BOX_
#define _LOWENGINE_BOX_

#include "Object.h"
#include <glut.h>
#include <string>

namespace lowengine
{

class RasterText : public Object
{
  float x, y, z;
  GLsizei width, height;
  std::string text;
public:

  RasterText(float x, float y, float z, GLsizei width, GLsizei height, std::string text);

  void Draw();

};

}

#endif