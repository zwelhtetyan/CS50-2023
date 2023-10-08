import sys
from pyfiglet import Figlet
from pyfiglet import FigletFont
import random


def main():
    valid_flag = ["-f", "--font"]
    argv = sys.argv
    argc = len(argv)

    if argc == 1:
        input_str = str(input("Input: "))
        all_fonts = FigletFont.getFonts()
        random_font = random.choice(all_fonts)

        renderText(input_str, random_font)
    elif argc == 3:
        flag = argv[1]
        desired_font = argv[2]
        all_fonts = FigletFont.getFonts()

        if flag in valid_flag and desired_font in all_fonts:
            input_str = str(input("Input: "))

            renderText(input_str, desired_font)
        else:
            print("Invalid usage!")
            sys.exit(1)
    else:
        print("Invalid usage!")
        sys.exit(1)


def renderText(input_str, font):
    f = Figlet(font=font)
    print("Output: ")
    print(f.renderText(input_str))


main()
