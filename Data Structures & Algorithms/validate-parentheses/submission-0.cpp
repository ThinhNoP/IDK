class Solution {
public:
    bool check(string& s, const string& option) {
        size_t pos = s.find(option);
        if(pos != string::npos) {
                s.erase(pos, 2);
                return true;
            }
        return false;
    }

    bool isValid(string s) {
//  /*  Trâu - Bruce Force
        while(true) {
            if(check(s, "{}")) continue;
            if(check(s, "[]")) continue;
            if(check(s, "()")) continue;

            break;
        }

        return s.empty();
//  */
        
    }
};
