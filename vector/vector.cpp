#include "vector.h"

template <typename T>
Vector<T>::Vector() {
    Array_ = new T[Capacity_];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] Array_;
}

template <typename T>
void Vector<T>::push_back(T x) {
    if (Size_ < Capacity_) {
        Array_[Size_] = x;
    } else {
        T* newArray = new T[Capacity_ * 2];
        for (size_t i = 0; i != Capacity_; ++i) {
            newArray[i] = Array_[i];
        }
        T* temp = Array_;
        Array_ = newArray;
        newArray = temp;
        delete[] newArray;

        Capacity_ *= 2;
    }
    ++Size_;
}

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
}