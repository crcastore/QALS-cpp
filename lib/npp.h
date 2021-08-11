#ifndef NPP_H
#define NPP_H

#include "lib.h"

class NPP {
   public:
    //Input: Matrix Q, empty vector of dimension n that will contain the vector, range max of number gen
    //Output: Sum of elements of nums
    static ll number_partitioning_problem(MatrixXd &Q, vector<ll> &nums, int range);
    // Input: Matrix Q, solution vector x, sum of elements of nums c
    static ll diff(const MatrixXd &Q, const VectorXd &x, ll c);
    static void to_file(chrono::duration<double> difference, int it, double f, int n, int range, ll diff, const VectorXd &x, const vector<ll> nums, string filename);
};
#endif