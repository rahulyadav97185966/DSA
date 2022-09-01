#include <bits/stdc++.h>
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
    bool isSingleChild(TrieNode *root)
    {
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
                count++;
        }
        if (count > 1)
            return false;
        return true;
    }
    void searchUtil(TrieNode *root, string &ans, string min_str)
    {
        // base cond
        if (min_str.length() == 0)
        {
            return;
        }
        int index = min_str[0] - 'a';
        TrieNode *child;
        if (isSingleChild(root))
        {
            ans += min_str[0];
            child = root->children[index];
        }
        else
        {
            return;
        }
        // call recursion
        searchUtil(child, ans, min_str.substr(1));
    }
    void search(string &ans, string min_str)
    {
        searchUtil(root, ans, min_str);
    }
};
int main()
{

    vector<string> strs = {"flower", "flow", "floght"};
    string minStr = "";
    int minlength = INT_MAX;
    Trie *t = new Trie();
    string ans = "";
    for (int i = 0; i < strs.size(); i++)
    {
        t->insert(strs[i]);
        if (strs[i].length() == 0){
            cout<<""<<endl;
            return 0;
        }
        if (strs[i].length() < minlength)
        {
            minlength = strs[i].length();
            minStr = strs[i];
        }
    }
    t->search(ans, minStr);
    cout<<ans<<endl;
    return 0;
}