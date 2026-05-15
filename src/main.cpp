#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

#include "../include/qam_modulator.h"
#include "../include/qam_demodulator.h"
#include "../include/awgn_channel.h"

int main()
{
    const int NUM_BITS = 120000;

    // Select modulation type:
    // "QPSK", "QAM16", "QAM64"

    std::string modulationType = "QAM64";

    // Noise variance values

    std::vector<double> noiseVariances =
    {
        0.01,
        0.02,
        0.03,
        0.05,
        0.07,
        0.1,
        0.15,
        0.2,
        0.3,
        0.4,
        0.5,
        0.7,
        1.0
    };

    std::vector<int> bits; // Beat Generation

    std::random_device rd; // Random bit generator

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 1); // 0 or 1

    for (int i = 0; i < NUM_BITS; i++)
    {
        bits.push_back(dist(gen));
    }

    QAMModulator modulator;

    QAMDemodulator demodulator;

    AWGNChannel channel;

    std::ofstream resultFile; // Saving Results

    if (modulationType == "QPSK")
    {
        resultFile.open("results/ber_qpsk.txt");
    }
    else if (modulationType == "QAM16")
    {
        resultFile.open("results/ber_qam16.txt");
    }
    else
    {
        resultFile.open("results/ber_qam64.txt");
    }

    std::vector<std::complex<double>> symbols;

    if (modulationType == "QPSK")
    {
        symbols =
            modulator.modulateQPSK(bits);
    }
    else if (modulationType == "QAM16")
    {
        symbols =
            modulator.modulateQAM16(bits);
    }
    else
    {
        symbols =
            modulator.modulateQAM64(bits);
    }

    std::cout
        << modulationType
        << " \n";

    for (double noiseVariance : noiseVariances)
    {
        // Add Gaussian noise to symbols

        auto noisySymbols =
            channel.addNoise(
                symbols,
                noiseVariance
            );

        // Demodulate received symbols

        std::vector<int> receivedBits;

        if (modulationType == "QPSK")
        {
            receivedBits =
                demodulator.demodulateQPSK(
                    noisySymbols
                );
        }
        else if (modulationType == "QAM16")
        {
            receivedBits =
                demodulator.demodulateQAM16(
                    noisySymbols
                );
        }
        else
        {
            receivedBits =
                demodulator.demodulateQAM64(
                    noisySymbols
                );
        }

        // Count bit errors

        int errorCount = 0;

        for (size_t i = 0; i < bits.size(); i++)
        {
            if (bits[i] != receivedBits[i])
            {
                errorCount++;
            }
        }

        // Calculate BER

        double BER =
            static_cast<double>(errorCount)
            / bits.size();

        // Save BER results to file

        resultFile
            << noiseVariance
            << " "
            << BER
            << "\n";

        // Print BER to terminal

        std::cout
            << "Noise variance: "
            << noiseVariance
            << " , BER: "
            << BER
            << "\n";
    }

    // Close output file

    resultFile.close();

    std::cout << "\nSimulation completed.\n";

    return 0;
}