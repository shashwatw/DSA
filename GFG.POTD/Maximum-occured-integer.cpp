//* https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1

class Solution
{
public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx)
    {
        //^ Create a difference array initialized to 0
        vector<int> freq(maxx + 2, 0);

        //^ Use the difference array technique

        //^ Here we are storing start of range by incrementing by 1 and end by decrementing the next elem to last range by 1
        for (int i = 0; i < n; i++)
        {
            freq[l[i]]++;
            freq[r[i] + 1]--;
        }
        //^ After the above loop we have arr like below
        //&  [0 2 0 1 1 -1 -2 0 0 -1]

        //^ After this we will find one by one prefix sum from starting and the one having highest prefix sum will be our ans
        //&   [0 2 2 3 4 3 1 1 1 0 0 0 .... till maxx(i.e. 10^6)]
        //?i-> 0 1 2 3 4 5 6 7 8 9...........
        //^Hence as 4th index has max prefix sum it should be the most occured character from all ranges

        //^ Convert the difference array to a prefix sum array
        int max_count = freq[0];
        int res = 0;
        for (int i = 1; i <= maxx; i++)
        {
            freq[i] += freq[i - 1];
            if (freq[i] > max_count)
            {
                max_count = freq[i];
                res = i;
            }
        }

        return res;
    }
};