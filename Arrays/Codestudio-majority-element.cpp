//https://www.codingninjas.com/studio/problems/majority-element_6783241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

int majorityElement(vector<int> v) {
	sort(v.begin(), v.end());
	int cnt=0;
	if(v.size() == 1)
	{
		return v[0];
	}
	for(int i = 0; i<v.size() ; i++)
	{
		if(v[i]==v[i+1])
		{
			cnt++;
			if(cnt >= (v.size()-1)/2)
			{
				return v[i];
			}
		}
		else
		{
			cnt =0;
		}
	}
}