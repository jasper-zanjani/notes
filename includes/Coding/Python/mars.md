```py
def main():
    weight = input("Enter weight in kilograms:\n")
    try:
        mars_weight = (int(weight)/9.81) * 3.711
    except ValueError:
        mars_weight = 0.0
    print("Weight on Mars: {} kg".format(mars_weight))


if __name__ == '__main__':
    main()
```