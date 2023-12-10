#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

class Calculation {
public:
    
    double result;

    Calculation() 
    {
        result = 0.0;
    }

    double calc(double x) 
    {
        if (x == 0)
        {
            throw std::runtime_error("Divide by zero exception");
        }
        result = std::cos(x) / std::tan(2 * x);
        return result;
    }

    void saveToBinary(const std::string& filename) {
        std::ofstream file(filename, std::ios::binary);
        if (file.is_open()) {
            file.write(reinterpret_cast<char*>(&result), sizeof(result));
        }
        else {
            std::cerr << "Failed to open binary file for writing." << std::endl;
        }
    }

    void loadFromBinary(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open()) {
            file.read(reinterpret_cast<char*>(&result), sizeof(result));
        }
        else {
            std::cerr << "Failed to open binary file for reading." << std::endl;
        }
    }

    void saveToText(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << result;
        }
        else {
            std::cerr << "Failed to open text file for writing." << std::endl;
        }
    }

    void loadFromText(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> result;
        }
        else {
            std::cerr << "Failed to open text file for reading." << std::endl;
        }
    }
};

int main() {
    
    Calculation equation;

    try {
        double result = equation.calc(5);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    equation.saveToBinary("binary.txt");
    equation.loadFromBinary("binary.txt");
    std::cout << equation.result << std::endl;

    equation.saveToText("text.txt");
    equation.loadFromText("text.txt");
    std::cout << equation.result << std::endl;

    return 0;
}
