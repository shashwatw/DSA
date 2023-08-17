vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();
    k = k % n; // Effective number of rotations

    vector<int> rotated(n);

    for (int i = 0; i < n; i++) {
        int newIndex = (i - k + n) % n;
        rotated[newIndex] = arr[i];
    }

    return rotated;
}
