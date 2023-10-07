# Just pseudocode


words = set()


def check(word):
    if word.lower() in words:
        return True
    else:
        return False


def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
        file.close()
        return True


def size():
    return len(words)


def unload():
    return True
