#include <iostream>
#include <climits>
using namespace std;
#define size 10
string hashtable[size];
bool occupied[size] = {false};
int hashFunction(string key)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
    {
        sum = sum + key[i];
    }
    return (3*sum+4) % size;
}
void insert(string key)
{
    int index = hashFunction(key);
    int startindex = index;
    while (occupied[index] == true)
    {
        index = (index + 1) % size;
        if (index == startindex)
        {
            cout << "hashtable is full";
            break;
        }
    }
    hashtable[index] = key;
    occupied[index] = true;
}
void search(string key)
{
    int index = hashFunction(key);
    int startindex = index;
    while (occupied[index] == true)
    {
        if(hashtable[index]==key){
            cout << key <<" found at index "<<index <<endl;
            break;
        }
        index = (index + 1) % size;
        if (index == startindex)
        {

            break;
        }
    }
         cout << "NOT found";
}
// Display function
void display()
{
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i << " : " << hashtable[i] << endl;
    }
}
int main()
{
    insert("Data Structure");
    // insert("Sara");
    // insert("Zain");
    // insert("Ayan");
    // insert("Ali");
    display();
    
}