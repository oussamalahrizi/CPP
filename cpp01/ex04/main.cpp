#include <iostream>
#include <fstream>


void replace(std::string &line, std::string &s1, std::string &s2)
{
    size_t i = 0;

    while (!s1.empty() && (i = line.find(s1, i) ) != std::string::npos)
    {
        line.erase(i, s1.length());
        line.insert(i, s2);
    }
}

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cerr << "Wrong usage" << std::endl;
        return (1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream inputfile(filename.c_str());
    if (!inputfile.is_open() || !inputfile.good())
    {
        std::cerr << "Failed to open the file " << filename << std::endl;
        return (1);
    }
    std::ofstream outputfile((filename + ".replace").c_str());
    if (!outputfile.is_open())
    {
        std::cerr << "Failed to create a replace file" << std::endl;
        inputfile.close();
        return (1);
    }
    std::string line;
    while (std::getline(inputfile, line))
    {
        replace(line, s1, s2);
        line += '\n'; 
        outputfile << line;
    }
    inputfile.close();
    outputfile.close();
    return (0);
}