/*
 * Copyright - Talha Sikandar
 */

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <complex.h>

#define PI 3.1428f
#define SIGNAL_LENGTH 8

// Precomputed pi/2 using atan2f
static const float PI_2 = atan2f(1.0f, 1.0f) * 4.0f;

/**
 * Computes the Discrete Fourier Transform (DFT) of a signal.
 * @param signal: Input signal array.
 * @param frequency_signal: Output array containing complex frequency-domain representation.
 */
void discrete_fourier_transform(const float signal[], float complex frequency_signal[]) {
    for (size_t f = 0; f < SIGNAL_LENGTH; ++f) {
        frequency_signal[f] = 0;
        for (size_t i = 0; i < SIGNAL_LENGTH; ++i) {
            float t = (float)i / SIGNAL_LENGTH;
            frequency_signal[f] += cexpf(I * 2 * PI_2 * f * t) * signal[i];
        }
    }
}

/**
 * Computes the Discrete Fourier Transform (DFT) using separate cosine and sine components.
 * @param signal: Input signal array.
 * @param cosine_frequency: Output array containing cosine components.
 * @param sin_frequency: Output array containing sine components.
 */
void discrete_fourier_transform_2(const float signal[], float cosine_frequency[], float sin_frequency[]) {
    for (size_t f = 0; f < SIGNAL_LENGTH; ++f) {
        cosine_frequency[f] = 0;
        sin_frequency[f] = 0;
        for (size_t i = 0; i < SIGNAL_LENGTH; ++i) {
            float t = (float)i / SIGNAL_LENGTH;
            cosine_frequency[f] += cosf(2 * PI_2 * f * t) * signal[i];
            sin_frequency[f] += sinf(2 * PI_2 * f * t) * signal[i];
        }
    }
}

/**
 * Computes the Fast Fourier Transform (FFT) of a signal
 * @param signal: Input signal array.
 * @param jump: Step size for recursive FFT computation.
 * @param fs: Output array containing frequency-domain representation.
 * @param length: Length of the signal.
 */
void fast_fourier_transform(const float signal[], size_t jump, float complex fs[], size_t length) {
    if (length == 1) {
      fs[0] = signal[0];
      return;
    }
    fast_fourier_transform(signal, jump * 2, fs, length / 2);             // Even indices
    fast_fourier_transform(signal + jump, jump * 2, fs + length / 2, length / 2); // Odd indices

    for (size_t k = 0; k < length / 2; ++k) {
        float t = (float)k / length;
        float complex odd_term = cexp(-2 * PI_2 * I * t) * fs[k + length/2];
        float complex even_term = fs[k];
        fs[k] = even_term + odd_term; // Adding odd term to even terms
        fs[k + length/2] = even_term - odd_term;
    }
}

/**
 * Main function to demonstrate signal processing and run tests.
 */
int main(void) {
    float signal[SIGNAL_LENGTH] = {0};

    // Populate the signal with a combination of two sine waves
    for (size_t i = 0; i < SIGNAL_LENGTH; ++i) {
        float t = (float)i / SIGNAL_LENGTH;
        signal[i] = sinf(2 * PI_2 * 1 * t) + sinf(2 * PI_2 * 2 * t);
    }

    // Declare arrays for testing
    float complex frequency_signal[SIGNAL_LENGTH] = {0};
    float cosine_frequency[SIGNAL_LENGTH] = {0};
    float sin_frequency[SIGNAL_LENGTH] = {0};

    // Perform the Fourier Transform using the first method (complex form)
    discrete_fourier_transform(signal, frequency_signal);

    // Print the results of the Discrete Fourier Transform (DFT) with complex numbers
    printf("\nDiscrete Fourier Transform (Complex Form):\n");
    for (size_t i = 0; i < SIGNAL_LENGTH; ++i) {
        printf("frequency_signal[%zu] = %.2f + %.2fi\n", i, crealf(frequency_signal[i]), cimagf(frequency_signal[i]));
    }

    // Perform the Fourier Transform using the second method (separate cosine and sine components)
    discrete_fourier_transform_2(signal, cosine_frequency, sin_frequency);

    // Print the results of the Discrete Fourier Transform using separate cosine and sine components
    printf("\nDiscrete Fourier Transform (Cosine and Sine Components):\n");
    for (size_t i = 0; i < SIGNAL_LENGTH; ++i) {
        printf("Cosine[%zu] = %.2f, Sine[%zu] = %.2f\n", i, cosine_frequency[i], i, sin_frequency[i]);
    }

    float complex fft_signal[SIGNAL_LENGTH] = {0};
    fast_fourier_transform(signal, 1, fft_signal, SIGNAL_LENGTH);
    printf("\nFast Fourier Transform (FFT):\n");
    for (size_t i = 0; i < SIGNAL_LENGTH; ++i) {
        printf("fft_signal[%zu] = %.2f + %.2fi\n", i, crealf(fft_signal[i]), cimagf(fft_signal[i]));
    }

    return 0;
}
