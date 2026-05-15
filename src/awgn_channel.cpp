#include "../include/awgn_channel.h"

#include <random>
#include <cmath>

std::vector<std::complex<double>>
AWGNChannel::addNoise(
    const std::vector<std::complex<double>>& symbols,
    double noiseVariance // noise variance
)
{
    std::vector<std::complex<double>> noisySymbols;

    std::random_device rd;
    std::mt19937 gen(rd()); // Random Number Generator

    std::normal_distribution<double> // Gaussian distribution
        dist(0.0, std::sqrt(noiseVariance));

    for (const std::complex<double>& s : symbols)
    {
        double noiseReal = dist(gen); // I

        double noiseImag = dist(gen); // Q

        std::complex<double> noise(
            noiseReal,
            noiseImag
        );

        noisySymbols.push_back(s + noise);
    }

    return noisySymbols;
}