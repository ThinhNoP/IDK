class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(string s : strs) {
            encoded_string += to_string(s.size()) + "_" + s;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;

        int i = 0;
        int n = s.size();
        while(i < n) {
            int j = i;
            while( j < n && s[j] != '_') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            i = ++j;

            decoded_string.push_back(s.substr(i, len));

            i += len;
        }

        return decoded_string;
    }
};
