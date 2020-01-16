#include"Header.h"
#include<iostream>
#include<fstream>
using namespace std;
void pathFinding(int start_Index, bool& goalFound, list<int>* arr[], bool visited[], stack<list<int>::diterator>& pointStack,list<int>::diterator& current, int goal)
{
		pointStack.top(current);
		if (*current == goal)//base case
		{
			goalFound = true;

			cout << "THE GOAL WAS FOUND: " << goalFound << endl;
			list<int> result;

			while (!pointStack.isEmpty())//copying contents of stack into list
			{
				pointStack.pop(current);
				result.insertAtStart(*current);
			}
			//printing the path that led to the goal
			cout << "Path to the goal : " << endl;
			cout << start_Index << " ";
			result.printList();
			return;
		}
		else
		{
			if (goalFound == false && !(pointStack.isEmpty()))
			{
				current = (*(arr[*current])).begin();//iterator for connected list accessible from currentPoint 
				if (visited[*current] == true)
				{
					while ((current != ((*(arr[0]))).end()))//this loop iterates until an iterator is found whose node hasn't been visited yet
					{
						++current;//moves on to the next possible position the current point we're at is connected to
						if (current != ((*(arr[0]))).end())
						{
							if (visited[*current] == false)
							{
								pointStack.push(current);
								visited[*current] = true;
								break;
							}
						}
						else
						{
							pointStack.pop(current);

							while ((current == ((*(arr[0])).end())) && (!(pointStack.isEmpty())))//back traces to find a point which has other connections that haven't been visited yet
							{
								pointStack.pop(current);
								++current;
							}
						}

					}
				}
				else
				{
					pointStack.push(current);
					visited[*current] = true;
				}
				

			}
			if (goalFound == false || !pointStack.isEmpty())
			{
				pathFinding(start_Index, goalFound, arr, visited, pointStack, current, goal);

			}




		}

	}

void main()
{
	fstream fin;  //populating data from txt file into an array of linked lists
	fin.open("inputfile.txt");
	int start_Index;
	fin >> start_Index;
	int end_Index;
	fin.ignore(100, '\n');
	fin >> end_Index;
	fin.ignore(100, '\n');
	int size;
	fin >> size;
	fin.ignore(100, '\n');
	int num;
	char a;

	list<int>** arr = new list<int>*[size];

	for (int k = 0; k < size; k++)
	{
		fin >> num;
		arr[k] = new list<int>;
		(*(arr[k])).insertAtEnd(num);
		fin >> a;// skips comma;
		while (a != '/')
		{
			fin >> num;
			(*(arr[k])).insertAtEnd(num);
			fin >> a;// skips comma;
		}
		fin.ignore(100, '\n');


	}
	fin.close();

	bool* visited = new bool[size];
	for (int x = 0; x < size; x++)//to check whether a given connection has been visited when following a path

	{
		visited[x] = false;
	}

	stack<list<int>::diterator> pointStack;
	//initialisations
	bool goalFound = false;
	int currentPoint = start_Index;
	int goal = end_Index;
	list<int>::diterator current = (*(arr[currentPoint])).begin();
	visited[0] = true;
	visited[*current] = true;
	pointStack.push(current);
	pathFinding(start_Index, goalFound, arr, visited, pointStack, current, goal);


	system("pause");

}