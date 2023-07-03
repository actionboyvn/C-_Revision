#pragma once
#include "CNodeDynamic.h"
template<typename T>
class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T>* pcGetRoot();
	void vPrintTree();
	//int iGetTreeHeight(CNodeDynamic* pc_root);
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
private:
	CNodeDynamic<T>* c_root;
};

template<typename T>
inline CTreeDynamic<T>::CTreeDynamic()
{
	c_root = new CNodeDynamic<T>();
}

template<typename T>
inline CTreeDynamic<T>::~CTreeDynamic()
{
	delete c_root;
}

template<typename T>
inline CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot()
{
	return c_root;
}

template<typename T>
inline void CTreeDynamic<T>::vPrintTree()
{
	if (c_root != nullptr)
		c_root->vPrintAllBelow();
}

template<typename T>
inline bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode)
{
	if (pcParentNode == nullptr || pcNewChildNode == nullptr)
		return false;
	CNodeDynamic<T>* pc_parent_node_current = pcNewChildNode->pcGetParentNode();
	if (pc_parent_node_current != nullptr)
		pc_parent_node_current->vReleaseChild(pcNewChildNode);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}
