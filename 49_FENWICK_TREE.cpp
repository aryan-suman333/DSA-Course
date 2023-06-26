#include <bits/stdc++.h>
using namespace std;

class BIT{// 1 based indexing
    vector<int> ft;
public:
    BIT(int size=0) {
        ft.assign(size + 1, 0);
    }
    int getSum(int idx) { // 1 to idx inclusive
        int sum = 0;
        for (; idx > 0; idx &= idx-1)
            sum += ft[idx];
        return sum;
    }
    void addValue(int idx, int val) {
        for (; idx < ft.size(); idx += idx & (-idx))
            ft[idx] += val;
    }
    int lowerBound(int k){
        int curr = 0,prevsum = 0;
        for(int i = log2(ft.size()-1);i >= 0;i--){
            if(ft[curr+(1<<i)] + prevsum < k){
                curr += 1<<i;
                prevsum += ft[curr];
            }
        }
        return curr; // 1 based indexing isliye +1 nhi krna
    }
};

class Operations{
public:
    BIT bit;
    vector <int> v;
    Operations(vector <int> &nums){
        bit = BIT(nums.size());
        v = nums;
        for(int i = 0;i < nums.size();i++){
            bit.addValue(i+1,nums[i]);
        }
    }
    void update(int idx,int val){
        int difference = val-v[idx];
        bit.addValue(idx+1,difference);
        v[idx] = val;
    }
    int sumRange(int l,int r){
        return bit.getSum(r+1)-bit.getSum(l);
    }
    int findLB(int k){
        return bit.lowerBound(k);
    }
};

int main(){
    vector <int> v = {3,7,0,2,5,9,8,1,0,1,4,5,3,8,9,8};
    Operations op(v);

    cout<<op.sumRange(0,7)<<endl;
    op.update(0,0);
    cout<<op.sumRange(0,7)<<endl;

    cout<<op.sumRange(5,10)<<endl;
    op.update(7,6);
    cout<<op.sumRange(5,10)<<endl;

    cout<<op.sumRange(10,15)<<endl;
    op.update(14,1);
    cout<<op.sumRange(10,15)<<endl;

    cout<<op.findLB(8)<<endl;
    op.update(2,1);
    cout<<op.findLB(8)<<endl;
    return 0;
}