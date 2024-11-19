#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

namespace sv {

    // COMMON FUNCTIONS
    namespace common {

        // Returns a random value in the range [_min, _max] (only for arithmetic types).
        template <typename T>
        T RandomValue(T _min, T _max) {
            static_assert(std::is_arithmetic<T>::value, "RandomValue requires an arithmetic type");
            return _min + static_cast<T>(rand()) / RAND_MAX * (_max - _min);
        }

        // Swaps two values
        template <typename T>
        void Swap(T& _a, T& _b) {
            T temp = _a;
            _a = _b;
            _b = temp;
        }

        // Returns the absolute value of a number
        template <typename T>
        T Abs(T _value) {
            return _value < 0 ? -_value : _value;
        }

        // Returns the maximum of two values
        template <typename T>
        T Max(T _a, T _b) {
            return _a > _b ? _a : _b;
        }

        // Returns the minimum of two values
        template <typename T>
        T Min(T _a, T _b) {
            return _a < _b ? _a : _b;
        }

        // Returns the factorial of a number
        int Factorial(int _n) {
            if (_n < 0) {
                return -1;
            }
            int result = 1;
            for (int i = 2; i <= _n; ++i) {
                result *= i;
            }
            return result;
        }

        // Returns the nth Fibonacci number
        int Fibonacci(int _n) {
            if (_n < 0) {
                return -1;
            }
            if (_n == 0) {
                return 0;
            }
            if (_n == 1) {
                return 1;
            }
            int a = 0, b = 1, c;
            for (int i = 2; i <= _n; ++i) {
                c = a + b;
                a = b;
                b = c;
            }
            return b;
        }

        // Returns the nth Fibonacci number using recursion
        int FibonacciRecursive(int _n) {
            if (_n < 0) {
                return -1;
            }
            if (_n == 0) {
                return 0;
            }
            if (_n == 1) {
                return 1;
            }
            return FibonacciRecursive(_n - 1) + FibonacciRecursive(_n - 2);
        }

        // Returns the nth Fibonacci number using memoization
        int FibonacciMemoization(int _n, int* _memo) {
            if (_n < 0) {
                return -1;
            }
            if (_n == 0) {
                return 0;
            }
            if (_n == 1) {
                return 1;
            }
            if (_memo[_n] != -1) {
                return _memo[_n];
            }
            _memo[_n] = FibonacciMemoization(_n - 1, _memo) + FibonacciMemoization(_n - 2, _memo);
            return _memo[_n];
        }

    }

    // LINKED LISTS
    namespace ll {

        // Node structure for linked lists
        template <typename T>
        struct Node {
            T data;
            Node* next;
        };

        // Inserts a new node at the beginning of the linked list
        template <typename T>
        void InsertFront(Node<T>*& _head, T _data) {
            Node<T>* newNode = new Node<T>;
            newNode->data = _data;
            newNode->next = _head;
            _head = newNode;
        }

