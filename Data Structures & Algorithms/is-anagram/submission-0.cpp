class Solution {
public:
    bool isAnagram(string s, string t) {
        int ascii[26]={};
        for(int i = 0; i < s.size(); i++) {
            ascii[s[i]-'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            ascii[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if( ascii[i] < 0 ) return false;
            if( ascii[i] > 0 ) return false;
        }

        return true;
    }
};
