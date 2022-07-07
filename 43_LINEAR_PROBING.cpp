#include <iostream>

using namespace std;

// quadratic probing m index + i ki jgh sab jgh index = i*i likhna h

void HTtraversal(int H[])
{
    for(int i = 0; i < 10; i++)
        cout<<H[i]<<" ";
    cout<<endl;
}

int hashfunc(int key)
{
    return key % 10;
}

int probe(int H[], int key)
{
    int index = hashfunc(key);
    int i = 0;

    while(H[(index + i) % 10] != 0) // jab tk khali jgh nhi milti
        i++;
    return (index + i) % 10;
}

void insert(int H[], int key)
{
    int index = hashfunc(key);

    if(H[index] != 0)    // agar index khali nhi h to next khali jgh dhundo
        index = probe(H, key);
    H[index] = key;
}

int search(int H[], int key)
{
    int index = hashfunc(key);
    int i = 0;

    while(H[(index + i) % 10] != key)
    {
        if(i == 10) // key present na ho to
            return -1;
        i++;
    }
    return (index + i) % 10;
}

int main()
{
    int HT[10] = {0}; // 10 size h to 5 se jyada insert nhi krne so that lambda <= 0.5
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);
    HTtraversal(HT);

    cout<<"Key found at: "<<search(HT, 2)<<endl;
    cout<<"Key found at: "<<search(HT, 26);
    return 0;
}