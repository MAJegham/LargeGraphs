#include "graph/EdgeListGraph.hpp"
#include "graph/elements/Edge.hpp"

#include "utils/FileUtils.hpp"
#include "utils/MathUtils.hpp"

#include <iostream>
#include <fstream>

EdgeListGraph::EdgeListGraph(std::string edgesListFileName_p, bool checkFormat_p)
    : Graph()
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
            _vectEdges.push_back(edge_l);
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

EdgeListGraph::~EdgeListGraph(){}

const std::vector<Edge> & EdgeListGraph::get_vectEdges() const
{
    return _vectEdges;
}