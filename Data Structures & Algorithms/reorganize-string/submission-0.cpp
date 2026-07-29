class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        // Frequency map
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;

            // If any character occurs more than ceil(n/2),
            // reorganization is impossible.
            if (freq[c] > (n + 1) / 2)
                return "";
        }

        // Max Heap -> {frequency, character}
        priority_queue<pair<int, char>> maxHeap;

        for (auto yoyo : freq) {
            maxHeap.push({yoyo.second, yoyo.first});
        }

        // ❌ Your code: string result = " ";
        // ✔ Correct: start with an empty string.
        string result = "";

        // ❌ Your code: {-1,'#'}
        // ✔ Better to initialize with 0 frequency.
        pair<int, char> block = {0, '#'};

        while (!maxHeap.empty()) {

            // Character with maximum remaining frequency
            auto current = maxHeap.top();
            maxHeap.pop();

            // Put it into answer
            result += current.second;

            // One occurrence has been used
            current.first--;

            // Push the previously blocked character back
            // only if it still has some frequency left.
            if (block.first > 0) {
                maxHeap.push(block);
            }

            // Current character becomes blocked.
            // It cannot be used in the next iteration.
            block = current;
        }

        // Safety check
        if (result.size() != n)
            return "";

        return result;
    }
};