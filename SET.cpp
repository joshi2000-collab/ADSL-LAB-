#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class Set
{
public:
    node *hn;

public:
    Set()
    {
        hn = NULL;
    }

    void insert(int data)
    {
        node *nn = new node;
        nn->next = NULL;

        nn->data = data;

        if (hn == NULL)
        {
            hn = nn;
        }
        else
        {
            node *cn = hn;

            while (cn->next != NULL)
            {
                cn = cn->next;
            }
            cn->next = nn;
        }
    }

    void display()
    {
        if (hn == NULL)
        {
            cout << "\nList is Empty";
        }
        else
        {
            node *cn = hn;

            while (cn != NULL)
            {
                cout << cn->data << " ";
                cn = cn->next;
            }
        }
    }

    void set_union(Set s1, Set s2)
    {
        node *hn1 = s1.hn;
        node *hn2 = s2.hn;

        node *cn1, *cn2;
        cn1 = hn1;
        cn2 = hn2;

        node *cn = hn;

        int flag = 0;

        while (cn1 != NULL)
        {
            insert(cn1->data);
            cn1 = cn1->next;
        }

        while (cn2 != NULL)
        {
            flag = 0;
            cn = hn;

            while (cn != NULL)
            {
                if (cn->data == cn2->data)
                {
                    flag++;
                    break;
                }
                cn = cn->next;
            }

            if (flag == 0)
            {
                insert(cn2->data);
            }

            cn2 = cn2->next;
        }
    }

    void set_intersection(Set s1, Set s2)
    {
        node *hn1 = s1.hn;
        node *hn2 = s2.hn;

        node *cn1, *cn2;
        cn1 = hn1;
        cn2 = hn2;

        node *cn = hn;

        int flag = 0;

        while (cn2 != NULL)
        {
            flag = 0;
            cn = hn;

            while (cn1 != NULL)
            {
                if (cn1->data == cn2->data)
                {
                    flag++;
                    break;
                }
                cn1 = cn1->next;
            }

            if (flag == 1)
            {
                insert(cn2->data);
            }

            cn2 = cn2->next;
        }
    }

    void set_difference(Set s1, Set s2)
    {
        node *hn1 = s1.hn;
        node *hn2 = s2.hn;

        node *cn1, *cn2;
        cn1 = hn1;
        cn2 = hn2;

        node *cn = hn;

        int flag = 0;

        while (cn2 != NULL)
        {
            flag = 0;
            cn = hn;

            while (cn1 != NULL)
            {
                if (cn1->data == cn2->data)
                {
                    flag++;
                    break;
                }
                cn1 = cn1->next;
            }

            if (flag == 0)
            {
                insert(cn2->data);
            }

            cn2 = cn2->next;
        }
    }

    void search(int key)
    {
        node *cn = hn;

        while (cn != NULL)
        {
            if (cn->data == key)
            {
                cout << "\nElement found!!";
                return;
            }
            cn = cn->next;
        }

        cout << "\nElement not found!!";
    }

    void delete_ele(int ele)
    {
        node *cn = hn;
        node *prev = cn;

        if (hn->data == ele)
        {
            cout << "\nElement " << ele << "deleted!!";
            hn = hn->next;
        }

        while (cn != NULL)
        {
            if (cn->data == ele)
            {
                cout << "\nElement " << ele << "deleted!!";
                prev->next = cn->next;
                delete cn;
                return;
            }
            prev = cn;
            cn = cn->next;
        }

        cout << "\nElement not found!!";
    }

    void count()
    {
        int cnt = 0;

        node *cn = hn;

        while (cn != NULL)
        {
            cnt++;
            cn = cn->next;
        }

        cout << "\nToatal number of elements in Set is: " << cnt;
    }
};

int main()
{
    Set s1, s2, s3, s4, s5;
    int ch, data, n;
    char choice;

    do
    {
        cout << "\n\n*************SET OPERATIONS**************\n";
        cout << "1.Insert Node\n2.Display List\n3.Search\n4.Delete\n5.Count\n6.Union\n7.Intersection\n8.Difference\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "\n1.Insert in Set 1 \n2.Insert in Set 2\n>>";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                cout << "\nEnter data to Insert: ";
                cin >> data;
                s1.insert(data);
                break;
            }
            case 2:
            {
                cout << "\nEnter data to Insert: ";
                cin >> data;
                s2.insert(data);
                break;
            }
            }
            break;
        }
        case 2:
        {
            cout << "\n1.Display Set 1 \n2.Display Set 2\n>>";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                s1.display();
                break;
            }
            case 2:
            {
                s2.display();
                break;
            }
            }
            break;
        }
        case 3:
        {
            cout << "\n1.Search in Set 1 \n2.Search in Set 2\n>>";
            cin >> ch;
            cout << "\nEnter element to search: ";
            cin >> data;
            switch (ch)
            {
            case 1:
            {
                s1.search(data);
                break;
            }
            case 2:
            {
                s2.search(data);
                break;
            }
            }
            break;
        }
        case 4:
        {
            cout << "\n1.Delete from Set 1 \n2.Search from Set 2\n>>";
            cin >> ch;
            cout << "\nEnter element to delete: ";
            cin >> data;
            switch (ch)
            {
            case 1:
            {
                s1.delete_ele(data);
                break;
            }
            case 2:
            {
                s2.delete_ele(data);
                break;
            }
            }
            break;
        }
        case 5:
        {
            cout << "\n1.Count elements in Set 1 \n2.Count elements in Set 2\n>>";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                s1.count();
                break;
            }
            case 2:
            {
                s2.count();
                break;
            }
            }
            break;
        }
        case 6:
        {
            cout << "\nUnion of Set 1 and Set 2 is: ";
            s3.set_union(s1, s2);
            s3.display();
            break;
        }
        case 7:
        {
            cout << "\nIntersection of Set 1 and Set 2 is: ";
            s4.set_intersection(s1, s2);
            s4.display();
            break;
        }
        case 8:
        {
            cout << "\nDifference of Set 1 and Set 2 is: ";
            s5.set_difference(s1, s2);
            s5.display();
            break;
        }
        }

        cout << "\n\nDo you want to continue: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
