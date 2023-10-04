#include<iostream>
#include<vector>
using namespace std;
class TrieNode
{
    public: char data;
            TrieNode* children[26];
            bool isTerminal;
            int childcount;

            TrieNode( char ch )
            {
                this->data=ch;
                isTerminal=false;
                childcount=0;
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

            Trie(char ch)
            {
                root = new TrieNode(ch);
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
                    root->childcount++;
                    root->children[index]=child;
                }
                //recursion
                insertUtil( child,word.substr(1) );
            }
            void insertWord( string word )
            {
                return insertUtil( root,word );
            }
            void lcp(string str, string &ans)
            {
                TrieNode* current = root; // Create a separate pointer for traversal
                
                // Loop to compare characters from the input string
                for (int idx = 0; idx < str.length(); idx++)
                {
                    char ch = str[idx];
                    int index = ch - 'a';
                    
                    if (current->childcount == 1)
                    {
                        ans.push_back(ch);
                        current = current->children[index]; // Move to the next TrieNode
                    }
                    else
                    {
                        break;
                    }
                    
                    if (current->isTerminal == true)
                    {
                        break;
                    }
                }
            }

};
string longestCommonPrefix(vector<string>& strs) 
{ 
    for( int idx=0; idx<strs.size();idx++)
    {
        if( strs[idx] == "" )
        {
            string ans = "";
            return ans;
        }                
    } 
    Trie *t = new Trie('\0');
    for( int idx=0; idx<strs.size();idx++)
    {
        t->insertWord(strs[idx]);
    }    
    string firstword = strs[0];
    string ans="";
    t->lcp( firstword, ans );
    return ans;
}
int main()
{
    vector<string> strings{"flower","flow","flight"};
    string ans="";
    ans = longestCommonPrefix( strings );
    cout<<"The Longest common Prefix in the given arrays is: "<<ans<<endl;
    return 0;
}
