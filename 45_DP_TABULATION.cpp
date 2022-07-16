#include <bits/stdc++.h>

using namespace std;

// In LCS weight and value will be replaced by string sizes
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
    vector <vector<int>> dp(n+1,vector <int>(w+1,0));
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < w+1;j++){
            if(v[i-1][0] <= j)
                dp[i][j] = max(v[i-1][1]+dp[i-1][j-v[i-1][0]],dp[i-1][j]);
            // unbounded knapsack
            // dp[i][j] = max(v[i-1][1]+dp[i][j-v[i-1][0]],dp[i-1][j]);
            // LCS
            // dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j];
            // LCS 
            // dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<"Maximum value: "<<dp[n][w];
    return 0;
}