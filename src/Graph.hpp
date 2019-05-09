#pragma once
#include <iostream>
#include <string>

class Graph
{


protected:
    //number of edges in the graph
    unsigned long _nbEdges;
    //number of vertives in the graph 
    //FIXME for now it's over-estimated 
    unsigned long _nbVertices;
    //highest index used for vertices
    unsigned long _maxVertexIndex;
    //lowest index used for vertices
    unsigned long _minVertexIndex;

public:
    /**
    *@brief default constructor for graph
    */
    Graph();

    /**
    *@brief construct the graph from an input file
    *
    *@param edgesListFileName_p: path to a file listing the edges of the graph
    *@param checkFormat_p: true if we should check the file's format before using it
    *
    *@throw runtime_error when file has the wrong format
    *@throw runtime_error when file doesn't exist
    */
    Graph(std::string edgesListFileName_p, bool checkFormat_p = true);

    //destructor
    virtual ~Graph();

    //Getter for attribute _nbVertices
    unsigned long get_nbVertices() const;
    
    //Getter for attribute _nbEdges
    unsigned long get_nbEdges() const;
    
    //Getter for attribute _maxVertexIndex
    unsigned long get_maxVertexIndex() const;
    
    //Getter for attribute _minVertexIndex
    unsigned long get_minVertexIndex() const;

};


//Graph's operator<< overload for output streams
std::ostream& operator<<(std::ostream & strm, const Graph & graph);