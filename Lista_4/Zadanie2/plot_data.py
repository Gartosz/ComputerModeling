from matplotlib import pyplot as plt
from glob import glob
from numpy import loadtxt

if __name__ == "__main__":
    dirs = [glob("1D/*")[-1], glob("2D/*")[-1]]
