#ifndef ALGO_2D_ARRAY_H__
#define ALGO_2D_ARRAY_H__

#include <vector>

namespace alg {
    template <typename T = char>
    class Array2D {
    private:
        uint32_t NR;  // num of rows
        uint32_t NC;  // num of columns
        std::vector<T> m_data;  // the place where the array resides.

    public:
        Array2D(uint32_t nrow, uint32_t ncol)
            : NR(nrow), NC(ncol), m_data(nrow * ncol) {}

        inline const uint32_t row() const { return NR; }
        inline const uint32_t col() const { return NC; }

        inline T& operator()(int row, int col) { return m_data[row * NC + col]; }
        inline const T& operator()(int row, int col) const { return m_data[row * NC + col]; }

        inline T* operator[](int row) { return &m_data[row * NC]; }
        inline const T* operator[](int row) const { return &m_data[row * NC]; }

        void clear(const T& value) {
            std::fill(m_data.begin(), m_data.end(), value);
        }
    };
}

#endif //
//Odii Odeh
