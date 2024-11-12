#include <iostream>
#include <cmath>

int InvertNumber(int);

int main() {

    std::cout << InvertNumber(654) << std::endl;

}

int InvertNumber(int _number) {

    int result = 0;
    int digit = 0;

    while(_number != 0) {

        int unita = _number % 10;
        _number /= 10;
        result *= 10;
        result += unita;

    }

    return result;

}