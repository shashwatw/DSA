//* https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1

class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        // add code here.
        int l = 0;
        int h = n - 1;
        int mid;

        while (l <= h)
        {
            mid = h + (l - h) / 2;

            if (mid == n - 1 || arr1[mid] != arr2[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};