import matplotlib.pyplot as plt
import numpy as np

# Inserir pontos manualmente (2D)
x = np.array([0.5, 0.3, 3.9, -4.7])
y = np.array([1.5, 0.3, 0.9, -2.7])

CELLS = 100  # Numero de divisoes da malha

nCPTS = np.size(x, 0)  # Numero de pontos de controle
n = nCPTS - 1  # Grau da curva
t = np.linspace(0, 1, CELLS)  # Parametro da curva

xBezier = np.zeros((1, CELLS))
yBezier = np.zeros((1, CELLS))

def Ni(n, i):
    return np.math.factorial(n) / (np.math.factorial(i) * np.math.factorial(n - i))

def Bernstein(n, i, t):
    return Ni(n, i) * (t ** i) * ((1 - t) ** (n - i))

# Loop principal
for k in range(nCPTS):
    xBezier += Bernstein(n, k, t) * x[k]
    yBezier += Bernstein(n, k, t) * y[k]

# Plotagem
plt.plot(xBezier[0], yBezier[0])
plt.scatter(x, y, c='red')  # Ponto de controle em vermelho
plt.xlim([-5, 5])
plt.ylim([-5, 5])
plt.show()
