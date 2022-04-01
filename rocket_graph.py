import matplotlib.pyplot as plt

parameters = open('/home/ivankhripunov/CLionProjects/ITproject/cmake-build-debug/parameters.txt', 'r')

rocket_x = []
rocket_y = []
target_x = []
target_y = []

data = parameters.readlines()


for line in data:
    array = [float(i) for i in line.split()]
    rocket_x.append(array[0])
    rocket_y.append(array[1])
    target_x.append(array[2])
    target_y.append(array[3])


parameters.close()

fig, ax = plt.subplots()

ax.plot(rocket_x, rocket_y)
ax.plot(target_x, target_y)
ax.axis("equal")
plt.show()