#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
from scipy import linalg

N = 16

def FWHT(x, n, direction=1):

    if n == 1:
        return x

    c = np.zeros(n // 2, dtype=np.complex)
    b = np.zeros(n // 2, dtype=np.complex)

    for j in range(n // 2):
        b[j] = x[j] + x[j + n // 2]
        c[j] = (x[j] - x[j + n // 2])

    lefch = FWHT(b, n // 2, direction)
    raich = FWHT(c, n // 2, direction)

    result = np.zeros(N, dtype=np.complex)

    if direction == 1:
        for j in range(n // 2):
            result[n//2 + j] = raich[j]
            result[j] = lefch[j]

    elif direction == -1:
        for j in range(n // 2):
            result[n//2 + j] = raich[j]
            result[j] = lefch[j]
    return result


def DWHT(x):

    walsh = linalg.hadamard(N)

    return np.dot(walsh, x)


samples_vector = np.linspace(0, 2 * np.pi, N)

x = np.sin(samples_vector) + np.cos(4 * samples_vector)

fig, ax = plt.subplots(5, 1)
ax[0].plot(samples_vector, x)
ax[0].set_title('Source')

ax[1].stem(FWHT(x, N) / N, markerfmt='ro', linefmt='r-')
ax[1].set_title('Fast Walsh–Hadamard transform')
ax[2].plot(samples_vector, FWHT(FWHT(x, N) / N, N))

ax[3].stem(DWHT(x) / N, markerfmt='ro', linefmt='r-')
ax[3].set_title('Discrete Walsh-Hadamard Transform')
ax[4].plot(DWHT(DWHT(x) / N))
fig.tight_layout()
plt.show()
