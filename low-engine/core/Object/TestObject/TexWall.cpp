//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  TexWall.cpp - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "TexWall.h"

void lowengine::TexWall::Draw()
{
  glTranslatef(x, y, z);
  glRotatef(angle, 0.0f, 1.0f, 0.0f);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, tex.GetId());
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
    glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, width);
    glTexCoord2f(1.0, 1.0); glVertex3f(0, height, width);
    glTexCoord2f(0.0, 1.0); glVertex3f(0, height, 0);
  glEnd();

  glDisable(GL_TEXTURE_2D);
  glDisable(GL_BLEND);
}
