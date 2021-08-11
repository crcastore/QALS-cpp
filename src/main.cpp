#include "../lib/lib.h"
#include "../lib/npp.h"
#include "../lib/tsp.h"

using namespace std;
using namespace Eigen;

/*
Use ./deploy.sh to genereate an annealer executable
Use ./simulate.sh to generate a classical excutable
These two will compile in 64 bit architecture using g++ -std=c++2a

BINARY computes using vectors of {0, 1}^n
SPIN computes using vecotrs of {-1, 1}^n

Use solve() to compute a QUBO problem
- Input:
    MatrixXf Q that contains a QUBO problem
    int number of iteration
    bool mode (BINARY or SPIN) -> SPIN is not required for NPP and QAP
    int number of annealers run (effective only on annealer's executable code)
    bool log
- Output
    VectorXf containing the solution

NPP class contains number partitioning problem generator and solution mapper

NPP::number_partitioning_problem will generate a NPP problem
- Input:
    Empty MatrixXf Q
    Empty vector<int> nums (which dimension will be used to gen the sequence)
    int range (will be generated numbers in the range [1, range])
- Output:
    float c which is the sum over nums
NPP::diff
- Input:
    Q
    Solution vector 
    c
- Output:
    Difference btw the two most similar subsets
*/

#define IT 10     // Algorithm iteration
#define K 5       // Number of measurements per problem
#define N 9      // Problem's dimension
#define RANGE 10  // Problem's range

int main() {
    string filename = to_string(time(0));

    MatrixXd Q;
    vector<ll> nums(N);

    ll c = NPP::number_partitioning_problem(Q, nums, RANGE);

    auto start = chrono::steady_clock::now();
    VectorXd x = solve(Q, IT, K, filename, LOG_CONSOLE | LOG_FILE);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> difftime = end - start;

    NPP::to_file(difftime, IT, fQ(Q, x), N, RANGE, NPP::diff(Q, x, c), x, nums, filename);

    return 0;
}