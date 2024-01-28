'use strict';
const checkStartsWithAny = (startString: string) => {
    const predicateFunctionObject = (stringItem: string) => stringItem.startsWith(startString);
    return predicateFunctionObject;
}

const filterArrayOfStrings = (stringArray: string[], criteria: (stringItem: string) => boolean) => {
    const filteredArray: string[] = [];
    for(const element of stringArray){
        if(criteria(element)){
            filteredArray.push(element);
        }
    }
    return filteredArray;
}

const exampleArray = ["Tiger", "Lion", "Ranger", "Dictator", "Blue", "Foo"];

console.log(filterArrayOfStrings(exampleArray, checkStartsWithAny('B')));
