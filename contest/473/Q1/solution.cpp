#include <iostream>

using namespace std;

class solution{
public:
    long long removeZeros(long long n) {
        int times = 1;
        long long ret = 0;

        while(n) {
            if(n%10) {
                int tmp = n%10;
                ret += tmp*times;
                times *= 10;
            }

            n /= 10;
        }

        return ret;
    }
private:
};

int main(int argc, char* argv[]) {
    solution s;

    cout<<s.removeZeros(1020030)<<endl;
    cout<<s.removeZeros(1)<<endl;

    return 0;
}
