#include "utils/FileUtils.hpp"

#include <bits/stdc++.h>
#include <fstream>
#include <stdexcept>

#include <regex>

//#include <dirent.h>
#include <unistd.h>


bool isWellFormatted(std::string filename_p)
{
    std::ifstream file_l(filename_p);
    if (file_l.is_open())
    {
        const std::regex regex_l{"^\\s*\\d+\\s+\\d+\\s*$"};

        std::string line_l;
        while(std::getline(file_l,line_l))
        {
            if ( !std::regex_match(line_l, regex_l) )
            {
                return false;
            }
        }
    }
    else
    {
        throw std::runtime_error("FileUtils::isWellFormatted: inexistant file " + filename_p );
    }

    return true;
}

void makeUndirectedUniqueEdges(std::string filename_p, std::string outFilename_p)
{
    if ( outFilename_p == "" )
    {
        outFilename_p = filename_p;
    }

    std::ifstream file_l(filename_p);
    if (file_l.is_open())
    {
        std::string command = "awk '{if ($1<$2) print $1\" \"$2;else if ($2<$1) print $2\" \"$1}' "+ filename_p +
                            " | sort -n -k1,1 -k2,2 -u > " + outFilename_p;
        system(command.c_str());
    }
    else
    {
        throw std::runtime_error("FileUtils::isWellFormatted: inexistant file " + filename_p );
    }
}

std::string getTestDataDir()
{
    std::string currentDir_l = get_current_dir_name();
    std::string baseDir_l = currentDir_l.substr(0, currentDir_l.find("/LargeGraphs/")+13);
    std::string dataDir_l = baseDir_l+"test/data_test/";

    return dataDir_l;
}