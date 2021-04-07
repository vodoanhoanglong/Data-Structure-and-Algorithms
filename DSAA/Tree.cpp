#include<iostream>

using namespace std;

class node
{
  private:
	int data;
	node *left;
	node *right;
  public:
    friend node *insert(node *t, int x);
	friend void printTree(node *t);
	friend int MaxDepth(node* t);
	friend node *FindAndReplace(node *p);
	friend node *DeleteNode(node *t, int x);
	friend node *Search(node *t, int key);
};
node *insert(node *t, int x)
{
	if (t == NULL){
		node *temp = new node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else{
		if (x < t->data){
			t->left = insert(t->left, x);
		} else{
			t->right = insert(t->right, x);
		}
	}	
}
void printTree(node *t)
{
	if (t)
	{
		printTree(t->left);
		cout << t->data << " ";
		printTree(t->right);
	}
}
int MaxDepth(node* t)
{
	if(t==NULL)
	   return 0;
	else
	{
		int lDepth=MaxDepth(t->left);
		int rDepth=MaxDepth(t->right);
		if(lDepth>rDepth)
		   return (lDepth+1);
		else return (rDepth+1);
	}
}
node *Search(node *t, int key){
	if(t != NULL){
		if(key == t->data){
			return t;
		}
		if(key < t->data){
			return Search(t->left, key);
		}else{
			return Search(t->right, key);
		}
	}else{
		return NULL;
	}
}

node *FindAndReplace(node *p)
{
    node *current = p;
	while(current && current->left!=NULL)
	    current = current->left;
	return current; 
}
node *DeleteNode(node *t, int x)
{
    if (t==NULL)
	{
	   cout << "Not found!\n";
	   return 0;
	}
	if(x<t->data) t->left = DeleteNode(t->left, x);
	else if(x>t->data) t->right = DeleteNode(t->right, x);
	else
	{
		if(t->data==NULL)
		{
			node *temp = t->right;
			delete t;
			return temp;
		}
		else if(t->right==NULL)
		{
			node *temp = t->left;
			delete t;
			return temp;
		}
		node *temp = FindAndReplace(t->right);
		t->data = temp->data;
		t->right = DeleteNode(t->right, temp->data);
	}
	return t;
	
}
int main(){
	int n, x, z, key;
	cout<<"\nEnter number: ";
	cin >> n;
	node * t = NULL;
	for (int i = 0; i < n; i++){
		cout<<"Enter value "<<i+1<<": "; 
		cin >> x;
		t = insert(t, x);
	}
	cout<<MaxDepth(t)<<"\n";
	printTree(t);
	cout<<"\nEnter element need to search: "; cin>>key;
	if(Search(t, key)) cout<<"\nElement in tree";
	else cout<<"\nNot found!";
	cout<<"\nEnter value need to delete: "; cin>>z;
	DeleteNode(t, z);
	printTree(t);
	cout<<endl;
	system("pause");
}
