//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Camera.h - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_POLAR_
#define _LOWENGINE_POLAR_

#include <glut.h>

namespace lowengine
{

class Polar
{
  GLfloat yaw, pitch, roll;
public:

  Polar() : yaw(90.0), pitch(90.0), roll(0.0) { }

  GLfloat GetYaw() const { return yaw; }
  GLfloat GetPitch() const { return pitch; }
  GLfloat GetRoll() const { return roll; }

  void AddYaw(GLfloat offset) { 
    yaw += offset;
  }
  void AddPitch(GLfloat offset) { 
    pitch += offset;
    if (pitch > 179.9) pitch = 179.9;
    else if (pitch < 0.1) pitch = 0.1;
  }
  void AddRoll(GLfloat offset) {
    roll += offset;
  }
};

}
#endif