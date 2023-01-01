https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


// --------------------------------------------

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (auto s: tokens) {
            if (s == "+" or s == "-" or s == "*" or s == "/") {
                int i = operands.top();
                operands.pop();
                int j = operands.top();
                operands.pop();

                int k;

                if (s == "+") k = j + i;
                if (s == "-") k = j - i;
                if (s == "*") k = j * i;
                if (s == "/") k = j / i;

                operands.push(k);
            }
            else 
                operands.push(stoi(s));
        }

        return operands.top();
    }
};