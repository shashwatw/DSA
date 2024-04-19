// https://www.naukri.com/code360/problems/complete-string_2687860

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
            if (!node->isEnd())
            {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    for (string &str : a)
    {
        trie.insert(str);
    }

    string longest = "";
    for (string &str : a)
    {
        if (trie.checkIfPrefixExists(str))
        {
            if (str.length() > longest.length() ||
                (str.length() == longest.length() && str < longest))
            {
                longest = str;
            }
        }
    }

    if (longest == "")
        return "None";
    return longest;
}