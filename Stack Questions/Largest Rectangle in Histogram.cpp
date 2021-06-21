class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int> left(n),right(n);
        
        //left
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push(i);
                left[i]=0;
            }
            else
            {
                while(!s.empty() and heights[s.top()]>=heights[i])
                    s.pop();
                if(s.empty())
                    left[i]=0;
                else
                    left[i]=s.top()+1;
                s.push(i);
            }
        }
        while(!s.empty())
            s.pop();
        
        //right
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(i);
                right[i]=n-1;
            }
            else
            {
                while(!s.empty() and heights[s.top()]>=heights[i])
                    s.pop();
                if(s.empty())
                    right[i]=n-1;
                else
                    right[i]=s.top()-1;
                s.push(i);
            }
        }

        int mx=0;
        for(int i=0;i<n;i++)
        {
            int cur=(right[i]-left[i]+1)*heights[i];
            mx=max(mx,cur);
        }
        return mx;
    }
};