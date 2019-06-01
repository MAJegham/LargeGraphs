#pragma once

#include <string>


/**
 * Returns true if the file has the following format
 * (spacing)* digits (spacing)* digits (spacing)*
 * on each line
 *
 * @Throws runtime_error if the input file does not exist
**/
bool isWellFormatted(std::string filename_p);

/**
 * Transforms a file representing the edge list of some graph
 * into that of a simple undirected graph with non duplicate edges
 *
 * @Params filename_p input file to process
 * @params outFilename_p target file to print output defaults to the inputfile itself
 *
 * @throws runtime_error if the input file does not exist
 **/
void makeUndirectedUniqueEdges(std::string filename_p, std::string outFilename_p = "");

// returns the path to the test data directory
std::string getTestDataDir();