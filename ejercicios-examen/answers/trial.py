import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
x, exact, numeric = np.loadtxt("campo.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(x, numeric, '-o', label='numeric')
ax.set_xlabel('x')
ax.set_ylabel('numeric')
ax.legend()
fig.savefig('campos.pdf')