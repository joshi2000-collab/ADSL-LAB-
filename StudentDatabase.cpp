#include <iostream>
#include <fstream>

using namespace std;


class Student
{
	char name[10];
	int rollno;
	char div;
	char address[50];
public:
	void get()
	{
		cout<<"Enter name ";
		cin>>name;
		cout<<"Enter rollno ";
		cin>>rollno;
		cout<<"Enter div {A,B,C} : ";
		cin>>div;
		cout<<"Enter Address : ";
		cin>>address;

	}
	void show()
	{
		cout<<"Name : "<<name<<endl<<"Roll :"<<rollno<<endl;
		cout<<"Div : "<<div<<endl<<"Address :: "<<address<<endl;
	}
	int rollNO()
	{
		return rollno;
	}
};

class Department
{	
	fstream f;	
	public:
		void addStudent()
		{
			
			Student s;
			s.get();
			f.open("database",ios::out| ios::app | ios::binary);
			f.write((char *)&s,sizeof(s));
			f.close();

		}
		void updateStudent()
		{
			int target;
			bool found=false;
			cout<<"Enter target roll number";
			cin>>target;
			Student s;
			f.open("database",ios::in |ios::out | ios::binary);
			
			while(f.read((char *)&s,sizeof(s)))
				if(s.rollNO()==target)
				{
					found=true;
					f.seekp((int)f.tellg()-sizeof(s),ios::beg);

					s.get();
					f.write((char *)&s,sizeof(s));

				}

			if(!found)
			{
				cout<<"Student Doesn't Exist\a";
			}
			f.close();

		}
		void deleteStudent()
		{

		}
		void searchStudent()
		{
			int target;
			bool found=false;
			cout<<"Enter target roll number";
			cin>>target;
			Student s;
			f.open("database",ios::in |ios::out | ios::binary);
			
			while(f.read((char *)&s,sizeof(s)))
				if(s.rollNO()==target)
				{
					found=true;
                    s.show();

				}

			if(!found)
			{
				cout<<"Student Doesn't Exist\a";
			}
			f.close();
		}
		void showStudents()
		{
			Student s;
			f.open("database",ios::in | ios::binary);
			while(f.read((char *)&s,sizeof(s)))
				cout<<endl,s.show(),cout<<endl;
			f.close();
		}

};



int main()
{
	Department Comp;
	int ui;
	cout<<"File Operations\n";
	while(1)
	{
		cout<<"1.Add\n2.Show\n3.Delete\n4.Update\n5.Search\n99.Exit\n>>";
		cin>>ui;
		switch(ui)
		{
			case 1:
			Comp.addStudent();
			break;
			case 2:
			Comp.showStudents();
			break;
			case 3:
			Comp.deleteStudent();
			break;
			case 4:
			Comp.updateStudent();
			break;
			case 5:
			Comp.searchStudent();
			break;
			case 99:
			return 0;
			break;
			default:
				cout<<"Invalid Option";

		}

	}
}
