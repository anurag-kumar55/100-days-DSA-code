/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

*/
#include <stdio.h>
#include <stdlib.h>
int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    int *hash = (int *)malloc(sizeof(int) * 10000);
    for(int i = 0; i < 10000; i++) hash[i] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) max_len = i + 1;

        int key = sum + 5000;

        if(hash[key] != -1) {
            if(max_len < i - hash[key])
                max_len = i - hash[key];
        } else {
            hash[key] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}