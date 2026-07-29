class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        //1. HAAR CONSECUTUVE WORDS KO COMPARE KRO
        //2. USSE EDGES BNAO
        //3. INDEGREE NIKALO
        //4. KAHNS ALGROITHM TOPOLOGICAL SORT

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;

        // Sab unique characters ko indegree map me daal do
        for (string &w : words) {
            for (char c : w)
                indeg[c] = 0;
        }

        // Consecutive words compare karo
        for (int i = 0; i + 1 < words.size(); i++) {

            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());

            // invalid abc pehle aaya ab se
            if (a.size() > b.size() && a.compare(0, len, b) == 0) {
                return "";
            }

            // different char ko dhund na consectutive words mei a aur b mei mtlb

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {

                    // aare different mil gaya wow
                    // ab sabse pehle bolo jai mata di mata rani aap btao pehle adj mei check krlu iski node bni na ho

                    if (!adj[a[j]].count(b[j])) {

                        // nhi bni to bna na
                        adj[a[j]].insert(b[j]);

                        // indegree destination ka badhega
                        indeg[b[j]]++;
                    }

                    break;
                }
            }
        }

        // aajo ab sab hogya indegree hai graph hai lgado kahns algo

        queue<char> q;

        for (auto &[c, d] : indeg) {
            if (d == 0)
                q.push(c);
        }

        string order;

        while (!q.empty()) {

            char u = q.front();
            q.pop();

            order += u;

            for (char v : adj[u]) {

                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        return order.size() == indeg.size() ? order : "";
    }
};