#ifndef algorithms_h
#define algorithms_h

enum ERBTNodeColor
{
	BLACK,
	RED
};

template<typename T>
struct RBTNode
{
	T value;
	ERBTNodeColor color;
	RBTNode* right;
	RBTNode* left;
	RBTNode* parent;

	RBTNode():value()
	 	, color(BLACK)
		, right(nullptr)
		, left(nullptr)
		, parent(nullptr)
	{
	};
};

class RBT
{
	public:
		RBT(int * A, int n);
		~RBT();

		void Insert(int value);
		const RBTNode<int>* Find(int value);
	protected:
		RBTNode<int>* BSTInsert(int value, bool& out_bExist);

		RBTNode<int>* root;
};

class Sorting
{
public:
	Sorting();
	//插入排序算法 时间复杂度n的2次方
	void InsertionSort(int * A, int n);
	//归并排序算法 时间复杂度nlogn
	void MergeSort(int * A, int n);
};

class Search
{
	public:
		Search();
		//平衡搜索树 时间复杂度logn
		void BalancedSearchTree();
		//红黑树，平衡二叉树的一种 时间复杂度logn
		void RedBlackTree();
};
#endif
