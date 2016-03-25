#include <iostream>
#include <fstream>

class VCPSolver
{

    VCPSolver();
    ~VCPSolver();

    VCPSolver(const VCPSolver&) = delete;
    operator=(const VCPSolver&) = delete;


    void readGraph();
    
    void preColoring();

    void solveMatrix();
}