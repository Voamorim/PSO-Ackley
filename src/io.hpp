#ifndef IO_HPP
#define IO_HPP

#include <bits/stdc++.h>

using namespace std;

class Io{
    private:
        string getFileName(const int &argc, char **argv, const string &flag);
        int getId(const int &argc, char **argv, const string &flag);
    public:
        string getFacOutputFileName(const int &argc, char **argv);
        string getGenOutputFileName(const int &argc, char **argv);
        int getSolutionId(const int &argc, char **argv);
        int getTopologyId(const int &argc, char **argv);
};

#endif