from re import sub
from matplotlib import pyplot as plt

if __name__ == "__main__":
    files = ["tekst_1.txt"]
    for file_name in files:
        words_dict = {}
        with open(file_name, "r", encoding="utf-8") as file:
            words = file.read().split()
            words = [sub(r'\W+', '', word.lower()) for word in words]
            words_dict = {word: words.count(word) for word in set(words)}
        words_dict = dict(sorted(words_dict.items(), reverse=True, key=lambda item: item[1]))
        words_ranks = {rank + 1: (word, words_dict[word]) for rank, word in enumerate(words_dict.keys())}
        plt.plot(words_ranks.keys(), list(zip(*words_ranks.values()))[1])
        plt.xlabel("Liczba wystąpień")
        plt.ylabel("Ranga")
        plt.show()