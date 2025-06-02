import matplotlib.pyplot as plt # plot
import numpy as np # read data

x, y, y_cal  = np.loadtxt("Data.txt", unpack=True)

fig, ax = plt.subplots()
ax.plot(x, y, 'o', label="data")
ax.plot(x, y_cal, '-', label="data")
ax.set_xlabel("Hertz")
ax.set_ylabel("Voltios")
fig.suptitle('Valores encontrados: h = 6.55006e-34      ϕ = -1.73124 ', fontsize=16)
plt.show()
fig.savefig("x.pdf",bbox_inches='tight')