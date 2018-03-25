//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Texture.h - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <gl/glew.h>
#include <glfw/glfw3.h>

#include "Texture.h"

#include <stdio.h>

// https://stackoverflow.com/a/12524013/3355656
GLuint lowengine::Texture::LoadTexture(const char * filename)
{
  GLuint texture;
  int width, height;
  unsigned char * data;
  FILE * file;

  fopen_s(&file, filename, "rb");

  if (file == NULL) return 0;
  width = 512;
  height = 512;
  data = new unsigned char[width * height * 3];
  fread(data, width * height * 3, 1, file);
  fclose(file);

  for (int i = 0; i < width * height; ++i)
  {
    int index = i * 3;
    unsigned char B, R;
    B = data[index];
    R = data[index + 2];

    data[index] = R;
    data[index + 2] = B;

  }

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
  delete[] data;
  return texture;
}
