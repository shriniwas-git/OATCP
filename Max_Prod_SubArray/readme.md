Approach:

The dynamic programming (DP) approach efficiently finds the maximum product subarray of a given array.

Algorithm:

Initialize three variables: p1, p2, and res.

p1: Represents the maximum product ending at the current index.
p2: Represents the minimum product ending at the current index.
res: Represents the maximum product seen so far.
Initialize p1 and p2 with the first element of the array.

Iterate through the array starting from the second element:

    Calculate the maximum of three values: current element, p1 * current element, and p2 * current element. This gives the new maximum product ending at the current index.
    Calculate the minimum of three values: current element, p1 * current element, and p2 * current element. This gives the new minimum product ending at the current index.
    Update p1 and p2 with the new maximum and minimum products, respectively.
    Update the maximum product seen so far (res) with the maximum of res and p1.
Return the maximum product seen so far (res) modulo 1000000007 as the result.

This approach efficiently solves the problem by dynamically updating the maximum and minimum products ending at each index of the array and keeping track of the maximum product seen so far. Finally, it returns the maximum product modulo 1000000007.