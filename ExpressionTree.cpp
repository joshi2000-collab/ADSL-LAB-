#include<iostream>
#include<string.h>
using namespace std;


struct node
{
	char data;
	struct node *l, *r;
};

class stack
{

	private:
		node* arr[20];
		int top;

	public:
	stack()
	{
		top=-1;
	}

	void push(node *x)
	{
		arr[++top]=x;
	}

	node* pop()
	{
		return arr[top--];
	}

	bool isFull()
	{
		if(top==19)
		return true;
		else
		return false;
	}
	bool isEmpty()
	{
		if(top==-1)
		return true;
		else return false;
	}


};


class exptree
{
	public:
		node *root;
        stack s1, s2;



	void convert(string x)
	{
		for(int i=0; x[i]!='\0'; i++)
		{
			if(x[i]=='+' ||x[i]=='-' ||x[i]=='*' ||x[i]=='/')
			{
				if(s2.isEmpty())
				{
					node *nn=new node();
					nn->data= x[i];
					nn->r=nn->l=NULL;
					s2.push(nn);
				}
				else
				{
					
					root = s2.pop();
					root->r= s1.pop();
					root->l=s1.pop();
					s1.push(root);
					
					
					node *nn;
					nn=new node();
					nn->data= x[i];
					nn->r=nn->l=NULL;
					s2.push(nn);


				}
			}
			else
			{
				node *nn= new node();
				nn->data= x[i];
				nn->r=nn->l=NULL;
				s1.push(nn);

			}
		}

					node *nn;
					nn = s2.pop();
					nn->r= s1.pop();
					nn->l=s1.pop();
					root=nn;
					s1.push(root);
	}

	void display(node *nn)
	{
		if(nn)
		{
			display(nn->l);
			cout<<nn->data<<" ";

			display(nn->r);
		}
		
	}


};


int main()
{
exptree t1;
t1.convert("a-b+c+x-y/z*p");

t1.display(t1.root);

cout<<"end";
return 0;
}
