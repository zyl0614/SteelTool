#pragma once
#include "zEntity.h"
#include "zPoint3d.h"

class zSeg;
class STEELDATA_API zJoint :
  public zEntity
{
public:
  zJoint();
  virtual ~zJoint();


  zPoint3d mPnt;
};

