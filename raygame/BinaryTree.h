#include "TreeNode.h"
#pragma once
class BinaryTree {
public:
	BinaryTree() {}
	~BinaryTree() {}
	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);
	TreeNode* find(int a_nValue);
	void draw(TreeNode* selected = nullptr);

private:
	//Find the node with the specified value.
	bool findNode(int a_nSearchValue, TreeNode** ppOutNode,
		TreeNode** ppOutParent);
	void draw(TreeNode*, int x, int y,
		int horizontalSpacing, TreeNode* selected = nullptr);
	//The root node of the tree
	TreeNode* m_pRoot;
	TreeNode * parentNode;
};