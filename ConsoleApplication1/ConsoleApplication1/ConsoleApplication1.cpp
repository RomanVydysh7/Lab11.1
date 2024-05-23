#include <iostream>
#include <fstream>
#include <string>

// Функція для створення файлу з даними
void createDataFile(const std::string& fileName) {
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error creating file: " << fileName << std::endl;
        return;
    }

    std::string data = "це приклад рядка з різними символами для геометрія тестування";
    outFile << data;
    outFile.close();
}

// Функція для перевірки, чи містить символ у слові "геометрія"
bool isInGeometry(char ch) {
    std::string geometry = "геометрія";
    return geometry.find(ch) != std::string::npos;
}

// Функція для копіювання символів, що не входять в слово "геометрія"
void copyNonGeometryChars(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error opening input file: " << inputFile << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error creating output file: " << outputFile << std::endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        if (!isInGeometry(ch)) {
            outFile << ch;
        }
    }

    inFile.close();
    outFile.close();
}

// Функція для виводу вмісту файлу на екран
void displayFileContent(const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
}

int main() {
    std::string inputFileName, outputFileName;

    // Введення імен файлів з клавіатури
    std::cout << "Enter the name of the input file: ";
    std::cin >> inputFileName;
    std::cout << "Enter the name of the output file: ";
    std::cin >> outputFileName;

    // Створення вхідного файлу
    createDataFile(inputFileName);

    // Копіювання символів, що не входять до "геометрія", у вихідний файл
    copyNonGeometryChars(inputFileName, outputFileName);

    // Виведення вмісту вихідного файлу на екран
    displayFileContent(outputFileName);

    return 0;
}
