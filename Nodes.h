#pragma once
#include <vector>
#include <iostream>

class Nodes
{
public:
    Nodes();
    Nodes(char);
    Nodes(char, const std::vector<std::pair<Nodes*, int>>&);
    Nodes(char, Nodes*, int);
    ~Nodes();

    std::vector<std::pair<Nodes*, int>> getNeighbors() const;

    void addNeighbor(Nodes*, int);
    void addNeighbor(std::vector<std::pair<Nodes*, int>>);
    void removeNeighbor(Nodes*);
    void removeAllNeighbors();
    void showNeighbors();

    char getName() const;
    void setName(char);

    bool Getalreadysee();
    void Setseealready(bool a);

    int GetdistMin();
    void SetMindist(int d);

    Nodes* GetlastVisited();
    void SetVisitedLast(Nodes* n);

private:
    char name_;
    std::vector<std::pair<Nodes*, int>> neighbors_;
    bool alreadysee = false;
    int distMin = INT_MAX;
    Nodes* lastVisited = nullptr;
};