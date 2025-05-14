import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# leer datos del archivo generado por el programa C++
N, error_trapezoid, error_simpson, error_trapezoid_richardson, error_simpson_richardson = np.loadtxt("integral_errors.txt", unpack=True)

# crear figura y ejes
fig, ax = plt.subplots()

# graficar los errores
ax.plot(N, error_trapezoid, '-o', label='Trapecio', markersize=4)
ax.plot(N, error_simpson, '-s', label='Simpson', markersize=4)
ax.plot(N, error_trapezoid_richardson, '-^', label='Trapecio + Richardson', markersize=4)
ax.plot(N, error_simpson_richardson, '-d', label='Simpson + Richardson', markersize=4)

ax.set_xlabel('N (Número de intervalos)')
ax.set_ylabel('Errores')
ax.set_yscale('log')  # Escala logarítmica para ver mejor la convergencia
ax.set_xscale('log')  # Escala logarítmica también en X
ax.legend()
ax.grid(True, which="both", linestyle='--', linewidth=0.5)

fig.savefig('integral.pdf')
plt.show()
