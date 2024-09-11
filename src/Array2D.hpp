#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP

template <typename T>
class Array2D {
    T *m_arr;
    std::size_t m_l, m_w;

    T* m_get_pointer(std::size_t x, std::size_t y);

public:
    Array2D(std::size_t w, std::size_t l);
    Array2D(T* array, std::size_t w, std::size_t l);
    ~Array2D();

    T& At(std::size_t x, std::size_t y);
    Array2D<T> Range(std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2);
    T* Data();
    std::size_t Length();
    std::size_t Width();
    std::size_t Size();

    void Set(std::size_t x, std::size_t y, T val);
    void Set(std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2, Array2D<T> vals);
    void Fill(T val);
};

#include "Array2D.tpp"

#endif