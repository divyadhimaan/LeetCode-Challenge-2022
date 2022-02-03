Count the total number of solutions to that satisfies the condition -->  a + b = -(c + d)
​
1) Iterate over the first 2 vectors and count the frequency of all possible sums of pairs and store it in a map
2) Iterate over the other 2 vectors and sum up the frequency of -(c + d)
3) If (a + b) is be equal to -(c + d). Then add the frequency of -(c + d) to the counter .
4) The total number of pairs which satisfies the above condition is the required result