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

#include "Render.h"

lowengine::Render::Render()
{
  //glutInit(&argc, argv);
  glutInitWindowPosition(400, 200);
  glutInitWindowSize(400, 300);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("OpenGL");

  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0f, 0.0f, 0.0f);
  gluOrtho2D(0.0, 400.0, 0.0, 300.0);

  setupDrawCallback();
}

static lowengine::Display* display_instance;

extern "C"
static void drawCallback()
{
  display_instance->Callback();
}

void lowengine::Render::setupDrawCallback()
{
  ::display_instance = &display;
  ::glutDisplayFunc(::drawCallback);
}

void lowengine::Render::MainLoop()
{
  glutMainLoop();
}
