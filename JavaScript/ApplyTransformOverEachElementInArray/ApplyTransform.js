/*
LeetCode 2635. Apply Transform Over Each Element in Array

Given an integer array arr and a mapping function fn, return a new array with a transformation applied to each element.
The returned array should be created such that returnedArray[i] = fn(arr[i], i).
Please solve it without the built-in Array.map method.

Example 1:
    Input: arr = [1,2,3], fn = function plusone(n) { return n + 1; }
    Output: [2,3,4]

Example 2:
    Input: arr = [1,2,3], fn = function plusI(n, i) { return n + i; }
    Output: [1,3,5]
*/

// using Array.map
var _map = function(arr, fn) {
    return arr.map(fn);
}

// without using Array.map
var map = function(arr, fn) {
    let arrMapped = [];
    for (let i = 0; i < arr.length; i++) {
        arrMapped.push(fn(arr[i], i));
    }
    return arrMapped;
}

let _arr = [1, 2, 3];
let _fn = (n) => n + 1;

console.log("before: " + _arr);
console.log("after: " + map(_arr, _fn));