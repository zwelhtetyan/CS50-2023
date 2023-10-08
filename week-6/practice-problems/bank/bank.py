def main():
    greeting = str(input("Greeting: "))

    if "hello" in greeting.lower():
        print("$0")
    elif greeting.lower().startswith("h"):
        print("$20")
    else:
        print("$100")


main()
