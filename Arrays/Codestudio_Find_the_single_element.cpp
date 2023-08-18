//https://www.codingninjas.com/studio/problems/find-the-single-element_6680465?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include<vector>

int getSingleElement(vector<int> &arr){
	int s = 0;
	int l = 1;
	int n = arr.size();
	for(int i = 0; i<n ; i++){
		if(arr[s] == arr[l])
		{
			s+=2;
			l+=2;
		}
		else
		{
			return arr[s];
		}
	}	
}