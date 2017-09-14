//
// Created by CFWLoader on 9/14/17.
//

#ifndef GRAPHVIZCONVERTOR_GRAPHVIZCONVERTORS_HPP
#define GRAPHVIZCONVERTOR_GRAPHVIZCONVERTORS_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>

namespace graphviz_convertors
{
    bool convertFromEdgesFile(
            std::string inputFilePath,
            std::string outputFilePath,
            bool hasWeight = false,
            bool directed = false)
    {
        std::ifstream in(inputFilePath);

        std::ofstream out(outputFilePath);

        if(!in.is_open() or !out.is_open())
        {
            return false;
        }

        std::string linkerSym;

        if(directed)
        {
            out << "digraph{" << std::endl;

            linkerSym = "->";
        }
        else
        {
            out << "graph{" << std::endl;

            linkerSym = "--";
        }

        std::string buf;

        while(std::getline(in, buf))
        {
            std::istringstream sstream(buf);

            std::istream_iterator<int> theBegin(sstream), theEnd;

            std::vector<int> array_tokens(theBegin, theEnd);

            out << array_tokens[0] << linkerSym << array_tokens[1] << ";" << std::endl;
        }

        out << "}" << std::endl;

        in.close();

        out.close();

        return true;
    }

    bool convertFromLabelFile(
            std::string inputFilePath,
            std::string outputFilePath)
    {
        std::ifstream in(inputFilePath);

        std::ofstream out(outputFilePath);

        if(!in.is_open() or !out.is_open())
        {
            return false;
        }

        out << "graph{" << std::endl;

        std::map<size_t, std::set<size_t>> communities;

        std::string buf;

        while(std::getline(in, buf))
        {
            std::istringstream sstream(buf);

            std::istream_iterator<int> theBegin(sstream), theEnd;

            std::vector<int> array_tokens(theBegin, theEnd);

//            if(communities.find(array_tokens[1]) == communities.end())
//            {
//                communities[array_tokens[1]] = std::set<size_t>();
//            }

            communities[array_tokens[1]].insert(array_tokens[0]);

//            out << array_tokens[0] << linkerSym << array_tokens[1] << ";" << std::endl;
        }

        for(std::map<size_t, std::set<size_t>>::const_iterator commIter = communities.begin();
                commIter != communities.end();
                ++commIter)
        {
            out << "subgraph cluster_" << commIter->first << "{" << std::endl;

            for(std::set<size_t>::const_iterator memIter = commIter->second.begin();
                    memIter != commIter->second.end();
                    ++memIter)
            {
                out << *memIter << ";" << std::endl;
            }

            out << "}" << std::endl;
        }

        out << "}" << std::endl;

        in.close();

        out.close();

        return true;
    }
}

#endif //GRAPHVIZCONVERTOR_GRAPHVIZCONVERTORS_HPP
