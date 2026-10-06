class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        if (nums.size() <= 0) {
            for ( int i = 0; i < nums.size(); i++ ) {
                for ( int j = i + 1; j < nums.size(); j++ ) {
                    if ( nums[i] + nums[j] == target ) return {i, j};
                }
            }
/*
        } else if (nums.size() <= 100) {
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

        //  Hash Map - 1/2 pass
        } else if (nums.size() <= 500) {
            unordered_map<int, int> Save;

            for (int i = 0; i < nums.size(); i++) {
                int diff = target - nums[i];
                if (Save.find(diff) != Save.end()) {
                    return {Save[diff], i};
                }
                Save.insert({nums[i], i});
            }
*/
        } else {
            unordered_map<int, int> Save;

            for (int i = 0; i < nums.size(); i++) {
                Save[nums[i]] = i;
            }

            for (int i = 0; i < nums.size(); i++) {
                int diff = target - nums[i];
                if (Save.count(diff) != 0 && Save[diff] != i) {
                    return {i, Save[diff]};
                }
            }
        }

        return {};
    }
};
