#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <string.h>
using namespace std;

std::string append(std::string input);
void splitter(std::string input1, std::string input2, int N, int arr[],std::string fname);
int stoi(const char *s)

{
    int i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}
class Node
{
	public:
	int adjacent;
	Node *next;
	Node(int value)
	{
		adjacent=value;
		next=NULL;
	}
};

class adj_list
{
	public:
	int numNodes;
	Node *head;
	Node *current;
	adj_list()
	{
		numNodes=0;
		head=NULL;
		current=head;
	}
};

void addEdge(int u, int v, int x, adj_list A[])
{
	for (int i=0;i<x;i++)
	{
		if (i==u)
		{
			Node *newNode = new Node(v);
			Node *newNode2 = new Node(u);
			if(A[u].numNodes==0)
			{
				A[u].head = newNode;
				A[u].current = A[u].head;
			}
			else
			{
				A[u].current->next=newNode;
				A[u].current = A[u].current->next;
			}

			if(A[v].numNodes==0)
			{
				A[v].head = newNode2;
				A[v].current = A[v].head;
			}
			else
			{
				A[v].current->next=newNode2;
				A[v].current = A[v].current->next;
			}

			A[u].numNodes=A[u].numNodes + 1;
			A[v].numNodes=A[v].numNodes + 1;
		}
	}
}

void printList(adj_list A[],int x)
{
	cout << "Degree \t Vertex \tEdges" << endl;
	for (int i=0;i<x;i++)
	{
		cout<< "\t" << A[i].numNodes <<  "\t\t" << i << "\t\t";
		Node *tmp = A[i].head;
		for (int j=0; j<A[i].numNodes;j++)
		{
			cout << tmp->adjacent << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}
void histogram(int x, adj_list A[])
{
	int max=0;
	for (int i=0;i<x;i++)
	{
		if(A[i].numNodes>max)
		{
			max = A[i].numNodes;
		}
	}
	cout << max << endl;
	for (int i=0;i<max;i++)
	{
		int count = 0;
		for (int j=0;i<x;j++)
		{
			if(i==A[j].numNodes)
			{
				count++;
			}
		}
		cout << i << ": ";
		for (int k=0;k<count;k++)
		{
			cout << "*";
		}
		cout <<endl;
	}
}

int main()
{
		char input[20];
		cin.getline(input,sizeof(input));
		string input1=input;
		std::transform(input1.begin(), input1.end(), input1.begin(), ::tolower);
		std::string name = append(input1);
		ifstream inFile(name.c_str(), ios::in);
			if (! inFile)
			   {
			      cerr << "unable to open  file: "
				   << name << endl;
			   }
			if (inFile)
			{
				cout << "start processing  data of: " << name << endl;
				ifstream myfile;
				std::string line ="";
				myfile.open(name.c_str());
				getline(myfile, line);
				const char *line1 = line.c_str();
				int N=stoi(line1);
				int y = N;
				adj_list *A = new adj_list[N];   // Pointer to int, initialize to nothing.
				cout << N << endl;
				getline(myfile, line);
				line1 = line.c_str();
				int m = stoi(line1);
				cout << m << endl;
				char str[] ="";
				char *start;
				char *end;
				int x = m;
				for (int i = 0; i< x ; i++)
				{
					getline(myfile, line);
					line1 = line.c_str();
					strcpy(str,line1);
					start = strtok(str," ");
					end = strtok(NULL," ");
					int u = stoi(start);
					int v = stoi(end);
					addEdge(u,v,x,A);
				}
			printList(A,y);


			int max=0;
			for (int i=0;i<y;i++)
			{
				if(A[i].numNodes>max)
				{
					max = A[i].numNodes;
				}
			}
			//cout << max << endl;
			int dist[max];
			int count =0;
			cout << "\nHISTOGRAM\n" << endl;
			for (int j =1 ; j<max+1; j++)
			{
				count=0;
				cout << j << ": ";
				for (int i=0;i<y;i++)
				{
					if(A[i].numNodes==j)
					{
						cout << "*";
						count ++;
					}
				}
			cout << "\t" << count << " Occurences"<<endl;
			}
		}
}
std::string append(std::string input)
{
	int x = input.find(".txt");
	string app = ".txt";
	if (x>=0)
	{
		return input;
	}
	else
	{
		input = input.append(app);
		return input;
	}
}
