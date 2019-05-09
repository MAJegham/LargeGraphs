#include "Graph.hpp"
#include "Edge.hpp"
#include "utils.hpp"
#include <fstream>
#include <stdexcept>
#include <limits> 
#include <regex> 

Graph::Graph(std::string edgesListFileName_p, bool checkFormat_p):
    _nbVertices(0),
    _nbEdges(0),
    _maxVertexIndex(0),
    _minVertexIndex(std::numeric_limits<unsigned long>::max()) 
{
    std::ifstream file_l(edgesListFileName_p);
    
    if (checkFormat_p)
    {
        const std::regex regex_l{"^\\s*\\d+\\s+\\d+\\s*$"};

        std::string line_l;
        while(std::getline(file_l,line_l))
        {
            if ( !std::regex_match(line_l, regex_l) )
            {
                throw std::runtime_error("Graph::Graph: innapropriate file format! please use: NODE1 NODE2" );
            }
        }

        //go back to the beginning of the file to process it 
        file_l.clear();
        file_l.seekg(0);
    }

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
    
	_nbVertices = _maxVertexIndex - _minVertexIndex;
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