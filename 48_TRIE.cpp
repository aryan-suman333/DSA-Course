#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* links[26];
    bool end = false;
    int cntendWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch){
        links[ch-'a'] = new Node();
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node = node->get(word[i]);
            node->cntPrefix++;
        }
        node->end = true;
        node->cntendWith++;
    }
    bool search(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->end;
    }
    bool startsWith(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
    int cntWordsEqualto(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->cntendWith;
    }
    int cntWordsStartWith(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->cntPrefix;
    }
    void erase(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node = node->get(word[i]);
            node->cntPrefix--;
        }
        node->cntendWith--;
    }
};

int main(){
    Trie node;
    node.insert("apple");
    node.insert("apps");
    node.insert("bat");
    node.insert("battle");

    if(node.search("apple")) cout<<"EXISTS"<<endl;
    else cout<<"DON'T EXIST"<<endl;
    if(node.startsWith("batl")) cout<<"EXISTS"<<endl;
    else cout<<"DON'T EXIST"<<endl;

    node.insert("batling");
    if(node.startsWith("batl")) cout<<"EXISTS"<<endl;
    else cout<<"DON'T EXIST"<<endl;

    node.insert("apple");
    node.insert("apps");

    cout<<node.cntWordsEqualto("apple")<<endl;
    cout<<node.cntWordsStartWith("app")<<endl;

    cout<<node.cntWordsStartWith("bat")<<endl;
    node.erase("battle");
    cout<<node.cntWordsStartWith("bat")<<endl;
    return 0;
}