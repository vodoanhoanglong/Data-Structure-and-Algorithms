#include <iostream>
using namespace std;
struct node
{
	int value;
	node *left;
	node *right;
};
class Tree
{
private:
	node *root;

public:
	Tree();
	Tree(int data);
	~Tree();
	void insert(int key);
	void insert(int key, node *root);
	// node *search(int key);
	// node *search(int key, node *root);
	void inorder(node *root);
	// void postorder(node *root);
	void preorder();
	void preorder(node *root);
	void inorder();
	// void postorder();
};
Tree::Tree()
{
	root = NULL;
}
Tree::Tree(int data)
{
	root = new node;
	root->value = data;
	root->left = NULL;
	root->right = NULL;
}
Tree::~Tree()
{
}

void Tree::insert(int key, node *root)
{
	if (key < root->value)
	{
		if (root->left)
		{
			insert(key, root->left);
		}
		else
		{
			root->left = new node;
			root->left->value = key;
			root->left->left = NULL;
			root->left->right = NULL;
		}
	}
	else
	{
		if (root->right)
		{
			insert(key, root->right);
		}
		else
		{
			root->right = new node;
			root->right->value = key;
			root->right->right = NULL;
			root->right->left = NULL;
		}
	}
}

void Tree::insert(int key)
{
	if (root)
		insert(key, root);
	else
	{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
// node *Tree::search(int key, node *root)
// {
// 	if(root!=NULL)
// 	   if(key == root->value)
// 	       return root;
// 	    else if(key < root->value)
// 	       return search(key, root->left);
// 	    else
// 	       return search(key, root->right);
// 	else
// 	    return NULL;
// }
// node *Tree::search(int key)
// {
// 	return search(key, root);
// }
void Tree::inorder()
{
	inorder(root);
	cout<<"\n";
}
void Tree::inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->value<<", ";
		inorder(root->right);
	}
}
// void Tree::postorder()
// {
// 	postorder(root);
// 	cout<<"\n";
// }
// void Tree::postorder(node *root)
// {
// 	if(root)
// 	{
// 		inorder(root->left);
// 		inorder(root->right);
// 		cout<<root->value<<", ";
// 	}
// }
void Tree::preorder()
{
	preorder(root);
	cout << "\n";
}
void Tree::preorder(node *root)
{
	if (root)
	{
		cout << root->value << ", ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	Tree *tree;
	tree = new Tree(10);
	int n, x, data;
	cout << "\nEnter the number of the tree: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter data " << i + 1 << ": " << endl;
		cin >> data;
		tree->insert(data);
	}
	cout << "Output: " << endl;
	//Duyet tien tu
	tree->inorder();
	//Duyet trung tu
	// tree->inorder();
	// //Duyet hau tu
	// tree->postorder();
	// cout<<"Search elements"<<endl;
	// cout<<"Enter value need to search: "; cin>>x;
	// if(tree->search(x))
	//     cout<<"Value in tree"<<endl;
	// else cout<<"Not found!";
	system("pause");
}
