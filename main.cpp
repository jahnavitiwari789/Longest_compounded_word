#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

class Node {
    Node *child[26];
    bool flag = false;
    public:
    bool haveKey(char ch) {
        return (child[ch - 'a'] != NULL);  //checking whether it contains the reference or not
    }
    void put(char ch, Node *node) {
        child[ch - 'a'] = node;     //Setting up the reference
    }
    Node *get(char ch) {
        return child[ch - 'a'];   //Returning the reference
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;  //checking whether the word is completed or not
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        //creating new obejct
        root = new Node();
    }

    void insert(string word) {
        //initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->haveKey(word[i])) {
                node->put(word[i], new Node());
            }
            //moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->haveKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string s) {
        Node* node = root;
        for (int i = 0; i < s.size(); i++) {
            if (!node->haveKey(s[i])) {
                return false;
            }
            node = node->get(s[i]);
        }
        return true;
    }

    vector<int> suffices(string s)
    {
        vector<int>ans;
        Node *node=root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->haveKey(s[i]))
            return ans;

            node=node->get(s[i]);
            if(node->isEnd())
            ans.push_back(i+1);
        }

        return ans;
    }
};

int main()
{
    auto start= chrono::steady_clock::now();
    vector<string> res;

    #ifndef ONLINE_JUDGE    
        freopen("Input_01.txt", "r", stdin);
        // freopen("Input_02.txt", "r", stdin);
    #endif

    string str;
    while(cin>>str){
        res.push_back(str);
    }
    Trie trie;
    for(int i=0;i<res.size();i++)
    {
        trie.insert(res[i]);
    }

       queue<pair<string,string>> q;
      for(int i=0;i<res.size();i++)
      {
          string word=res[i];
          vector<int> suffix=trie.suffices(word);

          for(auto j:suffix)
          {
              if(j>=word.size())
              break;

              string temp=word.substr(j);
              q.push({word,temp});
          }
      }

      int max_len=0;
      string longest="";
      string second_longest="";


      while(!q.empty())
      {
          auto it=q.front();
          q.pop();
          string original=it.first;
          string suff=it.second;

          vector<int>index=trie.suffices(suff);

          if(index.size()==0)
          continue;

          for(auto j:index)
          {
              if(j>suff.size())
              break;

              if(j==suff.size())
              {
                  if(original.size()>max_len)
                  {
                      max_len=original.size();
                      second_longest=longest;
                      longest=original;
                  }
              }

              else
              {
                   string temp=suff.substr(j);
                   q.push({original,temp});
              }
          }
      }

      auto end= chrono::steady_clock::now();
      auto duration = duration_cast<milliseconds>(end-start);
      cout<<"Longest Compound Word in  given Input File "<<longest<<endl;
      cout<<"Second Longest Compound Word in given Input File "<<second_longest<<endl;
      cout<<"Time taken to process the given file "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" milliseconds";

    return 0;
}
