#include <iostream>
#include <vector>

class ArrayGenerator {

private:
    int matrixSize;
    char fillSymbol;

public:

    ArrayGenerator(int size, char symbol) : matrixSize(size), fillSymbol(symbol) {}

    std::vector<std::vector<char>> generateArray() const {
        std::vector<std::vector<char>> result;

        for (int i = 0; i < matrixSize; i++) 
        {
            std::vector<char> row;
            for (int j = 0; j < matrixSize; j++) 
            {
                char element;
                if (i % 2 == 0) 
                {
                    element = fillSymbol;
                }
                else 
                {
                    element = ' ';
                }
                row.push_back(element);
            }
            result.push_back(row);
        }
        return result;
    }
};

int main() {
    int size;
    char symbol;

    std::cout << "Enter matrix size: ";
    std::cin >> size;

    std::cout << "Enter fill symbol: ";
    std::cin >> symbol;


    ArrayGenerator arrayGen(size, symbol);
    std::vector<std::vector<char>> generatedArray = arrayGen.generateArray();

    for (int i = 0; i < generatedArray.size(); i++) 
    {
        const auto& row = generatedArray[i];
        for (int j = 0; j < row.size(); j++) 
        {
            std::cout << row[j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
