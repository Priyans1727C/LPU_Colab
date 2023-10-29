#include<iostream>
#include<stdlib.h>

using namespace std;
int main()
{
    int *arr,sum=0;
    int size;
    cin>>size;
    arr=new int[size];
    if(arr=NULL)
    {
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }

    }
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
            }    
}