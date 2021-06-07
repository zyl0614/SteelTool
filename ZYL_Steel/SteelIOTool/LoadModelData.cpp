#include "stdafx.h"
#include "LoadModelData.h"
#include "CSqliteDBTool.h"

#include "libTool.h"

#pragma comment(lib, "SteelData.lib")
LoadModelData::LoadModelData()
{
}

LoadModelData::~LoadModelData()
{
}

void SplitString(const std::string& s, std::vector<double>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while (std::string::npos != pos2)
  {
    std::string strtemp = s.substr(pos1, pos2 - pos1);
    double x = stod(strtemp);
    v.push_back(x);

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if (pos1 != s.length())
  {
    std::string strtemp = s.substr(pos1);
    double x = stod(strtemp);
    v.push_back(x);
  }
}
 
void LoadModelData::setLoadPath(std::string strFilePathName)
{
  mFilePathName = strFilePathName;
}

void LoadModelData::Load()
{
  _Load_Project    ();
  _load_Material   ();
  _load_Sect       ();
  _load_Case       ();
  _load_Comb       ();
  _load_Axis       ();
  _load_Floor      ();
  _load_Joint      ();
  _load_Col        ();
  _load_Beam       ();
  _load_Brace      ();
  _load_Wall       ();
  _Load_CraneAssign();
  _Load_CraneLoad  ();
}

void LoadModelData::_Load_Project    ()
{

}
void LoadModelData::_load_Material   ()
{

}
void LoadModelData::_load_Sect       ()
{

}
void LoadModelData::_load_Case       ()
{

}
void LoadModelData::_load_Comb       ()
{

}
void LoadModelData::_load_Axis       ()
{

}
void LoadModelData::_load_Floor      ()
{

}
void LoadModelData::_load_Joint      ()
{

}
void LoadModelData::_load_Col        ()
{
  CSqliteDBTool sqDbTool;
  int n = sqDbTool.ConnectDB(mFilePathName); if (n == -1) return;
  qAStr str = "SELECT * from tblColSeg";
  int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == -1) return;

  while (true)
  {
    zColumnSeg colSeg;
    sqDbTool.get_Field("ID", &colSeg.mID);
    mpPrj->colSegs.push_back(colSeg);
    sqDbTool.MoveNext();
    if (sqDbTool.IsEOF()) break;
  }

  for (zColumnSeg & iCol : mpPrj->colSegs)
  {
    qAStr str = "SELECT * from tblColSeg where ID = " + std::to_string(iCol.mID);
    int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == 0) break;
    int x1 = sqDbTool.get_Field("Jt1", &iCol.jointI.mID);
    int x2 = sqDbTool.get_Field("Jt2", &iCol.jointJ.mID);
  }

  for (zColumnSeg &colSeg : mpPrj->colSegs)
  {
    {
      qAStr str = "SELECT * from tblJoint where ID = " + std::to_string(colSeg.jointI.mID);
      int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == 0) break;
      qAStr strCoord;
      int x1 = sqDbTool.get_Field("Coord", strCoord); if (x1 == -1) break;
      std::vector<double> v;
      SplitString(strCoord, v, ",");
      colSeg.jointI.mPnt.Set(v[0], v[1], v[2]);
    }
    {
      qAStr str = "SELECT * from tblJoint where ID = " + std::to_string(colSeg.jointJ.mID);
      int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == 0) break;
      qAStr strCoord;
      int x1 = sqDbTool.get_Field("Coord", strCoord); if (x1 == -1) break;
      std::vector<double> v;
      SplitString(strCoord, v, ",");
      colSeg.jointJ.mPnt.Set(v[0], v[1], v[2]);
    }
  }
  sqDbTool.CloseQuery();
  sqDbTool.CloseDB();
}
void LoadModelData::_load_Beam       ()
{
  CSqliteDBTool sqDbTool;
  int n = sqDbTool.ConnectDB(mFilePathName); if(n == -1) return;
  qAStr str = "SELECT * from tblBeamSeg";
  int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == -1) return;

  while (true)
  {
	  zBeamSeg beamSeg;
	  sqDbTool.get_Field("ID", &beamSeg.mID); 	 
	  mpPrj->beamSegs.push_back(beamSeg);
	  sqDbTool.MoveNext();
	  if (sqDbTool.IsEOF()) break;
  }

  for (zBeamSeg & iBeam : mpPrj->beamSegs)
  {
	  qAStr str = "SELECT * from tblBeamSeg where ID = " + std::to_string(iBeam.mID);
	  int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == 0) break;
	  int x1 = sqDbTool.get_Field("Jt1", &iBeam.jointI.mID);
	  int x2 = sqDbTool.get_Field("Jt2", &iBeam.jointJ.mID);
  }

  for (zBeamSeg &beamSeg : mpPrj->beamSegs)
  {
    {
      qAStr str = "SELECT * from tblJoint where ID = " + std::to_string(beamSeg.jointI.mID);
      int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == 0) break;
      qAStr strCoord;
      int x1 = sqDbTool.get_Field("Coord", strCoord); if (x1 == -1) break;
      std::vector<double> v;
      SplitString(strCoord, v, ",");
      beamSeg.jointI.mPnt.Set(v[0], v[1], v[2]);
    }
    {
      qAStr str = "SELECT * from tblJoint where ID = " + std::to_string(beamSeg.jointJ.mID);
      int n_query_succed = sqDbTool.QueryDataInDB(str); if (n_query_succed == 0) break;
      qAStr strCoord;
      int x1 = sqDbTool.get_Field("Coord", strCoord); if (x1 == -1) break;
      std::vector<double> v;
      SplitString(strCoord, v, ",");
      beamSeg.jointJ.mPnt.Set(v[0], v[1], v[2]);
    }
  }

  sqDbTool.CloseDB();
}
void LoadModelData::_load_Brace      ()
{

}
void LoadModelData::_load_Wall       ()
{

}
void LoadModelData::_Load_CraneAssign()
{

}
void LoadModelData::_Load_CraneLoad  ()
{

}
                    
                      