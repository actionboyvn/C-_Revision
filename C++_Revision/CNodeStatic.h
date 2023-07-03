#pragma once
#include <vector>
using namespace std;
class CNodeStatic
{
public:
	CNodeStatic();
	~CNodeStatic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();	
	void vAddNewChild();
	void vAddNewChild(CNodeStatic* pcNewChildNode);
	void vRemoveChild(CNodeStatic* pcChildNode);
	void vUpdateParentNode(CNodeStatic* pcNewParentNode);
	CNodeStatic* pcGetParentNode();
	CNodeStatic* pcGetChild(int iChildOffset);
	void vPrintVal();
	void vPrintAllBelow();
	void vPrintUp();

	//const int const_i_default_val = 0;
private:
	int i_val;
	vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
};//class CNodeStatic