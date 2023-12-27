#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class GNode {
public:
    string id;
    string color;
    int distance;
    GNode* parent;

    GNode(string _id, string _color = "W", int _d = 0, GNode* _p = nullptr)
        : id(_id), color(_color), distance(_d), parent(_p) {}

    string getId() const {
        return id;
    }
};

unordered_map<string, vector<string>> show_GNode(const unordered_map<string, vector<GNode*>>& G) {
    unordered_map<string, vector<string>> res;
    for (const auto& entry : G) {
        string key_id = entry.first;
        const vector<GNode*>& items = entry.second;
        vector<string> items_id_list;
        for (const GNode* item : items) {
            items_id_list.push_back(item->getId());
        }
        res[key_id] = items_id_list;
    }
    return res;
}

void bfs(unordered_map<string, vector<GNode*>>& G, GNode* s) {
    queue<GNode*> que;
    s->color = "G";

    que.push(s);

    while (!que.empty()) {
        GNode* node = que.front();
        que.pop();

        for (GNode* neigh : G[node->id]) {
            if (neigh->color == "W") {
                neigh->color = "G";
                neigh->distance = node->distance + 1;
                neigh->parent = node;
                que.push(neigh);
            }
        }

        node->color = "B";
    }
}

vector<vector<string>> level_partition(unordered_map<string, vector<GNode*>>& G, GNode* s) {
    unordered_map<int, vector<string>> level_dict;
    vector<vector<string>> res;

    bfs(G, s);

    for (const auto& entry : G) {
        const string key = entry.first;
        if (level_dict.find(G[key][0]->distance) != level_dict.end()) {
            level_dict[G[key][0]->distance].push_back(key);
        } else {
            level_dict[G[key][0]->distance] = {key};
        }
    }

    for (int i = 0; i < level_dict.size(); i++) {
        res.push_back(level_dict[i]);
    }

    return res;
}

int main() {
    GNode r("r"), s("s"), t("t"), u("u"), v("v");
    GNode w("w"), x("x"), y("y");

    unordered_map<string, vector<GNode*>> G;
    G["r"] = {&s, &v};
    G["s"] = {&w, &r};
    G["t"] = {&w, &x, &u};
    G["u"] = {&t, &x, &y};
    G["v"] = {&r};
    G["w"] = {&s, &t, &x};
    G["x"] = {&w, &t, &u, &y};
    G["y"] = {&x, &u};

    unordered_map<string, vector<string>> result = show_GNode(G);
    for (const auto& entry : result) {
        cout << entry.first << ": ";
        for (const string& item : entry.second) {
            cout << item << " ";
        }
        cout << endl;
    }

    vector<vector<string>> levels = level_partition(G, &s);
    for (int i = 0; i < levels.size(); i++) {
        cout << "Level " << i << ": ";
        for (const string& node : levels[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
