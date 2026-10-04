class Codec {
public:
    string serialize(TreeNode* root) {
        vector<string> res;
        serializeDfs(root, res);
        string out;
        for (size_t k = 0; k < res.size(); ++k) {
            if (k) out += ',';
            out += res[k];
        }
        return out;
    }
    TreeNode* deserialize(string data) {
        vector<string> vals;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) vals.push_back(token);
        int i = 0;
        return deserializeDfs(vals, i);
    }
private:
    void serializeDfs(TreeNode* node, vector<string>& res) {
        if (!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        serializeDfs(node->left, res);
        serializeDfs(node->right, res);
    }
    TreeNode* deserializeDfs(const vector<string>& vals, int& i) {
        if (i >= (int)vals.size() || vals[i] == "N") {
            ++i;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(vals[i++]));
        node->left = deserializeDfs(vals, i);
        node->right = deserializeDfs(vals, i);
        return node;
    }
};