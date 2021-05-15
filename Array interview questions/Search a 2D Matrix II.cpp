/*
The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/


// binary search on matrix type(2)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        int l=0,r=cols-1;    // top right corner
        while(l<rows && r>=0)
        {
            if(matrix[l][r]==target)
                return true;
            if(matrix[l][r]<target)
                l++;
            else
                r--;
        }
        return false;
    }
};