// xor solution
pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
    // find missing^repeat
    int curXor = 0;
    for(int int i = 1; i <= n; i++) {
        curXor ^= (i ^ arr[i - 1]);
    }
    //partition the array
    int lsb = curXor & ~(curXor - 1);
    int x = 0; 
    int y = 0;
    auto assignToBucket = [&](int num)->void {
        if (num & lsb) {
            x ^= num;
        } else {
            y ^= num;
        }  
    };
    for(int i = 1; i <= n; i++) {
        assignToBucket(i);
        assignToBucket(arr[i - 1]);
    }
    // make sure which one is missing
    int cnt = 0;
    for(int num : arr) {
        if (num == x) cnt++;
    }
    if (cnt > 0) swap(x, y);
    return {x, y};
}
