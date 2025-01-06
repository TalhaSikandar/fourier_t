# Fourier Transform Implementation in C

This project implements the Discrete Fourier Transform (DFT) and provides placeholders for a Fast Fourier Transform (FFT) algorithm. The program processes a discrete signal and computes its frequency-domain representation using cosine, sine, and complex exponential forms.

## Features
- **Discrete Fourier Transform (DFT):**
  - Computes the DFT of a signal using complex exponential functions.
  - Provides separate computations for cosine and sine components.
- **Fast Fourier Transform (FFT):**
  - Placeholder for implementing an optimized FFT algorithm.
- **Signal Generation:**
  - Generates a test signal composed of a combination of sine waves.

## Prerequisites
- GCC Compiler
- Make Utility

## Compilation and Execution
To compile and run the program, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone <repository_url>
   cd <repository_name>
   ```

2. **Build the Program**:
   ```bash
   make
   ```

3. **Run the Executable**:
   ```bash
   ./main
   ```

4. **Clean the Build**:
   ```bash
   make clean
   ```

## File Structure
- **`main.c`**: Contains the implementation of DFT, signal generation, and a placeholder for FFT.
- **`Makefile`**: Automates the build process for the project.
- **`README.md`**: Provides an overview of the project.

## Functions
### 1. `discrete_fourier_transform`
Calculates the DFT using complex exponential functions.

**Prototype**:
```c
void discrete_fourier_transform(const float signal[], float complex frequency_signal[]);
```

### 2. `discrete_fourier_transform_2`
Calculates the DFT by separating cosine and sine components.

**Prototype**:
```c
void discrete_fourier_transform_2(const float signal[], float cosine_frequency[], float sin_frequency[]);
```

### 3. `fast_fourier_transform`
A placeholder function for implementing the FFT algorithm.

**Prototype**:
```c
void fast_fourier_transform(const float signal[], size_t jump, float complex fs[], size_t length);
```

## Example Output
The program generates a discrete signal composed of two sine waves. It prints the signal values to the console.

Example signal:
```
Signal[0] = 0.00
Signal[1] = 0.85
Signal[2] = 1.31
Signal[3] = 1.06
Signal[4] = 0.00
Signal[5] = -1.06
Signal[6] = -1.31
Signal[7] = -0.85
```

## Future Work
- Complete the implementation of the FFT algorithm.
- Add support for signals of arbitrary lengths.
- Optimize memory usage for large signals.

## License
This project is licensed under the **Talha Sikandar License**.
