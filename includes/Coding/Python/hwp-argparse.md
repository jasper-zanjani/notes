``` py
import argparse


def main():
    parser = argparse.ArgumentParser(description="Say hello")
    parser.add_argument(
        dest="name",metavar="name", default="World", help="Name to greet"
    )
    args = parser.parse_args()
    print(f"Hello, {args.name}!")


if __name__ == "__main__":
    main()
```