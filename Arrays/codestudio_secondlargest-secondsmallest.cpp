// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    vector<int> arr;
    sort(a.begin(), a.end());
    arr.push_back(a[n - 2]);
    arr.push_back(a[1]);
    return arr;
}
