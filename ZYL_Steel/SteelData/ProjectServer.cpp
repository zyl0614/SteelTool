#include "stdafx.h"
#include "ProjectServer.h"


ProjectServer::ProjectServer()
{
}


ProjectServer::~ProjectServer()
{
}

void ProjectServer::Delete()
{
  if (mdata != NULL) { delete mdata; mdata = NULL; }
}

ProjectServer *ProjectServer::mdata = nullptr;
