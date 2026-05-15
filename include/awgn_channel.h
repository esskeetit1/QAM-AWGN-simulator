#ifndef AWGN_CHANNEL_H
#define AWGN_CHANNEL_H

#include <vector>
#include <complex>

class AWGNChannel
{
public:

    std::vector<std::complex<double>>
    addNoise(
        const std::vector<std::complex<double>>& symbols,
        double noiseVariance
    );

};

#endif