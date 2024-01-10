'use strict';
const checkStartsWithAny = (startString: string) => {
    const predicateFunctionObject = (stringItem: string) => stringItem.startsWith(startString);
    return predicateFunctionObject;
}

const filterArrayOfStrings = (words: string[], criteria: (stringItem: string) => boolean) => {
    const filteredArray: string[] = [];
    for(const word of words){
        if(criteria(word)){
            filteredArray.push(word);
        }
    }
    return filteredArray;
}

const exampleArray = ["Tiger", "Lion", "Ranger", "Dictator", "Blue", "Foo"];

console.log(filterArrayOfStrings(exampleArray, checkStartsWithAny('B')));
