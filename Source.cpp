
#include "Nodes.h"

Nodes* GetCloserNodes(std::vector<Nodes*> g) {
    int mindist = INT_MAX;
    Nodes* MinNodes = nullptr;

    for (Nodes* node:g)
    {
        if (!node->Getalreadysee() && node->GetdistMin() < mindist) {
            mindist = node->GetdistMin();
            MinNodes = node;
       }
    }
    return MinNodes;
}

void Dijkstra(std::vector<Nodes*> t, Nodes* Start) {
    Start->SetMindist(0);
    while (true) {
        Nodes* CurrentNode = GetCloserNodes(t);
        if (CurrentNode == nullptr) break;
        CurrentNode->Setseealready(true);
        for (std::pair<Nodes*, int> n : CurrentNode->getNeighbors()) {
            Nodes* NodeNeighbors = n.first;
            int height = n.second;
            int distanceToNext = CurrentNode->GetdistMin() + height;
            if (distanceToNext < NodeNeighbors->GetdistMin()) {
                NodeNeighbors->SetMindist(distanceToNext);
                NodeNeighbors->SetVisitedLast(CurrentNode);
            }
        }
    }
}

void printPath(Nodes* target) {
    if (target->GetlastVisited() == nullptr) {
        std::cout << target->getName();
        return;
    }
    printPath(target->GetlastVisited());
    std::cout << " -> " << target->getName();
}

int main(int argc, char* argv[])
{
    std::vector<Nodes*> graphs;
    Nodes A('A');
    Nodes B('B');
    Nodes C('C');
    Nodes D('D');
    Nodes E('E');
    Nodes F('F');
    Nodes G('G');
    Nodes H('H');
    Nodes I('I');
    Nodes J('J');

    A.addNeighbor(&B, 85);
    A.addNeighbor(&C, 217);
    A.addNeighbor(&E, 173);
    B.addNeighbor(&F, 80);
    C.addNeighbor(&G, 186);
    C.addNeighbor(&H, 103);
    D.addNeighbor(&H, 183);
    E.addNeighbor(&J, 502);
    F.addNeighbor(&I, 250);
    H.addNeighbor(&J, 167);
    I.addNeighbor(&J, 84);

    graphs.emplace_back(&A);
    graphs.emplace_back(&B);
    graphs.emplace_back(&C);
    graphs.emplace_back(&D);
    graphs.emplace_back(&E);
    graphs.emplace_back(&F);
    graphs.emplace_back(&G);
    graphs.emplace_back(&H);
    graphs.emplace_back(&I);
    graphs.emplace_back(&J);

    Dijkstra(graphs, &A);

    std::cout << " La distance de A a " << J.getName() << " est de ";
    if (J.GetdistMin() == INT_MAX)
        std::cout << "infinie \n";
    else
        std::cout << J.GetdistMin();
    std::cout << " (path:  ";
    printPath(&J);
    std::cout << ")\n";

    return 0;
}