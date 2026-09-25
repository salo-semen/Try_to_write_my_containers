#include <cstddef>

template <typename T>
class Vector {
public:
    Vector();
    Vector(const Vector& other);
    ~Vector();
    void push_back(const T& x);
    size_t size();
    size_t capacity();
    bool empty();

    void reserve(int n);
    void resize(int n);
    T operator[](size_t index);
    T at(size_t index);
    T front();
    T back();
    T* data();
    void push_back(T&& x);
    void pop_back();
    void clear();
    void insert();
    void erase();
private:
        T* Array_ = nullptr;
        size_t Size_ = 0;
        size_t Capacity_ = 1;
};

//Добавить Итерататоры, выделение памяти через аллокаторы и умные указатели, конструкторы копирования, перемещения

template <typename T>
Vector<T>::Vector() {
    Array_ = new T[Capacity_];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] Array_;
}

template <typename T>
void Vector<T>::push_back(const T& x) {
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

template <typename T>
size_t Vector<T>::size() {
    return Size_;
}

template <typename T>
size_t Vector<T>::capacity() {
    return Capacity_;
}

template <typename T>
bool Vector<T>::empty() {
    return size();
}