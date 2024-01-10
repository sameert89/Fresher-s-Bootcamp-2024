
#include <bits/stdc++.h>

using namespace std;

class StringMethods{
    public:
    bool endsWith(const string &s, char ch){
        return s.back() == ch;
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
    vector<string> services = {"fiverr", "youtube", "tinder", "facebook", "snapchat", "uber"};
    VectorMethods<string> servicesVM;
    StringMethods servicesSM;
    vector<string> filteredServices = servicesVM.filter(services, 
                                                [&](string s){return servicesSM.endsWith(s, 'r');});
    UtilityFunctions servicesUF;
    servicesUF.displayVectorToConsole(filteredServices);
    return 0;
}
