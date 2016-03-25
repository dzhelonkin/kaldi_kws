#include "VCPSolver.h"

using namespace std;

VCPSolver::VCPSolver(const char* a_file_path):
        m_graph(NULL),
        m_graph_matrix(NULL)
{
    m_graph = graph_read_dimacs_file(const_cast<char*>(a_file_path));
    m_graph_matrix = reorder_by_degree(m_graph,FALSE);
}

VCPSolver::~VCPSolver()
{
    graph_free(m_graph);
}

void VCPSolver::readGraph()
{

}














/*-------------------------------------------------------------*/

//temprorary here
int main(int argc, char **argv)
{
    if(argv[1] == nullptr)
    {    
        cout << "Please specify DIMACS format file as argument" << endl;
        return -1;
    }
    
    VCPSolver solver(argv[1]);


    return 0;
}