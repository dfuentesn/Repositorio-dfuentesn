import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
n, p, p2, norma = np.loadtxt("twin_primes.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(n, norma, '-o', label='Relación')
ax.set_xlabel('Pareja n de números primos')
ax.set_ylabel('Norma de la pareja')
ax.legend()
fig.savefig('twin_primes.pdf')