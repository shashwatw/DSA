//https://www.codingninjas.com/studio/problems/majority-element_6915220?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

//Better approach
#include <bits/stdc++.h>

vector<int> majorityElement(vector<int> v) {
	vector<int> ls;
	map<int,int> mpp;
	int n = v.size();
	int mini = (int)(n/3) + 1;
	for(int i = 0 ; i<n; i++)
	{
		mpp[v[i]]++;
		if(mpp[v[i]] == mini)
		{
			ls.push_back(v[i]);
		}
		if(ls.size() == 2) break;
	}
	sort(ls.begin(), ls.end());
	return ls;
}

//Optimal Code
#include<bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {
	int cnt1 = 0, cnt2 =0;
	int el1 = INT_MIN;
	int el2 = INT_MIN;
	int n = v.size();
	for(int i =0 ; i< v.size(); i++){
		if(cnt1==0 && el2 != v[i])
		{
			cnt1 = 1;
			el1 = v[i];
		}
		else if(cnt2 == 0 && el1 != v[i])
		{
			cnt2 = 1;
			el2 = v[i];
		}
		else if(v[i] == el1) cnt1++;
		else if(v[i] == el2) cnt2++;
		else{
			cnt1--, cnt2--;
		}
	}
	
	vector<int> ls;
	cnt1 = 0, cnt2 = 0;
	for(int i =0 ; i< v.size(); i++)
	{
		if(el1 == v[i]) cnt1++;
		if(el2 == v[i]) cnt2++;
	}
	int mini = (int)(n/3) +1;
	if(cnt1 >= mini) ls.push_back(el1);
	if(cnt2 >= mini) ls.push_back(el2);
	sort(ls.begin(), ls.end());
	return ls;
}