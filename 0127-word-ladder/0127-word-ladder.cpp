class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // sabse pehle wordlist ko set mei daal do 
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // agr end word ho hi na dict mei to return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<pair<string,int>> q; // current word aur uske liye steps 
        q.push({beginWord, 1});
        wordSet.erase(beginWord); // beginWord ko bhi mark visited kar do

        while (!q.empty()) {
            auto [word, steps] = q.front(); 
            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {   // FIX 1: i < word.size()
                // har position pr letter badal do 
                char originalChar = word[i];

                for (char c = 'a'; c <= 'z'; c++) {    // FIX 2: c <= 'z'
                    if (c == originalChar) continue; // kyoki replace ka fayda nhi 

                    word[i] = c;

                    // so naya word bana, agr dict mei hai to neighbor hai 
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, steps + 1});
                        wordSet.erase(word); // mark visited 
                    }
                }

                word[i] = originalChar; // position ko vapis originalChar pr restore krdo 
            }
        }
        return 0;
    }
};