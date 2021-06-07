#include "stdafx.h"

#include "CSqliteDBTool.h"
#include <assert.h>
#include <math.h>
//HINSTANCE hDll; //声明一个Dll实例文件句柄 
// 
//CSqliteDBTool g_SqlDB;

CSqliteDBTool::CSqliteDBTool()
{
	m_connection = NULL;
	m_stmtPtr    = NULL;
	m_recordset  = NULL;
	
	m_rows  = 0;
	m_cols  = 0;
	m_index = 1;
}

CSqliteDBTool::~CSqliteDBTool()
{
	CloseDB();
}

int CSqliteDBTool::ConnectDB(const string& source/*,const string& name,const string& password*/)
{
	int      res        = 1;	
	res = sqlite3_open(source.c_str(), &m_connection);
	
	if(res != SQLITE_OK)
	{
		sqlite3_close(m_connection);
		m_connection = 0;
		return -1; 
	}
	//sqlite3_key(m_connection,&name,sizeof(name));  
	/*
	1.在sqlite3.h文件中添加下面3行
	#ifndef SQLITE_HAS_CODEC
	# define SQLITE_HAS_CODEC
	#endif
	2.http://www.cnblogs.com/pennant/archive/2012/10/11/2716134.html
	*/
	return 0;
}

int CSqliteDBTool::CloseDB()
{
	sqlite3_close(m_connection);
	m_connection = 0;

	return 0;
}

int CSqliteDBTool::QueryDataInDB(const string& query)
{	
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	int ret = sqlite3_prepare(m_connection, query.c_str(), query.length(), &m_stmtPtr, NULL);
	int count = sqlite3_column_count(m_stmtPtr);
	string name = "";
	
	for (int i = 0; i < count; i++)
	{
		name = sqlite3_column_name(m_stmtPtr, i);
		m_fieldMap[name] = i;

	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/

	char* errMsg = NULL;
	int   res    = 1;
	
	res = sqlite3_get_table(m_connection, query.c_str(),&m_recordset, &m_rows, &m_cols, &errMsg);

	if (res != SQLITE_OK)
	{
		sqlite3_free_table(m_recordset);	
		m_recordset = NULL;
		return -1; 
	}
	//added by dengwei
	else if (m_rows == 0)
	{
		return 0;
	}
	m_index = 1;
	return 1;
}

int CSqliteDBTool::CloseQuery()
{
	sqlite3_free_table(m_recordset);
	m_recordset = NULL;

	sqlite3_reset(m_stmtPtr);

	m_fieldMap.clear();

	return 0;
}
int CSqliteDBTool::get_Field(int iIndex, string& value)
{	
	value = "";
	assert(m_index<=m_rows);
	
	//第几个字段的内容
	int offset = iIndex;
	
	if(m_recordset[m_index*m_cols+offset])
		value = m_recordset[m_index*m_cols+offset];
	else
		value = "";
	
	return 0;
}

int CSqliteDBTool::get_Field(const string& field, string& value)
{	
	value = "";
	assert(m_index<=m_rows);

	int offset = m_fieldMap[field];
	
	if(m_recordset[m_index*m_cols+offset])
		value = m_recordset[m_index*m_cols+offset];
	else
		value = "";

	return 0;
}

int CSqliteDBTool::get_Field(const string& field, double* value)
{
	*value = -1;
	assert(m_index<=m_rows);
	
	int offset = m_fieldMap[field];
	
 	*value = atof(m_recordset[m_index*m_cols+offset]);

	return 0;
}

int CSqliteDBTool::get_Field(const string& field, int* value)
{
	*value = -1;
	assert(m_index<=m_rows);
	
	int offset = m_fieldMap[field];
	
 	*value = atoi(m_recordset[m_index*m_cols+offset]);
	
	return 0;

}

int CSqliteDBTool::get_Field(const string& field, long* value)
{
	*value = -1;
	assert(m_index<=m_rows);
	
	int offset = m_fieldMap[field];
	
	*value = atol(m_recordset[m_index*m_cols+offset]);
	
	return 0;
}

int CSqliteDBTool::get_Field(int iIndex, long* value)
{
	*value = -1;
	assert(m_index<=m_rows);
	
	int offset = iIndex;
	
	*value = atol(m_recordset[m_index*m_cols+offset]);
	
	return 0;
}
//20111110
int CSqliteDBTool::get_DateTime(int iIndex,string* value)
{
	*value = "";
	assert(m_index<=m_rows);
	
	int offset = iIndex;
		
	if(m_recordset[m_index*m_cols+offset])
		*value = m_recordset[m_index*m_cols+offset];
	else
		*value = "";
	return 0;
}
//20111110
int CSqliteDBTool::put_Field(const string& field, string value)
{
	return 0;
}

int CSqliteDBTool::put_Field(const string& field, int value)
{
	return 0;
}

int CSqliteDBTool::put_Field(const string& field, double value)
{
	return 0;
}

int CSqliteDBTool::MoveNext()
{
	m_index++;
	return 0;
}

int CSqliteDBTool::AddNew()
{
	return 0;
}

int CSqliteDBTool::Update()
{
	return 0;
}

bool CSqliteDBTool::IsEOF()
{
	return (m_index > m_rows);
}

bool CSqliteDBTool::Execute(const string& command)
{
	char* errMsg = NULL;
	int   res    = 1;
	
	res = sqlite3_exec(m_connection,"begin transaction;",0,	0,&errMsg);
	if (res != SQLITE_OK)
	{
		return false; 
	}

	res = sqlite3_exec(m_connection,command.c_str(),0,0,&errMsg);
	
	if (res != SQLITE_OK)
	{
		return false; 
	}
	
	res = sqlite3_exec(m_connection,"commit transaction;",0,0,&errMsg);
	if (res != SQLITE_OK)
	{
		return false; 
	}
	return true;
}
bool CSqliteDBTool::ExecuteAttachDatabase(const string& command)//20111223
{
	char* errMsg = NULL;
	int   res    = 1;
	res = sqlite3_exec(m_connection,command.c_str(),0,0,&errMsg);
	
	if (res != SQLITE_OK)
	{
		return false; 
	}	
	return true;
}