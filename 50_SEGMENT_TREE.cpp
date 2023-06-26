#include <bits/stdc++.h>
using namespace std;

vector <int> arr(100000),stMax(4*100000),stSum(4*100000),lazyMax(4*100000),lazySum(4*100000);

void buildMax(int idx,int low,int high){
    if(low == high){
        stMax[idx] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    buildMax(2*idx+1,low,mid);
    buildMax(2*idx+2,mid+1,high);
    stMax[idx] = max(stMax[2*idx+1],stMax[2*idx+2]);
}

int queryMax(int idx,int l,int r,int low,int high){
    if(lazyMax[idx]){
        stMax[idx] += lazyMax[idx];
        if(low != high){
            lazyMax[2*idx+1] += lazyMax[idx];
            lazyMax[2*idx+2] += lazyMax[idx];
        }
        lazyMax[idx] = 0;
    }
    if(l > high || r < low){
        return INT_MIN;
    }
    if(l <= low && r >= high){
        return stMax[idx];
    }
    int mid = (low+high)/2;
    int left = queryMax(2*idx+1,l,r,low,mid);
    int right = queryMax(2*idx+2,l,r,mid+1,high);
    return max(left,right);
}
void buildSum(int idx,int low,int high){
    if(low == high){
        stSum[idx] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    buildSum(2*idx+1,low,mid);
    buildSum(2*idx+2,mid+1,high);
    stSum[idx] = stSum[2*idx+1]+stSum[2*idx+2];
}

int querySum(int idx,int l,int r,int low,int high){
    if(lazySum[idx]){
        stSum[idx] += (high-low+1)*lazySum[idx];
        if(low != high){
            lazySum[2*idx+1] += lazySum[idx];
            lazySum[2*idx+2] += lazySum[idx];
        }
        lazySum[idx] = 0;
    }
    if(l > high || r < low || low > high){
        return 0;
    }
    if(l <= low && r >= high){
        return stSum[idx];
    }
    int mid = (low+high)/2;
    int left = querySum(2*idx+1,l,r,low,mid);
    int right = querySum(2*idx+2,l,r,mid+1,high);
    return left+right;
}

void pointUpdate(int idx,int node,int val,int low,int high){
    if(low == high){
        arr[node] += val;
        stMax[idx] += val;
        stSum[idx] += val;
    }
    else{
        int mid = (low+high)/2;
        if(node >= low && node <= mid){
            pointUpdate(2*idx+1,node,val,low,mid);
        }
        else{
            pointUpdate(2*idx+2,node,val,mid+1,high);
        }
        stMax[idx] = max(stMax[2*idx+1],stMax[2*idx+2]);
        stSum[idx] = stSum[2*idx+1]+stSum[2*idx+2];
    }
}

void rangeUpdate(int idx,int l,int r,int val,int low,int high){
    if(lazySum[idx]){
        cout<<low<<high<<endl;
        stSum[idx] += (high-low+1)*lazySum[idx];
        stMax[idx] += lazyMax[idx];
        if(low != high){
            lazySum[2*idx+1] += lazySum[idx];
            lazySum[2*idx+2] += lazySum[idx];
            lazyMax[2*idx+1] += lazyMax[idx];
            lazyMax[2*idx+2] += lazyMax[idx];
        }
        lazySum[idx] = 0;
        lazyMax[idx] = 0;
    }
    if(l > high || r < low || low > high){
        return;
    }
    if(l <= low && r >= high){
        stSum[idx] += (high-low+1)*val;
        stMax[idx] += val;
        if(low != high){
            lazySum[2*idx+1] += val;
            lazySum[2*idx+2] += val;
            lazyMax[2*idx+1] += val;
            lazyMax[2*idx+2] += val;
        }
        return;
    }
    int mid = (low+high)/2;
    rangeUpdate(2*idx+1,l,r,val,low,mid);
    rangeUpdate(2*idx+2,l,r,val,mid+1,high);
    stMax[idx] = max(stMax[2*idx+1],stMax[2*idx+2]);
    stSum[idx] = stSum[2*idx+1]+stSum[2*idx+2];
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    buildMax(0,0,n-1);
    buildSum(0,0,n-1);

    int q;
    cout<<"Enter q: ";
    cin>>q;
    pointUpdate(0,2,7,0,n-1);
    rangeUpdate(0,3,6,1,0,n-1);
    vector <int> ans;
    for(int i = 0;i < q;i++){
        int l,r;
        cin>>l>>r;
        cout<<queryMax(0,l,r,0,n-1)<<endl;
        cout<<querySum(0,l,r,0,n-1)<<endl;
    }
    return 0;
}