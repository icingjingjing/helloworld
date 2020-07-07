#include  <stdio.h>
#include "hello.h"
#include "algorithms.h"

//#define TEST_SORTING
//#define TEST_ADD
#define TEST_RBT

void testSorting()
{
	printf("test Soring\n");
	Sorting sort;
	int A[] = {9, 8, 1, 3, 5, 7, 6, 2, 4, 0};
	const int nSize = sizeof(A)/sizeof(int); 
	sort.InsertionSort(A, nSize);
	for(int i = 0; i < nSize; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void testAdd()
{
	int a, b;
	printf("test add intput a");
	scanf("%d", &a);
	printf("intput b");
	scanf("%d", &b);
	add(a, b);
}

void testRBT()
{
	int A[] = {9, 8, 1, 3, 5, 7, 6, 2, 4, 0};
	RBT tree(A, sizeof(A)/sizeof(int));
	
	char cmd[16]={0};
	int value = -1;
	while(cmd[0] != 'q')
	{
		scanf("%s %d", cmd, &value);
		if(cmd[0] == 'i')
		{
			tree.Insert(value);
			printf("inserted %d\n", value);
		}
		else if(cmd[0] == 'f')
		{
			const RBTNode<int>*node = tree.Find(value);
			if(node == nullptr)
				printf("can't find %d\n", value);

			while(node != nullptr)
			{
				printf("%d %s %s\n", node->value, node->color == BLACK ? "BLACK":"RED"
						, node->parent == nullptr ? "root" : node == node->parent->right ? "right" : "left");
				node = node->parent;
			}
		}
	}
}

int main()
{
#ifdef TEST_SORTING
	testSorting();
#endif

#ifdef TEST_ADD
	testAdd();
#endif

#ifdef TEST_RBT
	testRBT();
#endif
	printf("press any key to exit");
	getchar();
	return 0;
}
