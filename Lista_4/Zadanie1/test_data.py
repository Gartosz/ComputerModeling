from matplotlib import pyplot as plt
from glob import glob

if __name__ == "__main__":
    files = [glob("rand*.txt")[-1], glob("mt_rand*.txt")[-1]]
    for file_name in files:
        with open(file_name) as f:
            numbers = list(map(float, f.readlines()))
            n, bins, patches = plt.hist(numbers)
            print(n)
            plt.savefig(file_name.removesuffix("txt") + "svg", format = "svg")
            plt.close()