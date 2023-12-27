#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

class GNode {
public:
    string id;

    GNode(string id) : id(id) {}

    string getId() const {
        return id;
    }

    // 비교 연산자 정의
    bool operator==(const GNode& other) const {
        return id == other.id;
    }
};

// GNode의 해시 함수 정의
namespace std {
    template <>
    struct hash<GNode> {
        size_t operator()(const GNode& node) const {
            return hash<string>()(node.id);
        }
    };
}

vector<vector<string>> paths(unordered_map<GNode, vector<GNode>>& G, GNode s, GNode t) {
    vector<vector<string>> result;

    function<void(GNode, vector<string>)> dfs = [&](GNode curr, vector<string> path) {
        if (curr.getId() == t.getId()) {
            path.push_back(curr.getId());
            result.push_back(path);
        } else {
            path.push_back(curr.getId());
            for (GNode neighbor : G[curr]) {
                dfs(neighbor, path);
            }
        }
    };

    dfs(s, {});

    return result;
}

int main() {
    GNode a("a");
    GNode b("b");
    GNode c("c");
    GNode d("d");

    unordered_map<GNode, vector<GNode>> G;
    G[a] = {b, c};
    G[b] = {d};
    G[c] = {};
    G[d] = {c};

    vector<vector<string>> result = paths(G, a, c);

    cout << "Paths from 'a' to 'c':" << endl;
    for (vector<string> path : result) {
        for (string node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
