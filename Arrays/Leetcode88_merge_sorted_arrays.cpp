class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans(m + n);
        int k = 0, i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] >= nums2[j])
            {
                ans[k] = nums2[j];
                j++;
                k++;
            }
            else
            {
                ans[k] = nums1[i];
                i++;
                k++;
            }
        }
        while (i < m)
        {
            ans[k] = nums1[i];
            k++;
            i++;
        }
        while (j < n)
        {
            ans[k] = nums2[j];
            k++;
            j++;
        }
        for (int l = 0; l < m + n; l++)
        {
            nums1[l] = ans[l];
        }
    }
};