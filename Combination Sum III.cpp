https://leetcode.com/problems/combination-sum-iii/description/

// --------------------------------------------

// had to look at solution

class Solution {
public:

    vector<vector<int>> combs;

    void combinationSum(int k, int n, vector<int> &currcomb, int currnum) {

        if (n < 0 or currcomb.size() > k) return;

        if (n == 0 and currcomb.size() == k) {
            combs.push_back(currcomb);
            return;
        }

        for (int i = currnum; i < 10; i++) {
            currcomb.push_back(i);
            combinationSum(k, n - i, currcomb, i + 1);
            currcomb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> currcomb;

        combinationSum(k, n, currcomb, 1);

        return combs;
    }
};