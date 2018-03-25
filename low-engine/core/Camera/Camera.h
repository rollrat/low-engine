//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Camera.h - 03/21/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_CAMERA_
#define _LOWENGINE_CAMERA_

#include <glut.h>
#include "Polar.h"

namespace lowengine
{

class Camera
{
  Polar polar;

public:

  Camera();
  void SetLookAt();
  void SetPin(GLdouble xpin, GLdouble ypin);

  void PassiveMotionCallback(int x, int y);

  void MoveFront(int value);
  void MoveBack(int value);
  void MoveLeft(int value);
  void MoveRight(int value);
  void MoveUp(int value);
  void MoveDown(int value);
  void RotateLeft(int value);
  void RotateRight(int value);

  void SetFreePoint(bool type);

private:

  void updatePolar();
};

}

#endif