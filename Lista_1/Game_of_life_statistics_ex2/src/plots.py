from matplotlib import pyplot
from os import listdir
from numpy import linspace


if __name__ == "__main":
    for file_name in listdir("../bin/data/"):
        if file_name.startswith("probability"):
            with open("../bin/data/" + file_name, "r") as file:
                pyplot.figure(figsize=(20, 6))
                iterations = []
                max_value = 0
                min_value = 1
                for line in file:
                    if "Iteration" in line:
                        if len(iterations) == 0:
                            continue
                        x = [eval(iteration.split()[0]) for iteration in iterations]
                        y = [eval(iteration.split()[1]) for iteration in iterations]
                        max_value = max(y) if max(y) > max_value else max_value
                        min_value = min(y) if min(y) < min_value else min_value
                        pyplot.plot(x, y)
                        iterations = []
                    else:
                        iterations.append(line.replace('\n', ''))
                pyplot.yticks(linspace(min_value, max_value, 10))
                pyplot.xticks(list(range(0, 500)[::15])[:-1] + [499])
                pyplot.title(file_name.split('.')[0])
                pyplot.xlabel("Frame")
                pyplot.ylabel("Density")
                pyplot.savefig("../bin/data/" + fname=file_name.split('.')[0] + '.svg',format='svg')
                pyplot.show()


