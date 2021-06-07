#include "stdafx.h"
#include "zPoint3d.h"
#include "libTool.h"


zPoint3d::zPoint3d()
{
}


zPoint3d::zPoint3d(double dX, double dY, double dZ, double dA /*= 0*/)
{

}

zPoint3d::~zPoint3d()
{
}

void zPoint3d::Set(double dX, double dY, double dZ)
{
	mdX = dX; mdY = dY; mdZ = dZ;
}

bool zPoint3d::operator==(const zPoint3d& pnt) const
{
  bool bRe(true);

  if (this != &pnt)
  {
    bRe = bRe && MEQf03(mdX, pnt.mdX);
    bRe = bRe && MEQf03(mdY, pnt.mdY);
    bRe = bRe && MEQf03(mdZ, pnt.mdZ);
    bRe = bRe && MEQf03(mdA, pnt.mdA);
  }

  return bRe;
}
