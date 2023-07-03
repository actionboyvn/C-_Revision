#include "CTreeStatic.h"
#include <iostream>

CTreeStatic::CTreeStatic()
{
}

CTreeStatic::~CTreeStatic()
{
}

CNodeStatic* CTreeStatic::pcGetRoot()
{
	return &c_root;
}

void CTreeStatic::vPrintTree()
{
	c_root.vPrintAllBelow();
}

int CTreeStatic::iGetTreeHeight(CNodeStatic* pc_root)
{
	int i_height_max = 0;
	if (pc_root != nullptr) {
		int i_children_num = pc_root->iGetChildrenNumber();
		for (int i = 0; i < i_children_num; i++)
			i_height_max = max(i_height_max, iGetTreeHeight(pc_root->pcGetChild(i)));
		if (i_children_num > 0)
			i_height_max++;
	}
	return i_height_max;
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode)
{
	if (pcParentNode == nullptr || pcNewChildNode == nullptr)
		return false;	
	CNodeStatic* pc_parent_node_current = pcNewChildNode->pcGetParentNode();
	pcParentNode->vAddNewChild(pcNewChildNode);
	if (pc_parent_node_current != nullptr)
		pc_parent_node_current->vRemoveChild(pcNewChildNode);	
	return true;
}
