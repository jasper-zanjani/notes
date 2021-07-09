``` py linenums="1"
import argparse

def get_args():
    parser = argparse.ArgumentParser(description="Say hello")
    parser.add_argument(
        dest="name",metavar="name", default="World", help="Name to greet"
    )
    parser.add_argument(
        "--greeting","-g", dest="greeting", default="Hello", help="Greeting to use"
    )
    return parser.parse_args()


def main():
    args = get_args()
    print(f"{args.greeting}, {args.name}!")


if __name__ == "__main__":
    main()
```