/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int find(Node* root)
    {
       if(root==NULL)
           return 0;
        int l=0;
        for(auto it:root->children)
        {
            int f=find(it);
            l=max(f+1,l);
        }
        return l;
    }
    void dfs(Node* root,int lvl,vector<vector<int>> & ans)
    {
        if(root==NULL)
            return;
        ans[lvl].push_back(root->val);
        for(auto it:root->children)
        {
            dfs(it,lvl+1,ans);
        }
        return;
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return {};
        }
        int level=find(root);
        vector<vector<int>> ans(level+1,vector<int>());
        dfs(root,0,ans);
        return ans;
    }
};


// can also done using bfs 


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> tmp;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                Node* cur=q.front();
                q.pop();
                for(auto it:cur->children)
                    q.push(it);
               tmp.push_back(cur->val); 
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};