#include "CTable.h"
#include <iostream>

CTable::CTable()
{
	s_name = const_s_name;
	cout << "parameterless: " << s_name << endl;
	i_table_len = const_i_table_len;
	pi_table = new int[const_i_table_len];
}

CTable::CTable(string sName, int iTableLen)
{
	s_name = sName;
	cout << "parameter: " << s_name << endl;
	i_table_len = iTableLen;
	pi_table = new int[i_table_len];
}

CTable::CTable(const CTable& cOther)
{
	s_name = cOther.s_name + "_copy";
	cout << "copy: " << s_name << endl;
	vCopy(cOther);
}

CTable::CTable(CTable&& cOther)
{
	vMove(cOther);
}

CTable::~CTable()
{
	cout << "delete: " << s_name << endl;
	delete[] pi_table;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}

string CTable::sGetName()
{
	return s_name;
}

bool CTable::bSetNewSize(int iTableLen)
{
	if (iTableLen < 0)
		return false;
	int i_new_table_len = iTableLen;
	int* pi_new_table = new int[i_new_table_len];
	for (int i = 0; i < min(i_new_table_len, i_table_len); i++)
		pi_new_table[i] = pi_table[i];
	delete[] pi_table;
	i_table_len = i_new_table_len;
	pi_table = pi_new_table;
	return true;
}

int CTable::iGetSize()
{
	return i_table_len;
}

void CTable::vSetValueAt(int iOffSet, int iVal)
{
	if (iOffSet < 0 || iOffSet >= i_table_len)
		return;
	pi_table[iOffSet] = iVal;
}

CTable* CTable::pcClone()
{
	CTable* pc_new_clone = new CTable(*this);
	return pc_new_clone;
}

void CTable::vPrint()
{
	for (int i = 0; i < i_table_len; i++)
		cout << pi_table[i] << ' ';
	cout << endl;
}

void CTable::operator=(const CTable& cNewTable)
{
	s_name = cNewTable.s_name;
	vCopy(cNewTable);
}

void CTable::operator=(CTable&& cNewTable)
{
	vMove(cNewTable);
}

CTable CTable::operator+(const CTable& cAddTable)
{
	CTable c_tab_add(s_name + "+" + cAddTable.s_name, i_table_len + cAddTable.i_table_len);
	for (int i = 0; i < c_tab_add.i_table_len; i++)
		if (i < i_table_len)
			c_tab_add.pi_table[i] = pi_table[i];
		else
			c_tab_add.pi_table[i] = cAddTable.pi_table[i - i_table_len];
	return c_tab_add;
}

void CTable::vCopy(const CTable& cOther)
{
	i_table_len = cOther.i_table_len;
	delete pi_table;
	pi_table = new int[i_table_len];
	for (int i = 0; i < i_table_len; i++)
		pi_table[i] = cOther.pi_table[i];
	cout << "COPY" << endl;
}

void CTable::vMove(CTable& cOther)
{
	delete pi_table;
	s_name = cOther.s_name;
	i_table_len = cOther.i_table_len;
	pi_table = cOther.pi_table;
	cOther.pi_table = nullptr;
	cout << "MOVE" << endl;
}
