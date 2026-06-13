Intuition
The idea is to use four separate loops to print the array elements in spiral. 1st loop will print the elements from left to right. 2nd loop will print the elements from top to bottom. 3rd loop will print the elements from right to left. 4th loop will print the elements from bottom to top.

Approach 
Initialize four variables top as 0, left as 0, bottom as TotalRow - 1, right as TotalColumn - 1.
Iterate till top is less than or equal to bottom and left less than or equal to right
For moving left to right use a loop(say i) and add the elements. Increment top by 1.
For moving top to bottom use another loop and add the elements in answer. Decrement right by 1.
If top is less than or equal to bottom then for moving right to left use another loop and add the elements in answer. Decrement bottom by 1.
If left is less than or equal to right the for moving bottom to top take another loop and add the elements in answer. Increment left by 1. Lastly, return the answer.
Illustration 


C++
Java
Python
JavaScript
C#
Go



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to print matrix in spiral manner.
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         // Define ans vector to store the result
        vector<int> ans; 
        
        // Number of rows
        int n = matrix.size();

        // Number of columns
        int m = matrix[0].size();
        
        // Initialize pointers for traversal
        int top = 0, left = 0;
        int bottom = n - 1, right = m - 1;
        
        // Traverse the matrix in spiral order
        while (top <= bottom && left <= right) {

            // Traverse from left to right
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }

            top++;
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            // Traverse from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        //Return the ans
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
   #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to print matrix in spiral manner.
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         // Define ans vector to store the result
        vector<int> ans; 
        
        // Number of rows
        int n = matrix.size();

        // Number of columns
        int m = matrix[0].size();
        
        // Initialize pointers for traversal
        int top = 0, left = 0;
        int bottom = n - 1, right = m - 1;
        
        // Traverse the matrix in spiral order
        while (top <= bottom && left <= right) {

            // Traverse from left to right
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }

            top++;
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            // Traverse from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        //Return the ans
        return ans;
    }
};


Complexity Analysis 
Time Complexity: O(MxN) since all the elements are being traversed once and there are total N x M elements ( M elements in each row and total N rows) so the time complexity will be O(N x M).

Space Complexity: O(1) as extra space to store answer is not considered.
