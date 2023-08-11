#include "Autocompletion.h"

Trie::TrieNode* Trie::getNewNode(void)
{

    TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    pNode->count = 1;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


//Вставляет ключ в дерево, если его нет.
//Иначе, если ключ явлется префиксом узла дерева, 
//помечает в качестве листового т.е. конец слова.
void Trie::insert(std::string& key)
{
    TrieNode* node = root;                       

    for (int i = 0; i < key.length(); i++)
    {
        //Вычисляет индекс в алфавите через смещение относительно первой буквы.
        int index = key[i] - 'a';

        //Если указатель пустрой, т.е. детей с таким префиксом нет, 
        //то создает новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            (node->children[index]->count)++;

        node = node->children[index];
    }
    //Помечает последний узел как лист, т.е. конец слова.
    node->isEndOfWord = true;
}

//Функция, для нахождения кратчайшего уникального префикса для каждого слова в дереве.
void Trie::findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res)
{

    if (root == nullptr)
        return;

    if (root->count == 1 and ind)
    {
        buf[ind] = '\0';
        res += buf;
        res += " ";
        std::cout << res << " ";
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr)
        {
            buf[ind] = 'a' + i;

            findMinPrefixes(root->children[i], buf, ind + 1, res);
        }
    }
}


Trie::TrieNode* Trie::insertion(std::string arr[], int n)
{

    for (int i = 0; i < n; i++)
        insert(arr[i]);
    return root;

}

bool Trie::isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}


//Ищет все слова в дереве соответствующие префиксу.
void Trie::findAllPrefix(std::string& key)
{
    TrieNode* node2 = root;                   
    int start_index(0);
    for (int i = 0; i < key.length(); i++)    
    {
        int index = key[i] - 'a';
        if (!node2->children[index])
            return;
        node2 = node2->children[index];
        start_index = index;
    }

    int numb_word = node2->count;                

    while (numb_word)                            
    {
        TrieNode* node = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!node->children[index])
                return;
            std::cout << char(index + 'a');
            node = node->children[index];
        }

        int word_size = WORD_SIZE;  
        while (word_size)
        {
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (node->children[i] != nullptr and node->children[i]->count) 
                {
                    std::cout << char(i + 'a');
                    if (!node->isEndOfWord)
                        node->count--;
                    node = node->children[i];

                    for (int i = 0; i < ALPHABET_SIZE; i++)
                    {
                        if (node->children[i] != nullptr and (node->isEndOfWord))
                        {
                            node->count--;
                            break;
                        }
                        else  if (node->isEndOfWord)
                        {
                            node->count--;
                            break;
                        }
                    }
                }
            }
            word_size--;
        }
        std::cout << " ";
        numb_word--;
    }
}



