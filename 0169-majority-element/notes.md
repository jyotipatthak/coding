## Intuition 
Imagine you are at a large party, and you want to determine which dish is the most popular. Each guest has brought a dish, and some dishes are brought by more guests than others. The party is large enough that one dish is guaranteed to be the majority dish, meaning it was brought by more than half of the guests.

Initial observation is as we move around the party, you decide to start keeping track of the dishes in a specific way. Begin with no specific dish in mind and no count. On seeing each dish, do the following:

If you don’t have a dish you’re tracking yet, start tracking the current dish and set its count to 1.
If the current dish matches the one you’re tracking, increase its count by 1.
If the current dish doesn’t match the one you’re tracking, decrease the count by 1. If the count drops to zero, stop tracking that dish and start tracking the next dish.
The idea is that at any point where the count of tracked dishes drops to zero, it means up to that point, the popularity of different dishes has balanced out. This reset allows you to focus on potentially more popular dishes as you continue through the party. At the end check which dish you ended up tracking last. This dish is your 
candidate for the most popular dish. To confirm if this dish is indeed the majority dish, recount its appearances to see if it indeed makes up more than half of all dishes at the party. If it does, then you have found your majority dish. If it doesn’t, there was an error in the process, but for this scenario, we assume the party is large 
enough to guarantee one majority dish.


## Approach 
Initialize 2 variables: countfor tracking the count of elements and element for keeping a track of the element we are counting.
Traverse through the given array. If count is 0 then store the current value of the array as element .
If the current array value andelement are the same increase the count by 1. If they are different decrease the count by 1. The integer present in element should be the result expected.
## Dry Run

<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/0e2aa021-0be7-4dc5-8501-0fbc574d9af2" />
<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/7faf9f7a-f031-4c13-8827-e69e5c7356c3" />
<img width="668" height="418" alt="image" src="https://github.com/user-attachments/assets/7620b2c0-e7f7-4e4b-95d4-0888d55b308f" />
<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/a1e62850-4f51-4d66-beb1-f1bdba61c224" />
<img width="949" height="594" alt="image" src="https://github.com/user-attachments/assets/ab76cc5b-ad16-472b-9df0-400ac255d671" />


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the majority element in an array
    int majorityElement(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size();
        
        // Count
        int cnt = 0;
        
        // Element
        int el; 
        
        // Applying the algorithm
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        /* Checking if the stored element
         is the majority element*/
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        
        //return element if it is a majority element
        if (cnt1 > (n / 2)) {
            return el;
        }
        
        //return -1 if no such element found
        return -1;
    }
};

int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    
    // Create an instance of Solution class
    Solution sol;

    int ans = sol.majorityElement(arr);
    
    // Print the majority element found
    cout << "The majority element is: " << ans << endl;
    
    return 0;
}


## Complexity Analysis 
Time Complexity: O(N) + O(N), where N is size of the given array. The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.

Space Complexity: O(1) no extra space used.
