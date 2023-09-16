#include <iostream>
#include <fstream>
#include <complex>
#include <cstring>
#include <vector>
#include <cmath>

const int MAX_SIZE = 1048576;

bool isZero(std::complex<double> val) {
    return std::abs(val.real()) < 1e-10;
}

void FFT(std::complex<double>* A, int n, int inv, std::complex<double>* O) {
    if (n == 1) {
        O[0] = A[0];
        return;
    }
    std::complex<double> E[MAX_SIZE / 2], ODD[MAX_SIZE / 2], Y_E[MAX_SIZE / 2], Y_O[MAX_SIZE / 2];
    for (int i = 0; i < n / 2; i++) {
        E[i] = A[2 * i];
        ODD[i] = A[2 * i + 1];
    }
    FFT(E, n / 2, inv, Y_E);
    FFT(ODD, n / 2, inv, Y_O);
    std::complex<double> w = 1, wn = std::exp(std::complex<double>(0, 2 * M_PI / n * (inv ? 1 : -1)));
    for (int i = 0; i < n / 2; i++) {
        O[i] = Y_E[i] + w * Y_O[i];
        O[i + n / 2] = Y_E[i] - w * Y_O[i];
        w *= wn;
    }
}

void multiplyPolynomials(const std::vector<std::complex<double>>& A, const std::vector<std::complex<double>>& B, std::vector<std::complex<double>>& result) {
    int nA = A.size();
    int nB = B.size();
    int n = 1;
    while (n < nA + nB) {
        n *= 2;
    }
    std::complex<double> pA[MAX_SIZE] = {0}, pB[MAX_SIZE] = {0}, FA[MAX_SIZE], FB[MAX_SIZE], FC[MAX_SIZE];

    for (int i = 0; i < nA; i++) {
        pA[i] = A[i];
    }

    for (int i = 0; i < nB; i++) {
        pB[i] = B[i];
    }

    FFT(pA, n, 0, FA);
    FFT(pB, n, 0, FB);

    for (int i = 0; i < n; i++) {
        FC[i] = FA[i] * FB[i];
    }

    FFT(FC, n, 1, result.data());

    for (int i = 0; i < n; i++) {
        result[i] = std::round(result[i].real()) / n;
    }
}

void read(std::ifstream& file, std::vector<int>& p) {
    std::string line;
    if (std::getline(file, line)) {
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            p.push_back(num);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cout << "Error opening file.\n";
        return 1;
    }
    

    std::vector<int> p1, p2;
    read(file, p1);
    read(file, p2);

    std::vector<std::complex<double>> A(p1.size()), B(p2.size()), result(MAX_SIZE);

    for (int i = 0; i < p1.size(); i++) {
        A[i] = p1[i];
    }

    for (int i = 0; i < p2.size(); i++) {
        B[i] = p2[i];
    }

    multiplyPolynomials(A, B, result); 

    int idx = MAX_SIZE - 1;
    while (idx >= 0 && isZero(result[idx])) {
        idx--;
    }

    for (int i = 0; i <= idx; i++) {
        std::cout << static_cast<int>(std::round(result[i].real())) << ' ';
    }
    std::cout << '\n';

    return 0;
}












