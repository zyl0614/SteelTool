#pragma once

#include "ProjectServer.h"

class LoadModelData
{
public:
  LoadModelData();
  ~LoadModelData();

  ProjectServer *mpPrj;

  std::string mFilePathName;

public:
  void setLoadPath(std::string strFilePathName);
  void Load();

private:
  void _Load_Project    ();
	void _load_Material   ();
	void _load_Sect       ();
	void _load_Case       ();
	void _load_Comb       ();
	void _load_Axis       ();
	void _load_Floor      ();
	void _load_Joint      ();
	void _load_Col        ();
	void _load_Beam       ();
	void _load_Brace      ();
	void _load_Wall       ();
	void _Load_Crane      ();
	void _Load_CraneAssign();
	void _Load_CraneLoad  ();

};

