//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Keyboard.cpp - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "Keyboard.h"

static bool mapping[128];

void lowengine::Keyboard::KeyboardDownCallback(unsigned char key, int x, int y)
{
  if (key < 128)
  mapping[key] = true;
}

void lowengine::Keyboard::KeyboardUpCallback(unsigned char key, int x, int y)
{
  if (key < 128)
  mapping[key] = false;
}

bool lowengine::Keyboard::NormalKeyStatus(unsigned char key)
{
  if (key < 128)
    return mapping[key];
  return false;
}
