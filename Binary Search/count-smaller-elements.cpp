//* https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1

// User function Template for C++
//  User function template for C++

class Solution
{
public:
    int binarySearch(vector<int> &arr, int x)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }

    vector<int> constructLowerArray(vector<int> &arr)
    {
        // code here
        vector<int> res;
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());

        int size = arr.size();
        for (int i = 0; i < size; i++)
        {
            int firstIndex = binarySearch(sorted, arr[i]);

            // if(firstIndex != -1)
            res.push_back(firstIndex);
            // else
            // res.push_back(0);

            // if(firstIndex)
            sorted.erase(sorted.begin() + firstIndex);
        }

        return res;
    }
};