#include "vector.hpp"

int main() {
    dsa::Vector<int> v;
    for (int i{0}; i < 5; ++i) {
        v.push_back(i);
    }
    const dsa::Vector<int>& cv = v;
}
