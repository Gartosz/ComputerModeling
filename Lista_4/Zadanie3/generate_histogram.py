from matplotlib import pyplot as plt
from glob import glob
from numpy import loadtxt

if __name__ == "__main__":
    file_name = glob("*.txt")[-1]
    with open(file_name) as f:
        numbers = list(map(int, f.readlines()))
        count_1 = numbers.count(1)
        count_30 = numbers.count(30)
        print(count_1, count_30)
        n, bins, patches = plt.hist(numbers)
        print(n, bins)
        plt.savefig(file_name.removesuffix("txt") + "svg", format = "svg")
        plt.close()