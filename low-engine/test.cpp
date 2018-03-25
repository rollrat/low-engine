//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  test.cpp - 03/20/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Render\Render.h>

#include <Object\TestObject\RGBBox.h>
#include <Object\TestObject\Grid.h>
#include <Object\TestObject\Box.h>

using namespace lowengine;

int main(int argc, char** argv) 
{
  Render render;
  Display& display = render.GetDisplay();

  display.AddObject(new RGBBox());
  display.AddObject(new Grid());

  display.AddObject(new Box(5.0, 5.0, 5.0));

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
        display.AddObject(new Box(i+5.0, j, k+5.0));

  render.MainLoop();
}