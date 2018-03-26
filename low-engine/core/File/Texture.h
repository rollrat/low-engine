//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Texture.h - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_TEXTURE_
#define _LOWENGINE_TEXTURE_

#include <glut.h>
#include <string>

namespace lowengine
{

class Texture
{
  GLuint id;
public:

  bool LoadTexture(std::string path);
  GLuint GetId() const { return id; }
  
};

}

#endif