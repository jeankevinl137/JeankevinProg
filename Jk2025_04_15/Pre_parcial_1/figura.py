import matplotlib.pyplot as plt
import numpy as np

x, y = np.loadtxt("magnitud_primes.txt", unpack = True)

# plot 
fig, ax = plt.subplots()

ax.plot(x, y, '--', label='norma primos gemelos')
#ax.set_xscale('log')
#ax.set_yscale('log')
plt.title('Grafica Norma de los n_esimos primos gemelos')
ax.set_xlabel(' n-esimos primos gemelos')
ax.set_ylabel('magnitud de primos')
ax.legend()
plt.show()
fig.savefig('magnitud_primes_draw.pdf')