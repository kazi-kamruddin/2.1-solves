#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

int cnt=0;
int cycleLength=0;
int nonCycleLength=0;
struct node* cyclePoint = new node();
struct node* meetingPoint = new node();
struct node *cycleStart = new node();

void push_back(struct node*& root, int value){
    cnt++;
    struct node* newNode = new node();
    newNode->data = value;
    newNode->next = NULL;

    if(root == NULL)
        root = newNode;
    else{
        struct node* head = root;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = newNode;

        if(cnt == 5){
            cyclePoint = newNode;
        }
    }
}

void print(struct node *a){
    cout << a->data << " ";
    while(a->next != NULL){
        a = a->next;
        cout << a->data << " "; 
    }
    cout << endl;
}

void cycleFinding(struct node *root){
    struct node *hare = root;
    struct node *tortoise = root;

    while(tortoise->next != NULL || hare->next->next != NULL && hare->next != NULL){
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise == hare){
            cout << endl << endl << "cycle exists." << endl;
            cout << "met at: " << hare->data << endl;
            meetingPoint = hare;
            return;
        }
    }
}

void cycleStartPoint(struct node *root){
    struct node *tortorise1 = root;
    struct node *tortorise2 = meetingPoint;

    while(tortorise1 != tortorise2){
        tortorise1 = tortorise1->next;
        tortorise2 = tortorise2->next;
    }

    cycleStart = tortorise1;
    cout << "cycle starts here: " << cycleStart->data << endl;
}

void length(struct node *root, struct node *cycleStart){
    struct node *tortoise = cycleStart->next;
    
    cycleLength++;
    while(tortoise != cycleStart){
        tortoise = tortoise->next;
        cycleLength++;
    }

    tortoise = root;
    while(tortoise != cycleStart){
        tortoise = tortoise->next;
        nonCycleLength++;
    }

    cout << "total length: " << cycleLength+nonCycleLength << endl;
    cout << "cycle length: " << cycleLength << endl;
}

int main() {
    struct node *root = new node();
    root = NULL;

    push_back(root,1);
    push_back(root,2);
    push_back(root,3);
    push_back(root,4);
    push_back(root,5);
    push_back(root,6);
    push_back(root,7);
    push_back(root,8);
    push_back(root,9);
    push_back(root,10);

    struct node* head = root;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = cyclePoint;

    cout << "initially the linked list: " << endl;

    head = root;
    for(int i=0 ; i<25 ; i++){
        cout << head->data << " ";
        head = head->next;
    }

    cycleFinding(root);
    cycleStartPoint(root);
    length(root, cycleStart);
}