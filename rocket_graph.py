import matplotlib.pyplot as plt

parameters = open('/home/ivankhripunov/CLionProjects/ITproject/cmake-build-debug/parameters.txt', 'r')

x = []
y = []

data = parameters.readlines()


for line in data:
    array = [float(i) for i in line.split()]
    x.append(array[0])
    y.append(array[1])

parameters.close()

fig, ax = plt.subplots()

ax.plot(x, y)
ax.axis("equal")
plt.show()