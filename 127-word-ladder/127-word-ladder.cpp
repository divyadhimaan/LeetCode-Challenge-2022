class Solution {
public:
    bool is_adj(string &mp1, string &mp2) {   
        
        int i = mp1.size();

        // loop will break when found first different character
        while(i >= 0 && mp1[i] == mp2[i]) i--; 
        
        i--; //skip that index [as it conatiner different character]
        
        // if it break on second condition, that means we have more than two different character
        while(i >= 0 && mp1[i] == mp2[i]) i--; 
        
        //i == - 1, only when second loop breaks at first condition.
        //It is also sure that first loop will never break at first condition, as all strings are unique
        return i == -1;
        
    }    
    
    int ladderLength(string beginWord, string endWord, vector<string>& given_wordList) {
        int sol = 1; //because beginWord will always get counted
        unordered_set<string> queue;
        unordered_set<string> wordList;
        
        for (int i = 0; i < given_wordList.size(); i++) {
            wordList.insert(given_wordList[i]); //converting in unordered_set, becuse they are fast for looking for a value and also to easre the visited strings
        }  
        
        queue.insert(beginWord);
        
        
        //BFS
        while (queue.size() != 0) {
            unordered_set<string> temp;
            for (auto y : queue) {
                for (auto x : wordList) {
                    if (is_adj(y, x)) {
                        if (x == endWord) return sol + 1;
                        temp.insert(x);
                    }
                }
            }
            queue.clear();
            queue = temp;
            
            //erase the visited string from the wordList
            for (auto x : queue) { 
                wordList.erase(x);
            }
            sol++;
        }
        
        return 0;
    }
};