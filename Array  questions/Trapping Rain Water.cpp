// 2 pointer approach o(n)time o(1)space

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        if(n<=2)
            return 0;
        int left=1,right=n-2;
        int left_max=height[0],right_max=height[n-1];
        int trapped=0;
        while(left<=right)
        {
            if(left_max<right_max)
            {
                if(height[left]>left_max)
                    left_max=height[left];    //no water trapped
                else
                    trapped+=(left_max-height[left]);
                left++;
            }
            else
            {
                if(height[right]>right_max)
                    right_max=height[right];    //no water trapped
                else
                    trapped+=(right_max-height[right]);
                right--;
            }
        }
        return trapped;
    }
};



// dynamic programming approach:

// can also solve using maintain left_max and right_max at every position( 1 to n-2 ) 
// and do   for(i=1 to n-2) do-> trapped+=min(left_max[i],right_max[i])-h[i]
// o(n) space o(n) time