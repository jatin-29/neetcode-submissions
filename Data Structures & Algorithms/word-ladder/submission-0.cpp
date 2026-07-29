class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Pattern Identification
        // Minimum transformation / shortest path in an unweighted graph
        // -> BFS

        // Store all words in a hash set for O(1) lookup
        unordered_set<string> dict(wordList.begin(), wordList.end());

        // If endWord doesn't exist, transformation is impossible
        if (!dict.count(endWord))
            return 0;

        // Normal BFS queue
        queue<string> q;
        q.push(beginWord);

        // Mark beginWord as visited
        dict.erase(beginWord);

        // Level = number of words in the transformation sequence
        int count = 1;

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level at a time
            for (int i = 0; i < size; i++) {

                string w = q.front();
                q.pop();

                // Reached destination
                if (w == endWord)
                    return count;

                // Try changing every character
                for (int pos = 0; pos < w.length(); pos++) {

                    char original = w[pos];

                    // Replace current character with every lowercase letter
                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == original)
                            continue;

                        w[pos] = ch;

                        // Valid next word
                        if (dict.count(w)) {

                            // Mark visited immediately
                            dict.erase(w);

                            // Push into queue for next level
                            q.push(w);
                        }
                    }

                    // Restore original character
                    w[pos] = original;
                }
            }

            // Move to next transformation level
            count++;
        }

        return 0;
    }
};