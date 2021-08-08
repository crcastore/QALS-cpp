# QALS C++
C++ implementation of Quantum Annealing Learning Search Algorithm (Pastorello, Davide, and Enrico Blanzieri. "*Quantum annealing learning search for solving QUBO problems.*" *Quantum Information Processing* 18.10 (2019): 1-17.) \

# Introduction
This repo refers to "*Quantum Annealing Learning Search Implementations*"

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