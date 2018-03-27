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
#include <Object\TestObject\Teapot.h>
#include <Object\TestObject\TexBox.h>
#include <Object\TestObject\Wall.h>
#include <Object\TestObject\TexWall.h>
#include <Object\TestObject\TexTile.h>
#include <Object\TestObject\Sphere.h>
#include <File\Texture.h>

using namespace lowengine;

int main(int argc, char** argv) 
{
  Render render(argc, argv);
  Display& display = render.GetDisplay();

  //display.AddObject(new RGBBox());
  //display.AddObject(new Grid());

  //for (int i = 0; i < 10; i++)
  //  for (int j = 0; j < 10; j++)
  //    for (int k = 0; k < 10; k++)
  //      display.AddObject(new Box(i+5.0, j, k+5.0));
  //
  //display.AddObject(new Teapot());
  //display.AddObject(new Wall(-5.0,0.0,-5.0, 10.0,10.0));

  /*Texture tex;
  tex.LoadTexture("back.png");
  TexBox *texbox = new TexBox(-5.0, 0, -5.0);
  texbox->SetTexture(tex);
  display.AddObject(texbox);*/

  Texture tex1;
  tex1.LoadTexture("building.jpg");
  TexWall *texwall = new TexWall(-50.0, 0.0, -50.0, 100.0, 100.0, 0.0);
  TexWall *texwall2 = new TexWall(-50.0, 0.0, 50.0, 100.0, 100.0, 90.0);
  TexWall *texwall3 = new TexWall(50.0, 0.0, 50.0, 100.0, 100.0, 180.0);
  TexWall *texwall4 = new TexWall(50.0, 0.0, -50.0, 100.0, 100.0, -90.0);
  texwall->SetTexture(tex1);
  texwall2->SetTexture(tex1);
  texwall3->SetTexture(tex1);
  texwall4->SetTexture(tex1);
  display.AddObject(texwall);
  display.AddObject(texwall2);
  display.AddObject(texwall3);
  display.AddObject(texwall4);

  Texture tile;
  tile.LoadTexture("tile-texture.jpg");
  TexTile *textile = new TexTile(-50.0, 0.0, -50.0, 100.0, 100.0);
  textile->SetTexture(tile);
  display.AddObject(textile);

  Texture sun;
  sun.LoadTexture("sun.jpg");
  TexTile *suntile = new TexTile(-50.0, 100.0, -50.0, 100.0, 100.0);
  suntile->SetPattern(false);
  suntile->SetTexture(sun);
  display.AddObject(suntile);

  Sphere *sphere;// = new Sphere(2.0, 2.0, 2.0);
  //display.AddObject(sphere);
   sphere = new Sphere(2.0, 2.0, 0.0);
  display.AddObject(sphere);
  sphere = new Sphere(2.0, 2.0, -2.0);
  display.AddObject(sphere);
  sphere = new Sphere(2.0, 2.0, 4.0);
  display.AddObject(sphere);
  sphere = new Sphere(2.0, 2.0, 6.0);
  display.AddObject(sphere);


  render.MainLoop();
}