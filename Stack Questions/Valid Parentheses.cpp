class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(auto it:s)
        {
            if(it=='(' || it=='{' || it=='[')
                st.push(it);
            else
            {
                if(st.empty())
                    return false;
                if(it==')')
                {
                    if(st.top()!='(')
                        return false;
                    else
                        st.pop();
                }
                if(it=='}')
                {
                    if(st.top()!='{')
                        return false;
                    else
                        st.pop();
                }
                if(it==']')
                {
                    if(st.top()!='[')
                        return false;
                    else
                        st.pop();
                }
            }
        }
        return st.size()==0;
        
    }
};