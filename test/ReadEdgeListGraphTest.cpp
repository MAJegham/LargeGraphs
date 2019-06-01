#include <gtest/gtest.h>

#include "graph/EdgeListGraph.hpp"
#include "graph/elements/Edge.hpp"
#include "utils/FileUtils.hpp"

#include <iostream>
#include <sys/types.h> //opendir
#include <dirent.h> //opendir
#include <string>

class ReadEdgeListGraphTest : public ::testing::Test
{
protected:
    std::string _dataDir = "";
    bool _dataDirFound = false;

    //executed before each test
    virtual void SetUp()
    {
        _dataDir = getTestDataDir();

        DIR * dir = opendir(_dataDir.c_str());
        if (dir)
        {
            _dataDirFound = true;
        }
        closedir(dir);
    }
};



//test with toy graph
TEST_F(ReadEdgeListGraphTest, basicTest)
{
 	EXPECT_TRUE(_dataDirFound);

    EdgeListGraph graph_l = EdgeListGraph(_dataDir+"toy.txt");

    EXPECT_EQ(graph_l.get_nbEdges(), 7u);
    EXPECT_EQ(graph_l.get_nbVertices(), 6u);
    EXPECT_EQ(graph_l.get_maxVertexIndex(), 5u);
    EXPECT_EQ(graph_l.get_minVertexIndex(), 0u);

    std::vector<Edge> edges_l = graph_l.get_vectEdges();
    EXPECT_EQ(edges_l.size(), 7u);

    Edge Edge_0(1u,5u);
    EXPECT_EQ(edges_l[0], Edge_0);

}



//FIXME need to count vertices
TEST_F(ReadEdgeListGraphTest, wrongNumberOfVertices)
{
 	EXPECT_TRUE(_dataDirFound);

    EdgeListGraph graph = EdgeListGraph(_dataDir+"nonContinuous.txt");

    EXPECT_EQ(graph.get_nbEdges(), 7u);
    EXPECT_EQ(graph.get_nbVertices(), 16u); //WRONG
    EXPECT_NE(graph.get_nbVertices(), 8u); //Actual nb
    EXPECT_EQ(graph.get_maxVertexIndex(), 15u);
    EXPECT_EQ(graph.get_minVertexIndex(), 0u);
}
