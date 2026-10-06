class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& x : count){
            buckets[x.second].push_back(x.first); 
            // Use the number of occurrences as the index position
        }

        vector<int> rs;
        for(int i = buckets.size() - 1; i >= 0; i--){
            for(int num : buckets[i]){
                rs.push_back(num);
                if(rs.size() == k) {
                    return rs;
                }
            }
        }

        return rs;
    }
};
