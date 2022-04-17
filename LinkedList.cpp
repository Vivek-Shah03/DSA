#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

void insert_at_end_ll(int x){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    node* save = head;
    //if linked list is empty
    if(head == NULL){
        head = newNode;
    }else{
            while(save->next != NULL){
            save = save->next;
            }
            save->next = newNode;
    }
}

void insert_at_front_ll(int x){
 struct node *newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = x;
 newnode->next = NULL;
 if(head != NULL){
    newnode->next = head;
 }
 head = newnode;
}

void print_ll(){
struct node *current = head;
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }
    while(current != NULL) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << endl;
}

void delete_data_in_ll(int x)
{
    if(head == NULL){
        cout << "Linked List is Empty\n";
    }else{
        // If value at head is same as x
        if(head->data == x){
            head = head->next;
        }else{
            node* save = head;
            while(save->next!=NULL)
            {
                if(save->next->data == x)
                {
                    save->next = save->next->next;
                    return;
                }
                save = save->next;
            }
            if(save->next == NULL){
                cout << x << " is not available in linkedlist.\n";
            }
        }
    }
}

main()
{
    insert_at_end_ll(10);
    insert_at_end_ll(20);
    insert_at_end_ll(30);
    insert_at_front_ll(0);
    print_ll();
    delete_data_in_ll(50);
    print_ll();

    return 0;
}
