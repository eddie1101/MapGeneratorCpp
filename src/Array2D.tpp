#ifndef ARRAY2D_TPP
#define ARRAY2D_TPP

#ifndef ARRAY2D_HPP
#error __FILE__ should only be included from Array2D.hpp
#endif //Array2D_HPP

#include <algorithm>
#include <cstring>

template <typename T>
T* Array2D<T>::m_get_pointer(std::size_t x, std::size_t y) {
    return m_arr + (y * m_l + x);
}

template <typename T>
Array2D<T>::Array2D(std::size_t w, std::size_t l): m_l(l), m_w(w) {
    m_arr = new T[m_l * m_w];
}

template <typename T>
Array2D<T>::Array2D(T *array, std::size_t w, std::size_t l): m_l(l), m_w(w) {
    m_arr = new T[m_l * m_w];
    for(std::size_t i = 0; i < m_l * m_w; i++) {
        m_arr[i] = array[i];
    }
    delete[] array;
}

template <typename T>
Array2D<T>::~Array2D() {
    delete[] m_arr;
}

template <typename T>
T& Array2D<T>::At(std::size_t r, std::size_t c) {
    return nullptr;
}

template <typename T>
Array2D<T> Array2D<T>::Range(std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2) {

    std::size_t width = x2 - x1;
    std::size_t length = y2 - y1;
    T *arr = new T[width * length];

    for(std::size_t i = y1; i <= y2; i++) {
        memcpy(arr + (i * width), m_arr + (i * m_w) + x1, length);
    }
    return Array2D<T>(arr, width, length);

}

template <typename T>
T* Array2D<T>::Data() {
    return m_arr;
}

template <typename T>
std::size_t Array2D<T>::Length() {
    return m_l;
}

template <typename T>
std::size_t Array2D<T>::Width() {
    return m_w;
}

template <typename T>
std::size_t Array2D<T>::Size() {
    return m_l * m_w;
}

template <typename T>
void Array2D<T>::Set(std::size_t x, std::size_t y, T val) {
    *(m_get_pointer(x, y)) = val;
}

template <typename T>
void Array2D<T>::Set(std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2, Array2D<T> vals) {
    
}

template <typename T>
void Array2D<T>::Fill(T val) {
    std::fill(begin(m_arr), end(m_arr), val);
}

#endif
