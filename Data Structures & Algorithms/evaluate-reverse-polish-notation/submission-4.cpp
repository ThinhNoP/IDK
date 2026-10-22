class DoublyLinkedList { // IDK - Just use Linked List to save value and operators
public:
    string val;
    DoublyLinkedList* prev;
    DoublyLinkedList* next;

    DoublyLinkedList(string v = "", DoublyLinkedList* n = nullptr, DoublyLinkedList* p = nullptr) : val(v), prev(p), next(n) {}

    void clearList(DoublyLinkedList*& head) {
        DoublyLinkedList* curr = head;

        while (curr != nullptr) {
            DoublyLinkedList* temp = curr->next;
            delete curr;
            curr = temp;
        }

        head = nullptr;
    }
};

class Solution : public DoublyLinkedList {
private:
    int conversion (string str) {
        int sign = 1;
        if (str[0] == '-') {
            sign = -1;
            str.erase(str.begin(), str.begin() + 1);
        }

        int num = 0;
        for(auto c : str) {
            num = num * 10 + (c - '0');
        }

        return num * sign;
    }
public:
    int evalRPN (vector<string>& tokens) {
        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for (int i = 1; i < tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i], nullptr, curr);
            curr = curr->next;
        }

        int ans = 0;
        while (head != nullptr) {
            if (head->val == "+" || head->val == "-" ||
                head->val == "*" || head->val == "/") {
                    int l = conversion(head->prev->prev->val);
                    int r = conversion(head->prev->val);

                    int res = 0;
                    if      (head->val == "+") res = l + r;
                    else if (head->val == "-") res = l - r;
                    else if (head->val == "*") res = l * r;
                    else                       res = l / r;

                    head->val = to_string(res);
                    head->prev = head->prev->prev->prev;
                    if (head->prev != nullptr) {
                        head->prev->next = head;
                    }
                }

                ans = conversion(head->val);
                head = head->next;
        }

        clearList(head);
        return ans;
    }


    // Stupid Bruce Force :))) - TLE
    /*
    while (tokens.size() > 1) {
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens[i] == "+" || tokens[i] == "-" ||
                    tokens[i] == "*" || tokens[i] == "/"   ) {
                    int a = stoi(tokens[i - 2]);
                    int b = stoi(tokens[i - 1]);
                    int result = 0;
                    if (tokens[i] == "+") result = a + b;
                    else if (tokens[i] == "-") result = a - b;
                    else if (tokens[i] == "*") result = a * b;
                    else if (tokens[i] == "/") result = a / b;

                    tokens.erase(tokens.begin() + i - 2,
                                 tokens.begin() + i + 1);
                    tokens.insert(tokens.begin() + i - 2, to_string(result));
                    break;
                }
            }
        }

        return stoi(tokens[0]);
    */
};
