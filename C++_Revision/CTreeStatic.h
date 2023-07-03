#pragma once
#include <vector>
#include "CNodeStatic.h"
using namespace std;
class CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot();
	void vPrintTree();
	int iGetTreeHeight(CNodeStatic* pc_root);	
	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
private:
	CNodeStatic c_root;
};//class CTreeStatic



