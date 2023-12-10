import math


def main():
    try:
        x = float(input('Enter x: '))
        print(f'y = {math.cos(x) / math.tan(2 * x)}')
    except ValueError:
        print("Enter a number")
    except ZeroDivisionError:
        print("ZeroDivisionError occured")


if __name__ == '__main__':
    main()
