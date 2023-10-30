#include<bits/stdc++.h>
#include<string>

using namespace std;



int main()
{

    int n,count=0;
    cin>>n;
    int arr[n];
    string ans[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        ans[i]=to_string(arr[i]);
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])++count;
        }
        ans[i]+=to_string(count);
        count=0;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((int)ans[j][1]<(int )ans[j+1][1])
            {
                string temp=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=temp;
            }
        }
    }

    for(string i:ans)
    {
        cout<<i<<" ";
    }
}