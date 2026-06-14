## Approach (Optimal)
Sort the given array and initialize two pointers i.e. left, which points to the 0th index, and right, which points to the last index.
Now, using a loop, check the sum of arr[left] and arr[right] until left less than right.
If sum of arr[left] and arr[right] greater than target, decrement the right pointer.
If sum of arr[left] and arr[right] less than target, increment the left pointer.
If sum of arr[left] and arr[right] equals to target, return the result. Finally, if no results are found we will return {-1, -1}.


<img width="950" height="594" alt="image" src="https://github.com/user-attachments/assets/4be00215-5b1f-44b7-9ba1-622b02fc288a" />
<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/5dfd5c40-8bea-41a0-a249-2e8d5374a866" />
<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/c1786252-4994-44ff-ab07-ff998ba30cd4" />
<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/7afa8eb8-872a-41a8-80e1-e79ea2dab756" />
<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/0f63aa47-a5a2-460f-8b73-73c16fbe8b7a" />



Complexity Analysis 
Time Complexity: O(N) + O(N*logN), where N is size of the array. As the loop will run at most N times & sorting the array will take N * logN time complexity.

Space Complexity: O(N), because of the external data structure created to store the array elements along with their indices
