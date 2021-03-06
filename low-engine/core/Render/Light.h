//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Light.h - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//


#ifndef _LOWENGINE_LIGHT_
#define _LOWENGINE_LIGHT_

#include <gl\glew.h>
#include <glut.h>
#include "Display.h"

namespace lowengine
{

class Light
{
public:

  Light();
  void Init();
  void On();

private:
};

}


#endif