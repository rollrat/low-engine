//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Teapot.cpp - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Teapot.h"
#include <stdlib.h>
#include <glut.h>

//float randf()
//{
//  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
//}

void lowengine::Teapot::Draw()
{
  glTranslatef(10.0, 0.0, 0.f);
  glColor3f(1.0, 1.0, 1.0);
  glutSolidTeapot(5);
}
