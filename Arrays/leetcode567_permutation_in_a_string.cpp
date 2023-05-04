class Solution
{
private:
    bool permu(int arr[26], int arr2[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int arr[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            arr[s1[i] - 'a']++;
        }

        int arr2[26] = {0};

        int i = 0;
        while (i < s1.length() && i < s2.length())
        {
            arr2[s2[i] - 'a']++;
            i++;
        }
        if (permu(arr, arr2))
        {
            return true;
        }

        for (int i = s1.length(); i < s2.length(); i++)
        {
            arr2[s2[i] - 'a']++;
            arr2[s2[i - s1.length()] - 'a']--;
            if (permu(arr, arr2))
            {
                return true;
            }
        }
        return false;
    }
};