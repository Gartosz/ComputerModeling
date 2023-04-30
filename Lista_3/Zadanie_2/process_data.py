from glob import glob
from numpy import loadtxt
from matplotlib import pyplot as plt
from sys import argv
from numpy import sqrt

if __name__ == "__main__":
    files = glob("v*.txt")
    if len(argv) >= 2:
        files = [file for file in files if float(argv[1]) >= float(file.split("v_")[1].replace("_", ".").split(".txt")[0])]
    d_values = []
    v0_values = []
    for file_name in files:
        x1, y1, x2, y2 = loadtxt(file_name, delimiter=' ', unpack=True)
        d1 = max(x1) - min(x1)
        d2 = max(y1) - min(y1)
        d_values.append(d1/d2)
        v0_values.append(float(file_name.split("v_")[1].replace("_", ".").split(".txt")[0]))
        plt.figure()
        plt.plot(x1, y1)
        plt.plot(x2, y2)
        plt.xlabel("x")
        plt.ylabel("y")
        plt.savefig(file_name.removesuffix("txt") + "svg", format = "svg")
        plt.close()
    plt.scatter(v0_values, d_values)
    plt.xlabel("v0")
    plt.ylabel("d1/d2")
    m1 = 1 if len(argv) < 3 else argv[2]
    m2 = 1 if len(argv) < 4 else argv[3]
    plt.axvline(sqrt((m1**m1)/(m1+m2)))
    plt.grid()
    plt.savefig("d1_d2.svg", format = "svg")
    plt.close()