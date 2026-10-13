class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Trau
        // Sorting

        // Hash Set
        unordered_set<int> numS(nums.begin(), nums.end());
        int ans = 0;

        for(int num : numS) {
            if( numS.find(num - 1) == numS.end()) {
                int size = 1;
                while( numS.find(num + size) != numS.end()) {
                    size++;
                }

                ans = max( ans, size);
            }
        }

        return ans;
    }
};
