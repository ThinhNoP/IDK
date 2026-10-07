class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count;
        
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        /* Solution 1

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

//    */
//    /*
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;

    for(auto x : count){
        minHeap.push({x.second, x.first});
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    vector<int> rs;
    for(int i = 0; i < k; i++){
        rs.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return rs;
    
    }
};
