#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
public:
    vector <int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionRank(int u,int v){
        int up = findUPar(u);
        int vp = findUPar(v);
        if(up == vp) return;
        if(rank[up] < rank[vp]){
            parent[up] = vp;
        }
        else if(rank[vp] < rank[up]){
            parent[vp] = up;
        }
        else{
            parent[up] = vp;
            rank[vp]++;
        }
    }
    void unionSize(int u,int v){
        int up = findUPar(u);
        int vp = findUPar(v);
        if(up == vp) return;
        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};

int main(){
    DisjointSet ds(7);
    // ds.unionRank(1,2);
    // ds.unionRank(2,3);
    // ds.unionRank(4,5);
    // ds.unionRank(6,7);
    // ds.unionRank(5,6);
    // if(ds.findUPar(3) == ds.findUPar(7)){
    //     cout<<"Same"<<endl;
    // }
    // else cout<<"Not Same"<<endl;
    // ds.unionRank(3,7);
    // if(ds.findUPar(3) == ds.findUPar(7)){
    //     cout<<"Same"<<endl;
    // }
    // else cout<<"Not Same"<<endl;

    ds.unionSize(1,2);
    ds.unionSize(2,3);
    ds.unionSize(4,5);
    ds.unionSize(6,7);
    ds.unionSize(5,6);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same"<<endl;
    }
    else cout<<"Not Same"<<endl;
    ds.unionSize(3,7);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same"<<endl;
    }
    else cout<<"Not Same"<<endl;
    return 0;
}