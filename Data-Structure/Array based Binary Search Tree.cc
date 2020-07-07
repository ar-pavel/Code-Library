
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

///Maximum size of the Array
int mx=100;


void create_bst(int T[], int data, int index);
void preorder(int T[], int index);
void postorder(int T[], int index);
void inorder(int T[], int index);
int bsearch(int T[], int data, int index);
void bdelete(int T[], int data, int index);
int bmin(int T[], int index);
int bmax(int T[], int index);
void display(int T[], int index);
void breplace(int a[], int i, int j);

int main()
{

    int T[mx]; ///BST array declaration
    int data; ///data will contaion data/value of node/leaf
    int choice,num,index;
    ///inatilizing the array with -1
    for(int i=0; i<mx; i++)
        T[i]=-1;

    while (true)
    {

        cout<<"-----------------"<<endl;

        cout<<"Operations on BST"<<endl;

        cout<<"-----------------"<<endl;

        cout<<"1.Insert Element "<<endl;

        cout<<"2.Delete Element "<<endl;

        cout<<"3.Inorder Traversal"<<endl;

        cout<<"4.Preorder Traversal"<<endl;

        cout<<"5.Postorder Traversal"<<endl;

        cout<<"6.Display"<<endl;

        cout<<"7.Search Element"<<endl;

        cout<<"8.Find Minimun"<<endl;

        cout<<"9.Find Maximun"<<endl;

        cout<<"10.Replace a element"<<endl;

        cout<<"11.Quit"<<endl;


        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {

        case 1:
            ///input data on BST
            cout<<" Enter data to input on the tree :\n Input -9900 to stop\n";
            while(true)
            {
                cin>>data;
                if(data==-9900) break;

                create_bst(T,data,1);
            }
            break;

        case 2:
            ///Deleting a value from the tree
            if (T[1] == -1)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;

                continue;
            }

            cout<<"Enter the number to be deleted : ";
            cin>>num;

            bdelete(T,num,1);

            break;

        ///Treversing the tree
        case 3:

            cout<<"Inorder Traversal of BST:"<<endl;

            inorder(T,1);
            cout<<endl;
            break;

        case 4:
            cout<<"Preorder Traversal of BST:"<<endl;

            preorder(T,1);

            cout<<endl;

            break;

        case 5:

            cout<<"Postorder Traversal of BST:"<<endl;

            postorder(T,1);

            cout<<endl;

            break;

        case 6:

            cout<<"Display BST:"<<endl;

            display(T,1);

            cout<<endl;

            break;

                ///Srearching a value on the tree
        case 7:
            cout<<"Enter a the number to find:"<<endl;

            cin>>data;
            cout<<bsearch(T,data,1)<<endl;

            break;

        case  8:

            cout<<"Lowest Value On the BST is: "<<endl;
            cout<<T[bmin(T,1)]<<endl;

            break;

        case 9:

            cout<<"Gratest Value On the BST is: "<<endl;
            cout<<T[bmax(T,1)]<<endl;

            break;

        case 10:

            cout<<"Enter the number to be replaced: "<<endl;
            cin>>num;
           // cout<<"Enter the number to repalce: "<<endl;
           // cin>>data;
            index= bsearch(T,num,1);
            breplace(T, index, index*2);

            break;

        case 11:

            exit(1);

        default:

            cout<<"Wrong choice"<<endl;

        }

    }

}

/*

* Inserting Element into the Tree

*/

void create_bst(int T[], int data, int index){
    if(index >= 100)
        cout<<"Overflow!\n";

    else if(T[index]==-1)
        T[index] = data;

    else if(T[index]<data)
        create_bst(T, data, (index*2)+1);

    else if(T[index]>data)
        create_bst(T, data, index*2);
}

/*

 * Pre Order Traversal

 */

void preorder(int T[], int index){
    if(T[index]!=-1){
        cout<<T[index]<<" ";
        preorder(T,index*2);
        preorder(T,(index*2)+1);
    }
   // cout<<endl;
}


/*

 * Postorder Traversal

 */

void postorder(int T[], int index){
    if(T[index]!=-1){

        postorder(T,index*2);
        postorder(T,(index*2)+1);

        cout<<T[index]<<" ";
    }
}

/*

 * In Order Traversal

 */

void inorder(int T[], int index){
    if(T[index]!=-1){

        inorder(T,index*2);

        cout<<T[index]<<" ";

        inorder(T,(index*2)+1);
    }
   // cout<<endl;
}

/*

 * Find Element in the Tree

 */

int bsearch(int T[], int data, int index){

    if(index>=mx) return -1;

    if(T[index]==data)
        return index;

    if(T[index]<data)
        bsearch(T, data, (index*2)+1);

    else if(T[index]>data)
        bsearch(T, data, index*2);
}

/*

 * Delete Element from the tree

 */

void bdelete(int T[], int data, int index){

    index = bsearch(T, data, 1);

    if(index == -1) cout<<"No value found! \n";

    else
    {
        ///No child
        if(T[index*2]==-1 && T[(index*2)+1]==-1)
              T[index] = -1;

        ///One child
        else
              if(T[index*2]==-1){

                T[index] = T[(index*2)+1];

                T[(index*2)+1]=-1;

                }
        else
            if(T[(index*2)+1]==-1){

                T[index] = T[index*2];

                T[index*2] = -1;
            }

        ///Two child
        else {
            T[index]=T[2*index];

            bdelete(T,data,2*index);
        }
    }


}

/*

* Find Min Value on the Tree

*/

int bmin(int T[], int index){

    while(T[index*2] != -1){

        index = index*2;
    }
    return index;
}

/*

* Find Max Value on the Tree

*/

int bmax(int T[], int index){

    while(T[(index*2)+1] != -1){

        index = (index*2)+1;
    }
    return index;
}

/*

 * Display Tree Array

 */

void display(int T[], int index){

    for(int i=index; i<100; i++)
        cout<<T[i] <<" ";

        cout<<endl;
}

/*

* Replace a value on the Array/BST

*/

void breplace(int a[], int i, int j)
{
    if(a[i]==-1 && a[j]== -1) return;
    a[i]=a[j];
    a[j]= -1;
    breplace(a,2*i+1,2*j+1);
    breplace(a,2*i+2,2*j+2);

}
// End of the code
