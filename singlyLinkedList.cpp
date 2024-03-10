#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

void push_back(struct node*& root, int value){
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
    }
}

int listLength(struct node *a){
    int len=0;
    if(a->next == NULL)
        return 0;
    else    
        len++;

    while(a->next != NULL){
        len++;
        a = a->next;
    }
    
    return len;
}

struct node* insertFirst(struct node *a, int value){
    struct node *temp = new node();
    temp->data = value;
    temp->next = a;

    return temp;
}

void insertLast(struct node *a, int value){
    struct node *temp = (struct node*) malloc(sizeof(node));
    while(a->next != NULL){
        a = a->next;
    }
    a->next = temp;
    temp->data = value;
    temp->next = NULL;
}

struct node* insertAnywhere(struct node *a, int index, int value){
    int len = listLength(a);
    struct node *head = new node();
    head = a;

    if(index > len){
        cout << "index doesn't exist" << endl;
        return head;
    }

    if(index == 0){
        head = insertFirst(a,value);
        return head;
    }

    struct node *temp = new node();
    int curr=0;

    while(curr != index-1){
        a = a->next;
        curr++;
    }    
    temp->data = value;
    temp->next = a->next;
    a->next = temp;

    return head;
}

struct node* deleteFirst(struct node *a){
    a = a->next;
    return a;
}

void deleteLast(struct node *a){
    struct node *prevLast = new node();
    while(a->next != NULL){
        prevLast = a;
        a = a->next;
    }
    prevLast->next = NULL;
}

struct node* deleteAnywhereByIndex(struct node *a, int index){
    int len = listLength(a);
    struct node *head = new node();
    head = a;

    if(index > len-1){
        cout << "index doesn't exist" << endl;
        return head;
    }

    if(index == 0){
        head = deleteFirst(head);
        return head;
    }

    // struct node *prev = (struct node*) malloc(sizeof(node));
    int curr=0;

    while(curr != index-1){
        // prev->next = a;
        a = a->next;
        curr++;
    }    
    // prev->next = a->next->next;
    struct node *temp = new node();
    temp = a;
    temp = temp->next;
    a->next = temp->next;
    free(temp);
    
    return head;
}

struct node* deleteAnywhereByValue(struct node *a, int value){
    struct node *head = a;
    struct node *prev = NULL;
    int found = 0;

    while (a != NULL) {
        if (a->data == value) {
            if (prev == nullptr)
                head = a->next;     // eitai first element
            else
                prev->next = a->next;
        
            free(a);
            found = 1;
            break;
        }
        prev = a;
        a = a->next;
    }

    if (!found)
        cout << "The given number, " << value << " doesn't exist in the list." << endl;

    return head;
}


int searchValue(struct node *a, int value){
    int rice=0;
    while(a != NULL){
        if(a->data == value){
            return rice;
        }
        rice++;
        a = a->next;
    }
    return -1;
}

void printLast(struct node *a){
    while(a->next != NULL){
        a = a->next;
    }
    cout << endl << "9) value in the last node: " << a->data << endl;
}

void printPrevLast(struct node *a){
    struct node *temp = (struct node*) malloc(sizeof(node));
    
    while(a->next != NULL){
        temp = a;
        a = a->next;
    }
    cout << endl << "10) value in the previous node of the last node: " << temp->data << endl;
}

void print(struct node *a){
    cout << a->data << " ";
    while(a->next != NULL){
        a = a->next;
        cout << a->data << " "; 
    }
    cout << endl;
}

int main() {
    struct node *root = new node();
    root = NULL;

    push_back(root,20);
    push_back(root,30);
    push_back(root,40);
    push_back(root,50);

    cout << "initially the linked list: " << endl;
    print(root);

    cout << endl << "1) after adding element in the first index: " << endl;
    root = insertFirst(root,10);
    print(root); 

    cout << endl << "2) adding element in the back: " << endl;
    insertLast(root,60);
    print(root);

    cout << endl << "3) adding element in a given index (0...length): " << endl;
    root = insertAnywhere(root,2,25);
    print(root);

    cout << endl << "4) after deleting the first element: " << endl;
    root = deleteFirst(root);
    print(root);

    cout << endl << "5) deleting the last element: " << endl;
    deleteLast(root);
    print(root);

    cout << endl << "6.1) deleting the element from a given index: " << endl;
    root = deleteAnywhereByIndex(root,2);
    print(root);

    cout << endl << "6.2) deleting a given value: " << endl;
    root = deleteAnywhereByValue(root,40);
    print(root);

    cout << endl << "7) printing the list: " << endl;
    print(root);

    cout << endl << "8) input a value to search in the list: " << endl;
    int num;
    cin >> num;
    int result = searchValue(root,num);
    if(result == -1)
        cout << "the number " << num << " doesn't exist in the list" << endl;
    else    
        cout << "the number " << num << " was found in index " << result << endl;

    printLast(root);
    printPrevLast(root);

    int len = listLength(root);
    cout << endl << "11) length of the list: " << len << endl << endl << endl;
}