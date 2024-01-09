#include <bits/stdc++.h>

std::vector<int> filter(const std::vector<int> &nums, std::function<bool(int)> criteria) {
    std::vector<int> result;
    for(auto const &num: nums){
        if(criteria(num)){
            result.push_back(num);
        }
    }
    return result;
}

int main()
{
    std::vector<int> nums = {1, 7, 55, 22, 12, 24, 16};
    std::vector<int> evenNums = filter(nums, [](int e){ return a%2 == 0; });
    return 0;
}
