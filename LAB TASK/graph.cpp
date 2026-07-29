#include<iostream>
using namespace std;
#define SIZE 5
struct Vertex{
	int id;
	char name;
	
};
bool visited[SIZE] = {false};
//Matrix sirf 0 aur 1 store karta hai — names nahi!
//// Vertex array ke saath — naam dikhenge ?

//Marix stores connection eg 0 or 1
//Vertex array  INFORMATION store karti hai (naam, id)
Vertex array[SIZE];       // Global vertex array
int matrix[SIZE][SIZE]; // Global matrix

void initMatrix(){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			matrix[i][j]=0;	
		}
	}
}
//VERTEX
void addVertexInfo(int id, char name){
		array[id].id=id;
		array[id].name=name;
	}
//UNDIRECTED
void addEdge(int source,int destination){
	matrix[source][destination]=1;
	matrix[destination][source]=1;
}
//DIRECTED
void ADDEdgee(int source,int destination){
	matrix[source][destination]=1;
}
//UNDIRECTED
void removeEdge(int source,int destination){
	matrix[source][destination]=0;
	matrix[destination][source]=0;
}
//DIRECTED
void remEdge(int source,int destination){
	matrix[source][destination]=0;
}
//UNDIRECTED
int countDegree(int id){
	int deg=0;
	for(int i=0;i<SIZE;i++){
	if(matrix[id][i]==1);
	deg++;	
	}
	cout << array[id].name << " degree = " << deg << endl;
}
//DIRECTED
int countInDegree(int id){
	int inDeg=0;
	for(int i=0;i<SIZE;i++){
		if(matrix[i][id]==1){
			inDeg++;
		}
	}
	cout << array[id].name << " Indegree = " << inDeg << endl;
}
//Directed
void outdegreeCount(int id){
    int outdegree = 0;
    for(int i = 0; i < SIZE; i++){
        if(matrix[id][i] == 1){  // Row fix! (bahar jaana)
            outdegree++;
        }
    }
    cout << array[id].name << " outdegree = " << outdegree << endl;
}
//FINd PATH
void findPath(int src, int dest) {

    visited[src] = true;       

    if (src == dest) {         
        cout << array[dest].name;
        return;               
    }

    for (int i = 0; i < SIZE; i++) {          //  Har neighbor dekho
        if (matrix[src][i] == 1              // Connected hai?
            && !visited[i]) {                // Pehle nahi gaye?
            
            cout << array[src].name << "->";  // Print karo
            findPath(i, dest); 
			//cout<< endl;              
        }
    }
}
//Display
void display() {
    cout << "\t";
    for (int i = 0; i < SIZE; i++)		//header print kryga(only rows k name)
        cout << array[i].name <<"\t";
		cout<<endl;
		cout<<"      ------------------------------------";
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << array[i].name << "\t";
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}	
int main(){
	initMatrix();
	addVertexInfo(0,'A');
	addVertexInfo(1,'B');
	addVertexInfo(2,'C');
	addVertexInfo(3,'D');
	addVertexInfo(4,'E');
	addVertexInfo(5,'F');
	addVertexInfo(6,'G');
	
	addEdge(0,1);
	addEdge(0,3);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(1,4);
	addEdge(2,1);
	addEdge(2,3);
	addEdge(2,5);

	
	//findPath(0,3);
	
	display();
}
