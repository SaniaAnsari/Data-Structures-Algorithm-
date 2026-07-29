#include <iostream>
using namespace std;

// directed graph
struct Edge;
struct Vertex
{
    char data;
    Vertex *next;
    Edge *Edgelist;
    Vertex *parent;
};
struct Edge
{
    Vertex *V;
    Edge *next;
};

Vertex *Head = NULL;
//-------------- Add Vertex-----------------
void addVertex(char val)
{

    Vertex *newvert = new Vertex;
    newvert->data = val;
    newvert->next = NULL;
    newvert->Edgelist = NULL;

    if (Head == NULL)
    {
        Head = newvert;
    }
    else
    {
        Vertex *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newvert;
    }
}

// --------------Add Edge--------------
void addEdge(char sour, char dest)
{
    Vertex *s = NULL;
    Vertex *d = NULL;

    Vertex *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == sour)
        {
            s = temp;
        }
        if (temp->data == dest)
        {
            d = temp;
        }
        temp = temp->next;
    }

    if (s == NULL || d == NULL)
    {
        cout << "vertex not found" << endl;
        return;
    }

    Edge *newedge = new Edge;
    newedge->V = d;
    newedge->next = NULL;

    if (s->Edgelist == NULL)
    {
        s->Edgelist = newedge;
    }
    else
    {
        Edge *t = s->Edgelist;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = newedge;
    }
}

// //-------------RemoveEdge---------------
void removeEdge(char sour, char dest)
{
    Vertex *s = NULL;
    Vertex *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == sour)
        {
            s = temp;
            break;
        }
        temp = temp->next;
    }
    if (s == NULL)
    {
        cout << "not found" << endl;
        return;
    }
    Edge *cur = s->Edgelist; // s(A)->edgelist->B->C    (cur=B)
    Edge *pre = NULL;
    while (cur != NULL)
    {
        if (cur->V->data == dest) //(cur: edge node ka pointer)(cur->V: ye batata hai edge kis vertex ki taraf ja rahi hai)
        {
            if (pre == NULL) // A.Edgelist->B(cur)->C->D   B(ka pre NULL hai)
            {
                s->Edgelist = cur->next;
            }
            else
            {
                pre->next = cur->next;
            }
            delete cur;
            cout << "Edge removed successfully" << endl;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
    cout << "Edge not found" << endl;
}

//--------------------Remove Vertex--------------------
void RemoveVertex(char val) // B
{
    Vertex *del = NULL;
    Vertex *temp = Head;
    Vertex *Vpre = NULL;
    while (temp != NULL)
    {
        // find vertex or uski edges delete karo
        if (temp->data == val)
        {
            del = temp;
            break;
        }
        Vpre = temp;
        temp = temp->next;
    }
    if (del == NULL)
    {

        return;
    }
    Edge *e = del->Edgelist; // B->Edgelist
    while (e != NULL)
    {
        Edge *Etemp = e;
        e = e->next;
        delete Etemp;
    }
    del->Edgelist = NULL; // Bki edegs delete

    // traverse all the vertices or baqi vertices se uski edge remove karo
    Vertex *ver = Head;
    while (ver != NULL)
    {
        Edge *cur = ver->Edgelist;
        Edge *pre = NULL;
        while (cur != NULL)
        {
            if (cur->V == del) // pointer compare
            {
                if (pre == NULL)
                {
                    ver->Edgelist = cur->next;
                }
                else
                {
                    pre->next = cur->next;
                }
                Edge *t = cur;
                cur = cur->next;
                delete t;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        ver = ver->next;
    }
    if (Vpre == NULL)
    {
        Head = del->next;
    }
    else
    {
        Vpre->next = del->next;
    }
    delete del;
    cout << "Vertex deleted successfully" << endl;
}
int outDegree(char val) // sirf apne vertex ki edge list count karta hai
{
    Vertex *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            int count = 0;
            Edge *e = temp->Edgelist;
            while (e != NULL)
            {
                count++;
                e = e->next;
            }
            return count;
        }
        temp = temp->next;
    }
    cout << "Not found" << endl;
    return -1;
}
int InDegree(char val)
{
    int count = 0;
    Vertex *temp = Head;
    while (temp != NULL)
    {

        Edge *e = temp->Edgelist;
        while (e != NULL)
        {
            if (e->V->data == val)
            {
                count++;
            }
            e = e->next;
        }

        temp = temp->next;
    }
    return count;
}
int totalDegree(char val)
{
    return InDegree(val) + outDegree(val);
}
// ---------- STACK for DFS ----------
struct SNode
{
    Vertex *v;
    SNode *next;
};

SNode *top = NULL;

void push(Vertex *v)
{
    SNode *n = new SNode;
    n->v = v;
    n->next = top;
    top = n;
}

Vertex *pop()
{
    if (top == NULL)
        return NULL;

    SNode *t = top;
    Vertex *v = t->v;
    top = top->next;
    delete t;
    return v;
}

bool isStackEmpty()
{
    return top == NULL;
}
//-----------DFS-----------
void DFS(char start)
{
    bool visited[26] = {false};

    Vertex *startNode = NULL;

    // search start node
    Vertex *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == start)
        {
            startNode = temp;
            break;
        }
        temp = temp->next;
    }

    if (startNode == NULL)
    {
        cout << "Start vertex not found\n";
        return;
    }

    push(startNode); // stack me dalo
    visited[startNode->data - 'A'] = true;

    while (!isStackEmpty())
    {
        Vertex *curr = pop();

        cout << curr->data << " ";

        Edge *e = curr->Edgelist;

        while (e != NULL)
        {
            int index = e->V->data - 'A';

            if (!visited[index])
            {
                push(e->V);
                visited[index] = true;
            }

            e = e->next;
        }
    }

    cout << endl;
}
// ---------- QUEUE for BFS ----------
struct QNode
{
    Vertex *v;
    QNode *next;
};

