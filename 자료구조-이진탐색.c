#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY_SIZE = 100

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

int search(TreeNode* node, int key) {
	if (node == NULL) {
		return 0;
	}
	if (key == node->key) {;
		return 1;
	}
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
void Search(TreeNode* node, int key) {
	if (search(node, key) == 1)
		printf("T\n");
	else
		printf("F\n");
}

TreeNode* Create() {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = 0;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* new_node(int key) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;
}

TreeNode* Add(TreeNode* node) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	int data;
	printf("입력(마지막값은 0) : ");
	while(1) {
		scanf("%d",&data);
		if (data == 0)
			break;
		else {
			temp = insert_node(node, data);
		}
	}
	return temp;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}


TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder(TreeNode* root) {
	int cnt = 0;
	if (root != NULL) {
		inorder(root->left);
		if(root->key != 0)
			printf("[%d]", root->key);
		inorder(root->right);
	}
}

void inorder_nth(TreeNode* root,int pos) {
	static int count = 0;
	if (root != NULL) {
		inorder_nth(root->left,pos);
		if (root->key != 0) {
			count += 1;
			if (pos == count) {
				printf("[%d]", root->key);
			}
		}
		inorder_nth(root->right,pos);
	}
}
int LevelSum(TreeNode* root, int lev) {
	static int level = -1;
	level++;
	if (root == NULL) {
		level--;
		return 0;
	}
	int sum = 0;
	sum = LevelSum(root->right, lev) + LevelSum(root->left, lev);
	if (level == lev) {
		level--;
		sum = root->key;
		return sum;
	}
	else {
		level--;
		return sum;
	}
}

void preorder(TreeNode* root) {
	if (root != NULL) {
		if(root->key != 0)
			printf("[%d]", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

TreeNode* get(TreeNode* A, TreeNode* uni) {
	if (A == NULL)
		return uni;

	insert_node(uni, A->key);
	uni = get(A->right, uni);
	uni = get(A->left, uni);
	return uni;
}
TreeNode* Union(TreeNode* A, TreeNode* B) {
	TreeNode* uni = (TreeNode*)malloc(sizeof(TreeNode));
	uni = Create();
	uni = get(A, uni);
	uni = get(B, uni);
	
	return uni;
}
TreeNode* del(TreeNode* A, TreeNode* B) {
	if (B == NULL)
		return A;
	if(B->key != 0)
		delete_node(A, B->key);
	A = del(A,B->right);
	A = del(A,B->left);
	return A;
}
TreeNode* Difference(TreeNode* A, TreeNode* B) {
	TreeNode* diff = (TreeNode*)malloc(sizeof(TreeNode));
	diff = del(A, B);
	return diff;
}
void IsEmpty(TreeNode* root) {
	if (root == NULL)
		printf("T");
	else printf("F");
}

int main()
{
	TreeNode* A = Create();
	TreeNode* B = Create();
	TreeNode* C = Create();
	TreeNode* D = Create();

	A = Add(A);
	B = Add(B);
	
	printf("집합 A inorder: ");
	inorder(A);
	printf("\n");
	printf("집합 B inorder: ");
	preorder(B);
	printf("\n");
	C = Union(A, B); // AnB 합집합
	printf("집합 C(AnB) Preorder_Traverse: ");
	preorder(C);
	printf("\n");
	printf("집합 C의 5번째 원소(inorder_nth) : ");
	inorder_nth(C, 5);
	printf("\n");
	D = Difference(A, B);//A-B 차집합
	printf("집합 D(A-B) inorder: ");
	preorder(D);
	printf("\n");
	printf("IsEmpty(C,D) : ");
	IsEmpty(Difference(C, D));
	printf("\n");
	printf("C의 Level 3 의 합(Level_sum):");
	printf("%d",LevelSum(C, 3));
	

	return 0;
}