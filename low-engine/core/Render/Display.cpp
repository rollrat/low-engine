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

#include <Object\Text.h>

GLfloat fps;

void lowengine::Display::Initialize()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glutSetCursor(GLUT_CURSOR_NONE);
  
  camera.SetPin((GLfloat)width / 2, (GLfloat)height/2);
}

void lowengine::Display::DisplayCallback()
{
  adjustPerspective();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  // TODO: dsiplay processing
  for (auto& obj : display_objs)
  {
    glLoadIdentity();
    camera.SetLookAt();
    obj->Draw();
  }

  if (print_fps)
  {
    (new RasterText(0.0,10.0,0.0,width,height,std::string("FPS: ")+std::to_string(fps)))->Draw();
  }

  glutSwapBuffers();
}

void lowengine::Display::ReshapeCallback(GLsizei width, GLsizei height)
{
  if (height == 0) height = 1;
  this->width = width;
  this->height = height;
  glViewport(0, 0, width, height);
  camera.SetPin((GLfloat)width / 2, (GLfloat)height / 2);
}

static lowengine::Display* display_instance;
extern "C"
static void timerCallback(int value)
{
  display_instance->TimerCallback(value);
}
void lowengine::Display::TimerCallback(int value)
{
  // TODO: timer processing
  processKeyboardMove();
  updateFps();

  glutPostRedisplay();
  glutTimerFunc(1, timerCallback, 0);
}

void lowengine::Display::adjustPerspective()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void lowengine::Display::processKeyboardMove()
{
  if (keyboard.NormalKeyStatus('w'))
    camera.MoveFront(1);
  if (keyboard.NormalKeyStatus('s'))
    camera.MoveBack(1);
  if (keyboard.NormalKeyStatus('a'))
    camera.MoveLeft(1);
  if (keyboard.NormalKeyStatus('d'))
    camera.MoveRight(1);
  if (keyboard.NormalKeyStatus('c'))
    camera.MoveUp(1);
  if (keyboard.NormalKeyStatus('v'))
    camera.MoveDown(1);
}

static int frame=0,time=0,timebase=0;

void lowengine::Display::updateFps()
{
  frame++;
  time = glutGet(GLUT_ELAPSED_TIME);

  if (time - timebase > 1000)
  {
    fps = frame * 1000.0 / (time - timebase);
    timebase = time;
    frame = 0;
  }
}