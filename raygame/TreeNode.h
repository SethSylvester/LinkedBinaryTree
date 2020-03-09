#pragma once

class TreeNode
{
public:
	TreeNode() {}
	TreeNode(int value) { m_value = value; }
	~TreeNode() {}

	bool hasLeft() { return (m_left != nullptr); }
	bool hasRight() { return (m_right != nullptr); }

	//Get private varibles
	int getData() { return m_value; }
	TreeNode* getLeft() { return m_left; }
	TreeNode* getRight() { return m_right; }

	//Set the private variables
	void SetData(int value) { m_value = value; }
	void SetLeft(TreeNode* node) { m_left = node; }
	void SetRight(TreeNode* node) { m_right = node; }

	void draw(int x, int y, bool selected = false);

private:
	int m_value;

	TreeNode* m_left;
	TreeNode* m_right;
};
