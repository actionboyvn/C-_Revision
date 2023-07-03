#pragma once
#include <vector>
#include <atlstr.h>
#include <string>
#include <iostream>
using namespace std;
template<typename T>class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(T iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic<T>* pcNewChildNode);
	void vReleaseChild(CNodeDynamic<T>* pcChildNode);
	CNodeDynamic<T>* pcGetParentNode();
	CNodeDynamic<T>* pcGetChild(int iChildOffset);
	void vPrintVal();
	void vPrintAllBelow();
	void vPrintUp();

	CString sGetKnownType();
	//const int const_i_default_val = 0;
private:
	T i_val;
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
};

template<typename T>
inline CNodeDynamic<T>::CNodeDynamic()
{
	CString s_type = sGetKnownType();
	/*if (s_type == "INT")
		i_val = T(0);
	else if (s_type == "STRING")
		i_val = T("default");
	else*/
	i_val = T();
	pc_parent_node = nullptr;
}

template<typename T>
inline CNodeDynamic<T>::~CNodeDynamic()
{
	pc_parent_node = nullptr;
	for (int i = 0; i < v_children.size(); i++)
		delete v_children.at(i);
}

template<typename T>
inline void CNodeDynamic<T>::vSetValue(T iNewVal)
{
	i_val = iNewVal;
}

template<typename T>
inline int CNodeDynamic<T>::iGetChildrenNumber()
{
	return v_children.size();
}

template<typename T>
inline void CNodeDynamic<T>::vAddNewChild()
{
	CNodeDynamic<T>* pc_new_node = new CNodeDynamic<T>();
	pc_new_node->pc_parent_node = this;
	v_children.push_back(pc_new_node);
}

template<typename T>
inline void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* pcNewChildNode)
{
	pcNewChildNode->pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}

template<typename T>
inline void CNodeDynamic<T>::vReleaseChild(CNodeDynamic<T>* pcChildNode)
{
	for (int i = 0; i < v_children.size(); i++)
		if (v_children.at(i) == pcChildNode) {
			v_children.at(i) = nullptr;
			v_children.erase(v_children.begin() + i);
			return;
		}
}

template<typename T>
inline CNodeDynamic<T>* CNodeDynamic<T>::pcGetParentNode()
{
	return pc_parent_node;
}

template<typename T>
inline CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset >= v_children.size())
		return nullptr;
	return v_children.at(iChildOffset);
}

template<typename T>
inline void CNodeDynamic<T>::vPrintVal()
{
	cout << i_val << ' ';
}

template<typename T>
inline void CNodeDynamic<T>::vPrintAllBelow()
{
	vPrintVal();
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i)->vPrintAllBelow();
}

template<typename T>
inline void CNodeDynamic<T>::vPrintUp()
{
	vPrintVal();
	if (pc_parent_node != nullptr)
		pc_parent_node->vPrintUp();
}

template<typename T>
inline CString CNodeDynamic<T>::sGetKnownType()
{
	CString s_type = "unknown";
	return s_type;
}

template<>
inline CString CNodeDynamic<int>::sGetKnownType()
{
	CString s_type = "INT";
	return s_type;
}

template<>
inline CString CNodeDynamic<string>::sGetKnownType()
{
	CString s_type = "STRING";
	return s_type;
}
