// Identifications : if input is string or array...
//  INTUTION: need to break into k parts and check for every k fragment
//  If that's the case we know we have to approach using Matrix chain multiplication

int solve(int arr[], int i, int j)
{
    if (i > j) // ---- > could be diff depending on ques ... it is smallest invalid input
        return 0;

    for (int k = i; k < j; k++)
    {
        // calculate ans as per reqd logic it is just a template
        int tempans = solve(arr, i, k) + solve(arr, k + 1, j); // operations coul vary ques to ques

        ans = func(tempans); // func could be ques dependent
    }
    return ans;
}