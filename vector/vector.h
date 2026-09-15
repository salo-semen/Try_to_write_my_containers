#include <cstddef>

template <typename T>
class Vector {
public:
    Vector();
    Vector(const Vector& other);
    ~Vector();
    void push_back(T x);
private:
        T* Array_ = nullptr;
        size_t Size_ = 0;
        size_t Capacity_ = 1;
};