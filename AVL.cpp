#include <iostream>

using namespace std; 
struct node
{
	int value;
	node *left,*right;
};

int max(int a,int b)
{
	return a>b ? a:b;
}
class avl
{	

	node *BST_insert(node * root,int value)
	{
		if(root==NULL)
		{
			node * nn= new node;
			nn->value =value;
			nn->left=NULL;
			nn->right=NULL;
			root=nn;
		}
		if(value < root->value)
		{
			root->left=BST_insert(root->left,value);
			root=balance(root);
		}
		if(value > root->value)
		{
			root->right=BST_insert(root->right,value);
			root=balance(root);
		}
		return root;
	}
	int height(node *n)
	{
		if(n!=NULL)
			return max(height(n->left),height(n->right))+1;
	}
	int difference(node *n)
	{
		if(n!=NULL)
			return height(n->left)-height(n->right);
	}
	node * ll_rot(node *n)
	{
	   node *t;
	   t = n->left;
	   n->left = t->right;
	   t->right = n;
	   return t;
	}
	node * lr_rot(node *n)
	{
		node *t;
		t = n->left;
   		n->left = rr_rot(t);
		return t;
	}
	node * rl_rot(node *n)
	{
		node *t;
		t = n->right;
   		n->right = ll_rot(t);
		return t;
	}
	node * rr_rot(node *n)
	{
		node *t;
		t = n->right;
		n->right = t->left;
		t->left = n;
		return t;
	}
	node * balance(node *n)
	{
		int bal_fac = difference(n);
		if(bal_fac>1)
		{
			if(difference(n->left)>0)
				n=ll_rot(n);
			else
				n=lr_rot(n);
		}
		if(bal_fac<-1)
		{
			if(difference(n->left)>0)
				n=rl_rot(n);
			else
				n=rr_rot(n);
		}
		return n;
	}

public:
	node *root;
	avl()
	{
		root=NULL;
	}
	void insert()
	{
		int value;		
		cout<<"Enter value : ";
		cin>>value;
		root=BST_insert(root,value);
	}
	void print(node *root)
	{
		if(root==NULL)
		{
			return;
		}
		print(root->left);
		cout<<root->value<<" ";
		print(root->right);
	}



};


int main()
{
	cout<<"AVL\n";
	avl a;
	int ui;
	while(1)
	{
		cout<<"1.Insert\n2.Display\n99.Exit\n>>";
		cin>>ui;
		switch(ui)
		{
			case 1:
			a.insert();
			break;

			case 2:
			a.print(a.root);
			break;

			case 99:
			return 0;

			default:
			cout<<"Enter valid option\n";
		}
	}

}
