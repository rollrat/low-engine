//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Text.cpp - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Text.h"

lowengine::RasterText::RasterText(float x, float y, float z, 
  GLsizei width, GLsizei height, std::string text)
  : x(x), y(y), z(z), width(width), height(height), text(text)
{
}

void lowengine::RasterText::Draw()
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, width, height, 0);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  const char *c = text.c_str();
  glColor3d(1.0, 1.0, 1.0);
  glRasterPos3f(x, y, z);
  for ( ; *c != '\0'; c++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);

  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}
