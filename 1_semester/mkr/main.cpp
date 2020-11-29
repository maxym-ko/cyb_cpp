#include <iostream>
#include <cmath>
#include <climits>

// ============= IF-ELSE =============
template<bool Condition, long long value>
class IfElse {};

template<long long value>
class IfElse<true, value> {
public:
    static const long long res = value / 10000;
};

template<long long value>
class IfElse<false, value> {
public:
    static const long long res = value;
};

// ====================================


// ============= POW =============
template<long long Base, int Power>
class Pow {
public:
    static const long long value = Base * Pow<Base, Power - 1>::value;
};

template<long long Base>
class Pow<Base, 0> {
public:
    static const long long value = 1;
};
// ====================================


// ============= FACTORIAL =============
template<long long Number>
class Factorial {
public:
    static const long long value = Number * Factorial<Number - 1>::value;
};

template<>
class Factorial<1> {
public:
    static const long long value = 1;
};
// ===============================


// ============= COSH =============
template<long long M, long long N, long long K, long long KFactorial, long long NPow>
class CoshSeries {
public:
    static const long long numerator =
            KFactorial * NPow + M * M * CoshSeries<M, N, K + 2, KFactorial / (K * (K + 1)), NPow / N / N>::numerator;
    static const long long denominator = KFactorial * NPow;
};

template<long long M, long long N, long long K, long long KFactorial>
class CoshSeries<N, M, K, KFactorial, 0> {
public:
    static const long long numerator = 1;
    static const long long denominator = 1;
};

template<long long M, long long N, long long K, long long KFactorial>
class CoshSeries<N, M, K, KFactorial, 1> {
public:
    static const long long numerator = 1;
    static const long long denominator = 1;
};

template<int M, int N, int Depth>
class Cosh {
public:
    static inline float cosh() {
        return (long double) CoshSeries<M, N, 1, Factorial<Depth * 2>::value, Pow<N, Depth * 2>::value>::numerator /
               CoshSeries<M, N, 1, Factorial<Depth * 2>::value, Pow<N, Depth * 2>::value>::denominator;
    }
};
// ===============================


// ============= SINH =============
template<long long M, long long N, long long K, long long KFactorial, long long NPow>
class SinhSeries {
public:
    static const long long numerator =
            KFactorial * NPow + M * M * SinhSeries<M, N, K + 2, KFactorial / (K * (K + 1)), NPow / N / N>::numerator;
    static const long long denominator = KFactorial * NPow;
};

template<long long M, long long N, long long K, long long KFactorial>
class SinhSeries<N, M, K, KFactorial, 0> {
public:
    static const long long numerator = 1;
    static const long long denominator = 1;
};

template<long long M, long long N, long long K, long long KFactorial>
class SinhSeries<N, M, K, KFactorial, 1> {
public:
    static const long long numerator = 1;
    static const long long denominator = 1;
};

template<int M, int N, int Depth>
class Sinh {
public:
    static inline float sinh() {
        return (long double) M / N *
               SinhSeries<M, N, 2, Factorial<Depth * 2 + 1>::value, Pow<N, Depth * 2>::value>::numerator /
               SinhSeries<M, N, 2, Factorial<Depth * 2 + 1>::value, Pow<N, Depth * 2>::value>::denominator;
    }
};

float sinhRec(float x, float k, int depth) {
    if (depth == 0) return 1;
    return 1 + x * x / (2 * k) / (2 * k + 1) * sinhRec(x, k + 1, depth - 1);
}
// ===============================


// ============= LOG =============
template<long long M, long long N, long long K, long long KFactorial, long long NPow>
class LogSeries {
public:
    static const long long numerator = KFactorial * NPow - K * M * LogSeries<M, N, K + 1, KFactorial / (K + 1), NPow / N>::numerator;
    static const long long denominator = KFactorial * NPow;
};

template<long long M, long long N, long long K, long long NPow>
class LogSeries<N, M, K, 1, NPow> {
public:
    static const long long numerator = 1;
    static const long long denominator = 1;
};

template<int M, int N, int Depth>
class Log {
public:
    static inline float log() {
        return (double) M / N * LogSeries<M, N, 1, Factorial<Depth + 1>::value, Pow<N, Depth>::value>::numerator /
                LogSeries<M, N, 1, Factorial<Depth + 1>::value, Pow<N, Depth>::value>::denominator;
    }
};

//float logRec(float m, float n, float n_pow, float k, float k_factorial) {
//    if (n_pow == 0) return 1;
//    return k_factorial * n_pow * (m - 1) -
//}
// ===============================


// ============= EXP =============
template<long long M, long long N, long long K, long long KFactorial, long long NPow>
class ExpSeries {
public:
    static const long long numerator = KFactorial * NPow + M * ExpSeries<M, N, K + 1, KFactorial / K, NPow / N>::numerator;
    static const long long denominator = KFactorial * NPow;
};

template<long long M, long long N, long long KFactorial, long long NPow>
class ExpSeries<N, M, KFactorial, KFactorial, NPow> {
public:
    static const long long numerator = 1;
    static const long long denominator = 1;
};

