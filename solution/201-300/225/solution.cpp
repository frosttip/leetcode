#include <iostream>
#include <queue>

class MyStack{
public:
    std::queue<int> que;

    MyStack() {

    }

    void push(int x) {
        int size = que.size();
        int tmp = 0;

        que.push(x);

        while(size--) {
            tmp = que.front();
            que.pop();
            que.push(tmp);
        }
    }

    int pop() {
        int ret = que.front();
        que.pop();

        return ret;
    }

    int top() {
        int ret = que.front();

        return ret;
    }

    bool empty() {
        return que.empty();
    }
};

int main(int argc, char* argv[]) {
    MyStack s;

    s.push(1);
    s.push(2);
    std::cout<<s.top()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.empty()<<std::endl;

    return 0;
}