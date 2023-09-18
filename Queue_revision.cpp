#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"Present front: "<<q.front()<<endl;
    cout<<"Present back:  "<<q.back()<<endl;
    q.pop();
    cout<<"After poping element: "<<q.front()<<endl;
    q.();
    cout<<"After using pop in back: "<<q.back();
    return 0;
}