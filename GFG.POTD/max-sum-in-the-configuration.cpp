//*https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

/*You are required to complete this method*/
class Solution
{
public:
    long long max_sum(int a[], int n)
    {
        long long cum_sum = 0;
        for (long long i = 0; i < n; i++)
        {
            cum_sum += a[i];
        }

        // calculating initial val and setting max as initial value
        long long initial_val = 0;
        long long max = 0;
        for (long long i = 0; i < n; i++)
        {
            initial_val += i * a[i];
            max = initial_val;
        }

        /* Lets take example 1 2 3 for it answer is 1*0+2*1+3*2 = 8
        shifting it by one will make it 2 3 1 now here the answer will be 2*0+3*1+1*2=5
        if we observe it closely we can see that a property is followed ie (
        */
        for (long long i = 1; i < n; i++)
        {
            long long temp =
                initial_val - (cum_sum - a[i - 1]) + 1LL * a[i - 1] * (n - 1);
            initial_val = temp;
            if (temp > max)
                max = temp;
        }

        return max;
    }
};