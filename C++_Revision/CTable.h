#pragma once
#include <string>
using namespace std;
class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable& cOther);
	CTable(CTable&& cOther);
	~CTable();
	CTable* pcClone();
	void vSetName(string sName);
	string sGetName();
	bool bSetNewSize(int iTableLen);
	int iGetSize();
	void vSetValueAt(int iOffSet, int iVal);
	void vPrint();
	void operator=(const CTable& cNewTable);
	void operator=(CTable&& cNewTable);
	CTable operator+(const CTable& cAddTable);
	
	const string const_s_name = "DEFAULT";
	const int const_i_table_len = 0;
private:	
	string s_name;
	int i_table_len;
	int* pi_table;	
	void vCopy(const CTable& cOther);
	void vMove(CTable& cOther);
};

