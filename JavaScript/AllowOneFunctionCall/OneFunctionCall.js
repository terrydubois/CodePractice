/*
LeetCode 2666. Allow One Function Call

Given a function fn, return a new function that is identical to the original function
except that it ensures fn is called at most once.
- The first time the returned function is called, it should return the same result as fn.
- Every subsequent time it is called, it should return undefined.

Example 1
    Input: fn = (a,b,c) => (a + b + c), calls = [[1,2,3],[2,3,6]]
    Output: [{"calls":1,"value":6}]

Example 2
    Input: fn = (a,b,c) => (a * b * c), calls = [[5,7,4],[2,3,6],[4,6,8]]
    Output: [{"calls":1,"value":140}]
*/

var once = function(fn) {

    var firstCall = true;
    return function(...args){
        if (firstCall) {
            firstCall = false;
            return fn(...args);
        }
        else return undefined;
    };
};

let fn = (a, b, c) => (a + b + c);
let fnOnce = once(fn);
let calls = [[1,2,3],[2,3,6]];
for (let i = 0; i < calls.length; i++) {
    let args = calls[i];
    let result = fnOnce(...args);
    console.log("i: " + i + ", result: " + result);
}