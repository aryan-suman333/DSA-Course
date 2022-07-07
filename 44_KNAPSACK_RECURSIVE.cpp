#include <bits/stdc++.h>

using namespace std;

int memoize(vector <vector<int>>& dp,vector <vector<int>> v,int n,int w){
    if(!n || !w)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(v[n-1][0] <= w)
        return dp[n][w] = max(v[n-1][1] + memoize(dp,v,n-1,w-v[n-1][0]),memoize(dp,v,n-1,w));
    // unbounded knapsack
    // return dp[n][w] = max(v[n-1][1] + memoize(dp,v,n,w-v[n-1][0]),memoize(dp,v,n-1,w));
    return dp[n][w] = memoize(dp,v,n-1,w);
}

int main(){
    int n,w;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter weight: ";
    cin>>w;
    cout<<"Enter elements weight and value: ";
    vector <vector<int>> v(n,vector <int>(2));
    for(int i = 0;i < n;i++){
        int e1,e2;
        cin>>e1>>e2;
        v[i][0] = e1;
        v[i][1] = e2;
    }
    vector <vector<int>> dp(n+1,vector <int>(w+1,-1));
    memoize(dp,v,n,w);
    cout<<"Maximum value: "<<dp[n][w];
    return 0;
}