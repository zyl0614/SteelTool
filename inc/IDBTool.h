/*
* Copyright (c) 2008, ��Ժ��������������
* All rights reserved.
*
* �ļ����ƣ� IDBTool.h
* �ļ���ʶ��$Id: IDBTool.h 86 2008-03-31 09:09:25Z wenbowu $
* ժ Ҫ����Ҫ�������ļ�������
*/

#if !defined(_IDBTOOL_H)
#define _IDBTOOL_H

#include <string>
#include "sqlite3.h"

using std::string;

/**
 * ���ݿ�������࣬���������ݿ���ص�Ԫ������صĽӿ�
 **/
class IDBTool 
{
public:
	/**
	* ���ݿ�������๹�캯��
	**/
	IDBTool()
	{

	}
	/**
	* ���ݿ����������������
	**/
	virtual ~IDBTool()
	{
		
	}

public:
	/**
	* ���ӵ����ݿ�
	* @param source ����Դ�����ַ���
	* @param name �û�����
	* @param password ����
	* @returns ���̱�ʶ��0Ϊ���ӳɹ���-1Ϊ����ʧ��
	**/
	virtual int ConnectDB(const string& source/*, const string& name,const string& password*/) = 0;

	/**
    * �ر����ݿ�����
	* @returns ���̱�ʶ��0Ϊ�ر����ӳɹ���-1Ϊ�ر�����ʧ��
	**/
	virtual int CloseDB() = 0;

	/**
    * �����ݿ���ִ�в�ѯ����
	* @param query SQL���
	* @returns ���̱�ʶ��0Ϊ��ѯ�ɹ���-1Ϊ��ѯʧ��
	**/
	virtual int QueryDataInDB(const string& query) = 0;

	/**
	* �رղ�ѯ
	* @returns ���̱�ʶ��0Ϊ�رղ�ѯ�ɹ���-1Ϊ�رղ�ѯʧ��
	**/
    virtual int CloseQuery() = 0;
	
	/**
	* ��ȡ�ֶ�ֵ
	* @returns ���̱�ʶ��0Ϊ��ȡ�ɹ���-1Ϊ��ȡʧ��
	**/
	virtual int get_Field(const string& field, string& value) = 0;
	virtual int get_Field(const string& field, double* value) = 0;
	virtual int get_Field(const string& field, int* value) = 0;
	virtual int get_Field(const string& field, long* value) = 0;
	
	virtual int get_Field(int iIndex, string& value) = 0;
	virtual int get_Field(int iIndex, long* value) = 0;
	virtual int get_DateTime(int iIndex,string* value) = 0;
	/**
	* �����ֶ�ֵ
	* @returns ���̱�ʶ��0Ϊ���óɹ���-1Ϊ����ʧ��
	**/
	virtual int put_Field(const string& field, string value) = 0;
	virtual int put_Field(const string& field, double value) = 0;
	virtual int put_Field(const string& field, int value) = 0;
	
	/**
	* �ж��Ƿ��Ѿ�����¼��β
	* @returns ��¼����β��ʶ��trueΪ�Ѿ�����¼����β����֮Ϊfalse
	**/
	virtual bool IsEOF() = 0;
	
	/**
	* �ƶ���¼���α�����һ����¼
	* @returns ���̱�ʶ��0Ϊ�α��ƶ��ɹ���-1Ϊ�α��ƶ�ʧ��
	**/
	virtual int MoveNext() = 0;

	/**
	* ���һ���¼�¼
	* @returns ���̱�ʶ��0Ϊ��ӳɹ���-1Ϊ���ʧ��
	**/
	virtual int AddNew() = 0;
	
	/**
	* 
	**/
	virtual int Update() = 0;
	
	/**
	* ִ��һ��SQL���
	* @returns ���̱�ʶ��trueΪִ�гɹ���falseΪִ��ʧ��
	**/
	virtual bool Execute(const string& command) = 0;

	virtual bool ExecuteAttachDatabase(const string& command){return false;}//20111223
	bool m_bIsQueryOpen;
/*	//20120301
private:
	int m_iDatabaseType;//0:��ʾoracle//1:��ʾsqllite
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
