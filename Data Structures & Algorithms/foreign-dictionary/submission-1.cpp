class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;

        // Add all characters
        for(string& w : words) {
            for(char c : w) {
                indeg[c] = 0;
            }
        }

        // Build graph
        for(int i = 0; i + 1 < words.size(); i++) {

            string& a = words[i];
            string& b = words[i + 1];

            int len = min(a.size(), b.size());

            // Invalid prefix case
            if(a.size() > b.size() &&
               a.compare(0, len, b) == 0) {
                return "";
            }

            // First different character
            for(int j = 0; j < len; j++) {

                if(a[j] != b[j]) {

                    if(!adj[a[j]].count(b[j])) {

                        adj[a[j]].insert(b[j]);
                        indeg[b[j]]++;
                    }

                    break;
                }
            }
        }

        // Kahn's Algorithm
        queue<char> q;

        for(auto& [c, d] : indeg) {
            if(d == 0)
                q.push(c);
        }

        string order;

        while(!q.empty()) {

            char u = q.front();
            q.pop();

            order += u;

            for(char v : adj[u]) {

                indeg[v]--;

                if(indeg[v] == 0)
                    q.push(v);
            }
        }

        // Cycle detection
        return order.size() == indeg.size() ? order : "";
    }
};