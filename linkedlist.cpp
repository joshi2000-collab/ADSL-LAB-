#include <iostream>
#define SIZE 50
using namespace std; 

class HashTable
{
	int arr[SIZE],_items;
	bool isFilled[SIZE];
public:
	
	HashTable()
	{
		_items=0;
		for(int i=0;i<SIZE;i++)
		{
			isFilled[i]=false;
			arr[i]=0;
		}
	}
	int insert(int number)
	{
		_items++;
		int n=number%SIZE;
		while(1)
		{
			
			if(!isFilled[n])
			{
				arr[n]=number;
				isFilled[n]=true;
				return n;
			}
			n++;
		}
	}
	bool search(int number)
	{
		int n=number%SIZE;
		for(int i=0;i<SIZE;i++)
		{
			
			if(arr[n]==number)
			{
				return true;
			}
			n++;
		}
		return false;
	}

};

int main()
{
	HashTable ht;
	int ui;
	cout<<"HASH TABLE\n";
	while(1)
	{
		cout<<"1.Insert\n2.Search\n99.Exit\n>>";
		cin>>ui;

		switch(ui)
		{
			case 1:
				int m;
				cout<<"Enter value >> ";
				cin>>m;
				cout<<"Added at index "<<ht.insert(m)<<endl;
				break;

			case 2:
				cout<<"Enter value >> ";
				cin>>m;
				if(ht.search(m))
					cout<<"Element found\n";
				else
					cout<<"Element not found \n";
				break;

			case 99:
				return 0;
			default:
				cout<<"Invalid option";

		}
	}

}
