#include<bits/stdc++.h>
using namespace std;

int dp[10][10];

int knapsack(int w[], int v[], int W, int n){
    // if bag capacity is zero or if we don't have any item
    if(W==0 || n == 0){
        return 0;
    }
    // if we already have the value of below recursive calls
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    // if weight of item is less than or equal to bag capacity
    if(w[n-1] <= W){
        // maximum of if we add curruntly selected item in knapsack or don't add
        dp[n][W] = max(v[n-1]+knapsack(w,v,W-w[n-1],n-1),knapsack(w,v,W,n-1));
        return dp[n][W];
    }
    // if weight of item is greater than capacity
    else if(w[n-1] > W){
        dp[n][W] = knapsack(w,v,W,n-1);
        return dp[n][W];
    }
}
int main() {
    // initialize dp with -1
    memset(dp, -1, sizeof dp);
    // weight of items
    int w[] = {2, 3, 4, 5};
    // value of items
    int v[] = {3, 4, 5, 6};
    // total capacity of knapsack
    int W = 5;
    cout << "Maximum Profit: " << knapsack(w,v,W,4) << endl;
    return 0;
}
