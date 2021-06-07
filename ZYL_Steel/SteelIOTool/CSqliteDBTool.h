/*
* Copyright (c) 2008, ��Ժ��������������
* All rights reserved.
*
* �ļ����ƣ� CSqliteDBTool.h
* �ļ���ʶ��$Id: CSqliteDBTool.h 161 2008-04-14 08:11:49Z wenbowu $
* ժ Ҫ����Ҫ�������ļ�������
*/

#if !defined(_CSQLITEDBTOOL_H)
#define _CSQLITEDBTOOL_H

#include "IDBTool.h"

#pragma warning ( disable : 4786 )

#include <map>
using namespace std;

/**
 * SQLITE���ݿ������࣬���������ݿ���ص�Ԫ������صĽӿ�
 **/
class CSqliteDBTool : public IDBTool  
{
public:
	CSqliteDBTool();
	~CSqliteDBTool();

public:
	/**
	* ���ӵ����ݿ�
	* @param source ����Դ�����ַ���
	* @param name �û�����
	* @param password ����
	* @returns ���̱�ʶ��0Ϊ���ӳɹ���-1Ϊ����ʧ��
	**/
	int ConnectDB(const string& source/*, 
		const string& name, 
		const string& password*/);

	/**
    * �ر����ݿ�����
	* @returns ���̱�ʶ��0Ϊ�ر����ӳɹ���-1Ϊ�ر�����ʧ��
	**/
	int CloseDB();

	/**
    * �����ݿ���ִ�в�ѯ����
	* @param query SQL���
	* @returns ���̱�ʶ��0Ϊ��ѯ�ɹ���-1Ϊ��ѯʧ��
	**/
	int QueryDataInDB(const string& query);

	/**
	* �رղ�ѯ
	* @returns ���̱�ʶ��0Ϊ�رղ�ѯ�ɹ���-1Ϊ�رղ�ѯʧ��
	**/
    int CloseQuery();
	
	/**
	* ��ȡ�ֶ�ֵ
	* @returns ���̱�ʶ��0Ϊ��ȡ�ɹ���-1Ϊ��ȡʧ��
	**/
	int get_Field(const string& field, string& value);
	int get_Field(const string& field, double* value);
	int get_Field(const string& field, int* value);
	int get_Field(const string& field, long* value);
	
	int get_Field(int iIndex, string& value);
	int get_Field(int iIndex, long* value);
	virtual int get_DateTime(int iIndex,string* value);

	/**
	* �����ֶ�ֵ
	* @returns ���̱�ʶ��0Ϊ���óɹ���-1Ϊ����ʧ��
	**/
	int put_Field(const string& field, string value);
	int put_Field(const string& field, double value);
	int put_Field(const string& field, int value);
	
	/**
	* �ж��Ƿ��Ѿ�����¼��β
	* @returns ��¼����β��ʶ��trueΪ�Ѿ�����¼����β����֮Ϊfalse
	**/
	bool IsEOF();
	
	/**
	* �ƶ���¼���α�����һ����¼
	* @returns ���̱�ʶ��0Ϊ�α�ɹ���-1Ϊ�α��ƶ�ʧ��
	**/
	int MoveNext();

	/**
	* ���һ���¼�¼
	* @returns ���̱�ʶ��0Ϊ��ӳɹ���-1Ϊ���ʧ��
	**/
	int AddNew();
	
	/**
	* 
	**/
	int Update();
	
	/**
	* ִ��һ��SQL���
	* @returns ���̱�ʶ��trueΪִ�гɹ���falseΪִ��ʧ��
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
