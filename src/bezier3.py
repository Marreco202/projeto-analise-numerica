import matplotlib.pyplot as plt
import numpy as np

# Funções paramétricas
def x(t):
    return 13*t**3 - 27*t**2 + 9*t -1

def y(t):
    return  6*t**3 - 15*t**2 +9*t

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
plt.plot(-24.247000,0.324000, 'ro', label='Ponto real com t = 0.9')
plt.plot(-24.175872,0.327421, 'b.', label='Ponto em t = 0.9 com passo 0.001')
plt.plot(-24.247000,0.324000, 'g.', label='Ponto em t = 0.9 com passo 0.0001')
plt.plot(-24.247000,0.324000, 'y.', label='Ponto em t = 0.9 com passo 0.00001')
plt.legend()
plt.grid(linewidth=1, alpha = 1)
plt.show()
