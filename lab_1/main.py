class Array:
    def __init__(self, symbol: str, size: int):
        self.symbol = symbol + " " if symbol else "0 "
        self.size = size if size else 10

    def print(self) -> None:
        for _ in range(3):
            for _ in range(self.size // 6):
                print("")
            for _ in range(self.size // 6):
                print(self.symbol * self.size)

    def generate(self) -> str:
        result = ""
        for _ in range(3):
            for _ in range(self.size // 6):
                result += "\n"
            for _ in range(self.size // 6):
                result += self.symbol * self.size
                result += "\n"
        return result


def main():
    size = int(input("Enter size: "))
    symbol = input("Enter symbol-filler: ")
    Array(symbol, size).print()

    file_name = "array.txt"

    with open(file_name, "w") as file:
        file.write(Array(symbol, size).generate())


if __name__ == '__main__':
    main()