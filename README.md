# QALS C++
C++ implementation of Quantum Annealing Learning Search Algorithm (Pastorello, Davide, and Enrico Blanzieri. "*Quantum annealing learning search for solving QUBO problems.*" *Quantum Information Processing* 18.10 (2019): 1-17.)

# Introduction
This repo refers to ["*Quantum Annealing Learning Search Implementations*"](https://www.rintonpress.com/journals/doi/QIC22.3-4-1.html), Rinton Press, Quantum Information and Computation (Vol.22 No.3&4 pp0181-0208)

# Requirements
Since the C++ implementation requires a Python script in order to interface with the Quantum Annealer, some **python packages** must be installed.

```bash
pip install -r requirements.txt
```

# Configuring access to D-Wave
In order to use D-Wave's Solver API (SAPI), the remote compute resources for solving problems such as a D-Wave system or Leap‘s quantum-classical hybrid solvers a configuration file must be crated. [To do so follow this guide](https://docs.ocean.dwavesys.com/en/stable/overview/sapi.html).

# Run the project
QALS algorithm can be executed in two different modes:
1. **Simulation mode:** Only classical computation is used and an exhaustive search on D-Wave's equation is executed in order to find global minima.
```bash
sudo chmod +x simulate.sh
./simulate.sh
```
2. **Quantum computation mode.**
```bash
sudo chmod +x deploy.sh
./deploy.sh
```

# Problem submission
In ```src/main.cpp``` we provide an example on how a number partitioning problem can be solved by QALS.

## Number Partitioning Problem header
```C++
#include "lib/npp.h"
```
Function ```number_partitioning_problem``` generates a QUBO problem within a given range \
Function ```diff``` performs difference between the two sets of generated numbers \
Function ```to_file``` is a simple log file generator 

## Travel Salesman Problem header
```C++
#include "lib/tsp.h"
```
Function ```build_tsp``` generates Distance Matrix given a vector of Point \
Function ```travelling_salesman_problem``` generates a QUBO embedding of the Distance Matrix \
Function ```decode solution``` decode a given QUBO solution into a TSP one

# Logs
```solve``` function provides logs features in order to keep track of solutions computed in case the computation stops for some reasons. In the example provided both the log on console and log on file are enabled:
```C++
VectorXd x = solve(Q, IT, K, filename, LOG_CONSOLE | LOG_FILE)
```
```filename``` is the actual file where logs are written.

# Contacts
In case of some errors or bugs, please contact me at thomas.demin@studenti.unitn.it
