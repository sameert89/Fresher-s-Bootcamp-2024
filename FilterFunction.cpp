#include <bits/stdc++.h>

std::vector<std::string> filterVectorOfStrings(const std::vector<std::string> &words, std::function<bool(std::string)> criteria) {
    std::vector<std::string> result;
    for(auto const &word: words){
        if(criteria(word)){
            result.push_back(word);
        }
    }
    return result;
}

void printVectorToConsole(std::vector<std::string> vec){
    for(auto const &item: vec) {
        std::cout<<item<<", ";
    }
}
std::function<bool(std::string)> checkStringStartWithAny(std::string startString){
std::function<bool(std::string)> predicateFunObj=[&](std:string stringItem) { return stringItem.starts_with(startString);  } 
    return predicateFunObj;
}

int main()
{
    std::vector<std::string> words = {"Tiger", "Lion", "Ranger", "Dictator", "Blue", "Foo"};
    std::function<bool(std::string)> endsWithVowel = [](std::string s){
        std::unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        return vowels.find(s.back()) != vowels.end();
    };
    std::vector<std::string> wordsEndingInVowel = filterVectorOfStrings(words, endsWithVowel);
    std::function<bool(std::string)> startsWithR =checkStringStartWithAny("R");
    std::vector<std::string> wordsStartWithR= filterVectorOfStrings(words, startsWithR);
    printVectorToConsole(wordsStartWithR);
    printVectorToConsole(wordsEndingInVowel);
    return 0;
}
