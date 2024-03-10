#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

struct node* nodeCreator(int value){
    struct node* newNode = (struct node*) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push_back(struct node*& root, int value){
    struct node* newNode = nodeCreator(value);

    if(root == NULL){
        root = newNode;
        root->next = root;
        root->prev = root;
    }
    else{
        struct node* laddu = root->prev;
        laddu->next = newNode;
        newNode->prev = laddu;
        newNode->next = root;
        root->prev = newNode;
    }
}

void print(struct node *root){
    struct node* curr = root;
    do {
        //cout << curr->prev->data << " ";
        cout << curr->data << " ";
        //cout << curr->next->data << " " << endl;
        curr = curr->next;
    } while (curr != root);

    cout << endl;
}

int listLength(struct node *root){
    struct node* a = root;
    int len=0;
    if(a->next == root)
        return 0;
    else
        len++;

    while(a->next != root){
        len++;
        a = a->next;
    }

    return len;
}

struct node* insertFirst(struct node *head, int value){
    struct node *temp = (struct node*) malloc(sizeof(node));
    struct node* laddu = head->prev;
    temp->data = value;
    temp->next = head;
    head->prev = temp;
    temp->prev = laddu;
    laddu->next = temp;

    return temp;
}

void insertLast(struct node *root, int value){
    struct node *temp = (struct node*) malloc(sizeof(node));
    struct node *a = root;
    while(a->next != root){
        a = a->next;
    }
    a->next = temp;
    temp->prev = a;
    temp->data = value;
    temp->next = root;
    root->prev = temp;
}

struct node* insertAnywhere(struct node *a, int index, int value){
    int len = listLength(a);
    struct node *head = (struct node*) malloc(sizeof(node));
    head = a;

    if(index > len){
        cout << "index doesn't exist" << endl;
        return head;
    }

    if(index == len){
        insertLast(a,value);
        return head;
    }

    if(index == 0){
        head = insertFirst(a,value);
        return head;
    }

    struct node *temp = (struct node*) malloc(sizeof(node));
    struct node *b = a;
    int rice=0;

    while(rice != index-1){
        a = a->next;
        b = a->next;
        rice++;
    }
    temp->data = value;
    temp->next = b;
    b->prev = temp;
    a->next = temp;
    temp->prev = a;
    return head;
}

struct node* deleteFirst(struct node *root){
    struct node *a = root->next;
    struct node *laddu = root->prev;
    a->prev = laddu;
    laddu->next = a;
    free(root);
    return a;
}

void deleteLast(struct node *root){
    struct node *laddu = root->prev;
    struct node *prevLaddu = laddu->prev;
    prevLaddu->next = root;
    root->prev = prevLaddu;
    free (laddu);
}

struct node* deleteAnywhereByIndex(struct node *root, int index){
    int len = listLength(root);
    struct node *a = root;
    struct node *head = root;

    if(index > len-1){
        cout << "index doesn't exist" << endl;
        return head;
    }

    if(index == 0){
        head = deleteFirst(head);
        return head;
    }
    if(index == len-1){
        deleteLast(head);
        return head;
    }

    struct node *b = a->next;
    struct node *c = b->next;
    int rice=0;

    while(rice != index-1){
        // prev->next = a;
        a = a->next;
        b = a->next;
        c = b->next;
        rice++;
    }

    a->next = c;
    c->prev = a;
    free(b);

    return head;
}

struct node* deleteAnywhereByValue(struct node *a, int value){
    struct node *head = a;
    struct node *p = head->prev;
    int found = 0;

    while (a->next != head) {
        if (a->data == value) {
//            if (p == nullptr){
//                head = a->next;
//                head->prev = NULL;
//            }

            struct node *gg = a->next;
            p->next = gg;
            gg->prev = p;

            free(a);
            found = 1;
            break;
        }
        p = a;
        a = a->next;
    }

    if (!found)
        cout << "The given number, " << value << " doesn't exist in the list." << endl;

    return head;
}

int searchValue(struct node *a, int value){
    int rice=0;
    while(a->next != a){
        if(a->data == value){
            return rice;
        }
        rice++;
        a = a->next;
    }
    return -1;
}

void printLast(struct node *a){
    cout << endl << "9) value in the last node: " << a->prev->data << endl;
}

void printPrevLast(struct node *a){
    cout << endl << "10) value in the previous node of the last node: " << a->prev->prev->data << endl;
}

int main() {
    struct node *root = (struct node*) malloc(sizeof(node));
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
