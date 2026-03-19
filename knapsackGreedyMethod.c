#include <stdio.h>
int main() {
    int n, i;
    float w[20], p[20], ratio[20], cap, temp;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights and profits:");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &w[i], &p[i]);
        ratio[i] = p[i] / w[i];
    }
    printf("Enter capacity: ");
    scanf("%f", &cap);
    for(i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(ratio[i] < ratio[j]) {
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
    float profit = 0;
    for(i = 0; i < n && cap > 0; i++) {
        if(w[i] <= cap) {
            cap -= w[i]; profit += p[i];
        } else {
            profit += p[i] * (cap / w[i]); cap = 0;
        }
    }

    printf("Maximum Profit = %f", profit);
    return 0;
}
