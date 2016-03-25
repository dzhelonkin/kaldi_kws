#include <iostream>
#include <fstream>
#include <string>

extern "C" {
#include "cliquer.h"
#include "set.h"
#include "graph.h"
#include "reorder.h"
}

class VCPSolver
{
private:
//set 
    graph_t* m_graph;  
    int*     m_graph_matrix;

public:
    VCPSolver(const char* a_file_path);
    ~VCPSolver();

    VCPSolver(const VCPSolver&) = delete;
    VCPSolver& operator=(const VCPSolver&) = delete;


    void readGraph();
    
    void preColoring();

    void solveMatrix();

private:
    //addcolumn
    //removecolumn

};

