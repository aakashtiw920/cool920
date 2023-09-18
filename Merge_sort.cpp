#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>&a)
{
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void merge(vector<int>&a,int s,int mid,int e,vector<int>&temp)
{
    int k=s,j=mid+1,i=s;
    while(i<=mid && j<=e)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }
    while(s<=e)
    {
        a[s]=temp[s];  //a[++s]!=temp[++s] kyunki wo already increment hogya hai, phir"=" kaise change hoga
        ++s;
    }
    print(a);
}
void mergesort(vector<int>&a, int s,int e,vector<int>&temp)
{
    if(s>=e) return;
    int mid=s+(e-s)/2;
    mergesort(a,s,mid,temp);
    mergesort(a,mid+1,e,temp);
    merge(a,s,mid,e,temp);
}
int main()
{
    vector<int>a{89,8,43,3,7,3,2,146,7,3,5,8,8,35,1};
    vector<int>temp(a.size()-1);
    mergesort(a,0,a.size()-1,temp);
    print(a);
}