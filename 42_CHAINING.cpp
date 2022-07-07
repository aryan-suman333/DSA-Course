#include <iostream>

using namespace std;

struct node{
	int data;
	node * next;
};

void HTtraversal(node * H[])
{
    for(int i = 0; i < 10; i++)
    {
        while(H[i] != NULL)
        {
            cout<<H[i]->data<<" ";
            H[i] = H[i]->next;
        }
        cout<<endl;
    }
}

void SortedInsert(node ** h, int x)
{
    node * q = NULL, *p = *h;
    node * t = new node;       // new node
    t->data = x;
    t->next = NULL;

    if(*h == NULL) // agar index null h to direct t ko link krdo
        *h = t;
    else
    {
        while(p && p->data < x) // jab tak p data se ek bde p na aa jaaye
        {
            q = p;              // data se ek chote p q
            p = p->next;
        }

        if(p == *h)       // agar p 1st link p hi ruk jaaye
        {
            t->next = *h;
            *h = t;
        }

        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

node * search(node * p, int key) // linear search in ll
{
    while(p != NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

int hashfunc(int key)
{
    return key % 10; // key % size
}

void insert(node * H[], int key)
{
    int index = hashfunc(key);
    SortedInsert(&H[index], key);
}

int main()
{
    node * HT[10]; // hash table(array) of type ll
    node * temp;
    int i;

    for(i = 0; i < 10; i++)
        HT[i] = NULL;       // initialize by NULL

    insert(HT, 10);
    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    insert(HT, 37);
    insert(HT, 84);
    insert(HT, 95);
    insert(HT, 78);
    insert(HT, 11);
    insert(HT, 66);
    insert(HT, 57);

    HTtraversal(HT);

    temp = search(HT[hashfunc(57)], 57);
    cout<<temp;

    return 0;
}