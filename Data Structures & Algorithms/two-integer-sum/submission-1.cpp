class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        for ( int i = 0; i < nums.size(); i++ ) {
            for ( int j = i + 1; j < nums.size(); j++ ) {
                if ( nums[i] + nums[j] == target ) return {i, j};
           }
        }
        */

        vector<pair<int, int>> Ma;
        for (int i = 0; i < nums.size(); i++) {
            Ma.push_back({nums[i], i});
        }

        sort(Ma.begin(), Ma.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = Ma[l].first + Ma[r].first;
            if (mid == target) {
                return {min(Ma[l].second, Ma[r].second),            
                        max(Ma[l].second,Ma[r].second)};
            } else if (mid < target) {
                l++;
            } else {
                r--;
            }
        } 
        return {};
    }
};
