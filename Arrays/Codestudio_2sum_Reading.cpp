//https://www.codingninjas.com/studio/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

include<bits/stdc++.h>
//Better Approach
string read(int n, vector<int> book, int target)
{
   map<int,int> mpp;
   for(int i =0; i<n; i++)
   {
       int a = book[i];
       int more = target - a;
       if(mpp.find(more) != mpp.end())
       {
           return "YES"; //return (mpp[more], i)
       }
       mpp[a] = i;
       
   }
   return "NO";
}


//OPTIMAL APPROACH
//TC - O(N) + O(NLogN)
//SC - O(1)

string read(int n, vector<int> book, int target)
{
    int left = 0, right = n-1;
    sort(book.begin(), book.end());
    while(left<right){
        int sum = book[left] + book[right];
        if(sum == target){
            return "YES";
        }
        else if(sum <target) left++;
        else right--;
    }
    return "NO";
}
