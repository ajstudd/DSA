// class Solution {
// public:
//     char closureFinder(char ch){
//     switch(ch){
//             case '(' :
//             return ')';
//             case '{' :
//             return '}';
//             case '[' :
//             return ']';
//             default:
//             return '.';
//         }
//         return '.';
//     }
//     bool isValid(string s) {
//         stack<char> st;
//         int size = s.length();
//         for(int i=0;i<size;i++){
//             if(!st.empty() && closureFinder(st.top())==s[i]){
//                 st.pop();
//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
//         if(st.empty()){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char ch : s)
        {
            if (brackets.count(ch))
            { // If ch is a closing bracket
                if (st.empty() || st.top() != brackets[ch])
                    return false;
                st.pop();
            }
            else
            { // If ch is an opening bracket
                st.push(ch);
            }
        }
        return st.empty();
    }
};
