sort function for vector takes O(nlogn) time.
​
so Copying sqaures and sorting the vector is not the efficient solution.
​
Optimal Solution:
(Two pointer Algo)
​
* 1. In this method we initialize two pointers one for the leftmost index('l') and one for the rightmost index('r').
* 1. Initialize a vector array('v') of the same size as of nums with initial values as 0.
* 1. Initialize an integer 'i' to keep track of the index of 'v'.
* 1. Now, we run a loop through the given vector and checks if the value present at the index 'l' is greater than the value at index 'r' or not.
* 1. If it is then we add the square of that value at the end of the vector array v
* 1. Note that when we add the value to 'v' it get stored at the last index because we initialized 'i' as the last index.
* 1. And therefore the maximum value gets added at the last of the vector array.
* 1. So, in this method we don't have to sort the vector array as the values are being added in the sorted manner already.