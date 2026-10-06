class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (auto& x : strs) {
            string sortS = x;
            sort(sortS.begin(), sortS.end());
            res[sortS].push_back(x);
        }

        vector<vector<string>> kq;
        for (auto& pair : res) {
            kq.push_back(pair.second);
        }

        return kq;
    }
};
