#include <iostream>
#include <fstream>

/*
Scrivere un programma che, dato in input da riga di comando il
nome di un file F, ritorni a video il conteggio di tutte le lettere
presenti all’interno del file. Il conteggio è case insensitive (quindi
non c’è differenza tra maiuscole e minuscole).
*/

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Numero parametri non coerente: " << argv[0] << " <file_di_input> <N> <M>\n";
        return 1;
    }

    std::string filename = argv[1];

    std::fstream file(filename.c_str());

    int count[27] = {0};
    char c;

    if (!file) {
        std::cerr << "Errore nell'apertura del file: " << filename << "\n";
        return 1;
    }

    while (file >> c) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            count[c - 'A']++;
        }
        else {
            count[26]++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        std::cout << static_cast<char>('a' + i) << ": " << count[i] << "\n";
    }
    std::cout << "Non lettere: " << count[26] << "\n";

    file.close();

    return 0;

}
