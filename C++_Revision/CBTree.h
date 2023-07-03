#pragma once

struct SNode {
public:
	SNode() {
		i_data = 0;
		ps_left = nullptr;
		ps_right = nullptr;
	}
	~SNode() {
		delete ps_left;
		delete ps_right;
	}
	void vAddLeft() {
		if (ps_left == nullptr)
			ps_left = new SNode;
	}
	void vAddRight() {
		if (ps_right == nullptr)
			ps_right = new SNode;
	}
	int iGetData() {
		return i_data;
	}
	SNode* psGetLeft() {
		return ps_left;
	}
	SNode* psGetRight() {
		return ps_right;
	}
private:
	int i_data;
	SNode* ps_left;
	SNode* ps_right;
}; //struct SNode

class CBtree {
public:
	CBtree();
	~CBtree();
	SNode* psGetRoot();
	void vPrintTree(SNode* psParentNode);
	int iGetTreeHeight(SNode* psParentNode);
private:
	SNode* ps_root;
}; // class CBtree

inline CBtree::CBtree() {
	ps_root = new SNode;	
}
inline CBtree::~CBtree() {
	delete ps_root;
}

inline SNode* CBtree::psGetRoot()
{
	return ps_root;
}

inline void CBtree::vPrintTree(SNode* psParentNode)
{
	if (psParentNode == nullptr)
		return;
	cout << psParentNode->iGetData() << ' ';
	vPrintTree(psParentNode->psGetLeft());
	vPrintTree(psParentNode->psGetRight());
}

inline int CBtree::iGetTreeHeight(SNode* psParentNode)
{
	if (psParentNode->psGetLeft() == nullptr &&
		psParentNode->psGetRight() == nullptr)
		return 0;
	int i_left_subtree_height = 0;
	int i_right_subtree_height = 0;
	if (psParentNode->psGetLeft() != nullptr)
		i_left_subtree_height = iGetTreeHeight(psParentNode->psGetLeft());
	if (psParentNode->psGetRight() != nullptr)
		i_right_subtree_height = iGetTreeHeight(psParentNode->psGetRight());
	return max(i_left_subtree_height, i_right_subtree_height) + 1;
}
