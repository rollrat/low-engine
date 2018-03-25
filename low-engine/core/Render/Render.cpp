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
  glutInitDisplayMode(GLUT_DOUBLE);
  glutCreateWindow("OpenGL");

  setupCallback();

  display.Initialize();

  glewInit();
}

static lowengine::Display* display_instance;

extern "C"
static void displayCallback()
{
  display_instance->DisplayCallback();
}
extern "C"
static void reshapeCallback(GLsizei width, GLsizei height)
{
  display_instance->ReshapeCallback(width, height);
}
extern "C"
static void timerCallback(int value)
{
  display_instance->TimerCallback(value);
}
extern "C"
static void passiveMotionCallback(int x, int y)
{
  display_instance->CameraInstance().PassiveMotionCallback(x,y);
}
extern "C"
static void keyboardDownCallback(unsigned char key, int x, int y)
{
  display_instance->KeyboardInstance().KeyboardDownCallback(key,x,y);
}
extern "C"
static void keyboardUpCallback(unsigned char key, int x, int y)
{
  display_instance->KeyboardInstance().KeyboardUpCallback(key, x, y);
}

void lowengine::Render::setupCallback()
{
  ::display_instance = &display;
  glutDisplayFunc(::displayCallback);
  glutReshapeFunc(::reshapeCallback);
  glutTimerFunc(100,::timerCallback,0);
  glutPassiveMotionFunc(passiveMotionCallback);
  glutKeyboardFunc(keyboardDownCallback);
  glutKeyboardUpFunc(keyboardUpCallback);
}

void lowengine::Render::MainLoop()
{
  glutMainLoop();
}
