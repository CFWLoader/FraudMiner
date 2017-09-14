//
// Created by CFWLoader on 9/14/17.
//

#ifndef GRAPHVIZCONVERTOR_GRAPHVIZCONVERTORS_HPP
#define GRAPHVIZCONVERTOR_GRAPHVIZCONVERTORS_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

namespace graphviz_convertors
{
    bool convertFromEdgesFiles(
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
}

#endif //GRAPHVIZCONVERTOR_GRAPHVIZCONVERTORS_HPP
