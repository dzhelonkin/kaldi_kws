#include "VCPSolver.h"

using namespace std;

VCPSolver::VCPSolver(const char* a_file_path):
        m_graph(NULL),
        m_graph_matrix(NULL),
        m_clique_set(NULL)
{
    m_graph = graph_read_dimacs_file(const_cast<char*>(a_file_path));
    //m_graph_matrix = reorder_by_degree(m_graph,FALSE);

    graph2VertexMatrix(m_graph,&m_graph_matrix);
    graph2CliqueSet(m_graph,&m_clique_set);
    //std::copy(m_graph_matrix, m_graph_matrix + m_graph->n, std::ostream_iterator<int>(std::cout, ", "));
}

VCPSolver::~VCPSolver()
{
    graph_free(m_graph);
    free(m_graph_matrix);
    free(m_clique_set);
}

//void VCPSolver::readGraph()
//{

//}

void VCPSolver::graph2VertexMatrix(graph_t* a_graph,int** a_matrix)
{
    unsigned int edge_count = 0;
    unsigned int next_element = 0;
    //edge_count = graph_edge_count(a_graph);
    
    //cout << edge_count <<" " <<a_graph->n << endl;

    *a_matrix = (int*)malloc((edge_count*2+2)*sizeof(int));

    for(int i = 0; i < a_graph->n; ++i)
    {
        //set_print(a_graph->edges[i]);
        unsigned long current_set_size = SET_MAX_SIZE(a_graph->edges[i]);

        for (int j=i; j<current_set_size; ++j)
        {
            if (j == i)
                continue;
            if (SET_CONTAINS(a_graph->edges[i],j))
            {
                *(*a_matrix + next_element++) = i;
                *(*a_matrix + next_element++) = j; 
            }
           // cout << "current: " << next_element << endl;
        }
        
    }

    *(*a_matrix + next_element++) = -1;
    *(*a_matrix + next_element++) = -1; 

    //cout << next_element << endl;
}

void graph2CliqueSet(graph_t* a_graph,int** a_set)
{
    //todo
}

void VCPSolver::solveMatrix()
{
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
 
    GraphColorSpec spec(graph_edge_count(m_graph), m_graph_matrix, g1_c);



    Script::run<GraphColor,BAB,SizeOptions>(opt);
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

    solver.solveMatrix();


    return 0;
}