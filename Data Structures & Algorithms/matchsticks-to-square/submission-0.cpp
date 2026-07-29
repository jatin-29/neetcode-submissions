class Solution {

private:

    bool solve(vector<int> &matchsticks,
               vector<int> &side,
               int target,
               int index){

        // Saari matchsticks use ho gayi
        if(index == matchsticks.size()){

            return side[0] == target &&
                   side[1] == target &&
                   side[2] == target &&
                   side[3] == target;
        }

        for(int i = 0; i < 4; i++){

            // Constraint
            if(side[i] + matchsticks[index] > target)
                continue;

            // Choose
            side[i] += matchsticks[index];

            // Explore
            if(solve(matchsticks,
                     side,
                     target,
                     index + 1))
                return true;

            // Undo
            side[i] -= matchsticks[index];
        }

        return false;
    }

public:

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for(int x : matchsticks)
            sum += x;

        if(sum % 4 != 0)
            return false;

        int target = sum / 4;

        // Optimization
        sort(matchsticks.rbegin(),
             matchsticks.rend());

        vector<int> side(4, 0);

        return solve(matchsticks,
                     side,
                     target,
                     0);
    }
};