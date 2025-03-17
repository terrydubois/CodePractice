/*
2626. Array Reduce Transformation

Given an integer array nums, a reducer function fn, and an initial value init, return the final result obtained by executing the fn function on each element of the array, sequentially, passing in the return value from the calculation on the preceding element.
This result is achieved through the following operations: val = fn(init, nums[0]), val = fn(val, nums[1]), val = fn(val, nums[2]), ... until every element in the array has been processed. The ultimate value of val is then returned.
If the length of the array is 0, the function should return init.
Please solve it without using the built-in Array.reduce method.

Example 1:
    Input:
    - nums = [1,2,3,4]
    - fn = function sum(accum, curr) { return accum + curr; }
    - init = 0
    Output: 10

Example 2:
    Input: 
    - nums = [1,2,3,4]
    - fn = function sum(accum, curr) { return accum + curr * curr; }
    - init = 100
    Output: 130
*/

// with using Array.reduce
var _reduce = function(nums, fn, init) {
    return nums.reduce(fn, init);
};

// without using Array.reduce
var reduce = function(nums, fn, init) {
    let reduced = init;
    for (let i = 0; i < nums.length; i++) {
        reduced = fn(reduced, nums[i]);
    }
    return reduced;
};


let nums = [1, 2, 3, 4];
let fn = (accum, curr) => {
    return accum + curr;
};
let init = 0;
console.log("reduce: " + reduce(nums, fn, init));