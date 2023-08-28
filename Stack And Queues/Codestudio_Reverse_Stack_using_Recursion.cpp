//https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio



void insertAtBottom(stack<int> &s, int elem){
    //basecase
    if(s.empty())
    {
       s.push(elem);
       return;
    }

    int num = s.top();
    s.pop();

    //Recursive call
    insertAtBottom(s,elem);
    s.push(num);

}

void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);
    insertAtBottom(stack, num);

}