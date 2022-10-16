#include<bits/stdc++.h>
using namespace std;

// Bottom-Up Approach
int knapsack(int w[], int v[], int W, int n){
    int t[n+1][W+1];
    // initialize first column with zero
    for(int i=0;i<=n;i++) t[i][0]=0;
    // initialize first raw with zero
    for(int j=0;j<=W;j++) t[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            // if weight of item is less than or equal to bag capacity
            if(w[i-1] <= j)
                t[i][j]= max(v[i-1]+t[i-1][j-w[i-1]],t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][W];
}

int main() {
    int w[] = {2, 3, 4, 5};
    int v[] = {3, 4, 5, 6};
    int W = 5;
    cout << "Maximum Profit: " << knapsack(w,v,W,4) << endl;
    return 0;
}
