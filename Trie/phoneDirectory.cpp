#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char ch;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->ch = d;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string str)
    {
        // basec cond
        if (str.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = str[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }
        // call recursion
        insertUtil(child, str.substr(1));
    }
    void insert(string str)
    {
        insertUtil(root, str);
    }
    void printSuggestion(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            TrieNode* next = curr->children[ch-'a'];
            if(next != NULL){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string queryStr){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for(int i=0;i<queryStr.length();i++){
            char laststr = queryStr[i];
            prefix.push_back(laststr);

            //check for last char
            TrieNode* curr = prev->children[laststr - 'a'];

            //if not found
            if(curr == NULL){
                break;
            }
            //if found
            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
    
};
int main(int argc, char const *argv[])
{
    // creation of stack
    Trie* t = new Trie();
    //insert all contacts in trie
    vector<string> contactList = {"code", "coding", "coly", "coder"};
    for(int i=0;i<contactList.size();i++){
        t->insert(contactList[i]);
    }
    //return ans
    vector<vector<string>> ans;
    string queryStr = "codering";
    ans = t->getSuggestions(queryStr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
