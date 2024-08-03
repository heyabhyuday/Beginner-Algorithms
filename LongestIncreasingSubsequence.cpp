#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int N) {
    int lis[N];
    lis[0] = 1;
    for (int i = 0; i < N; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
            }
        }
        return *max_element(lis, lis + N);
    }

int main() {
    int arr[] = {10, 15, 13, 9, 21, 22, 35, 29, 64};
    int N = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", lis(arr, N));
    return 0;
}
