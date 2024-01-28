using System;
using System.Collections.Generic;
using System.Linq;

public static List<string> FilterVectorOfStrings(List<string> words, Predicate<string> criteria)
{
    var result = new List<string>();
    foreach (var word in words)
    {
        if (criteria(word))
        {
            result.Add(word);
        }
    }
    return result;
}

public static void PrintVectorToConsole(List<string> vec)
{
    foreach (var item in vec)
    {
        Console.WriteLine(item + ", ");
    }
}

public static Predicate<string> CheckStringStartWithAny(string startString)
{
    return delegate (string stringItem) { return stringItem.StartsWith(startString); };
}

class Program
{
    static void Main(string[] args)
    {
        List<string> words = new List<string>() { "Tiger", "Lion", "Ranger", "Dictator", "Blue", "Foo" };
        Predicate<string> endsWithVowel = delegate (string s)
        {
            HashSet<char> vowels = new HashSet<char>(){'a', 'e', 'i', 'o', 'u'};
            return vowels.Contains(s[s.Length - 1]);
        };
        List<string> wordsEndingInVowel = FilterVectorOfStrings(words, endsWithVowel);
        Predicate<string> startsWithR = CheckStringStartWithAny("R");
        List<string> wordsStartWithR = FilterVectorOfStrings(words, startsWithR);
        PrintVectorToConsole(wordsStartWithR);
        PrintVectorToConsole(wordsEndingInVowel);
    }
}

