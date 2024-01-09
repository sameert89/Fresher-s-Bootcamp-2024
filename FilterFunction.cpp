#include <bits/stdc++.h>

std::vector<std::string> filter(const std::vector<std::string> &words, std::function<bool(std::string)> criteria) {
    std::vector<std::string> result;
    for(auto const &word: words){
        if(criteria(word)){
            result.push_back(word);
        }
    }
    return result;
}

void printVector(std::vector<std::string> vec){
    for(auto const &item: vec) {
        std::cout<<item<<", ";
    }
}

int main()
{
    std::vector<std::string> words = {"Tiger", "Lion", "Ranger", "Dictator", "Blue", "Foo"};
    std::function<bool(std::string)> endsWithVowel = [](std::string s){
        std::unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        return vowels.find(s.back()) != vowels.end();
    };
    std::vector<std::string> wordsEndingInVowel = filter(words, endsWithVowel);
    printVector(wordsEndingInVowel);
    return 0;
}
