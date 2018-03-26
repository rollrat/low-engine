//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  TexTile.cpp - 03/26/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "TexTile.h"

float tile_x = 0.125;

void lowengine::TexTile::Draw()
{
  glTranslatef(x, y, z);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, tex.GetId());

  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    if (pattern)
    {
      glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
      glTexCoord2f(height*tile_x, 0.0); glVertex3f(0, 0, width);
      glTexCoord2f(height*tile_x, width*tile_x); glVertex3f(height, 0, width);
      glTexCoord2f(0.0, width*tile_x); glVertex3f(height, 0, 0);
    }
    else
    {
      glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
      glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, width);
      glTexCoord2f(1.0, 1.0); glVertex3f(height, 0, width);
      glTexCoord2f(0.0, 1.0); glVertex3f(height, 0, 0);
    }
  glEnd();

  glDisable(GL_TEXTURE_2D);
  glDisable(GL_BLEND);
}
