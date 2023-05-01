from matplotlib import pyplot as plt
from glob import glob
from numpy import loadtxt

if __name__ == "__main__":
    dirs = [glob("1D/*")[-1], glob("2D/*")[-1]]
    for walk in dirs:
        plt.xlabel("time" if "1D" in walk else "x")
        plt.ylabel("y")
        plt.title(walk.split("\\")[0] + " random walk")
        for file_name in glob(walk + "/*.txt"):
            print(file_name)
            x, y = loadtxt(file_name, delimiter=' ', unpack=True)
            plt.plot(x, y)
        plt.legend(range(0, 10))
        plt.savefig(walk + "\\" + walk.split("\\")[1] + ".svg", format = "svg")
        plt.close()