QNode *front = NULL;
QNode *rear = NULL;

void enqueue(Vertex *v)
{
    QNode *n = new QNode;
    n->v = v;
    n->next = NULL;

    if (front == NULL)
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

Vertex *dequeue()
{
    if (front == NULL)
        return NULL;

    QNode *t = front;
    Vertex *v = t->v;

    front = front->next;
    if (front == NULL)
        rear = NULL;

    delete t;
    return v;
}

bool isEmpty()
{
    return front == NULL;
}

//---------BFS---------
void BFS(char start)
{
    bool visited[26] = {false};

    Vertex *startNode = NULL;
    Vertex *temp = Head;

    while (temp != NULL)
    {
        if (temp->data == start)
        {
            startNode = temp;
            break;
        }
        temp = temp->next;
    }

    if (startNode == NULL)
    {
        cout << "Start vertex not found\n";
        return;
    }

    enqueue(startNode);
    visited[start - 'A'] = true;

    while (!isEmpty())
    {
        Vertex *curr = dequeue();

        cout << curr->data << " ";

        Edge *e = curr->Edgelist;

        while (e != NULL)
        {
            if (!visited[e->V->data - 'A'])
            {
                enqueue(e->V);
                visited[e->V->data - 'A'] = true;
            }
            e = e->next;
        }
    }

    cout << endl;
}
// -----------display------------
void display()
{
    Vertex *tempV = Head;

    while (tempV != NULL)
    {
        cout << tempV->data << " -> ";
        Edge *temp = tempV->Edgelist;

        while (temp != NULL)
        {
            cout << temp->V->data << " ";
            temp = temp->next;
        }

        cout << endl;
        tempV = tempV->next;
    }
}

void RecursiveDFS(Vertex *v, bool visited[])
{
    if (v == NULL)
        return;

    visited[v->data - 'A'] = true;

    Edge *e = v->Edgelist;

    while (e != NULL)
    {
        Vertex *neighbor = e->V;

        if (!visited[neighbor->data - 'A'])
        {
            RecursiveDFS(neighbor, visited);
        }

        e = e->next;
    }
}

bool isStornglyConnected()
{
    Vertex *temp = Head;
    while (temp != NULL)
    {
        bool visited[26] = {false};
        RecursiveDFS(temp, visited);

        Vertex *check = Head;
        while (check != NULL)
        {
            if (!visited[check->data - 'A'])
            {
                return false;
            }
            check = check->next;
        }
        temp=temp->next;
    }
    return true;
}
bool isAdjacent(char srcVal, char destVal)
{
    //  source vertex find karo
    Vertex *src = Head;

    while (src != NULL)
    {
        if (src->data == srcVal)
            break;

        src = src->next;
    }

    // Agar source hi nahi mila
    if (src == NULL)
        return false;

    //  edge list check karo
    Edge *e = src->Edgelist;

    while (e != NULL)
    {
        // Step 3: destination match check
        if (e->V->data == destVal)
        {
            return true; // adjacent hain
        }

        e = e->next;
    }

    //  agar na mile
    return false;
}

void findNeighbors(char val)
{
    Vertex *temp = Head;

    // Step 1: vertex find karo
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            break;
        }

        temp = temp->next;
    }

    // Agar vertex nahi mila
    if (temp == NULL)
    {
        cout << "Vertex not found";
        return;
    }

    //  edge list traverse karo
    Edge *e = temp->Edgelist;

    cout << "Neighbors of " << val << " are: ";

    while (e != NULL)
    {
        cout << e->V->data << " ";

        e = e->next;
    }
}

Vertex *searchVertex(char val)
{
    Vertex *temp = Head;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return temp; // vertex mil gayi
        }

        temp = temp->next;
    }

    return NULL; // vertex nahi mili
}
void printpath(Vertex *dest)
{
    if (dest == NULL)
    {
        return;
    }
    printpath(dest->parent);
    cout << dest->data << "->";
}
void BFSPathfind(char sour, char dest)
{
    bool visited[26] = {false};

    // start or dest vertex find karo
    Vertex *s = NULL;
    Vertex *d = NULL;

    Vertex *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == sour)
        {
            s = temp;
        }
        if (temp->data == dest)
        {
            d = temp;
        }
        temp = temp->next;
    }
    if (s == NULL || d == NULL)
    {
        cout << "Vertex not found!" << endl;
        return;
    }

    // BFS traverse karo
    enqueue(s);
    visited[s->data - 'A'] = true;
    s->parent = NULL; // start node parent NULL
    while (!isEmpty())
    {
        Vertex *cur = dequeue();

        // destination mil gaya
        if (cur == d)
        {
            printpath(cur);
            cout << endl;
            return;
        }
        // neighbors explore karo
        Edge *e = cur->Edgelist;
        while (e != NULL)
        {
            if (!visited[e->V->data - 'A'])
            {

                enqueue(e->V);
                visited[e->V->data - 'A'] = true;
                e->V->parent = cur;
            }
            e = e->next;
        }
    }
    cout << "Path exist nahi karta!" << endl;
}
int main()
{
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    addEdge('A', 'B');
    addEdge('A', 'C');
    addEdge('B', 'D');
    addEdge('C', 'D');
    display();

    cout << isAdjacent('A', 'D');
    cout<<endl;
    BFSPathfind('A', 'C');
    cout<<endl<<isStornglyConnected();
    // cout << "OutDegree of A:" << outDegree('A');
    // cout << "\nInDegree of :" << InDegree('A');
    // cout << "\ntotal degree " << totalDegree('A');

    // RemoveVertex('B');
    // display();

    // BFS('A');
    // DFS('A');

    return 0;
}