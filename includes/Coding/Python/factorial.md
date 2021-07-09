``` py linenums="1"
import math
import sys


def main():
    number = get_number()
    factorial = get_factorial(number)
    print(f"{number}! = {factorial}")


def get_factorial(number: int):
    factorial = math.prod(list(range(number + 1)))
    return factorial


def get_number():
    number = 0

    if len(sys.argv) == 2:
        try:
            number = int(sys.argv[1])
            return number
        except IndexError:
            pass
        except ValueError:
            pass

    while True:
        try:
            number = int(input("Enter a number: "))
            break
        except ValueError:
            print("Argument must be an integer")

    return number


if __name__ == "__main__":
    main()

```