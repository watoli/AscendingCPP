#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>

// 泛型算法 filter
template <typename InputIterator,
          typename OutputIterator,
          typename ElemType,
          typename Comp>
OutputIterator 
filter( InputIterator first, InputIterator last,
        OutputIterator at, 
        const ElemType &val, Comp pred )
{
    while (( first = 
             std::find_if( first, last, 
                           std::bind2nd( pred, val ))) != last )
    {
        std::cout << "found value: " << *first << std::endl;
        *at++ = *first++;
    }
    return at;
}

void ex_filter()
{
    const int elem_size = 8;

    int ia[ elem_size ] = { 12, 8, 43, 0, 6, 21, 3, 7 };
    std::vector<int> ivec( ia, ia + elem_size );

    int ia2[ elem_size ];
    std::vector<int> ivec2;

    std::cout << "filtering integer array for values less than 8\n";
    filter( ia, ia + elem_size, ia2, 8, std::less<int>() );

    std::cout << "filtering integer vector for values greater than 8\n";
    filter( ivec.begin(), ivec.end(), std::back_inserter( ivec2 ), 8, std::greater<int>() );

    std::cout << "Filtered array: ";
    for (int i = 0; i < elem_size; ++i) {
        if (ia2[i] != 0) {
            std::cout << ia2[i] << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Filtered vector: ";
    for (int num : ivec2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    ex_filter();
    return 0;
}