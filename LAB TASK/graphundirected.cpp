#include <iostream>
using namespace std;

// undirected graph
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
// ------------------Add Edge Undirected graph----------------------
void ADDEDGE(char sour, char dest)
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

    // A → B
    Edge *e1 = new Edge;
    e1->V = d;
    e1->next = s->Edgelist;
    s->Edgelist = e1;

    // B → A
    Edge *e2 = new Edge;
    e2->V = s;
    e2->next = d->Edgelist;
    d->Edgelist = e2;
}
// //-------------RemoveEdge Undirected graph---------------
void REMOVEEDGE(char sour, char dest)
{
    // ===== 1) Remove A -> B =====
    Vertex *s = Head;

    while (s != NULL)
    {
        if (s->data == sour)
            break;
        s = s->next;
    }

    if (s == NULL)
    {
        cout << "not found" << endl;
        return;
    }

    Edge *cur = s->Edgelist;
    Edge *pre = NULL;

    while (cur != NULL)
    {
        if (cur->V->data == dest)
        {
            if (pre == NULL)
                s->Edgelist = cur->next;
            else
                pre->next = cur->next;

            delete cur;
            break;
        }
        pre = cur;
        cur = cur->next;
    }

    // ===== 2) Remove B -> A (reverse edge) =====
    Vertex *d = Head;

    while (d != NULL)
    {
        if (d->data == dest)
            break;
        d = d->next;
    }

    if (d == NULL)
    {
        cout << "Edge removed from source but reverse vertex not found" << endl;
        return;
    }

    cur = d->Edgelist;
    pre = NULL;

    while (cur != NULL)
    {
        if (cur->V->data == sour)
        {
            if (pre == NULL)
                d->Edgelist = cur->next;
            else
                pre->next = cur->next;

            delete cur;
            break;
        }
        pre = cur;
        cur = cur->next;
    }

    cout << "Edge removed successfully (undirected)" << endl;
}
//----------degree-----------
int getDegree(Vertex *v)
{
    int count = 0;

    Edge *temp = v->Edgelist;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
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
bool isCyclic(Vertex *start)//Agar DFS/BFS ke dauran koi visited neighbor mil jaye jo parent nahi hai, to cycle exist karti hai.
{
    bool visited[26] = {false};

    // stack ke liye parent track
    Vertex *parent[26] = {NULL};

    push(start);
    visited[start->data - 'A'] = true;

    while (!isStackEmpty())
    {
        Vertex *curr = pop();

        Edge *e = curr->Edgelist;

        while (e != NULL)
        {
            Vertex *neighbor = e->V;
            int index = neighbor->data - 'A';

            if (!visited[index])
            {
                push(neighbor);
                visited[index] = true;
                parent[index] = curr;
            }

            else if (parent[curr->data - 'A'] != neighbor)
            {
                return true; // cycle
            }

            e = e->next;
        }
    }

    return false;
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

bool isGraphConnected()
{
    if (Head == NULL)
        return true;

    bool visited[26] = {false};

    // Step 1: start from first vertex
    RecursiveDFS(Head, visited);

    // Step 2: check all vertices
    Vertex *temp = Head;

    while (temp != NULL)
    {
        if (!visited[temp->data - 'A']) //
        {
            return false; // koi vertex visit nahi hua
        }

        temp = temp->next;
    }

    return true; // sab visited
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
