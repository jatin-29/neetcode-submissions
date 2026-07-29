class Solution {

private:

    void solve(string &digits,
               vector<string> &mapping,
               vector<string> &ans,
               int index,
               string &temp) {

        // Ek combination ban gayi
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        // Current digit ke letters
        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {

            // Choose
            temp.push_back(ch);

            // Explore
            solve(digits, mapping, ans, index + 1, temp);

            // Undo
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp;

        solve(digits, mapping, ans, 0, temp);

        return ans;
    }
};