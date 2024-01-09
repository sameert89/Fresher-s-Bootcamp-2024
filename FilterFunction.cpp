#include <bits/stdc++.h>

std::vector<int> filter(const std::vector<int> &arr, std::function<bool(int)> criteria) {
    std::vector<int> result;
    for(auto const &ele: arr){
        if(criteria(ele))
            result.push_back(ele);
    }
    return result;
}

int main()
{
    std::cout<<"Hello World";
    return 0;
}
