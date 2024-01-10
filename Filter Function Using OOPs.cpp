
#include <bits/stdc++.h>

using namespace std;

class Services{
private:
    vector<string> serviceList;
    Services(vector<string> serviceList){
        this.serviceList = vector<string>(serviceList);
    }
    vector<string> filterServices(function<bool(string)> filterCallback){
        return VectorMethods()<string>.filter(this.serviceList, filterCallback);
    }
};
class StringPredicates{
    public:
    bool endsWith(const string &s, char ch){
        return [&](string s){return s.back() == ch;};
    }
};
template<typename T>
class VectorMethods{
    public:
    vector<T> filter(const vector<T> &v, function<bool(T)> cmp){
        vector<T> filteredVector;
        for(auto const &ele: v){
            if(cmp(ele)){
                filteredVector.push_back(ele);
            }
        }
        return filteredVector;
    }
};
class UtilityFunctions{
    public:
        template<typename T>
        void displayVectorToConsole(const vector<T> &v){
            for(auto const &ele: v) {
                cout << ele << ", ";
            }
            cout << endl;
        }
};

int main()
{
    Services SocialMedia({"Instagram", "Facebook", "Telegram", "Signal", "Snapchat"});
    vector<string> socialMediaServicesEndsWithm = SocialMedia.filterServices(StringPredicates().endsWith('m'));
    UtilityFunctions().displayVectorToConsole(socialMediaServicesEndsWithm);
    return 0;
}
