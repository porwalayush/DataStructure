class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0;
        if(s.length()<2)
            return s.length();
        int pre=0;
        map<int,int> m;
        m[s[0]-'a']=0;
        for(int i=1;i<s.length();i++)
        {
            if(m.find(s[i]-'a')!=m.end())
            {
                pre=max(pre,m[s[i]-'a']+1);
                m[s[i]-'a']=i;
            }
            else
            {
                m[s[i]-'a']=i;
            }
            mx=max(mx,i-pre+1);
        }
        return mx;
    }
};