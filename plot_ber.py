import matplotlib.pyplot as plt
import numpy as np

qpsk = np.loadtxt("results/ber_qpsk.txt")
qam16 = np.loadtxt("results/ber_qam16.txt")
qam64 = np.loadtxt("results/ber_qam64.txt")

noise_qpsk = qpsk[:, 0]
ber_qpsk = qpsk[:, 1]

noise_qam16 = qam16[:, 0]
ber_qam16 = qam16[:, 1]

noise_qam64 = qam64[:, 0]
ber_qam64 = qam64[:, 1]

# Plot

plt.semilogy(
    noise_qpsk,
    ber_qpsk,
    marker='o',
    label='QPSK'
)

plt.semilogy(
    noise_qam16,
    ber_qam16,
    marker='s',
    label='QAM16'
)

plt.semilogy(
    noise_qam64,
    ber_qam64,
    marker='^',
    label='QAM64'
)

plt.xlabel("Дисперсия шума")
plt.ylabel("BER")
plt.title("Сравнение эффективности по BER")

plt.grid(True, which='both')
plt.legend()
plt.show()