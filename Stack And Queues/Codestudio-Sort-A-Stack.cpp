//https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio


#include <bits/stdc++.h>

void sortedInsert(stack<int> &s, int num)
{
	//base case
	if(s.empty() || (!s.empty() && s.top() < num))
	{
		s.push(num);
		return;
	}

	int n = s.top();
	s.pop();

	//recursive call
	sortedInsert(s, num);
	s.push(n);
	
}

void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	//recursive call
	sortStack(stack);

	sortedInsert(stack, num);
}