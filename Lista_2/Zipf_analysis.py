from re import sub
from matplotlib import pyplot as plt
from scipy.optimize import curve_fit

def fun_to_fit(r, c, b):
    return c*r**b

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
        x_data = list(words_ranks.keys())
        y_data = list(zip(*words_ranks.values()))[1]
        popt, pcov = curve_fit(fun_to_fit, x_data, y_data)
        fitted = fun_to_fit(x_data, popt[0], popt[1])
        plt.scatter(x_data, y_data, s = 10)
        plt.plot(x_data, fitted)
        plt.xlabel("Liczba wystąpień")
        plt.ylabel("Ranga")
        plt.title(file_name)
        plt.figtext(0.65, 0.9, "c = {c}\nb = {b}".format(c = popt[0], b = popt[1]))
        plt.show()