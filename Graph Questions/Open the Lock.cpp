class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> dead;
        for(auto it:deadends)
            dead.insert(it);
        string s="0000";
        queue<string>q;
        map<string,int> visited;
        q.push(s);
        q.push("");
        int level=0,ans=-1;
        while(!q.empty())
        {
            string cur=q.front();
            q.pop();
            if(cur=="")
            {
                level++;
                if(!q.empty())
                q.push("");
                continue;
            }
            if(cur==target)
            {
                ans=level;
                break;
            }
            if(dead.find(cur)!=dead.end())
                continue;
            string f;
            f=cur;
            f[0]=((f[0]=='9')?'0':f[0]+1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            f=cur;
            f[0]=((f[0]=='0')?'9':f[0]-1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            
            f=cur;
            f[1]=((f[1]=='9')?'0':f[1]+1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            f=cur;
            f[1]=((f[1]=='0')?'9':f[1]-1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            
            f=cur;
            f[2]=((f[2]=='9')?'0':f[2]+1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            f=cur;
            f[2]=((f[2]=='0')?'9':f[2]-1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            
            f=cur;
            f[3]=((f[3]=='9')?'0':f[3]+1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            f=cur;
            f[3]=((f[3]=='0')?'9':f[3]-1);
            if(visited.find(f)==visited.end())
            {
                visited[f]=1;
                q.push(f);
            }
            
        }
        return ans;
    }
};