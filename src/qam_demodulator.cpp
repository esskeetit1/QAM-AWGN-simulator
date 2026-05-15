#include "../include/qam_demodulator.h"
#include <cmath>

std::vector<int>
QAMDemodulator::demodulateQPSK(
    const std::vector<std::complex<double>>& symbols
)
{
    std::vector<int> bits;

    for (const std::complex<double>& s : symbols)
    {
        int b1;
        int b2;

        // Decision for real part

        if (s.real() < 0)
            b1 = 0;
        else
            b1 = 1;

        // Decision for imaginary part

        if (s.imag() < 0)
            b2 = 0;
        else
            b2 = 1;

        bits.push_back(b1);
        bits.push_back(b2);
    }

    return bits;
}

std::vector<int>
QAMDemodulator::demodulateQAM16(
    const std::vector<std::complex<double>>& symbols
)
{
    std::vector<int> bits;

    for (const std::complex<double>& s : symbols)
    {
        double real = s.real();
        double imag = s.imag();

        // Real part

        if (real < -2 / std::sqrt(10.0))
        {
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (real < 0 / std::sqrt(10.0))
        {
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (real < 2 / std::sqrt(10.0))
        {
            bits.push_back(1);
            bits.push_back(0);
        }
        else
        {
            bits.push_back(1);
            bits.push_back(1);
        }

        // Imaginary part

        if (imag < -2 / std::sqrt(10.0))
        {
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (imag < 0 / std::sqrt(10.0))
        {
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (imag < 2 / std::sqrt(10.0))
        {
            bits.push_back(1);
            bits.push_back(0);
        }
        else
        {
            bits.push_back(1);
            bits.push_back(1);
        }
    }

    return bits;
}

std::vector<int>
QAMDemodulator::demodulateQAM64(
    const std::vector<std::complex<double>>& symbols
)
{
    std::vector<int> bits;

    for (const std::complex<double>& s : symbols)
    {
        double real = s.real();
        double imag = s.imag();

        // real

        if (real < -6 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (real < -4 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (real < -2 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(0);
        }
        else if (real < 0 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(1);
        }
        else if (real < 2 / std::sqrt(42.0))
        {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (real < 4 / std::sqrt(42.0))
        {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (real < 6 / std::sqrt(42.0))
        {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(0);
        }
        else
        {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(1);
        }

        // imag

        if (imag < -6 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (imag < -4 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (imag < -2 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(0);
        }
        else if (imag < 0 / std::sqrt(42.0))
        {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(1);
        }
        else if (imag < 2 / std::sqrt(42.0))
        {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (imag < 4 / std::sqrt(42.0))
        {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (imag < 6 / std::sqrt(42.0))
        {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(0);
        }
        else
        {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(1);
        }
    }

    return bits;
}