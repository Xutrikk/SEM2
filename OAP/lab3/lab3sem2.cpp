#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <map> 
//Скопировать из файла FILE1 в файл FILE2 все строки, в которых содержится не менее двух одинаковых слов. 
//Определить номер слова, в котором больше всего цифр.

using namespace std; 

// Функция для копирования строк с двумя или более одинаковыми словами
void copyLinesWithDuplicateWords(const string& inputFile, const string& outputFile) {
    setlocale(LC_ALL, "rus"); 
    ifstream inFile(inputFile); 
    ofstream outFile(outputFile); 
    string line; 

    // Читаем строки из файла
    while (getline(inFile, line)) {
        istringstream iss(line); // создаем строковый поток
        map<string, int> wordCount; // map для подсчета слов
        string word; 

        // Читаем слова из строки
        while (iss >> word) {
            wordCount[word]++; 
        }

        // Проверяем количество одинаковых слов
        for (auto& wc : wordCount) {
            if (wc.second >= 2) {
                outFile << line << '\n'; 
                break;
            }
        }
    }

    inFile.close(); 
    outFile.close(); 
}

// Функция для определения номера слова с наибольшим количеством цифр
int wordWithMostDigits(const string& inputFile) {
    ifstream inFile(inputFile); 
    string line; 
    int maxDigits = 0, wordNumber = 0, maxDigitsWordNumber = 0; 

    // Читаем строки из файла
    while (getline(inFile, line)) {
        istringstream iss(line); // создаем строковый поток
        string word; 

        // Читаем слова из строки
        while (iss >> word) {
            wordNumber++; 
            int digitCount = 0; 

            // Подсчитываем количество цифр в слове
            for (char c : word) {
                if (isdigit(c)) digitCount++;
            }

            // Если количество цифр больше максимального, обновляем максимальное количество цифр и номер слова
            if (digitCount > maxDigits) {
                maxDigits = digitCount;
                maxDigitsWordNumber = wordNumber;
            }
        }
    }

    inFile.close(); 
    return maxDigitsWordNumber; 
}

int main() {
    string inputFile = "FILE1.txt"; 
    string outputFile = "FILE2.txt"; 

    copyLinesWithDuplicateWords(inputFile, outputFile); 
    cout << "Слово с наибольшим количеством цифр: " << wordWithMostDigits(inputFile) << endl; 

    return 0; 
}
