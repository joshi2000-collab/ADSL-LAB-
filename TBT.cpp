#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;
class N { //node declaration
   public:
      int k;
   N *l, *r;
   bool leftTh, rightTh;
};

class ThreadedBinaryTree {
   private:
   N *root;
   public:
   ThreadedBinaryTree() { //constructor to initialize the variables
      root= new N();
      root->r= root->l= root;
      root->leftTh = true;
      root->k = MAX_VALUE;
   }
   void insert(int key) {
      N *p = root;
      for (;;) {
         if (p->k< key) {
            if (p->rightTh)
               break;
            p = p->r;
         } else if (p->k > key) { // move to left thread
            if (p->leftTh)
               break;
            p = p->l;
         } else {
            return;
         }
      }
      N *temp = new N();
      temp->k = key;
      temp->rightTh= temp->leftTh= true;
      if (p->k < key) {
         temp->r = p->r;
         temp->l= p;
         p->r = temp;
         p->rightTh= false;
      } else {
         temp->r = p;
         temp->l = p->l;
         p->l = temp;
         p->leftTh = false;
      }
   }
  


void displayTree() { //print the tree
   N *temp = root, *p;
   for (;;) {
      p = temp;
      temp = temp->r;
      if (!p->rightTh) {
         while (!temp->leftTh) {
            temp = temp->l;
         }
      }
      if (temp == root)
         break;
      cout<<temp->k<<" ";
   }
   cout<<endl;
}
};
int main() {
   ThreadedBinaryTree tbt;
   cout<<"ThreadedBinaryTree\n";
   char ch;
   int c, v;  
   while(1) {
      cout<<"1. Insert "<<endl;
      cout<<"2. Display"<<endl;
      cout<<"99. Exit"<<endl;
      cout<<"Enter Your Choice: ";
      cin>>c;
      //perform switch operation
      switch (c) {
         case 1 :
            cout<<"Enter integer element to insert: ";
            cin>>v;
            tbt.insert(v);
            break;
         case 2:
            cout<<"Display tree: \n ";
            tbt.displayTree();
            break;
         case 99:
            exit(1);
         default:
            cout<<"\nInvalid type! \n";
      }
   }
   cout<<"\n";
   return 0;
}
