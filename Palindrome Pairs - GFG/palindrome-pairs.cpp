// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Trie{
    public:
    Trie* children[26];
    int index;
    bool isEnd;
};
Trie *createNode(){
    Trie* node = new Trie();
    for(int i=0; i<26; i++){
        node->children[i] = nullptr;
    }
    node->index = -1;
    node->isEnd = false;
    return node;
}
void insert(Trie *&root,string s,int index){
    if(root == nullptr){
        root = createNode();
    }
    Trie *curr = root;
    for(int i=0; i<(int)s.size(); i++){
        int idx = s[i]-'a';
        if(curr->children[idx] == nullptr){
            curr->children[idx] = createNode();
            curr = curr->children[idx];
        }
        else{
            curr = curr->children[idx];
        }
    }
    curr->isEnd = true;
    curr->index = index;//change even duplicates occur
}
bool search(Trie* root,string s,int index){
    Trie *curr = root;
    if(curr == nullptr){
        return false;
    }
    for(int i=0; i<(int)s.size(); i++){
        int idx = s[i]-'a';
        if(curr->children[idx] == nullptr){
            return false;
        }
        else{
            curr = curr->children[idx];
        }
    }
    if(curr->isEnd == true){
        return curr->index != index;
    }
    else{
        return false;
    }
}

class Solution{   
  public:
    bool isPalindrome(string s){
        int n = s.size();
        int i=0,j=n-1;
        while(i < j && s[i] == s[j]){
            i += 1;
            j -= 1;
        }
        return (i>=j);
    }
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        // we can use Trie for searching a string 
        // at each termination we need to store index of occurence during insertion
        Trie *root = nullptr;
        for(int i=0; i<N; i++){
            string s = arr[i];
            reverse(s.begin(),s.end());
            // root = insert(root,s,i);
            insert(root,s,i);
        }
        for(int i=0; i<N; i++){
            int m = arr[i].size();
            for(int j=0; j<m; j++){
                string s1 = arr[i].substr(0,j);
                string s2 = arr[i].substr(j);
                
                
                if(isPalindrome(s1) && search(root,s2,i)){
                    //added at left to make palidrome
                    return true;
                }
                if(isPalindrome(s2) && search(root,s1,i)){
                    // added at right to make palindrome
                    return true;
                }
            }
        }
        return false;
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends