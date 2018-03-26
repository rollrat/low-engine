//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Camera.cpp - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Camera.h"
#include <math.h>
#include <iostream>

#define radian 0.01745329251994329576923690768489

static GLdouble eyex, eyey, eyez;
static GLdouble centerx, centery, centerz;

static GLdouble x_pin, y_pin;
static GLfloat x_polar, y_polar, z_polar;
static GLfloat mouse_sensitivity;
static GLfloat move_sensitivity;

static GLfloat up_x, up_y, up_z;

static bool free_point;

lowengine::Camera::Camera()
{
  eyex = 0.0; eyey = 1.0; eyez = 0.0;
  x_polar = 0.0; y_polar = 0.0; z_polar = 0.0;
  x_pin = 0.0; y_pin = 0.0;
  mouse_sensitivity = 0.07f;
  move_sensitivity = 0.05f;
  up_x = 0.0; up_y = 1.0; up_z = 0.0;
  free_point = false;
}

void lowengine::Camera::SetLookAt()
{
  gluLookAt(eyex, eyey, eyez,
    eyex + x_polar, eyey + y_polar, eyez + z_polar,
    up_x, up_y, up_z);
}

void lowengine::Camera::SetPin(GLdouble xpin, GLdouble ypin)
{
  x_pin = xpin; y_pin = ypin;
}

void lowengine::Camera::PassiveMotionCallback(int x, int y)
{
  GLfloat x_offset = x - (int)x_pin;
  GLfloat y_offset = y - (int)y_pin;

  x_offset *= mouse_sensitivity;
  y_offset *= mouse_sensitivity;

  polar.AddYaw(x_offset);
  polar.AddPitch(y_offset);

  updatePolar();

  glutWarpPointer((int)x_pin, (int)y_pin);
}

void lowengine::Camera::MoveFront(int value)
{
  eyex += x_polar * move_sensitivity * (float)value;
  eyez += z_polar * move_sensitivity * (float)value;
  if (free_point)
    eyey += y_polar * move_sensitivity * (float)value;
}

void lowengine::Camera::MoveBack(int value)
{
  eyex -= x_polar * move_sensitivity * (float)value;
  eyez -= z_polar * move_sensitivity * (float)value;
  if (free_point)
    eyey -= y_polar * move_sensitivity * (float)value;
}

void lowengine::Camera::MoveLeft(int value)
{
  eyex += z_polar * move_sensitivity * (float)value;
  eyez -= x_polar * move_sensitivity * (float)value;
}

void lowengine::Camera::MoveRight(int value)
{
  eyex -= z_polar * move_sensitivity * (float)value;
  eyez += x_polar * move_sensitivity * (float)value;
}

void lowengine::Camera::MoveUp(int value)
{
  eyey += move_sensitivity * value;
}

void lowengine::Camera::MoveDown(int value)
{
  eyey -= move_sensitivity * value;
}

void lowengine::Camera::RotateLeft(int value)
{
}

void lowengine::Camera::RotateRight(int value)
{
}

void lowengine::Camera::SetFreePoint(bool type)
{
  free_point = type;
}

void lowengine::Camera::updatePolar()
{
  GLfloat yaw = polar.GetYaw();
  GLfloat pitch = polar.GetPitch();

  yaw *= radian;
  pitch *= radian;

  x_polar = sin(pitch) * cos(yaw);
  y_polar = cos(pitch);
  z_polar = sin(pitch) * sin(yaw);
}
