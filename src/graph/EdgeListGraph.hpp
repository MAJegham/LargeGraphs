#include "graph/Graph.hpp"


#include <vector>

struct Edge;


class EdgeListGraph : public Graph
{
protected:
    std::vector<Edge> _vectEdges;

public:

    /**
    *@brief default constructor for graph
    */
    EdgeListGraph();

    /**
    *@brief construct the graph from an input file
    *
    *@param edgesListFileName_p: path to a file listing the edges of the graph
    *@param checkFormat_p: true if we should check the file's format before using it
    *
    *@throw runtime_error when file has the wrong format
    *@throw runtime_error when file doesn't exist
    */
    EdgeListGraph(std::string edgesListFileName_p, bool checkFormat_p = true);

    //destructor
    virtual ~EdgeListGraph();

    //Getter for attribute _nbVertices
    const std::vector<Edge> & get_vectEdges() const;

};

//Graph's operator<< overload for output streams
std::ostream& operator<<(std::ostream & strm, const EdgeListGraph & edgeListGraph);