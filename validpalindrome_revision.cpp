#include<iostream>
#include<string>
using namespace std;
bool validpalindrome(string s,int i,int j)
{
    if(i>=j)
    {
        return true;
    }
    if(s[i]==s[j])
    {
        i=i+1;
        j=j-1;
    }
    else{
        return false;
    }
    return validpalindrome(s,i,j);
}
int main()
{
    string s;
    cin>>s;
    if(validpalindrome(s,0,s.size()-1))
    {
        cout<<"yo man it is palindrome"<<endl;
    }
    else{
        cout<<"It is not palindrome"<<endl;
    }
    return 0;
}