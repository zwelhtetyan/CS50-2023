import re


def main():
    text = input("Text: ")

    l = len(re.findall('[a-zA-Z]', text))
    w = len(text.split())
    s = len(re.split(r'[.!?]', text)) - 1

    # l = 0
    # w = 1
    # s = 0
    # for i in range(len(text)):
    #     if text[i].isalpha():
    #         l += 1
    #     elif text[i].isspace():
    #         w += 1
    #     elif text[i] == '.' or text[i] == '!' or text[i] == '?':
    #         s += 1

    L = (l / w) * 100
    S = (s / w) * 100
    R = round(0.0588 * L - 0.296 * S - 15.8)

    if R >= 16:
        print("Grade 16+")
    elif R < 1:
        print("Before Grade 1\n")
    else:
        print(f"Grade {R}")


if __name__ == "__main__":
    main()
