#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *down, *up;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->down = temp->up = NULL;
	return temp;
}

void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->down);

	printPostorder(node->up);

	cout << node->data << " ";
}

void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	printInorder(node->down);

	cout << node->data << " ";

	printInorder(node->up);
}

void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	cout << node->data << " ";

	printPreorder(node->down);

	printPreorder(node->up);
}


int main()
{
	struct Node* root = newNode(3);
	root->down = newNode(5);
	root->up = newNode(10);
	root->down->down = newNode(4);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}
