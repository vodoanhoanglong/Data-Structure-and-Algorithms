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
		void insert1(int key);
		void insert2(int key);
		void insertLeft(int key, node *root);
		void insertRight(int key, node *root);
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
void Tree::insertLeft(int key, node *root)
{
	   if(root->left)
		{
			insertLeft(key, root->left);
		}
	   else
	   {
		    root->left = new node;
		    root->left->value = key;
		    root->left->left = NULL;
		    root->left->right = NULL;
	   }
}
void Tree::insertRight(int key, node *root)
{
	    if(root->right)
		{
            insertRight(key, root->right);
		}
		else
		{
			root->right = new node;
			root->right->value = key;
			root->right->right = NULL;
			root->right->left = NULL;
		}
}
void Tree::insert1(int key)
{
	if(root)
	    insertLeft(key, root);
    else
    {
    	root = new node;
    	root->value = key;
    	root->left = NULL;
    	root->right = NULL;
	}
}
void Tree::insert2(int key)
{
	if(root)
       insertRight(key, root);
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
// void Tree::inorder()
// {
// 	inorder(root);
// 	cout<<"\n";
// }
// void Tree::inorder(node *root)
// {
// 	if(root)
// 	{
// 		inorder(root->left);
// 		cout<<root->value<<", ";
// 		inorder(root->right);
// 	}
// }
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
	cout<<"\n";
}
void Tree::preorder(node *root)
{
	if(root)
	{
		cout<<root->value<<", ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	Tree *tree;
	tree = new Tree(10);
	int n, x, data1, data2;
	cout<<"\nEnter the number of left and right pairs of the tree: "<<endl;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Enter data left "<< i+1 <<": "<<endl;
		cin>>data1;
		tree->insert1(data1);
		cout<<"Enter data right "<<i+1<<": "<<endl;
		cin>>data2;
		tree->insert2(data2);
	}
	cout<<"Output: "<<endl;
	//Duyet tien tu
	tree->preorder();
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



