class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, bool> m;
        vector<int> ret;
        for (int i = 0; i<nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                if (m.find(target - nums[i]) != m.end()) {
                    ret.push_back(i);
                    for (int j = 0; j<nums.size(), j++) {
                        if (nums[j] == (target - nums[i])) {
                            ret.push_back(j);
                            return ret;
                        }
                    }
                }
            }
        }

    }
};
