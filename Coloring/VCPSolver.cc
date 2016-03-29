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


    SizeOptions opt("GraphColor");
    opt.icl(ICL_DOM);
    opt.iterations(20);
    opt.solutions(0);
    //opt.model(GraphColor::MODEL_NONE);
    //opt.model(GraphColor::MODEL_NONE, "none", "no lower bound");
    opt.model(GraphColor::MODEL_CLIQUE, "clique", "use maximal clique size as lower bound");
    //opt.branching(GraphColor::BRANCH_DEGREE);
    opt.branching(GraphColor::BRANCH_DEGREE, "degree");
    opt.branching(GraphColor::BRANCH_SIZE, "size");
    opt.branching(GraphColor::BRANCH_SIZE_DEGREE, "sizedegree");
    opt.branching(GraphColor::BRANCH_SIZE_AFC, "sizeafc");
    opt.branching(GraphColor::BRANCH_SIZE_ACTIVITY, "sizeact");
    opt.symmetry(GraphColor::SYMMETRY_NONE);
    opt.symmetry(GraphColor::SYMMETRY_NONE,"none");
    //opt.symmetry(GraphColor::SYMMETRY_LDSB,"ldsb","use value symmetry breaking");
    //opt.parse(argc,argv);
    Script::run<GraphColor,BAB,SizeOptions>(opt);

    return 0;
}