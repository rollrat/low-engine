//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Render.h - 03/20/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_RENDER_
#define _LOWENGINE_RENDER_

#include <glut.h>
#include "Display.h"

namespace lowengine
{

class Render
{
  Display display;
public:

  Render();
  void MainLoop();

private:
  void setupDrawCallback();
};

}


#endif