#include<bits/stdc++.h>
using namespace std;

int pratition(int arr[],int l,int h)
{
    int pivot=arr[l];
    int i=l;
    int j=h;

    while(i<j)
    {
        while(pivot>=arr[i])i++;
        while(pivot<arr[j])j--;
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);

    return j;

}

void quickshort(int arr[],int l,int h)
{
    int pivot = pratition(arr,l,h);
    pratition(arr,l,pivot);
    pratition(arr,pivot+1,h);

}



int main()
{
    int arr[]={4,7,3,8,2,1,9};
    quickshort(arr,0,7);
    for(int i:arr)
    cout<<" "<<i;
}
