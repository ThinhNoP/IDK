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
    /*  Trâu - Bruce Force
        while(true) {
            if(check(s, "{}")) continue;
            if(check(s, "[]")) continue;
            if(check(s, "()")) continue;

            break;
        }

        return s.empty();
//  */

//  /* Stack
        std::stack<char> stack;
        std::unordered_map<char, char> dongMo = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c : s) {
            if(dongMo.count(c)) {
                if(!stack.empty() && stack.top() == dongMo[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }

        return stack.empty();
//  */
        
    }
};
