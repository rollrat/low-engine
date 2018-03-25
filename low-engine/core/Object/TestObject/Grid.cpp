//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Grid.cpp - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Grid.h"
#include <glut.h>

void lowengine::Grid::Draw()
{
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  //glColor3f(0.5, 0.5, 1);
  glLineWidth(1);

  int x_p = 100, z_p = 100;
  for (int i = -100; i < 100; i++)
  {
    glBegin(GL_LINES);
    glVertex3f(i, 0, z_p);
    glVertex3f(i, 0, -z_p);
    glEnd();
  }
  for (int i = -100; i < 100; i++)
  {
    glBegin(GL_LINES);
    glVertex3f(x_p, 0, i);
    glVertex3f(-x_p, 0, i);
    glEnd();
  }
  glEnd();
}
