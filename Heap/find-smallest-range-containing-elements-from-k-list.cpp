// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-heap/problem/find-smallest-range-containing-elements-from-k-lists

// 1. Create a min heap of size k and insert first elements of all k lists into the
// heap.
// 2. Maintain two variables min and max to store minimum and maximum
// values present in the heap at any point. Note min will always contain value
// of the root of the heap.
// 3. Repeat following steps
// o Get the minimum element from the heap (minimum is always at root)
// and compute the range.
// o Replace heap root with next element of the list from which the min
// element is extracted. After replacing the root, heapify the tree. Update
// max if next element is greater. If the list doesn't have any more
// elements, break the loop.