from re import sub
from matplotlib import pyplot as plt
from scipy.optimize import curve_fit
from glob import glob

def fun_to_fit(r, c, b):
    return c*r**b

def process_file(file_name):
    with open(file_name, "r", encoding="utf-8") as file:
        words = file.read().split()
        words = [sub(r'\W+', '', word.lower()) for word in words]
        words_dict = {word: words.count(word) for word in set(words) if word != ''}
    return words_dict

def generate_words_ranks(file_name):
    words_dict = process_file(file_name)
    words_dict = dict(sorted(words_dict.items(), reverse=True, key=lambda item: item[1]))
    words_ranks = {rank + 1: (word, words_dict[word]) for rank, word in enumerate(words_dict.keys())}
    return words_ranks

def make_plot(file_name, x_data, y_data, fitted, popt):
    plt.figure()
    plt.scatter(x_data, y_data, c='r', s = 7)
    plt.plot(x_data, fitted, 'b')
    plt.xlabel("Ranga")
    plt.ylabel("Liczba wystąpień")
    plt.xscale("log")
    plt.yscale("log")
    plt.title(file_name)
    plt.figtext(0.55, 0.8, "c = {c}\nb = {b}".format(c = popt[0], b = popt[1]))
    plt.savefig(file_name.removesuffix("txt") + "svg", format = "svg")

if __name__ == "__main__":
    files = glob("*.txt")
    for file_name in files:
        words_ranks = generate_words_ranks(file_name)
        x_data = list(words_ranks.keys())
        y_data = list(zip(*words_ranks.values()))[1]
        popt, pcov = curve_fit(fun_to_fit, x_data, y_data)
        fitted = fun_to_fit(x_data, popt[0], popt[1])
        make_plot(file_name, x_data, y_data, fitted, popt)