#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX;
int mcm(vector <int> v,int i, int j,vector <vector<int>>& dp){
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    for(int k = i;k < j;k++){
        int temp = mcm(v,i,k,dp)+mcm(v,k+1,j,dp)+v[i-1]*v[k]*v[j];
        ans = min(ans,temp);
    }
    return dp[i][j] = ans;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter elements: ";
    vector <int> v(n);
    for(int i = 0;i < n;i++){
        int e;
        cin>>e;
        v[i] = e;
    }
    vector <vector<int>> dp(n+1,vector <int>(n+1,-1));
    cout<<mcm(v,1,n-1,dp);
    return 0;
}