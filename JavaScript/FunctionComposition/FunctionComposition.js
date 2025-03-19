/*
LeetCode 2629. Function Composition

Given an array of functions [f1, f2, f3, ..., fn], return a new function fn that is the function composition of the array of functions.
The function composition of [f(x), g(x), h(x)] is fn(x) = f(g(h(x))).
The function composition of an empty list of functions is the identity function f(x) = x.
You may assume each function in the array accepts one integer as input and returns one integer as output.

Example 1
    Input: functions = [x => x + 1, x => x * x, x => 2 * x], x = 4
    Output: 65
*/

var compose = function(functions) {
    
    return function(x) {

        // run through functions right to left, applying current function each time
        for (let i = functions.length - 1; i >= 0; i--) {
            let currentFn = functions[i];
            x = currentFn(x);
        }
        return x;
    }
};

// driver code for compose function
let x = 4;
let functions = [
    (x) => {return x + 1},
    (x) => {return x * x},
    (x) => {return 2 * x}
];
let functionsComposed = compose(functions);
let result = functionsComposed(x);
console.log("x: " + x + ", result: " + result);