#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt

M = 100
CUTOFF = 0.05

seconds = 2
samples = np.linspace(0, seconds, M * seconds, endpoint=False)

signal = np.sin(np.pi * samples) + np.cos(4 * np.pi * samples) + np.sin(95 * np.pi * samples) + np.random.normal(0, 0.1, M * seconds)
signal1 = np.sin(np.pi * samples) + np.cos(4 * np.pi * samples) + np.random.normal(0, 0.1, M * seconds)

x = np.exp(-2 * np.pi * CUTOFF)

B1 = x
A0 = 1 - B1


def FIR_response(length):

    window = np.blackman(length)

    i = (np.arange(length) - length // 2).astype(np.float64)
    i[i == 0] = 2 * np.pi * CUTOFF
    h = (np.sin(2 * np.pi * CUTOFF * i) / i) * window
    h /= sum(h)

    return h


def IIR_response(length):

    pulse = np.zeros(length, dtype=np.float64)
    pulse[1] = 1

    return IIR_LPF(pulse)


def IIR_LPF(signal):

    result = np.zeros_like(signal, dtype=np.float64)
    for i in range(1, len(signal)):
        result[i] = A0 * signal[i] + B1 * result[i - 1]

    return result

h = FIR_response(M)
fig, ax = plt.subplots(2, 2)
#ax[0, 0].plot(signal)
ax[0, 0].stem(abs(np.fft.fft(signal))[:len(signal)//2:])
#ax[1, 0].plot(np.convolve(h, signal, mode='same'), color='g')
ax[0, 1].plot(h)
ax[1, 0].stem(abs(np.fft.fft(np.convolve(h, signal, mode='same'))[:len(signal)//2:]), color='g')
ax[1, 1].plot(np.arange(M // 2) / M, abs(np.fft.fft(h))[:M // 2])
plt.figure(1).canvas.set_window_title("Window filter")
#plt.show()


h = IIR_response(M)
fig, ax = plt.subplots(2, 2)
ax[0, 0].plot(signal1)
ax[1, 0].plot(IIR_LPF(signal1), color='g')
ax[0, 1].plot(h)
ax[1, 1].plot(np.arange(M // 2) / M, abs(np.fft.fft(h))[:M // 2])
plt.figure(2).canvas.set_window_title("Single-pole filter")
plt.show()
