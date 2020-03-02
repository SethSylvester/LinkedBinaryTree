#include "TreeNode.h"
#include "BinaryTree.h"
#include "raylib.h"

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void BinaryTree::insert(int a_nValue)
{
	if (isEmpty())
	{
		TreeNode * newNode = new TreeNode(0);
		m_pRoot = newNode;
		m_pRoot->setData(a_nValue);
	}
	bool inserting = true;
	//Create a pointer.
	TreeNode* node;
	node = m_pRoot;

	while (inserting)
	{
		//if less go left
		if (node->getData() > a_nValue)
		{
			//check if null
			if (node->getLeft() != nullptr)
			{
				node = node->getLeft();
			}
			//otherwise become.
			else
			{
				TreeNode* newNode = new TreeNode(a_nValue);
				node->setLeft(newNode);
				inserting = false;
			}
		}
		//if more go right
		else if (node->getData() <= a_nValue)
		{
			//check if null
			if (node->getRight() != nullptr)
			{
				node = node->getRight();
			}
			//otherwise become.
			else
			{
				TreeNode* newNode = new TreeNode(a_nValue);
				node->setRight(newNode);
				inserting = false;
			}
		}
	}
}

void BinaryTree::remove(int a_nValue)
{
	TreeNode * node = find(a_nValue);
	if (node->hasLeft() && node->hasRight())
	{
		//Swap with equal value to the right
		TreeNode * tempNode = node->getRight();

		bool searching = true;
		while (searching)
		{
			if (tempNode->getLeft() != nullptr)
			{
				tempNode = tempNode->getLeft();
			}
			else if (tempNode->getLeft() == nullptr)
			{
				node->setData(tempNode->getData());
				tempNode = nullptr;
				delete tempNode;
			}
		}
	}
	else if (node->hasLeft() || node->hasRight())
	{
		//replace parent pointer and delete
		if (node->hasLeft())
		{

		}
		if (node->hasRight())
		{

		}

		//delete node
		node = nullptr;
		delete node;
	}

	//Delete the node and ptr.
	else {
		node = nullptr;
		delete node;
	}
}

TreeNode * BinaryTree::find(int a_nValue)
{
	bool found = false;

	if (m_pRoot->getData() == a_nValue)
	{
		found = true;
		return m_pRoot;
	}

	//Create a pointer.
	TreeNode* node;
	node = m_pRoot;
	while (!found) {
		//if its the thing
		if (node->getData() == a_nValue)
		{
			found = true;
			return node;
		}
		//if its greater go right
		else if (node->getData() > a_nValue)
		{
			node = node->getRight();
		}
		//elsewise go left
		else
		{
			node = node->getLeft();
		}

		//no infinite loops allowed
		if (node->getLeft() == nullptr && node->getRight() == nullptr)
		{
			return nullptr;
		}
	}
	return nullptr;
}

void BinaryTree::draw(TreeNode * selected)
{
	draw(m_pRoot, 240, 80, 140, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	return false;
}

void BinaryTree::draw(TreeNode * pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	horizontalSpacing /= 2;

	if (pNode) {
		if (pNode->hasLeft()) {
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			draw(pNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
	
		if (pNode->hasRight()) {
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			draw(pNode->getLeft(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		pNode->draw(x, y, (selected == pNode));
	}
}