template<int M, int N, int Depth>
class Exp {
public:
    static inline float exp() {
        return (double) ExpSeries<M, N, 1, Factorial<Depth>::value, Pow<N, Depth>::value>::numerator /
               ExpSeries<M, N, 1, Factorial<Depth>::value, Pow<N, Depth>::value>::denominator;
    }
};
// ===============================

static const int Numerator = 1;
static const int Denominator = 2;
static const int Depth = 3;
static const int N_C = 2;
static const int N_S = 2;
static const int N_L = 2;
static const int N_E = 2;

// ============= FOR LOOP =============
template<int I, int N>
class For {
public:
    static const long long first_numerator_exp = ExpSeries<Numerator, Denominator, 1, Factorial<Depth>::value, Pow<Denominator, Depth>::value>::numerator;
    static const long long first_denominator_exp = ExpSeries<Numerator, Denominator, 1, Factorial<Depth>::value, Pow<Denominator, Depth>::value>::denominator;

    static const long long numerator_exp = ExpSeries<first_numerator_exp, first_denominator_exp, 1, Factorial<Depth>::value, Pow<first_denominator_exp, Depth>::value>::numerator * For<I + 1, N_E>::numerator_exp;
    static const long long denominator_exp = ExpSeries<first_numerator_exp, first_denominator_exp, 1, Factorial<Depth>::value, Pow<first_denominator_exp, Depth>::value>::numerator * For<I + 1, N_E>::denominator_exp;

    static const long long numerator_log = SinhSeries<numerator_exp, denominator_exp, 2, Factorial<Depth * 2 + 1>::value, Pow<numerator_exp, Depth * 2>::value>::numerator * For<I + 1, N_L>::numerator_log;
    static const long long denominator_log = SinhSeries<numerator_exp, denominator_exp, 2, Factorial<Depth * 2 + 1>::value, Pow<numerator_exp, Depth * 2>::value>::numerator * For<I + 1, N_L>::denominator_log;

    static const long long numerator_sinh = CoshSeries<numerator_log, denominator_log, 1, Factorial<Depth * 2>::value, Pow<numerator_log, Depth * 2>::value>::numerator * For<I + 1, N_S>::numerator_sinh;
    static const long long denominator_sinh = CoshSeries<numerator_log, denominator_log, 1, Factorial<Depth * 2>::value, Pow<numerator_log, Depth * 2>::value>::denominator * For<I + 1, N_S>::denominator_sinh;

    static const long long numerator_cosh = ExpSeries<numerator_sinh, denominator_sinh, 1, Factorial<Depth>::value, Pow<denominator_sinh, Depth>::value>::numerator * For<I + 1, N_C>::numerator_cosh;
    static const long long denominator_cosh = ExpSeries<numerator_sinh, denominator_sinh, 1, Factorial<Depth>::value, Pow<denominator_sinh, Depth>::value>::numerator * For<I + 1, N_C>::denominator_cosh;
};

template<int N>
class For<N, N> {
public:
    static const long long first_numerator_exp = 1;
    static const long long first_denominator_exp = 1;
    static const long long numerator_exp = 1;
    static const long long denominator_exp = 1;
    static const long long numerator_log = 1;
    static const long long denominator_log = 1;
    static const long long numerator_sinh = 1;
    static const long long denominator_sinh = 1;
    static const long long numerator_cosh = 1;
    static const long long denominator_cosh = 1;
};
// ===============================

template<int N_C, int N_S, int N_L, int N_E>
class Result {
public:
    static inline float res() {
        return (double) For<1, 0>::numerator_cosh / For<1, 0>::denominator_cosh;
    }
};

int main() {
    std::cout << "pow(24, 5) = " << Pow<24, 5>::value << std::endl;
    std::cout << "factorial(12) = " << Factorial<12>::value << std::endl;

    std::cout << "Real exp(2) = " << exp(0.5) << std::endl;
    std::cout << "Meta exp(2) = " << Exp<1, 5, 10>::exp() << std::endl;

    std::cout << "Real sinh(0.5) = " << sinh(0.5) << std::endl;
    std::cout << "Meta sinh(0.5) = " << Sinh<1, 2, 4>::sinh() << std::endl;

    std::cout << "Real cosh(0.5) = " << cosh(0.5) << std::endl;
    std::cout << "Meta cosh(0.5) = " << Cosh<1, 2, 4>::cosh() << std::endl;

    std::cout << "Real ln(0.5) = " << log(1) << std::endl;
    std::cout << "Meta ln(0.5) = " << Log<1, 1, 15>::log() << std::endl;

    std::cout << "Meta result: " << Result<N_C, N_S, N_L, N_E>::res() << std::endl;
    std::cout << "Real result: " << cosh(cosh(sin(sinh(log(log(exp(exp((float) Numerator / Denominator)))))))) << std::endl;


//    std::cout << "Meta result: " << For<0, 1>::first_numerator_exp << std::endl;
//    std::cout << "Meta result: " << For<0, 1>::first_denominator_exp << std::endl;
////
//    std::cout << "Meta result: " << For<0, 1>::numerator_exp << std::endl;
//    std::cout << "Meta result: " << For<0, 1>::denominator_exp << std::endl;
//
//    std::cout << "Meta result: " << For<0, 1>::numerator_log << std::endl;
//    std::cout << "Meta result: " << For<0, 1>::denominator_log << std::endl;
    return 0;
}
