//
//  main.cpp
//  StackQueuePriority
//
//  Created by Zareek Galvan on 3/3/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#include <iostream>
using namespace std;
#include <sstream>
#include <stack>
#include <vector>
#include <queue>
#include <deque>


int ent(string s)
{
    int n=0;
    for (int i=0; i<s.length(); i++)
    {
        n = n*10 + (s[i] - '0');
    }
    
    return n;
}

int main()
{
    string da,data;
    
    getline(cin, data);
    while (data != "#")
    {
        stringstream ss;
        ss<< data;
        stack<int> mystack;
        queue<int> myqueue;
        priority_queue<int, vector<int>, greater<int> > mypqueue;
        while (ss >> da)
        {
            int a=0,b=0,c=0,d=0,e=0,f=0,rs=0,rq=0,rp=0;
            if (da=="+")
            {
                a=mystack.top();
                mystack.pop();
                b=mystack.top();
                mystack.pop();
                rs=b+a;
                mystack.push(rs);
                c=myqueue.front();
                myqueue.pop();
                d=myqueue.front();
                myqueue.pop();
                rq=d+c;
                myqueue.push(rq);
                e=mypqueue.top();
                mypqueue.pop();
                f=mypqueue.top();
                mypqueue.pop();
                rp=f+e;
                mypqueue.push(rp);
            }
            else if (da=="-")
            {
                a=mystack.top();
                mystack.pop();
                b=mystack.top();
                mystack.pop();
                rs=b-a;
                mystack.push(rs);
                c=myqueue.front();
                myqueue.pop();
                d=myqueue.front();
                myqueue.pop();
                rq=d-c;
                myqueue.push(rq);
                e=mypqueue.top();
                mypqueue.pop();
                f=mypqueue.top();
                mypqueue.pop();
                rp=f-e;
                mypqueue.push(rp);
            }
            else if (da=="*")
            {
                a=mystack.top();
                mystack.pop();
                b=mystack.top();
                mystack.pop();
                rs=b*a;
                mystack.push(rs);
                c=myqueue.front();
                myqueue.pop();
                d=myqueue.front();
                myqueue.pop();
                rq=d*c;
                myqueue.push(rq);
                e=mypqueue.top();
                mypqueue.pop();
                f=mypqueue.top();
                mypqueue.pop();
                rp=f*e;
                mypqueue.push(rp);
            }
            else
            {
                int i=ent(da);
                mystack.push(i);
                myqueue.push(i);
                mypqueue.push(i);
            }
        }
        cout<<mystack.top()<<" "<<myqueue.front()<<" "<<mypqueue.top()<<endl;
        getline(cin, data);	
    }
    
}

