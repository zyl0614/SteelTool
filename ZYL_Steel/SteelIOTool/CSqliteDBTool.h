/*
* Copyright (c) 2008, 五院航天器测试中心
* All rights reserved.
*
* 文件名称： CSqliteDBTool.h
* 文件标识：$Id: CSqliteDBTool.h 161 2008-04-14 08:11:49Z wenbowu $
* 摘 要：简要描述本文件的内容
*/

#if !defined(_CSQLITEDBTOOL_H)
#define _CSQLITEDBTOOL_H

#include "IDBTool.h"

#pragma warning ( disable : 4786 )

#include <map>
using namespace std;

/**
 * SQLITE数据库引擎类，声明于数据库相关的元操作相关的接口
 **/
class CSqliteDBTool : public IDBTool  
{
public:
	CSqliteDBTool();
	~CSqliteDBTool();

public:
	/**
	* 连接到数据库
	* @param source 数据源名称字符串
	* @param name 用户名称
	* @param password 密码
	* @returns 过程标识，0为连接成功，-1为连接失败
	**/
	int ConnectDB(const string& source/*, 
		const string& name, 
		const string& password*/);

	/**
    * 关闭数据库连接
	* @returns 过程标识，0为关闭连接成功，-1为关闭连接失败
	**/
	int CloseDB();

	/**
    * 在数据库中执行查询操作
	* @param query SQL语句
	* @returns 过程标识，0为查询成功，-1为查询失败
	**/
	int QueryDataInDB(const string& query);

	/**
	* 关闭查询
	* @returns 过程标识，0为关闭查询成功，-1为关闭查询失败
	**/
    int CloseQuery();
	
	/**
	* 获取字段值
	* @returns 过程标识，0为获取成功，-1为获取失败
	**/
	int get_Field(const string& field, string& value);
	int get_Field(const string& field, double* value);
	int get_Field(const string& field, int* value);
	int get_Field(const string& field, long* value);
	
	int get_Field(int iIndex, string& value);
	int get_Field(int iIndex, long* value);
	virtual int get_DateTime(int iIndex,string* value);

	/**
	* 设置字段值
	* @returns 过程标识，0为设置成功，-1为设置失败
	**/
	int put_Field(const string& field, string value);
	int put_Field(const string& field, double value);
	int put_Field(const string& field, int value);
	
	/**
	* 判读是否已经到记录集尾
	* @returns 记录集结尾标识，true为已经到记录集结尾，反之为false
	**/
	bool IsEOF();
	
	/**
	* 移动记录集游标至下一条记录
	* @returns 过程标识，0为游标成功，-1为游标移动失败
	**/
	int MoveNext();

	/**
	* 添加一条新记录
	* @returns 过程标识，0为添加成功，-1为添加失败
	**/
	int AddNew();
	
	/**
	* 
	**/
	int Update();
	
	/**
	* 执行一条SQL语句
	* @returns 过程标识，true为执行成功，false为执行失败
	**/
	bool Execute(const string& command);
	bool ExecuteAttachDatabase(const string& command);//20111223
private:
	sqlite3* m_connection;
	sqlite3_stmt* m_stmtPtr;
	char** m_recordset;
	
	int    m_rows;
	int    m_cols;
	int    m_index;

	map<string, int> m_fieldMap;
};


//extern CSqliteDBTool g_SqlDB;


#endif  //_CSQLITEDBTOOL_H
