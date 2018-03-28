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
  glTranslatef(-50,0, -50);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, tex.GetId());
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  int   tiles = 50;
  float u_max = height * tile_x;
  float v_max = width * tile_x;

  glBegin(GL_QUADS);
  glNormal3f(0, 1, 0);

  float x0, x1, y0, y1;

  for (int x = 0; x < tiles; ++x)
  {
    for (int y = 0; y < tiles; ++y)
    {
      x0 = (float)x / (float)tiles;
      x1 = (float)(x + 1) / (float)tiles;
      y0 = (float)y / (float)tiles;
      y1 = (float)(y + 1) / (float)tiles;

      glTexCoord2f(0.0, 0.0); glVertex3f(height*x0, 0, width*y0);
      glTexCoord2f(1.0, 0.0); glVertex3f(height*x0, 0, width*y1);
      glTexCoord2f(1.0, 1.0); glVertex3f(height*x1, 0, width*y1);
      glTexCoord2f(0.0, 1.0); glVertex3f(height*x1, 0, width*y0);

       /*glTexCoord2f(u_max*x0, v_max*y0);
       glTexCoord2f(u_max*x1, v_max*y0);
       glTexCoord2f(u_max*x1, v_max*y1);
       glTexCoord2f(u_max*x0, v_max*y1);*/
    }
  }
  glEnd();

  //glTranslatef(x, y, z);

  //glEnable(GL_BLEND);
  //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  ////glEnable(GL_TEXTURE_2D);
  ////glBindTexture(GL_TEXTURE_2D, tex.GetId());
  ////glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  //glBegin(GL_QUADS);
  //  if (pattern)
  //  {
  //    glNormal3f(0, 1, 0);
  //    //glTexCoord2f(0.0, 0.0); 
  //    glVertex3f(0, 0, 0);
  //    //glTexCoord2f(height*tile_x, 0.0); 
  //    glNormal3f(0, 1, 0);
  //    glVertex3f(0, 0, width);
  //    //glTexCoord2f(height*tile_x, width*tile_x); 
  //    glNormal3f(0, 1, 0);
  //    glVertex3f(height, 0, width);
  //    //glTexCoord2f(0.0, width*tile_x); 
  //    glNormal3f(0, 1, 0);
  //    glVertex3f(height, 0, 0);
  //  }
  //  else
  //  {
  //    glNormal3f(0, -1, 0);
  //    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
  //    glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, width);
  //    glTexCoord2f(1.0, 1.0); glVertex3f(height, 0, width);
  //    glTexCoord2f(0.0, 1.0); glVertex3f(height, 0, 0);
  //  }
  //  /*glNormal3f(0, -1, 0);
  //  glVertex3f(0, 0, 0);
  //  glVertex3f(0, 0, width);
  //  glVertex3f(height, 0, width);
  //  glVertex3f(height, 0, 0);*/
  //glEnd();

  glDisable(GL_TEXTURE_2D);
  glDisable(GL_BLEND);
}
