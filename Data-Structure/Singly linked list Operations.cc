/* 
 * File:   main.cpp
 * 
 * Author: Pavel;
 * 
 */
#include<iostream>

using namespace std;

class list {
public:
    int val;
    list * next;

    list() {
        val = 0;
        next = NULL;
    }

    list(const list &a) {
        val = a.val;
        next = a.next;
    }
};

list *p;
list *head;
list *rev;
list *nh;
int t = 0;

void insert() {       
    p = new list;
    head = NULL;
    int n;

    while (true) {
        cin>>n;
        t++;
        if (n == -9900)
            break;
        if (head == NULL) {
            head = new list;
            head->val = n;
            p = head;
        } else {
            list *q;
            q = new list;       //new list creation
            p->next = new list; //new memory address allocation
            q->val = n;         //set the value to q
            p->next = q;        //memory address of q allocate to p
            p = q;              // p==q;
        }
    }
    cout << "Insertion Done! (~_~)" << endl;
}

void print() {
    // head = NULL;
    p = head;
    while (p->next != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << p->val << "\n";
}

void spinsert() {
    p = head;
    int index;
    cin>>index;
    t++;
    for (int i = 1; i < index; i++) {
        p = p->next;
    }
    list *l;
    l = new list;
    cin >> l->val;
    l->next = p->next;
    p->next = l;
}

void Delete ()
{
    int n;
    cin>>n;
    p = head;
    list *f;
    while(p->val!=n){
       
        f = new list;
        f = p;
        p = p->next;
        //if(p->val != n)
           // free(f);
    }
    f->next = p->next;   
    free(f);
}
/*
void reverse() {
    int n=0;
    p= head;
    while(p->next!=NULL){
        p= p->next;
        n++;
    }
    //nh = NULL;
    nh = new list;
    
    while(n--){
        rev = new list;
        rev->next = p->next;
        rev->val = p->val;
    }
    // free(p);
   p = new list;
     head=p;
    
     while(n--){
        p = new list;
        p->next = p->next;
        p->val = rev->val;
    }
 *
void rev_print() {
    // head = NULL;
    rev = nh;
    while (rev->next != NULL) {
        cout << rev->val << " ";
        rev = rev->next;
    }
    cout << rev->val << "\n";
}

   
}*/

int main() {
    while (true) {
        char c;
        cout << "i - Insert Data" << "\n"
                "c - Insert on specific index" << "\n"
                "p - Print data" << "\n"
                "d - Delete a data"<<"\n"
               // "r - Reverse the list \n"
                "e - Break\n";
        cin>>c;
        if (c == 'i') {                     // Insertion ; 
            cout << "Insert Data of list: [insert '-9900' to end] \n" << endl;
            insert();
        }
        else if (c == 'p') { //Print list
            cout << "Data of list : " << endl;
            print();
        } 
        else if (c == 'c') { //correction
            cout << "Insert on specific index" << endl;
            spinsert();
        } 
        else if (c == 'd') { //correction
            cout << "Insert data to delete" << endl;
            Delete();
        } 
      /*  else if (c == 'r') { //Reverse
            cout << "Reversing the list ....." << endl;
            reverse();
        }*/ 
        else if (c == 'e')
            break;

    }
    return 0;
}
