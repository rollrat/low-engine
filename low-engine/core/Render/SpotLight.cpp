//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  SpotLight.cpp - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "SpotLight.h"
#include <math.h>

GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 }; //Black Color
GLfloat qaGreen[] = { 1.0, 0.0, 0.0, 1.0 }; //Green Color
GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //Red Color

                                          // Set lighting intensity and color
GLfloat qaAmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };
GLfloat qaDiffuseLight[] = { 1, 1, 1, 1.0 };
GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat qaLightPosition[] = { 0, 0, 0, 1.0 };
GLfloat dirVector0[] = { 0, -1, 0 };

void lowengine::SpotLight::Init()
{
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

  // Set lighting intensity and color
  glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
  glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
  glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
  ////////////////////////////////////////////////

  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 80.0);// set cutoff angle
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector0);
  glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0); // set focusing strength

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

  //glMaterialfv(GL_FRONT, GL_SPECULAR, qaSpecularLight);
  //glMaterialf(GL_FRONT, GL_SHININESS, 100);
  /*glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaWhite);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaWhite);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);*/
}

void lowengine::SpotLight::On()
{
  glPushMatrix();
  glTranslatef(2.0, 10.0, 2.0);
  //glRotatef(90, 1, 0, 0);
  glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector0);
  glPopMatrix();

  glPushMatrix();
  glDisable(GL_LIGHTING);
  glTranslatef(2.0, 0.0, 2.0);
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glutWireCone(tan(80.0 / 180.0 * 3.14159265),10.0,20,20);
  glEnable(GL_LIGHTING);
  glPopMatrix();

  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaWhite);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaWhite);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
}
