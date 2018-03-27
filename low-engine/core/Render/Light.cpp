//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Light.cpp - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Light.h"

GLfloat gll_gambient[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat gll_ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat gll_diffuse[4] = { 0.9f, 0.9f, 0.9f, 1.0f };
GLfloat gll_specular[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat gll_pos[4] = { 0.0f, 5.0f, 0.0f, 1.0f };

lowengine::Light::Light()
{
}

void lowengine::Light::Init()
{
  glEnable(GL_LIGHTING);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gll_gambient);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

  glEnable(GL_LIGHT0);
}

void lowengine::Light::On()
{

  glLightfv(GL_LIGHT0, GL_AMBIENT, gll_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, gll_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, gll_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, gll_pos);

  glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.2);
  glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1);
  glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.05);

  GLfloat spec[] = { 1.0,1.0,1.0,1.0 };
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMateriali(GL_FRONT, GL_SHININESS, 64);


  //GLfloat ambient[] = { 0.3,0.3,0.3 };
  //glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);

  //diffuse material component
  //GLfloat diff[] = { 0.6,0.6,0.6 };
  //glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

  //specular material component
  //GLfloat WhiteSpec[] = { 1,1,1 };
  //glMaterialfv(GL_FRONT, GL_SPECULAR, WhiteSpec);

  //GLfloat shininess = 50;
  //glMaterialf(GL_FRONT, GL_SHININESS, shininess);

}
