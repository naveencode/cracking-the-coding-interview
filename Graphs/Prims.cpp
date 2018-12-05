#include <iostream>
#include <vector>
#include <utility>

class Node {
    private:
        std::string name;
        std::vector<std::pair<Node*, int> > adjacents;
        bool visited;

    public:
        Node(std::string newName) {
            name = newName;
            visited = false;
        }
        void addAdjacent(Node* newNode, int weight) {
            std::pair<Node*, int> newPair(newNode, weight);
            adjacents.push_back(newPair);
        }

        std::string getName() {
            return name;
        }

        std::vector<std::pair<Node*, int> > getAdjacent() {
            return adjacents;
        }

        bool isVisited() {
            return visited;
        }

        void setVisited() {
            visited = true;
        }

        friend class Graph;
        
};

class Graph {
    private:
        std::vector<Node*> all_nodes;

        void setAllUnvisited() {
            for (auto i : all_nodes) {
                i->visited = false;
            }
        }

    public:
        void addEdge(std::string start, std::string end, int weight) {
            Node* start_node = this->getNode(start);
            Node* end_node = this->getNode(end);
            start_node->addAdjacent(end_node, weight);
            end_node->addAdjacent(start_node, weight);
        }

        Node* getNode(std::string name) {
            for (auto node : all_nodes) {
                if (node->name == name)
                    return node;
            }
        }

        void addNode(std::string nodeName) {
            Node *n = new Node(nodeName);
            all_nodes.push_back(n);
        }

        std::vector<Node*> get_all_nodes(){
            return all_nodes;
        }

        void search(std::string start) {
            // DFS
            Node *startNode = this->getNode(start);
            if (startNode && !startNode->isVisited()) {
                // Not visited yet
                std::cout << startNode->getName() << " has been visited\n";
                startNode->setVisited();

                std::vector<std::pair<Node*, int> > all_adjacents = startNode->getAdjacent();
                for (auto adjacent : all_adjacents) {
                    search(adjacent.first->getName());
                }
            }
        }

        int min_connect_weight(std::string start) {
            setAllUnvisited();
            // Add start to visited set
            // for all adjacent nodes of visited
            // add next smallest to visited
            int total_weight = 0;
            Node *startNode = this->getNode(start);
            // std::set<Node*> visited;
            startNode->setVisited();
            std::vector<Node*> visited;
            visited.push_back(startNode);



            // visited.insert(startNode);

            int n = all_nodes.size();
            // Repeat n-1 times to find all nodes
            for (int i=0; i<n-1; i++) {
                int min_weight = 1000000;
                Node* next_visit = NULL;
                for (auto i : visited) {
                    std::vector<std::pair<Node*, int> > adj = i->getAdjacent();
                    for (auto j : adj) {
                        // weight less than min_weight
                        if (!j.first->isVisited() && (j.second < min_weight)) {
                            min_weight = j.second;
                            next_visit = j.first;
                        }
                    }
                }
                visited.push_back(next_visit);
                next_visit->setVisited();
                total_weight += min_weight;
            }

            return total_weight;
        }

        int max_connect_weight(std::string start) {
            setAllUnvisited();
            // Add start to visited set
            // for all adjacent nodes of visited
            // add next smallest to visited
            int total_weight = 0;
            Node *startNode = this->getNode(start);
            // std::set<Node*> visited;
            startNode->setVisited();
            std::vector<Node*> visited;
            visited.push_back(startNode);



            // visited.insert(startNode);

            int n = all_nodes.size();
            // Repeat n-1 times to find all nodes
            for (int i=0; i<n-1; i++) {
                int max_weight = -1000000;
                Node* next_visit = NULL;
                for (auto i : visited) {
                    std::vector<std::pair<Node*, int> > adj = i->getAdjacent();
                    for (auto j : adj) {
                        // weight greater than max_weight
                        if (!j.first->isVisited() && (j.second > max_weight)) {
                            max_weight = j.second;
                            next_visit = j.first;
                        }
                    }
                }
                visited.push_back(next_visit);
                next_visit->setVisited();
                total_weight += max_weight;
            }

            return total_weight;
        }

        
        ~Graph() {
            for (int i=0; i<all_nodes.size(); i++) {
                delete all_nodes[i];
            }
        }
};



int main() {
    Graph g;
    // std::string start_node[10] = {"1", "2", "3"}; 
    // std::string end[10] =        {"2", "3", "1"};

    g.addNode("1");
    g.addNode("2");
    g.addNode("3");

    g.addEdge("1", "2", 5);
    g.addEdge("2", "3", 5);
    g.addEdge("3", "1", 2);

    // DFS
    // g.search("1");

    std::cout << "Min weight to connect graph is " << g.min_connect_weight("1") << std::endl;
    std::cout << "Max weight to connect graph is " << g.max_connect_weight("1") << std::endl;

    return 0;
}