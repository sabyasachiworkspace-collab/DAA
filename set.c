/*Program to find a subset of a given set S = {Sl, S2,…, Sn} of n positive integers whose SUM is equal to a given positive integer d. For example, if S = {1, 2, 5, 6, 8} and d= 9, there are two solutions {1, 2, 6} and {1, 8}. Display a suitable message, if the given problem instance doesn't have a solution.*/

#include <stdio.h>
int set[10], n, sum;
void subset(int pos, int curr_sum) {
    if(curr_sum == sum) {
        printf("Subset found"); 
        return;
    }
    if(pos == n || curr_sum > sum) 
	return;
    subset(pos+1, curr_sum + set[pos]);
    subset(pos+1, curr_sum);
}

int main() {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:");
    for(i = 0; i < n; i++) scanf("%d", &set[i]);
    printf("Enter sum: ");
    scanf("%d", &sum);
    subset(0, 0);
    return 0;
}

