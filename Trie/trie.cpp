#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    //Insertion Code

    void insertutil(TrieNode* root, string str){
        //base case
        if(str.length() == 0){
            root->isTerminal = true;
            return;
        }
        //assumption word will be in small
        int index = str[0]-'a';
        TrieNode* child;
        //element is present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //element absent
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }
        //Call recursion
        insertutil(child, str.substr(1));
    }
    void insertWord(string str){
        insertutil(root, str);
    }

    //Search Code

    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0]-'a';
        TrieNode* child;
        //element is present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }
        //call recursion
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root, word);
    }
    bool isEmpty(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL)return false;
        }
        return true;
    }
    void deleteUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = false;
            if(isEmpty(root)){
                delete root;
                root = NULL;
            }
            return;
        }
        // assuming all nodes are true;
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }
        //call recursion
        deleteUtil(child, word.substr(1));

    }
    void deleteWord(string word){
        deleteUtil(root, word);
    }

};
int main(){
    Trie* t = new Trie();
    t->insertWord("sagarr");
    t->insertWord("sagar");
    t->insertWord("mayur");
    t->insertWord("mayreoe");
    t->insertWord("vardya");
    t->insertWord("vardi");
    t->insertWord("chaitya");
    t->insertWord("chaiti");
    cout<<"The String is: "<<t->searchWord("sagar")<<endl;
    cout<<"The String is: "<<t->searchWord("vardy")<<endl;
    cout<<"The String is: "<<t->searchWord("mayreoe")<<endl;
    cout<<"The String is: "<<t->searchWord("chaiti")<<endl;
    t->deleteWord("sagar");
    cout<<"The String is: "<<t->searchWord("sagar")<<endl;
    return 0;
}