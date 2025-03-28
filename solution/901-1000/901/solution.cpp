#include <iostream>
#include <stack>
#include <utility>

class StockSpanner{
public:
    std::stack<std::pair<int, int>> st;

    StockSpanner() {

    }

    int next(int price) {
        int ret = 1;
        while(!st.empty() && price >= st.top().first) {
            ret += st.top().second;
            st.pop();
        }

        st.push(std::make_pair(price, ret));

        return ret;
    }
};

int main(int argc, char* argv[]) {
    StockSpanner s;

    std::cout<< s.next(100) << std::endl;
    std::cout<< s.next(80) << std::endl;
    std::cout<< s.next(60) << std::endl;
    std::cout<< s.next(70) << std::endl;
    std::cout<< s.next(60) << std::endl;
    std::cout<< s.next(75) << std::endl;
    std::cout<< s.next(85) << std::endl;

    return 0;
}