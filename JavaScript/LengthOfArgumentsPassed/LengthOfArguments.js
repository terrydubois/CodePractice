/*
LeetCode 2703. Return Length of Arguments Passed

Write a function argumentsLength that returns the count of arguments passed to it.

Example
    Input: args = [{}, null, "3"]
    Output: 3
*/

var argumentsLength = function(...args) {

    // using array length
    //return args.length;

    // without using array.length
    let argsLen = 0;
    while (args[argsLen] !== undefined) argsLen++;
    return argsLen;
};

console.log(argumentsLength({}, null, "3"));