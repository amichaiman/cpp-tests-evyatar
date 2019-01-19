#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, typename S>
struct RD {
    bool operator()(const std::pair<T, S> &a, const std::pair<T, S> &b) const { return *a.first < *b.first; }
};
//                  int*           iterator
template<typename IterIn, typename IterOut>
//               int*          int*         iterator
void all_is_lost(IterIn first, IterIn last, IterOut out) {
    //            vector< pair<int*,int> > s(6)
    std::vector<std::pair<IterIn, int> > s(last - first);

    for (int i = 0; i < s.size(); ++i)
        // s[i] ---->   1000+i,   i
        // s[0] ---->   1000  ,   0
        s[i] = std::make_pair(first + i, i);

    // sort by value pointed at by s[i].first
    // sort by array a in main
    std::sort(s.begin(), s.end(), RD<IterIn, int>());

    // out iterator points to first index of b vector in main
    for (int i = 0; i < s.size(); ++i, ++out)
        // write s[i].second to vector at index i
        *out = s[i].second;
}

int main() {
    const int N = 6;
    int a[N] = {6, 5, 7, 4, 8, 3};
    std::vector<int> b(N);

    //         1000   1024
    //          int* int*   iterator
    all_is_lost(a, a + N, b.begin());

    for (int i = 0; i < N; ++i)
        std::cout << b[i] << ' ';

    std::cout << std::endl;
    return 0;
}

