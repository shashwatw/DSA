//* https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution
{
private:
    void merge(vector<int> &arr, vector<int> &arr1, vector<int> &arr2)
    {
        int i = 0, j = 0, k = 0;

        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] < arr2[j])
            {
                arr[k++] = arr1[i++];
            }
            else
            {
                arr[k++] = arr2[j++];
            }
        }

        while (i < arr1.size())
        {
            arr[k++] = arr1[i++];
        }

        while (j < arr2.size())
        {
            arr[k++] = arr2[j++];
        }
    }

public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        // code here
        vector<int> arr(arr1.size() + arr2.size());
        merge(arr, arr1, arr2);

        if (k > 0 && k <= arr.size())
        {
            return arr[k - 1];
        }
        return -1;
    }
};