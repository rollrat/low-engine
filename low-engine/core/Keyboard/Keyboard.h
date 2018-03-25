//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Keyboard.h - 03/25/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_KEYBOARD_
#define _LOWENGINE_KEYBOARD_

#include <vector>

namespace lowengine
{

class Keyboard
{
  bool key_ctrl, key_shift, key_alt;
public:

  void KeyboardDownCallback(unsigned char key, int x, int y);
  void KeyboardUpCallback(unsigned char key, int x, int y);

  bool NormalKeyStatus(unsigned char key);

};

}

#endif