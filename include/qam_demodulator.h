#ifndef QAM_DEMODULATOR_H
#define QAM_DEMODULATOR_H

#include <vector>
#include <complex>

class QAMDemodulator
{
public:

    std::vector<int>
    demodulateQPSK(
        const std::vector<std::complex<double>>& symbols
    );

    std::vector<int>
    demodulateQAM16(
        const std::vector<std::complex<double>>& symbols
    );

    std::vector<int>
    demodulateQAM64(
        const std::vector<std::complex<double>>& symbols
    );
};

#endif