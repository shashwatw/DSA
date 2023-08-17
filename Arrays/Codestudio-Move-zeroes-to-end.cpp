
//https://www.codingninjas.com/studio/problems/ninja-and-the-zero-s_6581958?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

vector<int> moveZeros(int n, vector<int> a) {
    int cnt = 0;
    vector<int> movedArr;
    for(int i = 0 ; i<n; i++)
    {
        if(a[i]!=0)
        {
            movedArr.push_back(a[i]);
        }
        else
        {
            cnt++;
        }
    }
    while(cnt !=0)
    {
        movedArr.push_back(0);
        cnt--;
    }
    return movedArr;
}
