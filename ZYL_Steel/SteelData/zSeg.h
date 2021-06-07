#pragma once
#include "zEntity.h"
#include "zJoint.h"
class STEELDATA_API zSeg :
  public zEntity
{
public:
  zSeg();
  virtual ~zSeg();

  zJoint jointI;
  zJoint jointJ;

};

