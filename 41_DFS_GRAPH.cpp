#include<iostream>

using namespace std;

//DFS Implementation
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int a[7][7] = { // adjcancy matrix representation
    {0, 1, 1, 1, 0, 0, 0},    //  0--1
    {1, 0, 0, 1, 0, 0, 0},    //  | \|
    {1, 0, 0, 1, 1, 0, 0},    //  2--3
    {1, 1, 1, 0, 1, 0, 0},    //   \/
    {0, 0, 1, 1, 0, 1, 1},    //   4
    {0, 0, 0, 0, 1, 0, 0},    /*  / \   */
    {0, 0, 0, 0, 1, 0, 0},    // 5   6
};

void DFS(int i){
    cout<<i;
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(a[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}

int main(){
    DFS(4); // jis node se start krna ho
    return 0;
}