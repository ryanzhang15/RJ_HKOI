#include <utility>

int lucky(int l, int r);
std::pair<int, int> answer(int N);

// TODO: global variables can be declared here
#include <cstdlib>
std::pair<int, int> answer(int N) {
    srand(12534213);
    for(;;) {
        int x = rand()%(N-1);
        if(lucky(x, x+1) == 1) return std::make_pair(x, x+1);
    }
}

#ifndef ONLINE_JUDGE

int main() {
    answer(5);

}

int lucky(int l, int r) {
    printf("queried from %d to %d\n", l, r);
    return 1;
}

#endif
