#include <bits/stdc++.h>
long long merge(long long *arr, int l, int mid, int r) {
    long long cnt = 0;
    long long temp[r - l + 1];
    int px = l, py = mid + 1, pt = 0;
    while(px <= mid && py <= r) {
        if (arr[py] > arr[px]) {
            temp[pt++] = arr[py++];
            cnt += (px - l);
        } else {
            temp[pt++] = arr[px++];
        }
    }
    while(px <= mid) {
        temp[pt++] = arr[px++];
    }
    while(py <= r) {
        temp[pt++] = arr[py++];
        cnt += (px - l);
    }
    for(int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
    return cnt;
}
long long countInversion(long long *arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2; 
    return countInversion(arr, l, mid) + countInversion(arr, mid + 1, r) + merge(arr, l, mid, r);    
} 
long long getInversions(long long *arr, int n){
    return countInversion(arr, 0, n - 1);
}