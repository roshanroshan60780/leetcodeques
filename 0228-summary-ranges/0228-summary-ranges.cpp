class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        vector<string> ans;
        int low = nums[0], high = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (low == high)
                    ans.push_back(to_string(low));
                else
                    ans.push_back(to_string(low) + "->" + to_string(high));
                low = nums[i];
                high = nums[i];
            } else
                high = nums[i];
        }
        if (low == high)
            ans.push_back(to_string(low));
        else
            ans.push_back(to_string(low) + "->" + to_string(high));
        return ans;
    }
};