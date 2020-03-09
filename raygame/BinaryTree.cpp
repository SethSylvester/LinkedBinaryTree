#include "BinaryTree.h"
#include "raylib.h"

BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}


BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* insertNode = new TreeNode(a_nValue);

	//If the tree is empty
	if (isEmpty())
	{

		m_pRoot = new TreeNode();

		//The value is inserted at the root
		m_pRoot->SetData(a_nValue);
	}
	else
	{
		TreeNode* currentNode = m_pRoot;
		TreeNode* parentNode = currentNode;

		//While the current node is !null
		while (currentNode != nullptr)
		{
			//If the value to be inserted is less than the value in the current node
			if (a_nValue < currentNode->getData())
			{
				//Set the current node to the left
				parentNode = currentNode;
				currentNode = currentNode->getLeft();
			}
			//If the value to be inserted is greater than the value in the current node
			else if (a_nValue > currentNode->getData())
			{
				//Set the current node to the right
				parentNode = currentNode;
				currentNode = currentNode->getRight();
			}
			//If the value to be inserted is equel the value in the current node
			else if (a_nValue == currentNode->getData())
			{
				//Set the current node to null
				currentNode = nullptr;
			}
		}

		//If the value to be inserted is less than parent
		if (a_nValue < parentNode->getData())
		{
			//Insert value as left child node
			parentNode->SetLeft(insertNode);
		}
		else if (a_nValue > parentNode->getData())
		{
			//Insert value as right child
			parentNode->SetRight(insertNode);
		}
	}
}

void BinaryTree::remove(int a_nValue)
{
	//Find the value in the tree, obtaining a pointer to the node and its parent
		//Return if node is not found
	//If the current node has a right branch
		/*Find the minimum value in the right branch by iterating
			down the left branch of the current node's right child
			until there are no more left branch nodes and keep track
			of the minimum node's parent*/
			//Copy the value from this minimum node to the current node
			//If we are deleting the parent's left node
				//Set the left child of the parent to the right child of the minimum node
			//If we are deleting the parent's right node
				//Set the right child of the parent to the right child of the minimum node
		//If the current no has no right branch
			//If we are deleting the parent's left child
				//Set the left child of the parent to the left child of the current node
			//If we are deleting the parent's right child
				//Set the right child of the parent to the left child of the current node
			//If we are deleting the root
				//The root becomes the left child of the current node


		//Create Pointers
	TreeNode* currentNode;
	TreeNode* parentNode;

	if (findNode(a_nValue, &currentNode, &parentNode) == true)
	{
		//Check if current node has a right branch
		if (currentNode->hasRight())
		{
			TreeNode* iteratorNode = currentNode->getRight();
			TreeNode* iteratorParent = currentNode;

			//Checks if the iterator's left isn't null
			while (iteratorNode->getLeft() != nullptr)
			{
				iteratorParent = iteratorNode;
				iteratorNode = iteratorNode->getLeft();
			}


			//Copies the iterator's data to the current node
			currentNode->SetData(iteratorNode->getData());

			//If we delete the parent's left node
			if (iteratorNode == iteratorParent->getLeft())
			{
				//Set the left child of the parent to the right of the iteratorNode
				if (iteratorNode->hasRight())
				{
					iteratorParent->SetRight(iteratorNode->getRight());
					delete iteratorNode;
				}
				else
				{
					delete iteratorNode;
					iteratorParent->SetLeft(nullptr);
				}
			}
			//If we delete the parent's right node
			else if (iteratorNode == iteratorParent->getRight())
			{
				//Set the right child of the parent to the right of the iteratorNode
				if (iteratorNode->hasRight())
				{
					iteratorParent->SetRight(iteratorNode->getRight());
					delete iteratorNode;
				}
				else
				{
					delete iteratorNode;
					iteratorParent->SetRight(nullptr);
				}
			}
		}

		//If the current node does not have a right branch
		else
		{
			//If we are deleting the parentNode's right
			if (currentNode == parentNode->getLeft())
			{
				//Set the left child of the parent to the left child of the current node
				if (currentNode->hasLeft())
				{
					parentNode->SetLeft(currentNode->getLeft());
					delete currentNode;
				}
				else
				{
					delete currentNode;
					parentNode->SetLeft(nullptr);
				}
			}
			//If we are deleting the parentNode's left
			else if (currentNode == parentNode->getRight())
			{
				//Set the right child of the parent to the left child of the current node
				if (currentNode->hasLeft())
				{
					parentNode->SetRight(currentNode->getLeft());
					delete currentNode;
				}
				else
				{
					delete currentNode;
					parentNode->SetRight(nullptr);
				}
			}
			//If we are deleting the root
			else if (currentNode == m_pRoot)
			{
				//The roor becomes the left child of the current node
				m_pRoot = currentNode->getLeft();
				m_pRoot->SetLeft(currentNode->getLeft()->getLeft());
				delete currentNode->getLeft();
			}
		}
	}
}

TreeNode * BinaryTree::find(int a_nValue)
{
	//Create Pointers
	TreeNode* currentNode = nullptr;
	TreeNode* parentNode = currentNode;

	findNode(a_nValue, &currentNode, &parentNode);

	return currentNode;
}

void BinaryTree::draw(TreeNode * selected)
{
	//Draw the root node
	drawNode(m_pRoot, 340, 80, 160, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	//Create Pointers
	TreeNode* currentNode = m_pRoot;
	TreeNode* parentNode = currentNode;

	//WHile the current node is not null
	while (currentNode != nullptr)
	{
		//If the search value = the current node
		if (a_nSearchValue == currentNode->getData())
		{
			//Set the current and parent node
			*ppOutNode = currentNode;
			*ppOutParent = parentNode;
			return true;
		}
		//If the search value is < the current value
		else if (a_nSearchValue < currentNode->getData())
		{
			//Set the parent node to current node
			parentNode = currentNode;
			//Set the current node to the left
			currentNode = currentNode->getLeft();
		}
		//If the search value os > the current value
		else
		{
			//Set the parent node to current node
			parentNode = currentNode;
			//Set the current node to the left
			currentNode = currentNode->getRight();
		}
	}
	//If the loop exits, a match was not found so return false
	return false;
}

void BinaryTree::drawNode(TreeNode * pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	//Cut the horizonta; spacing in half
	horizontalSpacing /= 2;

	//Check that the current node exists
	if (pNode)
	{
		//Check for a left Node
		if (pNode->hasLeft())
		{
			//Draw a line to the left node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			//Draw the left node
			drawNode(pNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Check for a right node
		if (pNode->hasRight())
		{
			//Draw a line to the right node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			//Draw the right node
			drawNode(pNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//
		pNode->draw(x, y, (selected == pNode));
	}
}
