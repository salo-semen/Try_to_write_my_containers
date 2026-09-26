#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector();
    Vector(const Vector& other);
    ~Vector();
    void push_back(const T& x);
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void reserve(size_t n);
    void resize(size_t n);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* data() const;
    void pop_back();
    // void push_back(T&& x);
    void clear();
    
    void insert();
    void erase();
private:
    T* Array_;
    size_t Size_;
    size_t Capacity_;

    void RemakeArray(size_t newCapacity);
};

//Добавить Итерататоры, выделение памяти через аллокаторы и умные указатели, конструкторы копирования, перемещения

template <typename T>
Vector<T>::Vector() : Array_(nullptr), Size_(0), Capacity_(0) {};

template <typename T>
Vector<T>::~Vector() {
    delete[] Array_;
}

template <typename T>
void Vector<T>::RemakeArray(size_t newCapacity) {
    T* newArray = new T[newCapacity];
    for (size_t i = 0; i != Size_; ++i) {
        newArray[i] = Array_[i];
    }
    T* temp = Array_;
    Array_ = newArray;
    newArray = temp;
    delete[] newArray;

    Capacity_ = newCapacity;
}

template <typename T>
void Vector<T>::push_back(const T& x) {
    if (Size_ == Capacity_) {
        size_t newCapacity = (Capacity_ == 0) ? 1 : Capacity_ * 2;
        RemakeArray(newCapacity);
    }
    Array_[Size_] = x;
    ++Size_;
}

template <typename T>
size_t Vector<T>::size() const {
    return Size_;
}

template <typename T>
size_t Vector<T>::capacity() const {
    return Capacity_;
}

template <typename T>
bool Vector<T>::empty() const {
    return Size_ == 0;
}

template <typename T>
void Vector<T>::reserve(size_t n) {
    if (n > Capacity_) {
        RemakeArray(n);
        Capacity_ = n;
    }
}

template <typename T>
void Vector<T>::resize(size_t n) {
    if (n < Size_) {
        for (size_t i = n; i != Size_; ++i) {
            Array_[i].~T();
        }
    } else if (n > Size_) {
        if (n > Capacity_) {
            reserve(n);
        } else {
            for (size_t i = Size_; i != n; ++i) {
                Array_[i] = T();
            }
        }
    }
    Size_ = n;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return Array_[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return Array_[index];
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index < Size_) {
        return Array_[index];
    } else {
        throw std::out_of_range("Index is less than 0 or greater than array size");
    }
}

template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index < Size_) {
        return Array_[index];
    } else {
        throw std::out_of_range("Index is less than 0 or greater than array size");
    }
}

template <typename T>
T& Vector<T>::front() {
    return Array_[0];
}

template <typename T>
const T& Vector<T>::front() const {
    return Array_[0];
}

template <typename T>
T& Vector<T>::back() {
    return Array_[Size_ - 1];
}

template <typename T>
const T& Vector<T>::back() const {
    return Array_[Size_ - 1];
}

template <typename T>
T* Vector<T>::data() const {
    return Array_;
}

template <typename T>
void Vector<T>::pop_back() {
    Array_[Size_ - 1].~T();
    --Size_;
}

template <typename T>
void Vector<T>::clear() {
    for (size_t i = 0; i != Size_; ++i) {
        Array_[i].~T();
    }
    Size_ = 0;
}