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
    int total_len=e-s+1;
    int gap=(total_len/2)+(total_len%2);
    while(gap>0)
    {
        int i=s,j=s+gap;
        while(j<=e)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
            i++,j++;
        }
        gap = gap <= 1 ? 0 : (gap/2) +(gap%2);
    }

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
    vector<int>a{9,8,7,6,5,4,3,2,1,0};
    vector<int>temp(a.size()-1);
    mergesort(a,0,a.size()-1,temp);
    print(a);
}