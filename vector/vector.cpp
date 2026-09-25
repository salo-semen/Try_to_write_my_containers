#include "vector.h"
#include <iostream>

int main() {
    Vector<int> v;
    std::cout << v.empty() << std::endl;
    v.push_back(1);
    v.push_back(2);

}