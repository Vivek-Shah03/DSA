#include<stdio.h>
int top = -1;
int s[5];
void push(int x){
    if(top == 4){
        printf("Stack Overflow");
        return;
    }
    top++;
    s[top]=x;
}

int pop(){
    if(top==-1){
        printf("Stack Underflow");
        return -1;
    }
    top--;
    return s[top+1];
}

void display(){
    if(top==-1){
        printf("Stack Underflow");
        return;
    }
printf("Stack Elements are :\n");
for(int i=0;i<=top;i++){
    printf("%d\n",s[i]);
}
}

void main(){
    int ch,x;
    printf("Enter choice:\n1.push\n2.pop\n3.display\n4.Exit\n");
    while(1){
        printf("Enter choice: ");
    scanf("%d",&ch);
    switch(ch){
case 1:
    printf("Enter data : ");
    scanf("%d",&x);
    push(x);
    break;
case 2:
    printf("Deleted Element: %d\n",pop());
    break;
case 3:
    display();
    break;
case 4:
    exit(0);
    }
    }
}
