
#include <bits/stdc++.h>

using namespace std;

/* -------- CORRECTIONS ---------*/

/* -------- Aggregation --------*/
class SearchStrategy {
public:
    virtual void invoke(string item) = 0;
};
class StartsWithStrategy : public SearchStrategy{
private:
    string startsWith;
public:
    void setStartsWith(string key){
        this->startsWith = key;
    }
    bool invoke(string item){
        return item.find(this->startsWith) == 0;
    }
};

class ConsoleDisplayController{
private:
    string content = "";
public:
    void setContent(string msg) {
        this->content = msg;
    }
    void display() {
        for(auto const &e: this->content) {
            cout << e << ",";
        }
    }
};
class StringListFilterController{
    private:
        SearchStrategy* S;
    public:
        void setSearchStrategy(SearchStrategy* ptr){
            this->S = ptr;
        }
        vector<string> filter(vector<string> strList){
            vector<string> result;
            for(auto const &str: strList){
                if(SS.invoke(str)) {
                    result.push_back(str);
                }
            }
            return result;
        }
};
int main(){
    StartsWithStrategy SS;
    SearchStrategy* ptr = &SS;
    StringListFilterController SLF;
    SLF.setStrategy(ptr);
}

/* -------- Composition --------*/
class ConsoleDisplayController{
private:
    string content = "";
public:
    void setContent(string msg) {
        this->content = msg;
    }
    void display() {
        for(auto const &e: this->content) {
            cout << e << ",";
        }
    }
};
class StartsWithStrategy{
private:
    string startsWith;
public
    void setStartsWith(string key){
        this->startsWith = key;
    }
    bool invoke(string item){
        return item.find(this->startsWith) == 0;
    }
};
class StringListFilterController{
    private:
        StartsWithStrategy SS;
    public:
        vector<string> filter(vector<string> strList){
            SS.setStartsWith('t');
            vector<string> result;
            for(auto const &str: strList){
                if(SS.invoke(str)) {
                    result.push_back(str);
                }
            }
            return result;
        }
};
/* --------- ORIGINAL CODE ----------- */
class StringPredicates{
    public:
    function<bool(string)> endsWith(char ch){
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

class Services{
public:
    vector<string> serviceList;
    Services(vector<string> serviceList){
        this->serviceList = vector<string>(serviceList);
    }
    vector<string> filterServices(function<bool(string)> filterCallback){
        return VectorMethods<string>().filter(this->serviceList, filterCallback);
    }
};


int main()
{
    Services SocialMedia({"Instagram", "Facebook", "Telegram", "Signal", "Snapchat"});
    vector<string> socialMediaServicesEndsWithm = SocialMedia.filterServices(StringPredicates().endsWith('m'));
    UtilityFunctions().displayVectorToConsole(socialMediaServicesEndsWithm);
    return 0;
}
