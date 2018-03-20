//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Render.cpp - 03/20/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Display.h"

void lowengine::Display::Callback()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  glColor3f(0.5, 0.5, 1);

  glLineWidth(10);
  glPolygonMode(GL_FRONT, GL_LINE);
  glBegin(GL_POLYGON);
    glVertex2i(100, 200);
    glVertex2i(50, 50);
    glVertex2i(350, 50);
    glVertex2i(250, 250);
  glEnd();

  glDisable(GL_LINE_SMOOTH);

  glFlush();
}
