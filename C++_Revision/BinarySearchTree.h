#pragma once

struct Node {
	int data;
	Node* left;
	Node* right;
	Node() {
		data = 0;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree {
public:
	BinarySearchTree();
	~BinarySearchTree();
	Node* getRoot();
	void deleteSubtree(Node* parent);
	void insert(int new_data);
	bool remove(int data);
	Node* search(int data);
	int getTreeHeight(Node* parent);
	void preOrder(Node* parent);
private:
	Node* root;
};

inline BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

inline BinarySearchTree::~BinarySearchTree()
{
	deleteSubtree(root);	
}
inline Node* BinarySearchTree::getRoot()
{
	return root;
}
inline void BinarySearchTree::deleteSubtree(Node* parent)
{
	if (parent->left != nullptr)
		deleteSubtree(parent->left);
	if (parent->right != nullptr)
		deleteSubtree(parent->right);
	delete parent;
}
inline void BinarySearchTree::insert(int new_data)
{
	Node* new_node = new Node;
	new_node->data = new_data;
	if (root == nullptr) {
		root = new_node;
		return;
	}
	Node* current_node = root;
	while (true) {
		if (new_data < current_node->data) {
			if (current_node->left == nullptr) {
				current_node->left = new_node;
				break;
			}
			current_node = current_node->left;
		}
		else {
			if (current_node->right == nullptr) {
				current_node->right = new_node;
				break;
			}
			current_node = current_node->right;
		}		
	}
}

inline bool BinarySearchTree::remove(int data)
{
	if (root == nullptr)
		return false;
	Node* current_node = root;
	Node* current_node_parent = nullptr;
	while (current_node != nullptr) {
		if (data == current_node->data) {
			break;
		}
		current_node_parent = current_node;
		if (data < current_node->data) 
			current_node = current_node->left;		
		else
			current_node = current_node->right;
	}
	if (current_node == nullptr)
		return false;
	Node* successor = current_node->right;
	Node* successor_parent = current_node;
	if (successor != nullptr)
	while (successor->left != nullptr) {
		successor_parent = successor;
		successor = successor->left;
	}	
	if (successor == nullptr) {
		if (current_node == root) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			if (current_node_parent->left == current_node)
				current_node_parent->left = current_node->left;
			else
				current_node_parent->right = current_node->left;
			delete current_node;
		}
	}
	else {
		current_node->data = successor->data;
		if (successor_parent->left == successor)
			successor_parent->left = nullptr;
		else
			successor_parent->right = nullptr;
		delete successor;
	}
	return true;
}

inline Node* BinarySearchTree::search(int data)
{
	Node* current_node = root;
	while (current_node != nullptr) {
		if (current_node->data == data)
			return current_node;
		if (data < current_node->data)
			current_node = current_node->left;
		else
			current_node = current_node->right;
	}
	return current_node;
}

inline int BinarySearchTree::getTreeHeight(Node* parent)
{
	if (parent->left == nullptr && parent->right == nullptr)
		return 0;
	int left_subtree_height = 0;
	int right_subtree_height = 0;
	if (parent->left != nullptr)
		left_subtree_height = getTreeHeight(parent->left);
	if (parent->right != nullptr)
		right_subtree_height = getTreeHeight(parent->right);
	return max(left_subtree_height, right_subtree_height) + 1;
}

inline void BinarySearchTree::preOrder(Node* parent)
{
	if (parent == nullptr)
		return;
	cout << parent->data << ' ';
	preOrder(parent->left);
	preOrder(parent->right);
}
