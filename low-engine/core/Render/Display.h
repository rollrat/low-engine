//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Display.h - 03/20/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_DISPLAY_
#define _LOWENGINE_DISPLAY_

#include <gl\glew.h>
#include <glut.h>
#include <vector>
#include <Object\Object.h>
#include <Camera\Camera.h>
#include <Keyboard\Keyboard.h>

namespace lowengine
{

class Display
{
  GLsizei width;
  GLsizei height;
  std::vector<Object*> display_objs;
  Camera camera;
  Keyboard keyboard;
  bool print_fps = true;

public:

  void Initialize();
  void DisplayCallback();
  void ReshapeCallback(GLsizei width, GLsizei height);
  void TimerCallback(int value);

  Camera& CameraInstance() { return camera; }
  Keyboard& KeyboardInstance() { return keyboard; }

  void AddObject(Object *obj) { display_objs.push_back(obj); }

private:
  void adjustPerspective();
  void processKeyboardMove();
  void updateFps();
};

}


#endif