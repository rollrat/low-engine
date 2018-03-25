//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Box.cpp - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Box.h"
#include <glut.h>

void lowengine::Box::Draw()
{
  glTranslatef(x, y, z);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  glColor3f(0.5, 0.5, 0.5);
  glLineWidth(5);

  GLfloat v1[][3] = {
    {0.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},
    {1.0, 0.0, 1.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, 0.0},
  };
  GLfloat v2[][3] = {
    {0.0, 1.0, 0.0},
    {1.0, 1.0, 0.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0},
    {0.0, 1.0, 0.0},
  };

  //glBegin(GL_LINES);

  //  // bottom
  //  for (int i = 0; i < 4; i++)
  //  {
  //    glVertex3fv(v1[i]);
  //    glVertex3fv(v1[i+1]);
  //  }

  //  // top
  //  for (int i = 0; i < 4; i++)
  //  {
  //    glVertex3fv(v2[i]);
  //    glVertex3fv(v2[i + 1]);
  //  }

  //  // vertices
  //  for (int i = 0; i < 4; i++)
  //  {
  //    glVertex3fv(v1[i]);
  //    glVertex3fv(v2[i]);
  //  }

  //  // x
  //  //for (int i = 0; i < 4; i++)
  //  //{
  //  //  glVertex3fv(v1[i]);
  //  //  glVertex3fv(v2[i+1]);
  //  //  glVertex3fv(v1[i+1]);
  //  //  glVertex3fv(v2[i]);
  //  //}
  //  //
  //  //glVertex3fv(v1[0]);
  //  //glVertex3fv(v1[2]);
  //  //glVertex3fv(v1[1]);
  //  //glVertex3fv(v1[3]);
  //  //
  //  //glVertex3fv(v2[0]);
  //  //glVertex3fv(v2[2]);
  //  //glVertex3fv(v2[1]);
  //  //glVertex3fv(v2[3]);

  //glEnd();
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 0.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0, 0.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0, 1.0);
  glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 1.0);
  glEnd();
}
