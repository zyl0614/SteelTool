/*
* Copyright (c) 2008, 五院航天器测试中心
* All rights reserved.
*
* 文件名称： IDBTool.h
* 文件标识：$Id: IDBTool.h 86 2008-03-31 09:09:25Z wenbowu $
* 摘 要：简要描述本文件的内容
*/

#if !defined(_IDBTOOL_H)
#define _IDBTOOL_H

#include <string>
#include "sqlite3.h"

using std::string;

/**
 * 数据库引擎基类，声明于数据库相关的元操作相关的接口
 **/
class IDBTool 
{
public:
	/**
	* 数据库引擎基类构造函数
	**/
	IDBTool()
	{

	}
	/**
	* 数据库引擎基类析构函数
	**/
	virtual ~IDBTool()
	{
		
	}

public:
	/**
	* 连接到数据库
	* @param source 数据源名称字符串
	* @param name 用户名称
	* @param password 密码
	* @returns 过程标识，0为连接成功，-1为连接失败
	**/
	virtual int ConnectDB(const string& source/*, const string& name,const string& password*/) = 0;

	/**
    * 关闭数据库连接
	* @returns 过程标识，0为关闭连接成功，-1为关闭连接失败
	**/
	virtual int CloseDB() = 0;

	/**
    * 在数据库中执行查询操作
	* @param query SQL语句
	* @returns 过程标识，0为查询成功，-1为查询失败
	**/
	virtual int QueryDataInDB(const string& query) = 0;

	/**
	* 关闭查询
	* @returns 过程标识，0为关闭查询成功，-1为关闭查询失败
	**/
    virtual int CloseQuery() = 0;
	
	/**
	* 获取字段值
	* @returns 过程标识，0为获取成功，-1为获取失败
	**/
	virtual int get_Field(const string& field, string& value) = 0;
	virtual int get_Field(const string& field, double* value) = 0;
	virtual int get_Field(const string& field, int* value) = 0;
	virtual int get_Field(const string& field, long* value) = 0;
	
	virtual int get_Field(int iIndex, string& value) = 0;
	virtual int get_Field(int iIndex, long* value) = 0;
	virtual int get_DateTime(int iIndex,string* value) = 0;
	/**
	* 设置字段值
	* @returns 过程标识，0为设置成功，-1为设置失败
	**/
	virtual int put_Field(const string& field, string value) = 0;
	virtual int put_Field(const string& field, double value) = 0;
	virtual int put_Field(const string& field, int value) = 0;
	
	/**
	* 判读是否已经到记录集尾
	* @returns 记录集结尾标识，true为已经到记录集结尾，反之为false
	**/
	virtual bool IsEOF() = 0;
	
	/**
	* 移动记录集游标至下一条记录
	* @returns 过程标识，0为游标移动成功，-1为游标移动失败
	**/
	virtual int MoveNext() = 0;

	/**
	* 添加一条新记录
	* @returns 过程标识，0为添加成功，-1为添加失败
	**/
	virtual int AddNew() = 0;
	
	/**
	* 
	**/
	virtual int Update() = 0;
	
	/**
	* 执行一条SQL语句
	* @returns 过程标识，true为执行成功，false为执行失败
	**/
	virtual bool Execute(const string& command) = 0;

	virtual bool ExecuteAttachDatabase(const string& command){return false;}//20111223
	bool m_bIsQueryOpen;
/*	//20120301
private:
	int m_iDatabaseType;//0:表示oracle//1:表示sqllite
public:
	int GetCurrentDatabaseType()
	{
		return m_iDatabaseType;
	}
	void SetCurrentDatabaseType(int iDatabaseType)
	{
		m_iDatabaseType = iDatabaseType;
	}
	//20120301*/
	
};

#endif  //_IDBTOOL_H
