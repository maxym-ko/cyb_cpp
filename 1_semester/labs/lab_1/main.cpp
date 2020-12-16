//
// Created by maxym_ko on 9/17/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "LinearCongruentialGenerator.h"
#include "QuadraticCongruentialGenerator.h"
#include "FibonacciNumbersGenerator.h"
#include "UnionMethodGenerator.h"
#include "InverseCongruentSequenceGenerator.h"
#include "PolarCoordinateMethodGenerator.h"
#include "RelationMethodGenerator.h"
#include "SigmaMethodGenerator.h"
#include "LogarithmMethodGenerator.h"
#include "ArensMethodGenerator.h"
#include "Histogram.h"

using namespace std;

void print_menu();

int main() {
    print_menu();

    int type;
    cin >> type;

    RandomGenerator *generator;
    int count = 0;
    int min = 0, max = 1;
    while (type != 0) {
        min = 0;
        max = 1;
        switch (type) {
            case 1:
                generator = new LinearCongruentialGenerator();
                break;
            case 2:
                generator = new QuadraticCongruentialGenerator();
                break;
            case 3:
                generator = new FibonacciNumbersGenerator();
                break;
            case 4:
                generator = new InverseCongruentSequenceGenerator();
                break;
            case 5:
                generator = new UnionMethodGenerator();
                break;
            case 6:
                generator = new SigmaMethodGenerator();
                min = -3;
                max = 3;
                count = 1000;
                break;
            case 7:
                generator = new PolarCoordinateMethodGenerator();
                min = -3;
                max = 3;
                break;
            case 8:
                generator = new RelationMethodGenerator();
                min = -3;
                max = 3;
                break;
            case 9:
                generator = new LogarithmMethodGenerator();
                max = 100;
                break;
            case 10:
                generator = new ArensMethodGenerator();
                max = 100;
                break;
            default:
                cout << "Wrong input!!!\nOnly 1-10 requires";
        }
        Histogram::printStat(generator, min, max, count);
        cout << endl;

        cin >> type;
    }

    return 0;
}

void print_menu() {
    cout << "Enter generator type: " << endl;
    cout << "\t1 - Linear Congruential Generator" << endl;
    cout << "\t2 - Quadratic Congruential Generator" << endl;
    cout << "\t3 - Fibonacci Numbers Generator" << endl;
    cout << "\t4 - Inverse Congruent SequenceGenerator" << endl;
    cout << "\t5 - Union Method Generator" << endl;
    cout << "\t6 - Sigma Method Generator" << endl;
    cout << "\t7 - Polar Coordinate Method Generator" << endl;
    cout << "\t8 - Relation Method Generator" << endl;
    cout << "\t9 - Logarithm Method Generator" << endl;
    cout << "\t10 - Arens Method Generator\n" << endl;
}