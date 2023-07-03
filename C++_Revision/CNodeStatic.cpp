#include "CNodeStatic.h"
#include <iostream>
using namespace std;
CNodeStatic::CNodeStatic()
{
	i_val = 0;
	pc_parent_node = nullptr;
}

CNodeStatic::~CNodeStatic()
{
	pc_parent_node = nullptr;	
}

void CNodeStatic::vSetValue(int iNewVal)
{
	i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber()
{
	return v_children.size();
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic c_node_new;
	c_node_new.pc_parent_node = this;
	v_children.push_back(c_node_new);
}

void CNodeStatic::vAddNewChild(CNodeStatic* pcNewChildNode)
{
	CNodeStatic c_node_new;		
	c_node_new.i_val = pcNewChildNode->i_val;
	c_node_new.v_children = pcNewChildNode->v_children;
	c_node_new.vUpdateParentNode(this);	
	v_children.push_back(c_node_new);
}

void CNodeStatic::vRemoveChild(CNodeStatic* pcChildNode)
{
	for (int i = 0; i < v_children.size(); i++)
		if (&v_children.at(i) == pcChildNode) {
			v_children.erase(v_children.begin() + i);
			return;
		}
}

void CNodeStatic::vUpdateParentNode(CNodeStatic* pcNewParentNode)
{
	pc_parent_node = pcNewParentNode;	
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i).vUpdateParentNode(this);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset >= v_children.size())
		return nullptr;
	return &v_children.at(iChildOffset);
}

CNodeStatic* CNodeStatic::pcGetParentNode()
{
	return pc_parent_node;
}

void CNodeStatic::vPrintVal()
{
	cout << i_val << ' ';
}

void CNodeStatic::vPrintAllBelow()
{
	vPrintVal();
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i).vPrintAllBelow();
}

void CNodeStatic::vPrintUp()
{
	vPrintVal();
	if (pc_parent_node != nullptr)
		pc_parent_node->vPrintUp();
}
