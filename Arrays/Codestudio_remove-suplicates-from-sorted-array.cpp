// https://www.codingninjas.com/studio/problems/remove-duplicates-from-sorted-array_1102307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

#include <bits/stdc++.h>
// int removeDuplicates(vector<int> &arr, int n) {
// 	set<int> st;
// 	for(int i = 0 ; i < n ; i++)
// 	{
// 		st.insert(arr[i]);
// 	}
// 	return st.size();
// }

int removeDuplicates(vector<int> &arr, int n)
{
    int c = 1;
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[c] == arr[i])
        {
            c++;
        }
        else
        {
            st.push_back(arr[c]);
            c++;
        }
    }
    return st.size();
}