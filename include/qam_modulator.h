#ifndef QAM_MODULATOR_H
#define QAM_MODULATOR_H

#include <vector>
#include <complex>
class QAMModulator
{
public:

    std::vector<std::complex<double>>
    modulateQPSK(const std::vector<int>& bits);

    std::vector<std::complex<double>>
    modulateQAM16(const std::vector<int>& bits);

    std::vector<std::complex<double>>
    modulateQAM64(const std::vector<int>& bits);

};

#endif