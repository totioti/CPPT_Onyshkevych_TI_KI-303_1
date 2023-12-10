import math
import pickle


class Calculation:

    def __init__(self):
        self.result = 0

    def calc(self, x):
        try:
            self.result = math.cos(x) / math.tan(2 * x)
        except ZeroDivisionError:
            print("ZeroDivisionError occured")

    def save_to_binary(self, filename):
        with open(filename, 'wb') as file:
            pickle.dump(self.result, file)

    def load_from_binary_file(self, filename):
        with open(filename, 'rb') as file:
            self.result = pickle.load(file)

    def save_to_text_file(self, filename):
        with open(filename, 'w') as file:
            file.write(str(self.result))

    def load_from_text_file(self, filename):
        with open(filename, 'r') as file:
            self.result = str(file.read())


def main():
    equation = Calculation()
    equation.calc(0)
    equation.save_to_binary("binary.txt")
    equation.load_from_binary_file("binary.txt")
    print(equation.result)
    equation.save_to_text_file("text.txt")
    equation.load_from_text_file("text.txt")
    print(equation.result)


if __name__ == "__main__":
    main()
