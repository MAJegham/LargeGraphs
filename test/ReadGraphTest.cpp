#include <gtest/gtest.h>

#include "graph/Graph.hpp"

#include "utils/FileUtils.hpp"

#include <iostream>
#include <sys/types.h> //opendir
#include <dirent.h> //opendir
#include <string>

class ReadGraphTest : public ::testing::Test
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
TEST_F(ReadGraphTest, basicTest)
{
 	EXPECT_TRUE(_dataDirFound);

    Graph graph = Graph(_dataDir+"toy.txt");

    EXPECT_EQ(graph.get_nbEdges(), 7u);
    EXPECT_EQ(graph.get_nbVertices(), 6u);
    EXPECT_EQ(graph.get_maxVertexIndex(), 5u);
    EXPECT_EQ(graph.get_minVertexIndex(), 0u);
}



//FIXME need to count vertices
TEST_F(ReadGraphTest, wrongNumberOfVertices)
{
 	EXPECT_TRUE(_dataDirFound);

    Graph graph = Graph(_dataDir+"nonContinuous.txt");

    EXPECT_EQ(graph.get_nbEdges(), 7u);
    EXPECT_EQ(graph.get_nbVertices(), 16u); //WRONG
    EXPECT_NE(graph.get_nbVertices(), 8u); //Actual nb
    EXPECT_EQ(graph.get_maxVertexIndex(), 15u);
    EXPECT_EQ(graph.get_minVertexIndex(), 0u);
}
