#include <iostream>
#include <stack>

class MyQueue{
public:
    std::stack<int> st1;
    std::stack<int> st2;

    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if(st2.empty()) {
            while(st1.size()!=0) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        int ret = st2.top();
        st2.pop();

        return ret;
    }

    int peek() {
        if(st2.empty()) {
            while(st1.size()!=0) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int ret = st2.top();

        return ret;
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main(int argc, char* argv[]) {
    MyQueue s;

    s.push(1);
    s.push(2);
    std::cout<<s.peek()<<std::endl;
    s.pop();
    std::cout<<s.empty()<<std::endl;

    return 0;
}