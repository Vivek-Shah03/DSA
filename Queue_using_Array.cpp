#include<iostream>
using namespace std;
#define N 5
int q[N];
int rear_p=-1,front_p=-1;
void enqueue(int data)
{
    if(rear_p == N-1){
        cout << "Queue Overflow\n";
    }
    else
    {
        rear_p++;
        q[rear_p] = data;
        if(front_p == -1)
        {
            front_p = 0;
        }
    }
}
int dequeue()
{
    if(front_p == -1)
    {
        cout << "Queue Underflow\n";
        return -1;
    }
    else
    {
        int temp = q[front_p];
        if(front_p == rear_p)
        {
            front_p = rear_p = -1;
        }
        else
        {
            front_p++;
        }
        return temp;
    }
}
int main()
{
    int choice,data;
    cout << "1.Enqueue\n2.Dequeue\n3.Exit\n";
    while(1)
    {
        cout<< "Enter Your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cin >> data;
            enqueue(data);
            break;
        case 2:
            cout << dequeue() << endl;
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}
