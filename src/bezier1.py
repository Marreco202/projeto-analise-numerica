import matplotlib.pyplot as plt
import numpy as np

# Funções paramétricas
def x(t):
    return 0.5+ 0.3*t + 3.9*t*t - 4.7*t*t*t;


def y(t):
    return 1.5+ 0.3*t + 0.9*t*t - 2.7*t*t*t;

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
plt.plot(1.008900,1.224900, 'ro', label='Ponto real com t = 0.7')
plt.plot(1.008900,1.224900, 'b.', label='Ponto em t = 0.7 com passo 0.1')
plt.plot(1.008900,1.224900, 'g.', label='Ponto em t = 0.7 com passo 0.001')
plt.plot(1.008900,1.224900, 'y.', label='Ponto em t = 0.7 com passo 0.0001')

plt.plot(0.814100,1.598100, 'ro', label='Ponto real com t = 0.3')
plt.plot(0.814100,1.598100, 'b.', label='Ponto em t = 0.3 com passo 1.0')
plt.plot(0.814100,1.598100, 'g.', label='Ponto em t = 0.3 com passo 0.001')
plt.plot(0.814100,1.598100, 'y.', label='Ponto em t = 0.3 com passo 0.0001')
plt.legend()
plt.grid(linewidth=1, alpha = 1)
plt.show()
