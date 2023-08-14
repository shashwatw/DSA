// https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

int isSorted(int n, vector<int> a)
{
    int x = a[0];
    for (int i = 0; i < n; i++)
    {
        if (x <= a[i])
        {
            x = a[i];
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
