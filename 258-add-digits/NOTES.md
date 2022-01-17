Naive Approach:
* Using two while loops
* One for finding digits of number and adding to sum
* Other for iterating until we reach a single digit sum
​
O(n^2)
​
**Better Approach:**
​
This can be acheived by **Finding the digital root**
dr(n) = 0, if n = 0
dr(n) = 9, if n = 9k
dr(n) = n mod 9, if n != 9k
int addDigits(int num) {
if(num == 0)
return 0;
if(num % 9 == 0)
return 9;
return num % 9;
}