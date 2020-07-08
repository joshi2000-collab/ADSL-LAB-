#include <iostream>

using namespace std; 



struct node{
	string key;
	string meaning;
	node *left , *right;

};

class BST{

	node *root;
	bool flag;

private:
	node *BST_insert(node * root,string key,string meaning)
	{
		if(root==NULL)
		{
			node * nn= new node;
			nn->key =key;
			nn->meaning=meaning;
			nn->left=NULL;
			nn->right=NULL;
			root=nn;
		}
		if(key < root->key)
		{
			root->left=BST_insert(root->left,key,meaning);
		}
		if(key > root->key)
		{
			root->right=BST_insert(root->right,key,meaning);
			
		}
		return root;
	}
	void print_node(node *n)
	{
		cout<<"\n\tKeyword  : "<<n->key;
		cout<<"\n\tMeaning  : "<<n->meaning<<endl;
	}
	void BST_print_in(node *root)
	{

		if(root==NULL)
		{
			return;
		}
		BST_print_in(root->left);
		print_node(root);
		BST_print_in(root->right);

	}
	void BST_print_pre(node *root)
	{

		if(root==NULL)
		{
			return;
		}
		print_node(root);

		BST_print_pre(root->left);
		BST_print_pre(root->right);

	}
	void BST_print_post(node *root)
	{

		if(root==NULL)
		{
			return;
		}
		

		BST_print_post(root->left);
		BST_print_post(root->right);
		print_node(root);

	}
	// node * BST_search(node *root,string key)
	// {
		
	// 	if(root->key==key || root==NULL)
	// 	{
	// 		cout<<root->key;
	// 		// flag=true;
	// 		return root;
	// 		print_node(root);

	// 	}
	// 	else if(key < root->key)
		
	// 		 return BST_search(root->left,key);

		
	// 	else if(key > root->key)
	// 	 return BST_search(root->right,key);

		

	// }
	bool BST_search(string key)
	{
		node *temp=root;
		do{
			if(temp->key==key)
			{
				print_node(temp)
				return true;
			}
			else if(key >temp->key)
				temp=temp->right;
			else if(key < temp->key)
				temp=temp->left;
		}while(temp!=NULL);

		return false;
	}
	node * minValueNode(struct node* node)
	{
		struct node* current = node;

		while (current && current->left != NULL)
		current = current->left;

		return current;
	} 
	node * deleteNode(node *root , string key)
	{
    if (root == NULL) return root;
  
    if (key < root->key)
        root->left = deleteNode(root->left, key);
  
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
  
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete(root);
            return temp;
        }
  
        node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root; 
	}


public:
	BST()
	{
		root=NULL;
		flag=false;

	}
	
	void insert()
	{
		string key;
		string meaning;
		cout<<"Enter keyword : ";
		cin>>key;
		cout<<"Enter Meaning : ";
		cin>>meaning;

		root=BST_insert(root,key,meaning);


	}
	void print()
	{
		int ui;
		cout<<"Print with :  \n1.Inorder\n2.PostOrder\n3.Preorder";
		cin>>ui;
		switch(ui)
		{
			case 1:
			BST_print_in(root);
			break;
			case 2:
			BST_print_post(root);
			break;
			case 3:
			BST_print_pre(root);
			break;

			default:
			BST_print_in(root);

		}
		
		cout<<endl;
	}
	// void update()
	// {
	// 	string key ,new_mean;
	// 	node *temp=root;
	// 	while(temp!=NULL);
	// }
	void Del()
	{
		string key;
		cout<<"Enter the keyword : ";
		cin>>key;
		flag=BST_search(key);
		if(!flag)
		{
			cout<<"No such Entry";
			return;

		}
		root=deleteNode(root,key);
	}


	void search()
	{
		bool flag;
		string key;
		cout<<"Enter key for searching : ";
		cin>>key;
		flag=BST_search(key);

		if(!flag)
		{
			cout<<"\tContent not found\n\a";
		}

		// cout<<root->key < "t";
	}
};




int main()
{
	BST b;
	int ui;
	cout<<"BST Operations\n";

	while(1)
	{
		cout<<"1.Insert\n2.Display\n3.Search\n4.Delete\n99.Exit";
		cout<<"\nEnter choice:: ";
		cin>>ui;
		switch(ui)
		{
			case 1:
				b.insert();
				break;
			case 2:
				b.print();
				break;
			case 3:
				b.search();
				break;
			case 4:
				b.Del();
				break;
			case 99:
				return 0;
			default:
				cout<<"Enter correct option\n";
		}

	}
}
