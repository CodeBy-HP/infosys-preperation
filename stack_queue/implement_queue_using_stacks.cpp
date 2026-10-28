#include<bits/stdc++.h>
using namespace std;


class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        // no need brother
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int element = peek();
        s2.pop();
        return element;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                int element = s1.top();
                s1.pop();
                s2.push(element);
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main(){

}


// 5 4 3 2 1

// s1 

// s2  

// queue -> first in first out

// ________
// ________

// stack -> last in first out

// | |
// | |
// |_|