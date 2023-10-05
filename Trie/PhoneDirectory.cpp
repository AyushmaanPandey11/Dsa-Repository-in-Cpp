#include <bits/stdc++.h>
#include <iostream>  
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        isTerminal = false;
        for (int idx = 0; idx < 26; idx++)
        {
            children[idx] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    // insertion function
    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // getting the index of the first character from word
        int index = word[0] - 'a';
        TrieNode* child;

        // if the char is already present
        if (root->children[index])
        {
            child = root->children[index];
        }
        else // absent
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string& prefix)
    {
        // base case
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string qstr)
    {
        TrieNode* prev = root;
        string prefix = "";
        vector<vector<string>> output;

        for (int idx = 0; idx < qstr.length(); idx++)
        {
            char lastchar = qstr[idx];
            prefix.push_back(lastchar);

            // going forward
            TrieNode* curr = prev->children[lastchar - 'a'];
            if (curr == NULL)
            {
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr)
{
    Trie* t = new Trie();
    for (int idx = 0; idx < contactList.size(); idx++)
    {
        string str = contactList[idx];
        t->insertWord(str);
    }
    return t->getSuggestions(queryStr);
}

int main()
{
    vector<string> contactlist {"cod", "coding", "codding", "code", "coly"};
    string querystr = "coding";

    vector<vector<string>> ans = phoneDirectory(contactlist, querystr);
    
    for (const vector<string>& suggestions : ans)
    {
        for (const string& suggestion : suggestions)
        {
            cout << suggestion << " ";
        }
        cout << endl;
    }
    
    return 0;
}
