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


plt.plot(-0.357000,0.756000, 'ro', label='Ponto real com t = 0.1')
plt.plot(-0.357000,0.756000, 'b.', label='Ponto em t = 0.1 com passo 0.0001')

plt.plot(-0.176000,1.248000, 'go', label='Ponto real com t = 0.2')
plt.plot(-0.176000,1.248000, 'y.', label='Ponto em t = 0.1 com passo 0.0001')

plt.plot(-0.379000,1.512000, 'ro', label='Ponto real com t = 0.3')
plt.plot(-0.379000,1.512000, 'b.', label='Ponto em t = 0.25 com passo 0.01')

plt.plot(-3.953125,0.843750, 'go', label='Ponto real com t = 0.75')
plt.plot(-3.953125,0.843750, 'y.', label='Ponto em t = 0.75 com passo 0.01')

plt.legend()
plt.xlim([-10, 10])
plt.grid(linewidth=1, alpha = 1)
plt.show()
