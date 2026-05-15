#include "../include/qam_modulator.h"
#include <cmath>

std::vector<std::complex<double>>
QAMModulator::modulateQPSK(const std::vector<int>& bits)
{
    std::vector<std::complex<double>> symbols;

    for (size_t i = 0; i < bits.size(); i += 2)
    {
        int b1 = bits[i];
        int b2 = bits[i + 1];

        double real; // I
        double imag; // Q

        // Mapping

        if (b1 == 0)
            real = -1.0;
        else
            real = 1.0;
        if (b2 == 0)
            imag = -1.0;
        else
            imag = 1.0;

        symbols.push_back(
            {real, imag}
        );
    }

    return symbols;
}

std::vector<std::complex<double>>
QAMModulator::modulateQAM16(
    const std::vector<int>& bits
)
{
    std::vector<std::complex<double>> symbols;

    for (size_t i = 0; i < bits.size(); i += 4)
    {
        int b1 = bits[i];
        int b2 = bits[i + 1];
        int b3 = bits[i + 2];
        int b4 = bits[i + 3];

        double real;
        double imag;

        // Real part

        if (b1 == 0 && b2 == 0)
            real = -3 / std::sqrt(10.0); // average symbol energy
        else if (b1 == 0 && b2 == 1)
            real = -1 / std::sqrt(10.0);
        else if (b1 == 1 && b2 == 0)
            real = 1 / std::sqrt(10.0);
        else
            real = 3 / std::sqrt(10.0);

        // Imaginary part

        if (b3 == 0 && b4 == 0)
            imag = -3 / std::sqrt(10.0);
        else if (b3 == 0 && b4 == 1)
            imag = -1 / std::sqrt(10.0);
        else if (b3 == 1 && b4 == 0)
            imag = 1 / std::sqrt(10.0);
        else
            imag = 3 / std::sqrt(10.0);

        symbols.push_back(
            {real, imag}
        );
    }

    return symbols;
}

std::vector<std::complex<double>>
QAMModulator::modulateQAM64(
    const std::vector<int>& bits
)
{
    std::vector<std::complex<double>> symbols;

    for (size_t i = 0; i < bits.size(); i += 6)
    {
        int r1 = bits[i];
        int r2 = bits[i + 1];
        int r3 = bits[i + 2];

        int im1 = bits[i + 3];
        int im2 = bits[i + 4];
        int im3 = bits[i + 5];

        double real;
        double imag;

        // Real mapping

        int realValue =
            r1 * 4 +
            r2 * 2 +
            r3;

        switch(realValue)
        {
            case 0: real = -7 / std::sqrt(42.0); break; // average symbol energy
            case 1: real = -5 / std::sqrt(42.0); break;
            case 2: real = -3 / std::sqrt(42.0); break;
            case 3: real = -1 / std::sqrt(42.0); break;
            case 4: real = 1 / std::sqrt(42.0); break;
            case 5: real = 3 / std::sqrt(42.0); break;
            case 6: real = 5 / std::sqrt(42.0); break;
            default: real = 7 / std::sqrt(42.0);
        }

        // Imag mapping

        int imagValue =
            im1 * 4 +
            im2 * 2 +
            im3;

        switch(imagValue)
        {
            case 0: imag = -7 / std::sqrt(42.0); break;
            case 1: imag = -5 / std::sqrt(42.0); break;
            case 2: imag = -3 / std::sqrt(42.0); break;
            case 3: imag = -1 / std::sqrt(42.0); break;
            case 4: imag = 1 / std::sqrt(42.0); break;
            case 5: imag = 3 / std::sqrt(42.0); break;
            case 6: imag = 5 / std::sqrt(42.0); break;
            default: imag = 7 / std::sqrt(42.0);
        }

        symbols.push_back(
            {real, imag}
        );
    }

    return symbols;
}