#include <gtest/gtest.h>

#include "graph/EdgeListGraph.hpp"

#include "utils/FileUtils.hpp"


#include <fstream>
#include <sys/types.h> //opendir
#include <dirent.h> //opendir
#include <string>


class FileUtilsTest : public ::testing::Test
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

//file has innapropriate format
TEST_F(FileUtilsTest, wrongFormatTest)
{
 	EXPECT_TRUE(_dataDirFound);
	EXPECT_FALSE(isWellFormatted(_dataDir+"wrongFormat.txt"));
}

TEST_F(FileUtilsTest, correctFormatTest)
{
 	EXPECT_TRUE(_dataDirFound);
	EXPECT_TRUE(isWellFormatted(_dataDir+"toy.txt"));
    EXPECT_TRUE(isWellFormatted(_dataDir+"nonContinuous.txt"));
    EXPECT_TRUE(isWellFormatted(_dataDir+"duplicates.txt"));
}

TEST_F(FileUtilsTest, makeUndirectedTest)
{
 	EXPECT_TRUE(_dataDirFound);
	std::string input_l = _dataDir+"duplicates.txt";
    std::string output_l = _dataDir+"out_duplicates.txt";
    makeUndirectedUniqueEdges(input_l, output_l);

    std::ifstream file_l(output_l);

    if (file_l.is_open())
    {
        std::map< std::pair<unsigned long, unsigned long > , unsigned long> occurences_l;
        unsigned long s;
        unsigned long t;
        while ( file_l >> s >> t )
        {
            EXPECT_LT(s,t); // s < t
            EXPECT_EQ(++occurences_l[std::make_pair(s,t)],1u);
	    }
        file_l.close();
    }
    else
    {
        throw std::runtime_error("Graph::Graph: inexistant file " + output_l );
    }
}


