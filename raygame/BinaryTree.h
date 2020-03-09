#pragma once
#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);

	TreeNode* find(int a_nValue);

	void draw(TreeNode* selected = nullptr);

private:
	bool findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);

	void drawNode(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	//Root node of the tree
	TreeNode* m_pRoot;
	TreeNode* parentNode;
};
