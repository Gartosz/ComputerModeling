from re import sub

if __name__ == "__main__":
    words_dict = {}
    with open("test_file.txt", "r") as file:
        words = file.read().split()
        words = [sub(r'\W+', '', word.lower()) for word in words]
        words_dict = {word: words.count(word) for word in set(words)}
    print(words_dict)