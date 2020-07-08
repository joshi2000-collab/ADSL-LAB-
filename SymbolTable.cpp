#include <iostream>
#include <iomanip>

using namespace std; 

const char separator    = ' ';
const int nameWidth     = 15;
const int numWidth      = 8;

struct variable_tuple{
	string datatype;
	string value;
	int occurance;
	int line_no[100];
	string identifier;
};

class SymbolTable{
	variable_tuple arr[10];
	int item_no;
public:
	SymbolTable()
	{
		item_no=-1;
	}
	void addEntry()
	{
		item_no++;
		cout<<"Enter identifier :: ";
		cin>>arr[item_no].identifier;
		cout<<"Enter datatype :: ";
		cin>>arr[item_no].datatype;
		cout<<"Enter value :: ";
		cin>>arr[item_no].value;
		cout<<"Enter number occurances :: ";
		cin>>arr[item_no].occurance;

		for(int i=0;i<arr[item_no].occurance;i++)
		{
			cout<<"Enter line number :: ";
			cin>>arr[item_no].line_no[i];
		}
	}
	void display()
	{
		cout << left << setw(nameWidth) << setfill(separator) << "Item no";
		cout << left << setw(nameWidth) << setfill(separator) << "Identifier";
		cout << left << setw(nameWidth) << setfill(separator) << "Data-type";
		cout << left << setw(nameWidth) << setfill(separator) << "Value";
		cout << left << setw(nameWidth) << setfill(separator) << "Occurances\n";
		for(int i=0;i<item_no+1;i++)
		{
			cout << left << setw(nameWidth) << setfill(separator) << i+1;
			cout << left << setw(nameWidth) << setfill(separator) << arr[i].identifier;
			cout << left << setw(nameWidth) << setfill(separator) << arr[i].datatype;
			cout << left << setw(nameWidth) << setfill(separator) << arr[i].value;
			for(int k=0;k<arr[i].occurance;k++)
			{
				cout << left << setw(3)<< arr[i].line_no[k];
				if(i+1!=k)
					cout<<",";
			}
			cout<<"\n";
		}
	
		

	}

};


int main()
{
	cout<<"Welcome to Symbol Table\n";
	SymbolTable s;
	s.addEntry();
	s.display();


}
