def agree():
    c = str(input("Do you agree? "))

    c = c.lower()
    if c in ["y", "yes"]:
        print("Agree!")
    elif c in ["n", "no"]:
        print("Not agree!")


agree()
