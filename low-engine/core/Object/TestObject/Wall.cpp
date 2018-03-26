//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Wall.cpp - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Wall.h"

void lowengine::Wall::Draw()
{
  glTranslatef(x, y, z);

  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, width);
    glVertex3f(0, height, width);
    glVertex3f(0, height, 0);
  glEnd();
}
