// 2 Jan
// https://leetcode.com/problems/rotate-function/description/
// solution video (no code):
// https://www.youtube.com/watch?v=3YNs_Ggqb-Q
// Notion contains image of notes written.
// --------------------------------------------

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        // sum all elements of vector
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        int prevsum = 0;

        for (int i = 0; i < nums.size(); i++)
            prevsum += nums[i] * i;

        int res = prevsum;

        // actual expression:
        // currsum = prevsum - (totalsum - nums[i-1]) + (nums[i-1] * n)

        for (int i = 1; i < nums.size(); i++) {
            int currsum = prevsum - totalsum + (nums[i - 1] * nums.size());
            res = max(res, currsum);
            prevsum = currsum;
        }

        return res;
    }
};