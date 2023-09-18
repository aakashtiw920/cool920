#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int  find_max_sub_array(vector<int>&a,int s,int e)
{
    if(s==e) return a[s];
    int max_leftB_sum=INT_MIN,max_rightB_sum=INT_MIN;
    int mid=s+((e-s)>>1);

    int left_sum=find_max_sub_array(a,s,mid);
    int right_sum=find_max_sub_array(a,mid+1,e);

    int leftB_sum=0,rightB_sum=0;

    for(int i=mid;i>=s;i--)
    {
        leftB_sum+=a[i];
        if(leftB_sum>max_leftB_sum)
        {
            max_leftB_sum=leftB_sum;
        } 
    }
    for(int i=mid+1;i<=e;i++)
    {
        rightB_sum+=a[i];
        if(rightB_sum>max_rightB_sum)
        {
            max_rightB_sum=rightB_sum;
        }
    }
    int crossB_sum= max_leftB_sum +  max_rightB_sum;

    return max(crossB_sum,max(left_sum,right_sum));
}
int main()
{
    vector<int>a{-2,1,-3,4,-1,2,1,-5,4};
    cout<<find_max_sub_array(a,0,a.size()-1);
}