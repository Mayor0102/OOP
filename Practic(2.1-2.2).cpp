// Practic(2.1-2.2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<map>
#include<string>
#include<list>
#include<set>
#include<vector>

using namespace std;


template<class K, class Z>
Z Find_Z(const map<K, Z>& myMap, const K& key)
{
    auto it = myMap.find(key);
    if (it != myMap.end())
    {
        return it->second;
    }
    else
    {
        return Z();
    }
}

template<class K, class Z>
Z Find_Z_multi(const multimap<K, Z>& myMulti, const K& key)
{
    auto it = myMulti.find(key);
    if (it != myMulti.end())
    {
        return it->second;
    }
    else
    {
        return Z();
    }
}

template<typename K, typename Z>
list<K> Find_K(const map<K, Z>& myMap, const Z& value) {
    list<K> result;
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        if (it->second == value) 
        {
            result.push_back(it->first);
        }
    }
    return result;
}

template<typename K, typename Z>
list<K> Find_K_multi(const multimap<K, Z>& myMulti, const Z& value) {
    list<K> result;
    for (auto it = myMulti.begin(); it != myMulti.end(); ++it)
    {
        if (it->second == value)
        {
            result.push_back(it->first);
        }
    }
    return result;
}

template<class K, class Z>
void printMap(const map<K, Z> myMap)
{
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << "Key: " << it->first << " " << "Value: " << it->second << endl;
    }
}

template<class K, class Z>
void printMulti(const multimap<K, Z> myMulti)
{
    for (auto it = myMulti.begin(); it != myMulti.end(); ++it)
    {
        cout << "Key: " << it->first << " " << "Value: " << it->second << endl;
    }
}

bool pred(const string& bloodGroup) {
    map<string, int> bloodGroupOrder;
    bloodGroupOrder["A+"] = 1;
    bloodGroupOrder["A-"] = 2;
    bloodGroupOrder["B+"] = 3;
    bloodGroupOrder["B-"] = 4;
    bloodGroupOrder["AB+"] = 5;
    bloodGroupOrder["AB-"] = 6;
    bloodGroupOrder["0+"] = 7;
    bloodGroupOrder["0-"] = 8;

    if (bloodGroupOrder.find(bloodGroup) != bloodGroupOrder.end())
    {
        return bloodGroupOrder[bloodGroup] > bloodGroupOrder["0-"];
    }
    else 
    {
        return false;
    }
}

bool pred_2(const string& bloodGroup) {
    multimap<string, int> bloodGroupOrder;
    bloodGroupOrder.emplace("A+", 8);
    bloodGroupOrder.emplace("A-", 7);
    bloodGroupOrder.emplace("B+", 6);
    bloodGroupOrder.emplace("B-", 5);
    bloodGroupOrder.emplace("AB+", 4);
    bloodGroupOrder.emplace("AB-", 3);
    bloodGroupOrder.emplace("0+", 2);
    bloodGroupOrder.emplace("0-", 1);

    auto bloodGroupIt = bloodGroupOrder.find(bloodGroup);
    if (bloodGroupIt != bloodGroupOrder.end())
    {
        auto zeroNegIt = bloodGroupOrder.find("0-");
        return bloodGroupIt->first > zeroNegIt->first;
    }
    else
    {
        return false;
    }
}

template<class K, class Z>
map<K, Z> filter(const map<K, Z>& myMap, bool (*pred)(const Z&))
{
    map<K, Z> result;
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        if (pred(it->second))
        {
            result.emplace(it->first, it->second);
        }
    }
    return result;
}

template<class K, class Z>
multimap<K, Z> filter_2(const multimap<K, Z>& myMulti, bool (*pred_2)(const Z&))
{
    multimap<K, Z> result;
    for (auto it = myMulti.begin(); it != myMulti.end(); ++it)
    {
        if (pred_2(it->second))
        {
            result.emplace(it->first, it->second);
        }
    }
    return result;
}

