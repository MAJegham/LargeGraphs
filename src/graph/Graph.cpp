#include "graph/Graph.hpp"
#include "graph/elements/Edge.hpp"

#include "utils/MathUtils.hpp"
#include "utils/FileUtils.hpp"

#include <fstream>
#include <stdexcept>
#include <limits>

Graph::Graph():
    _nbVertices(0),
    _nbEdges(0),
    _maxVertexIndex(0),
    _minVertexIndex(std::numeric_limits<unsigned long>::max())
{
}

Graph::Graph(std::string edgesListFileName_p, bool checkFormat_p):
    _nbVertices(0),
    _nbEdges(0),
    _maxVertexIndex(0),
    _minVertexIndex(std::numeric_limits<unsigned long>::max())
{
    if (checkFormat_p && !isWellFormatted(edgesListFileName_p))
    {
        throw std::runtime_error("Graph::Graph: innapropriate file format! please use: NODE1 NODE2" );
    }

    std::ifstream file_l(edgesListFileName_p);

    if (file_l.is_open())
    {
        Edge edge_l;
        while ( file_l >> edge_l.s >> edge_l.t )
        {
            _maxVertexIndex = max3(_maxVertexIndex,edge_l.s,edge_l.t);
            _minVertexIndex = min3(_minVertexIndex,edge_l.s,edge_l.t);
            ++_nbEdges;
	    }
        file_l.close();
    }
    else
    {
        throw std::runtime_error("Graph::Graph: inexistant file " + edgesListFileName_p );
    }

	_nbVertices = _maxVertexIndex - _minVertexIndex + 1;
}


Graph::~Graph(){}

unsigned long Graph::get_nbVertices() const
{
    return _nbVertices;
}

unsigned long Graph::get_nbEdges() const
{
    return _nbEdges;
}

unsigned long Graph::get_maxVertexIndex() const
{
    return _maxVertexIndex;
}

unsigned long Graph::get_minVertexIndex() const
{
    return _minVertexIndex;
}


std::ostream& operator<<(std::ostream & strm, const Graph & graph) {
    strm << "Number of Edges: " << graph.get_nbEdges() << "\n"
        << "Number of Vertices: " << graph.get_nbVertices() << "\n"
        << "Lowest vertex index: " << graph.get_minVertexIndex() << "\n"
        << "Biggest vertex index: " << graph.get_maxVertexIndex();
  return strm;
}