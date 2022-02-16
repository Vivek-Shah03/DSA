#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head, *tail = NULL;

void insert_at_front(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(head == NULL) {
        head = tail = newNode;
        head->previous = NULL;
        tail->next = NULL;
    }
    else {
        head->previous = newNode;
        newNode->next = head;
        newNode->previous = NULL;
        head = newNode;
    }
}

void insert_at_end(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(head == NULL) {
        head = tail = newNode;
        head->previous = NULL;
        tail->next = NULL;
    }
    else {
        tail->next = newNode;
        newNode->previous = tail;
        newNode->next = NULL;
        tail = newNode;
    }
}

void display() {
    struct node *current = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void backward_traversal(){
    struct node *current = tail;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->previous;
    }
    printf("\n");
}

void search_data(int x){
    struct node* temp = head;
    while(temp != NULL){
        if(temp->data == x){
            printf("%d Found in DLL.\n",x);
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
            printf("%d not found in DLL.\n",x);
        }
}

void delete_data(int x){
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->data == x){
            if(head == tail){
                head = NULL;
                tail = NULL;
                return;
            }
        head = head->next;
        head->previous = NULL;
        return;
    }
    if(tail->data == x){
        tail = tail->previous;
        tail->next = NULL;
        return;
    }
    struct node* temp = head;
    while(temp != NULL){
        if(temp->data == x){
            (temp->previous)->next = temp->next;
            (temp->next)->previous = temp->previous;
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
            printf("%d not found in DLL.\n",x);
        }
}

int main() {
    printf("1. INSERT AT FRONT\n");
    printf("2. INSERT AT END\n");
    printf("3. FORWARD TRAVERSAL\n");
    printf("4. BACKWARD TRAVERSAL\n");
    printf("5. SEARCH ELEMENT\n");
    printf("6. DELETE ELEMENT\n");
    printf("7. Exit\n");
    int choice,data;
    while(1){
        printf("\n----------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
    case 1:
        printf("Enter Data : ");
        scanf("%d",&data);
        insert_at_front(data);
        break;
    case 2:
        printf("Enter Data : ");
        scanf("%d",&data);
        insert_at_end(data);
        break;
    case 3:
        printf("Forward Traversal : ");
        display();
        break;
    case 4:
        printf("Backward Traversal : ");
        backward_traversal();
        break;
    case 5:
        printf("Enter Data : ");
        scanf("%d",&data);
        search_data(data);
        break;
    case 6:
        printf("Enter Data : ");
        scanf("%d",&data);
        delete_data(data);
        break;
    case 7:
        exit(0);
        }
    }
    return 0;
}
