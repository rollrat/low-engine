//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Interface.h - 03/20/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LOWENGINE_INTERFACE_
#define _LOWENGINE_INTERFACE_

namespace lowengine
{

class Object
{
public:
  virtual void Draw() = 0;
};

}


#endif