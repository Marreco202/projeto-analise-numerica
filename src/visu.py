import matplotlib.pyplot as plt
import numpy as np

# Funções paramétricas
def x(t):
    return 1 + 3*t+ 9 * t**2 + 5 * t**3


def y(t):
    return 1 - 3*t + 9*t**2 + t**3

# Parâmetros para avaliação da curva de Bezier
t_values = np.linspace(0, 1, 1000)

print(x(1))
# Avaliar as funções paramétricas para os valores de t
x_values = x(t_values)
y_values = y(t_values)

# Plotar a curva de Bezier
plt.plot(x_values, y_values, label='Curva de Bezier')
plt.title('Curva de Bezier')
plt.xlabel('X')
plt.ylabel('Y')
plt.plot(7.345000,7.291000, 'ro', label='Ponto real com t = 0.9')
plt.plot(7.337946,7.277536, 'b.', label='Ponto em t = 0.9 com passo 0.001')
plt.plot(7.345000,7.291000, 'g.', label='Ponto em t = 0.9 com passo 0.0001')
plt.plot(7.345000,7.291000, 'y.', label='Ponto em t = 0.9 com passo 0.00001')
plt.legend()
plt.grid(linewidth=1, alpha = 1)
plt.show()
