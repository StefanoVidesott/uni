#include <iostream>
#include <fstream>

/*
Scrivere un programma che, dato un file in input da linea di comando
contenente diverse temperature. Il file è costituito da una sola colonna
e le temperature sono rappresentate come numeri reali. Il programma
salvi queste temperature in un array dinamico e stampi a video le
prime N temperature più alte. Il valore N viene specificato dall’utente
da linea di comando. Il programma accetta anche un intero M che
indica quante temperature al massimo sono presenti nel file.
*/

void DecreasingBubbleSort(double*, int);
void PrintArray(double*, int);

int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cerr << "Numero parametri non coerente: proram <file_di_input> <N> <M>\n";
        return 1;
    }

    std::string filename = argv[1];
    int N = std::atoi(argv[2]);
    int M = std::atoi(argv[3]);

    double* temperatures = new double[M];
    int count = 0;

    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Errore nell'apertura del file: " << filename << "\n";
        return 1;
    }

    while (file >> temperatures[count] && count < M) {
        count++;
    }

    file.close();

    if (count < N) {
        std::cerr << "Il file contiene meno di " << N << " temperature\n";
        delete[] temperatures;
        return 1;
    }

    DecreasingBubbleSort(temperatures, count);

    std::cout << "Le prime " << N << " temperature più alte sono:\n";
    PrintArray(temperatures, N);

    delete[] temperatures;

    return 0;
}

void DecreasingBubbleSort(double* _array, int _count) {
    for (int i = 0; i < _count - 1; ++i) {
        for (int j = 0; j < _count - i - 1; ++j) {
            if (_array[j] < _array[j + 1]) {
                double temp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = temp;
            }
        }
    }
}

void PrintArray(double* _array, int _count) {
    for (int i = 0; i < _count; ++i) {
        std::cout << _array[i] << " ";
    }
    std::cout << "\n";
}
