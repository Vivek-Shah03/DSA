#include <iostream>
#include<algorithm>
using namespace std;

int knapsack(int w[], int v[], int W, int n){
    // if bag capacity is zero or if we don't have any item
    if(W==0 || n == 0){
        return 0;
    }
    // if weight of item is less than or equal to bag capacity
    if(w[n-1] <= W){
        // maximum of if we add curruntly selected item in knapsack or don't add
        return max(v[n-1]+knapsack(w,v,W-w[n-1],n-1),knapsack(w,v,W,n-1));
    }
    // if weight of item is greater than capacity
    else if(w[n-1] > W){
        return knapsack(w,v,W,n-1);
    }
}
int main() {
    // weight of items
    int w[] = {2, 3, 4, 5};
    // value of items
    int v[] = {3, 4, 5, 6};
    // total capacity of knapsack
    int W = 5;
    cout << "Maximum Profit: " << knapsack(w,v,W,4) << endl;
    return 0;
}
