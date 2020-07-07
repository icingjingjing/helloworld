#include "algorithms.h"
#include <list>

RBT::RBT(int *A, int n) : root(nullptr)
{
	if(A != nullptr && n > 0)
	{
		for(int i = 0; i < n; i++)
		{
			Insert(A[i]);
		}
	}
}

RBT::~RBT()
{
	if(root != nullptr)
	{
		std::list<RBTNode<int>*> tmp;
		tmp.push_back(root);
		while(tmp.size() > 0)
		{
			RBTNode<int>* node = tmp.front();
			if(node->left != nullptr)
				tmp.push_back(node->left);
			else if(node->right != nullptr)
				tmp.push_back(node->right);

			delete node;
			tmp.pop_front();
		}
	}
}

void RBT::Insert(int value)
{
	bool bExist = false;
	//BST Insert
	RBTNode<int>* x = BSTInsert(value, bExist);
	if(bExist)
		return;

	//Set Color RED
	x->color = RED;

	while(x != root && x->color == RED)
	{
		if(x->parent->color == BLACK)
			break;

		//Case A parent is grandparent's left child
		if(x->parent == x->parent->parent->left)
		{
			RBTNode<int>* uncle = x->parent->parent->right;
			//Case 1: uncle is RED recolor
			if(uncle != nullptr && uncle->color == RED)
			{
				x->parent->color = BLACK;
				uncle->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else
			{
				//Case 2: not in one side, L rotate parent
				if(x == x->parent->right)
				{
					x->parent->parent->left = x;
					x->parent->right = x->left;
					x->left = x->parent;

					x->parent = x->parent->parent;
					x->left->parent = x;
					if(x->left->right != nullptr)
						x->left->right->parent = x->left;

					x = x->left;
				}
				//Case 3: in one side, R rotate grandparent and recolor
				RBTNode<int> *tmp = x->parent->right;
				x->parent->right = x->parent->parent;
				x->parent->right->color = RED;
				x->parent->right->left = tmp;
				x->parent->color = BLACK;

				x->parent->parent = x->parent->right->parent;
				x->parent->right->parent = x->parent;
				if(tmp != nullptr)
					tmp->parent = x->parent->right;
			
				x = x->parent;
				if(x->parent == nullptr)
				{
					root = x;
					root->color = BLACK;
				}
				else if(x->parent->right == x->right)
				{
					x->parent->right = x;
				}
				else
				{
					x->parent->left = x;
				}
			}
		}
		//Case B
		else
		{
			RBTNode<int>* uncle = x->parent->parent->left;
			//Case 1: uncle is RED recolor
			if(uncle != nullptr && uncle->color == RED)
			{
				x->parent->color = BLACK;
				uncle->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else
			{
				//Case 2: not in one side, R rotate parent
				if(x == x->parent->left)
				{
					x->parent->parent->right = x;
					x->parent->left = x->right;
					x->right = x->parent;

					x->parent = x->parent->parent;
					x->right->parent = x;
					if(x->right->left != nullptr)
						x->right->left->parent = x->right;

					x = x->right;
				}
				//Case 3: in one side, L rotate grandparent and recolor
				RBTNode<int>* tmp = x->parent->left;
				x->parent->left = x->parent->parent;
				x->parent->left->color = RED;
				x->parent->left->right = tmp;
				x->parent->color = BLACK;

				x->parent->parent = x->parent->left->parent;
				x->parent->left->parent = x->parent;
				if(tmp != nullptr)
					tmp->parent = x->parent->left;
				
				x = x->parent;
				if(x->parent == nullptr)
				{
					root = x;
					root->color = BLACK;
				}
				else if(x->parent->right == x->left)
				{
					x->parent->right = x;
				}
				else
				{
					x->parent->left = x;
				}
			}
		}
	}

	root->color = BLACK;

}

const RBTNode<int>* RBT::Find(int value)
{
	RBTNode<int>* node = root;
	while(node != nullptr && node->value != value)
	{
		if(value > node->value)
			node = node->right;
		else
			node = node->left;
	}

	return node;
}

RBTNode<int>* RBT::BSTInsert(int value, bool& out_bExist)
{
	out_bExist = true;

	if(root == nullptr)
	{
		root = new RBTNode<int>();
		root->value = value;
		out_bExist = false;
		return root;
	}
	else
	{
		RBTNode<int> *node = new RBTNode<int>();
		node->value = value;
		RBTNode<int> *cur = root;
		while(cur->value != value)
		{
			if(value < cur->value)
			{
				if(cur->left == nullptr)
				{	
					cur->left = new RBTNode<int>();
					cur->left->value = value;
					cur->left->parent = cur;
					out_bExist = false;
				}
				cur = cur->left;
			}
			else
			{
				if(cur->right == nullptr)
				{
					cur->right = new RBTNode<int>();
					cur->right->value = value;
					cur->right->parent = cur;
					out_bExist = false;
				}
				cur = cur->right;
			}
		}

		return cur;
	}
}

Sorting::Sorting()
{
}

void Sorting::InsertionSort(int *A, int n)
{
	for(int j = 1; j < n; j++)
	{
		int key = A[j];
		int i = j - 1;
		while(i >= 0 and A[i] > key)
		{
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}

void Sorting::MergeSort(int *A, int n)
{
	
}

Search::Search()
{

}

void Search::BalancedSearchTree()
{
}

void Search::RedBlackTree()
{

}
