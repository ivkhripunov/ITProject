import matplotlib.pyplot as plt

parameters = open('/home/ivankhripunov/CLionProjects/ITproject/cmake-build-debug/parameters.txt', 'r')

x = []
y = []

data = parameters.readlines()


for line in data:
    tmp_x, tmp_y = [float(i) for i in line.split()]
    x.append(tmp_x)
    y.append(tmp_y)

parameters.close()

fig, ax = plt.subplots()

ax.plot(x, y)
ax.axis("equal")
plt.show()