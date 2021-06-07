#pragma once
#include "SteelData.h"
class STEELDATA_API zPoint3d
{
public:
  double mdX;
  double mdY;
  double mdZ;
  double mdA; //Բ�Ľ�(-2��,2��]

public:
  zPoint3d();
  zPoint3d(double dX, double dY, double dZ, double dA = 0);
  ~zPoint3d();
  void Set(double dX, double dY, double dZ);
  bool operator==(const zPoint3d& pnt)const;
};

