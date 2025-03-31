/*
LeetCode 2621. Sleep

Given a positive integer millis, write an asynchronous function that sleeps for millis milliseconds. It can resolve any value.
*/

async function sleep(millis) {
    return new Promise(resolve => setTimeout(resolve, millis));
}

async function delayedMessage() {
    await sleep(1000);
    console.log("delayed message");
}

console.log("instant message");
delayedMessage();