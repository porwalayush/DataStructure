/*
matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

*/

// binary search on matrix type(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int l=0, r= rows*cols-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(matrix[m/cols][m%cols]==target)
                return true;
            if(matrix[m/cols][m%cols]>target)
                r=m-1;
            else
                l=m+1;
        }
        return false;
        
    }
};