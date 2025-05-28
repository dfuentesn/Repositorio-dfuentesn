import numpy as np
import matplotlib.pyplot as plt

# Leer datos y ajuste
data = np.loadtxt("millikan.txt")
x, y = data[:, 0], data[:, 1]
ajuste = np.loadtxt("ajuste_lineal.txt")
x_ajuste, y_ajuste = ajuste[:, 0], ajuste[:, 2]

# Graficar
plt.scatter(x, y, label="Datos experimentales", color="blue")
plt.plot(x_ajuste, y_ajuste, label="y = (4.09e-15 ± 1.11)x - (1.73 ± 2.12)", color="red")
plt.plot([], [], ' ', label="h = 6.5500623482963051e-34 J·s") 
plt.plot([], [], ' ', label="Φ = 2.7737455530831321e-19 J") 

# Etiquetas y formato
plt.xlabel("Frecuencia (Hz)")
plt.ylabel("Voltaje (V)")
plt.title("Efecto fotoeléctrico: $V = (h/e)\\nu - \\phi$")
plt.legend()
plt.grid()
plt.savefig("millikan_ajuste.pdf")
plt.show()