        // Inserts a new node at the end of the linked list
        template <typename T>
        void InsertBack(Node<T>*& _head, T _data) {
            Node<T>* newNode = new Node<T>;
            newNode->data = _data;
            newNode->next = nullptr;
            if (_head == nullptr) {
                _head = newNode;
            } else {
                Node<T>* temp = _head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        // Insert a new node at a specific position in the linked list
        template <typename T>
        void InsertAt(Node<T>*& _head, T _data, int _position) {
            if (_position < 0) {
                std::cerr << "Invalid position\n";
                return;
            }
            if (_position == 0) {
                InsertFront(_head, _data);
                return;
            }
            Node<T>* newNode = new Node<T>;
            newNode->data = _data;
            Node<T>* temp = _head;
            for (int i = 0; i < _position - 1; ++i) {
                if (temp == nullptr) {
                    std::cerr << "Invalid position\n";
                    delete newNode;
                    return;
                }
                temp = temp->next;
            }
            if (temp == nullptr) {
                std::cerr << "Invalid position\n";
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        // Deletes the first node of the linked list
        template <typename T>
        void DeleteFront(Node<T>*& _head) {
            if (_head != nullptr) {
                Node<T>* temp = _head;
                _head = _head->next;
                delete temp;
            }
        }

        // Deletes the last node of the linked list
        template <typename T>
        void DeleteBack(Node<T>*& _head) {
            if (_head != nullptr) {
                if (_head->next == nullptr) {
                    delete _head;
                    _head = nullptr;
                } else {
                    Node<T>* temp = _head;
                    while (temp->next->next != nullptr) {
                        temp = temp->next;
                    }
                    delete temp->next;
                    temp->next = nullptr;
                }
            }
        }

        // Deletes all nodes of the linked list
        template <typename T>
        void DeleteAll(Node<T>*& _head) {
            while (_head != nullptr) {
                DeleteFront(_head);
            }
        }

        // Prints the linked list elements
        template <typename T>
        void PrintList(Node<T>* _head) {
            Node<T>* temp = _head;
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }

        // Prints the doubly linked list elements
        template <typename T>
        void PrintList(DoubleNode<T>* _head) {
            DoubleNode<T>* temp = _head;
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }

        // Searches for a value in the linked list, returns true if found
        template <typename T>
        bool SearchList(Node<T>* _head, T _value) {
            Node<T>* temp = _head;
            while (temp != nullptr) {
                if (temp->data == _value) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        // Deletes the first occurrence of a value in the linked list
        template <typename T>
        void DeleteValue(Node<T>*& _head, T _value) {
            Node<T>* temp = _head;
            Node<T>* prev = nullptr;
            while (temp != nullptr) {
                if (temp->data == _value) {
                    if (prev == nullptr) {
                        _head = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
        }

    }

    // DOUBLY LINKED LIST
    namespace dll {

        // Node structure for doubly linked lists
        template <typename T>
        struct DoubleNode {
            T data;
            DoubleNode* prev;
            DoubleNode* next;
        };

        // Action option for list interactions
        enum Action {
            FRONT,
            BACK
        };

        // Inserts a new node at the beginning or end of the doubly linked list
        template <typename T>
        void Insert(DoubleNode<T>*& _head, T _data, Action _action) {
            DoubleNode<T>* newNode = new DoubleNode<T>;
            newNode->data = _data;
            if (_head == nullptr) {
                newNode->prev = nullptr;
                newNode->next = nullptr;
                _head = newNode;
            } else {
                if (_action == FRONT) {
                    newNode->prev = nullptr;
                    newNode->next = _head;
                    _head->prev = newNode;
                    _head = newNode;
                } else {
                    DoubleNode<T>* temp = _head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    newNode->prev = temp;
                    newNode->next = nullptr;
                    temp->next = newNode;
                }
            }
        }

        // Deletes the first or last node of the doubly linked list
        template <typename T>
        void Delete(DoubleNode<T>*& _head, Action _action) {
            if (_head != nullptr) {
                if (_head->next == nullptr) {
                    delete _head;
                    _head = nullptr;
                } else {
                    if (_action == FRONT) {
                        DoubleNode<T>* temp = _head;
                        _head = _head->next;
                        _head->prev = nullptr;
                        delete temp;
                    } else {
                        DoubleNode<T>* temp = _head;
                        while (temp->next->next != nullptr) {
                            temp = temp->next;
                        }
                        delete temp->next;
                        temp->next = nullptr;
                    }
                }
            }
        }

        // Deletes all nodes of the doubly linked list
        template <typename T>
        void DeleteAll(DoubleNode<T>*& _head) {
            while (_head != nullptr) {
                Delete(_head, FRONT);
            }
        }

        // Searches for a value in the doubly linked list, from head or tail, returns true if found
        template <typename T>
        bool Search(DoubleNode<T>* _head, T _value, Action _action) {
            DoubleNode<T>* temp = nullptr;
            if (_action == FRONT) {
                temp = _head;
                while (temp != nullptr) {
                    if (temp->data == _value) {
                        return true;
                    }
                    temp = temp->next;
                }
            } else {
                temp = _head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                while (temp != nullptr) {
                    if (temp->data == _value) {
                        return true;
                    }
                    temp = temp->prev;
                }
            }
            return false;
        }

        // Deletes the first occurrence of a value in the doubly linked list starting from head or tail
        template <typename T>
        void DeleteValue(DoubleNode<T>*& _head, T _value, Action _action) {
            DoubleNode<T>* temp = nullptr;
            if (_action == FRONT) {
                temp = _head;
                while (temp != nullptr) {
                    if (temp->data == _value) {
                        if (temp->prev == nullptr) {
                            _head = temp->next;
                            if (temp->next != nullptr) {
                                temp->next->prev = nullptr;
                            }
                        } else {
                            temp->prev->next = temp->next;
                            if (temp->next != nullptr) {
                                temp->next->prev = temp->prev;
                            }
                        }
                        delete temp;
                        return;
                    }
                    temp = temp->next;
                }
            } else {
                temp = _head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                while (temp != nullptr) {
                    if (temp->data == _value) {
                        if (temp->prev == nullptr) {
                            _head = temp->next;
                            if (temp->next != nullptr) {
                                temp->next->prev = nullptr;
                            }
                        } else {
                            temp->prev->next = temp->next;
                            if (temp->next != nullptr) {
                                temp->next->prev = temp->prev;
                            }
                        }
                        delete temp;
                        return;
                    }
                    temp = temp->prev;
                }
            }
        }

    }

    namespace array_interactions {

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

        // Swaps two indexes in the array
        template <typename T>
        void SwapArrayIndexes(T* _array, int _index1, int _index2) {
            T temp = _array[_index1];
            _array[_index1] = _array[_index2];
            _array[_index2] = temp;
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

        // Populates the array with random values in the range [_min, _max] (only for arithmetic types).
        // Rememeber to call srand(time(0)) before using this function
        template <typename T>
        void PopulateArrayRandom(T* _array, int _count, T _min, T _max) {
            static_assert(std::is_arithmetic<T>::value, "PopulateArrayRandom requires an arithmetic type");
            for (int i = 0; i < _count; ++i) {
                _array[i] = common::RandomValue(_min, _max);
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

        // Shifts the array elements to the left by _shift positions
        template <typename T>
        void ShiftLeftArray(T* _array, int _count, int _shift) {
            _shift %= _count;
            if (_shift < 0) {
                _shift += _count;
            }
            for (int i = 0; i < _shift; ++i) {
                T temp = _array[0];
                for (int j = 0; j < _count - 1; ++j) {
                    _array[j] = _array[j + 1];
                }
                _array[_count - 1] = temp;
            }
        }

        // Shifts the array elements to the right by _shift positions
        template <typename T>
        void ShiftRightArray(T* _array, int _count, int _shift) {
            _shift %= _count;
            if (_shift < 0) {
                _shift += _count;
            }
            for (int i = 0; i < _shift; ++i) {
                T temp = _array[_count - 1];
                for (int j = _count - 1; j > 0; --j) {
                    _array[j] = _array[j - 1];
                }
                _array[0] = temp;
            }
        }

        // Removes the duplicates from the array
        template <typename T>
        void RemoveDuplicates(T* _array, int& _count) {
            for (int i = 0; i < _count; ++i) {
                for (int j = i + 1; j < _count;) {
                    if (_array[i] == _array[j]) {
                        for (int k = j; k < _count - 1; ++k) {
                            _array[k] = _array[k + 1];
                        }
                        --_count;
                    } else {
                        ++j;
                    }
                }
            }
        }

        // Merges two sorted arrays into a new sorted array
        template <typename T>
        void MergeSortedArrays(T* _array1, int _count1, T* _array2, int _count2, T* _result) {
            int i = 0, j = 0, k = 0;
            while (i < _count1 && j < _count2) {
                if (_array1[i] < _array2[j]) {
                    _result[k++] = _array1[i++];
                } else {
                    _result[k++] = _array2[j++];
                }
            }
            while (i < _count1) {
                _result[k++] = _array1[i++];
            }
            while (j < _count2) {
                _result[k++] = _array2[j++];
            }
        }

    }

}

#endif
