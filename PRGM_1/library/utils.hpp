#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Sorts an array in increasing order
template <typename T>
void IncreasingBubbleSort(T* _array, int _count) {
    for (int i = 0; i < _count - 1; ++i) {
        for (int j = 0; j < _count - i - 1; ++j) {
            if (_array[j] > _array[j + 1]) {
                T temp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = temp;
            }
        }
    }
}

// Sorts an array in decreasing order
template <typename T>
void DecreasingBubbleSort(T* _array, int _count) {
    for (int i = 0; i < _count - 1; ++i) {
        for (int j = 0; j < _count - i - 1; ++j) {
            if (_array[j] < _array[j + 1]) {
                T temp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = temp;
            }
        }
    }
}

// Finds the maximum element in the array
template <typename T>
T FindMax(T* _array, int _count) {
    T max = _array[0];
    for (int i = 1; i < _count; ++i) {
        if (_array[i] > max) {
            max = _array[i];
        }
    }
    return max;
}

// Finds the minimum element in the array
template <typename T>
T FindMin(T* _array, int _count) {
    T min = _array[0];
    for (int i = 1; i < _count; ++i) {
        if (_array[i] < min) {
            min = _array[i];
        }
    }
    return min;
}

// Calculates the mean (average) of the array elements (only for arithmetic types)
template <typename T>
double CalculateMean(T* _array, int _count) {
    double sum = 0.0;
    for (int i = 0; i < _count; ++i) {
        sum += static_cast<double>(_array[i]);
    }
    return sum / _count;
}

// Calculates the standard deviation of the array elements (only for arithmetic types)
template <typename T>
double CalculateStandardDeviation(T* _array, int _count) {
    double mean = CalculateMean(_array, _count);
    double sum = 0.0;
    for (int i = 0; i < _count; ++i) {
        sum += pow(static_cast<double>(_array[i]) - mean, 2);
    }
    return sqrt(sum / _count);
}

// Finds the median of an array (modifies the array for sorting)
template <typename T>
T CalculateMedian(T* _array, int _count) {
    IncreasingBubbleSort(_array, _count);
    if (_count % 2 == 0) {
        return (_array[_count / 2 - 1] + _array[_count / 2]) / 2.0;
    } else {
        return _array[_count / 2];
    }
}

// Searches for an element in the array, returns the index or -1 if not found
template <typename T>
int LinearSearch(T* _array, int _count, T _value) {
    for (int i = 0; i < _count; ++i) {
        if (_array[i] == _value) {
            return i;
        }
    }
    return -1;
}

// Prints the array elements
template <typename T>
void PrintArray(T* _array, int _count) {
    for (int i = 0; i < _count; ++i) {
        std::cout << _array[i] << " ";
    }
    std::cout << "\n";
}

// Populates the array with user input
template <typename T>
void PopulateArrayUser(T* _array, int _count) {
    for (int i = 0; i < _count; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> _array[i];
    }
}

template <typename T>
T RandomValue(T _min, T _max) {
    static_assert(std::is_arithmetic<T>::value, "RandomValue requires an arithmetic type");
    return _min + static_cast<T>(rand()) / RAND_MAX * (_max - _min);
}

// Populates the array with random values in the range [_min, _max] (only for arithmetic types).
// Rememeber to call srand(time(0)) before using this function
template <typename T>
void PopulateArrayRandom(T* _array, int _count, T _min, T _max) {
    static_assert(std::is_arithmetic<T>::value, "PopulateArrayRandom requires an arithmetic type");
    for (int i = 0; i < _count; ++i) {
        _array[i] = RandomValue(_min, _max);
    }
}

// Populates the array with values from a file
template <typename T>
void PopulateArrayFile(T* _array, int _count, const char* _filename) {
    std::ifstream file(_filename);
    if (!file) {
        std::cerr << "Error opening file: " << _filename << "\n";
        return;
    }
    for (int i = 0; i < _count && file >> _array[i]; ++i) {
        // Reading elements from the file
    }
    file.close();
}

// Saves the array elements to a file
template <typename T>
void SaveArrayToFile(T* _array, int _count, const char* _filename) {
    std::ofstream file(_filename);
    if (!file) {
        std::cerr << "Error opening file: " << _filename << "\n";
        return;
    }
    for (int i = 0; i < _count; ++i) {
        file << _array[i] << "\n";
    }
    file.close();
}

// Calculates the sum of all elements in the array (only for arithmetic types)
template <typename T>
T CalculateSum(T* _array, int _count) {
    T sum = T();
    for (int i = 0; i < _count; ++i) {
        sum += _array[i];
    }
    return sum;
}

// Reverses the order of elements in the array
template <typename T>
void ReverseArray(T* _array, int _count) {
    for (int i = 0; i < _count / 2; ++i) {
        T temp = _array[i];
        _array[i] = _array[_count - 1 - i];
        _array[_count - 1 - i] = temp;
    }
}

#endif
