#include <vector>
#include <cmath>
#include <iostream>
#include <boost/math/tools/norms.hpp>
#include <fstream>

//операции над векторами
template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector) {
    for (const auto &i: vector) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    return os;
}

double vector_length(const std::vector<double> &vector) {
    return boost::math::tools::l2_norm(vector.begin(), vector.end());
}

std::vector<double> operator+(const std::vector<double> &v1, const std::vector<double> &v2) {
    auto result = v1;

    const size_t len_max = std::max<size_t>(v1.size(), v2.size());
    result.resize(len_max, 0);

    for (size_t i = 0; i < result.size() && i < v2.size(); i++) {
        result[i] += v2[i];
    }

    return result;
}

std::vector<double> operator+(const std::vector<double> &v1, const float a) {
    auto result = v1;
    result.resize(v1.size(), 0);

    for (size_t i = 0; i < result.size() && i < v1.size(); i++) {
        result[i] += a;
    }

    return result;
}

std::vector<double> operator-(const std::vector<double> &v1, const std::vector<double> &v2) {
    auto result = v1;

    const size_t len_max = std::max<size_t>(v1.size(), v2.size());
    result.resize(len_max, 0);

    for (size_t i = 0; i < result.size() && i < v2.size(); i++) {
        result[i] -= v2[i];
    }

    return result;
}

// векторное умножение
std::vector<double> operator%(const std::vector<double> &vector_1, const std::vector<double> &vector_2) {
    std::vector<double> result;
    result.resize(vector_1.size());

    result[0] = vector_1[1] * vector_2[2] - vector_1[2] * vector_2[1];
    result[1] = vector_1[0] * vector_2[2] - vector_1[2] * vector_2[0];
    result[2] = vector_1[0] * vector_2[1] - vector_1[1] * vector_2[0];


    return result;
}

// скалярное умножение
double operator*(const std::vector<double> &vector_1, const std::vector<double> &vector_2) {
    double result = 0;

    for (auto i = 0; i < vector_1.size(); ++i) result += vector_1[i] * vector_2[i];

    return result;
}

//умножение на константу
std::vector<double> operator*(const float &a, const std::vector<double> &v1) {
    auto result = v1;
    result.resize(v1.size(), 0);

    for (size_t i = 0; i < result.size() && i < v1.size(); i++) {
        result[i] *= a;
    }

    return result;
}

std::vector<double> operator*(const std::vector<double> &v1, const float &a) {
    auto result = v1;
    result.resize(v1.size(), 0);

    for (size_t i = 0; i < result.size() && i < v1.size(); i++) {
        result[i] *= a;
    }

    return result;
}

std::vector<double> operator/(const std::vector<double> &v1, const std::vector<double> &v2) {
    auto result = v1;

    const size_t len_max = std::max<size_t>(v1.size(), v2.size());
    result.resize(len_max, 0);

    for (size_t i = 0; i < result.size() && i < v2.size(); i++) {
        result[i] /= v2[i];
    }

    return result;
}

std::vector<double> operator/(const std::vector<double> &v1, const float a) {
    auto result = v1;
    result.resize(v1.size(), 0);

    for (size_t i = 0; i < result.size() && i < v1.size(); i++) {
        result[i] /= a;
    }

    return result;
}

std::vector<double> sum_of_three_vectors(const std::vector<double> &v1, const std::vector<double> &v2,
                                         const std::vector<double> &v3) {
    auto result = v1;

    const size_t len_max = std::max<size_t>(v1.size(), v2.size());
    result.resize(len_max, 0);

    for (size_t i = 0; i < result.size() && i < v2.size(); i++) {
        result[i] += v2[i] + v3[i];
    }

    return result;
}


