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

void VCPSolver::graph2CliqueSet(graph_t* a_graph,int** a_set)
{
    // prepare optinons for cliquer
    clique_options* opts;
    opts = (clique_options*) malloc (sizeof(clique_options));
    opts->time_function=NULL;
    opts->reorder_function=reorder_by_greedy_coloring;
    opts->reorder_map=NULL;
    opts->user_function=NULL;
    opts->user_data=NULL;
    opts->clique_list=NULL;
    opts->clique_list_length=0;

    graph_t* g;    
    graph_t* h;  
    graph_t* G;  
    set_t*   Cs;
    int n = a_graph->n;
    int m = graph_edge_count(m_graph);
    int n_c = 0;   /// Number of maximal cliques found
    int UB = n;
    int LB = 0;
    set_t s = set_new(n);
    float density = (float)m/(n*(n-1)/2);
    
	/// Reorder the graph
    g = graph_new(n);
    h = graph_new(n);
    G = graph_new(n);
    vector<int> inver(n,0);
    for ( int i = 0; i < n-1; ++i ) 
		for ( int j = i+1; j < n ; ++j )
			if ( GRAPH_IS_EDGE(m_graph,m_graph_matrix[i],m_graph_matrix[j]) ) {
				GRAPH_ADD_EDGE(g,i,j);
				GRAPH_ADD_EDGE(h,i,j);
				GRAPH_ADD_EDGE(G,i,j);
				inver[m_graph_matrix[i]] = i;
				inver[m_graph_matrix[j]] = j;
			}

    Cs = (set_t*)malloc(m*sizeof(set_t));
    set_t C  = set_new(n);

    /// Start with a maximal clique as lower bound
    if ( density > 0.0 )
       s = clique_find_single ( g, 2, 0, TRUE, opts);
    else
       s = clique_find_single ( g, 0, 0, TRUE, opts);

    maximalize_clique(s,g);
   
    if ( s != NULL && set_size(s) > LB ) {
       LB = set_size(s);
       set_copy(C,s);  /// C is the best maximal clique found
    }

    bool removed = true;
    int  n_r = 0;
    while ( removed ) {
       removed = false;
       for ( int i = 0; i < n; ++i ) {
           if ( graph_vertex_degree(g, i) < LB-1 ) { 
             for ( int j = 0; j < n ; ++j )
                if ( GRAPH_IS_EDGE(g,i,j) ) {
                   GRAPH_DEL_EDGE(g,i,j);
                   GRAPH_DEL_EDGE(h,i,j);
                   n_r++;
                   removed = true;
                }
            }
        }
    }

    while ( graph_edge_count(h) > 0 ) {
        bool flag = false;
        /// Find a maximal clique for every vertex, and store the largest
        float density = (float)graph_edge_count(h)/(n*(n-1)/2);
     
        if ( density > 0.0 )
            s = clique_find_single ( h, 2, 0, TRUE, opts);
        else
            s = clique_find_single ( h, 0, 0, TRUE, opts);

        maximalize_clique(s,g);

        if ( s != NULL ) {
            if ( set_size(s) > LB ) {
            LB = set_size(s);
            set_copy(C,s);  // C is the best maximal clique found
            flag = true;
        } 
        Cs[n_c++]=set_duplicate(s);
        for ( int j = 0; j < n; ++j )
           if ( SET_CONTAINS_FAST(s,j) )
              for ( int l = j+1; l < n; ++l )
                 if ( SET_CONTAINS_FAST(s,l) && GRAPH_IS_EDGE(h,j,l) )
                    GRAPH_DEL_EDGE(h,j,l);
        }

        /// Reduce the graph (if degree smaller than LB, then remove the vertex)
        if ( flag )
           for ( int i = 0; i < n; ++i ) {
              if ( graph_vertex_degree(g, i) < LB-1 ) { 
                 for ( int j = 0; j < n ; ++j )
                    if ( GRAPH_IS_EDGE(g,i,j) ) {
                       GRAPH_DEL_EDGE(g,i,j);
                       if ( GRAPH_IS_EDGE(h,i,j) )
                          GRAPH_DEL_EDGE(h,i,j);
                       n_r++;
                    }
                 }
              }
           }

  /*
	
	int size = 0;
    int num_of_sets = 0;
    for (unsigned int i=0; i<m; ++i)
        if (Cs[i] != NULL)
        {
            size += set_size(Cs[i])+1;
            ++num_of_sets;
        }
    
    *a_set = (int*)malloc((size+1)*sizeof(int));
    
    int next_element = 0;
    for (int i=0; i<num_of_sets; i++)
    {
        *(*a_set + next_element++) = set_size(Cs[i]);
        for (int j=0; j<set_size(Cs[i]); ++j)
            *(*a_set + next_element++) = Cs[i][j];
    }
    *(*a_set + next_element++) = -1;

    std::copy(*a_set, *a_set + size+1, std::ostream_iterator<int>(std::cout, ", "));*/
   // return Cs;
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