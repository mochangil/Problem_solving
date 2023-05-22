#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums){
        vector<int> runsum;
        int sum = 0;
        for (auto number: nums){
            sum += number;
            runsum.push_back(sum);
        }
        return runsum;
    }
};
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Solution sol;
    vector<int> solu = sol.runningSum(nums);
    cout << solu;
    return 0;
}