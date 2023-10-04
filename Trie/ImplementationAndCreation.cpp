#include<iostream>
using namespace std;
/*
    TRIE
    1. It is a special type of Tree data structure where the node can have upto 26 childs as like 26 english alphabets.
*/
class TrieNode
{
    public: char data;
            TrieNode* children[26];
            bool isTerminal;

            TrieNode( char ch )
            {
                this->data=ch;
                isTerminal=false;
                for( int idx=0; idx<26;idx++ )
                {
                    children[idx]=NULL;
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
            void insertUtil( TrieNode* root, string word )
            {
                //base case 
                if( word.length()==0 )
                {
                    root->isTerminal=true;
                    return;
                }
                // getting the index of the first character from word
                int index = word[0]-'a';
                TrieNode* child;

                // if the char already present
                if( root->children[index] )
                {
                    child = root->children[index];       
                }
                else // absent 
                {
                    child = new TrieNode( word[0] );
                    root->children[index]=child;
                }
                //recursion
                insertUtil( child,word.substr(1) );
            }
            void insertWord( string word )
            {
                return insertUtil( root,word );
            }
            // search function
            bool SearchUtil( TrieNode* root, string word )
            {
                //base case 
                if( word.length()==0 )
                {
                    return root->isTerminal;
                }
                // getting the index of the first character from word
                int index = word[0]-'a';
                TrieNode* child;

                // if the char already present
                if( root->children[index] )
                {
                    child = root->children[index];       
                }
                else // absent 
                {
                    return false;
                }
                //recursion
                return SearchUtil( child,word.substr(1) );
            }
            bool Search( string word )
            {
                return SearchUtil( root,word );
            }
            // Deletion of a word from the Trie Dictionary 
            void DeleteUtil( TrieNode* root, string word )
            {
                //base case 
                if( word.length()==0 )
                {
                    root->isTerminal=false;
                    return;
                }
                // getting the index of the first character from word
                int index = word[0]-'a';
                TrieNode* child;

                // if the char already present
                if( root->children[index] )
                {
                    child = root->children[index];       
                }
                else // absent 
                {
                    return ;
                }
                //recursion
                DeleteUtil( child,word.substr(1) );
            }
            void Delete( string word )
            {
                return DeleteUtil( root,word );
            }
            // search Prefix in Trie
             bool SearchPrefixUtil( TrieNode* root, string word )
            {
                //base case 
                if( word.length()==0 )
                {
                    return true;
                }
                // getting the index of the first character from word
                int index = word[0]-'a';
                TrieNode* child;

                // if the char already present
                if( root->children[index] )
                {
                    child = root->children[index];       
                }
                else // absent 
                {
                    return false;
                }
                //recursion
                return SearchPrefixUtil( child,word.substr(1) );
            }
            bool SearchPrefix( string word )
            {
                return SearchPrefixUtil( root,word );
            }
};
int main() 
{
    Trie* t = new Trie();
    t->insertWord("hello");
    t->insertWord("hola");
    t->insertWord("hi");
    t->insertWord("amigo");
    t->insertWord("trie");
    cout<<"The is Presence of Prefix HELL is(1 means Yes and 0 means NO) :"<<t->SearchPrefix("hell");
    cout<<"The is Presence of word Hola is(1 means Yes and 0 means NO) :"<<t->SearchPrefix("hola");
    return 0;
}