template<class K, class Z>
vector<Z> values(map<K, Z>& myMap)
{
    set<Z> uniqueValSet;
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
        uniqueValSet.insert(it->second);
    vector<Z> uniqueVal(uniqueValSet.begin(), uniqueValSet.end());
    return uniqueVal;
}

template<class K, class Z>
vector<Z> values(multimap<K, Z>& myMulti)
{
    set<Z> uniqueValSet;
    for (auto it = myMulti.begin(); it != myMulti.end(); ++it)
        uniqueValSet.insert(it->second);
    vector<Z> uniqueVal(uniqueValSet.begin(), uniqueValSet.end());
    return uniqueVal;
}

template<class K, class Z>
vector<Z> same_key(multimap<K, Z>& myMulti, const K& key)
{
    vector<Z> res;
    
    for (auto it = myMulti.begin(); it != myMulti.end(); ++it)
    {
        if (it->first == key)
        {
            res.push_back(it->second);
        }
    }
    return res;
}



int main()
{
    cout << "----- Map -----" << endl;
    
    map<int, string> myMap;
    try
    {
        myMap[111] = "A+";
        myMap[112] = "0+";
        myMap[113] = "A+";
        myMap[117] = "AB-";
        myMap[114] = "AB+";
        myMap[115] = "0-";
        //myMap[111] = "AB-";
    }
    catch (const out_of_range& e) 
    {
        cerr << "Произошло исключение: " << e.what() << endl;
    }

    printMap(myMap);
    //printMap(myMap);

    string strResult = Find_Z(myMap, 111);
    cout << "Found values: " << strResult << endl;

    string valueToFind = "0-";
    list<int> foundKeys = Find_K(myMap, valueToFind);

    if (!foundKeys.empty())
    {
        cout << "Found keys " << valueToFind << " : ";
        for (int key : foundKeys) {
            cout << key << " ";
        }
        cout << endl;
    }
    else 
    {
        cout << "Keys with values \"" << valueToFind << "\" not found." << endl;
    }

    map<int, string> filtered_map = filter(myMap, pred);
    cout << "Filterd map: " << endl;
    for (auto it = filtered_map.begin(); it != filtered_map.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    vector<string> result = values(myMap);
    for (string value : result)
    {
        cout << value << " ";
    }
    cout << endl;
    cout << endl;
    cout << "----- Multimap -----" << endl;
    cout << endl;
    multimap<int, string> myMulti;
    myMulti.insert(make_pair(111, "A+"));
    myMulti.insert(make_pair(111, "0-"));
    myMulti.insert(make_pair(111, "0+"));
    myMulti.insert(make_pair(111, "A+"));
    myMulti.insert(make_pair(115, "AB-"));
    myMulti.insert(make_pair(115, "AB+"));
    myMulti.insert(make_pair(115, "A+"));
    myMulti.insert(make_pair(115, "0+"));
    myMulti.insert(make_pair(116, "A+"));
    printMulti(myMulti);

    string Result = Find_Z_multi(myMulti, 111);
    cout << "Found values: " << Result << endl;

    string valueTofind = "A+";
    list<int> foundkeys = Find_K_multi(myMulti, valueTofind);

    if (!foundkeys.empty())
    {
        cout << "Found keys " << valueTofind << " : ";
        for (int key : foundkeys) {
            cout << key << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Keys with values \"" << valueTofind << "\" not found." << endl;
    }


    multimap<int, string> filtered_multi = filter_2(myMulti, pred_2);
    cout << "Filterd multimap: " << endl;
    for (auto it = filtered_multi.begin(); it != filtered_multi.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    vector<string> same_keys_111 = same_key(myMulti, 111); 
    cout << "Elements with key 111: ";
    for (const auto& value : same_keys_111)
    {
        cout << value << " ";
    }
    cout << endl;

    vector<string> same_keys_115 = same_key(myMulti, 115);
    cout << "Elements with key 115: ";
    for (const auto& value : same_keys_115)
    {
        cout << value << " ";
    }

    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
