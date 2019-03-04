#include<stdio.h>
#include <limits.h>
#include <iostream>

// 정점의 수를 지정한다.
#define V 5
// INF를 무한대라고 지정하고, INT_MAX를 이용한다.
#define INF 10000



void printSolution(int dist[][V])
{
	printf("Following matrix shows the shortest distances, between every pair of vertices \n\n");
	printf("\t   to→ ");

	for (int i = 0; i < V; i++)
		printf("[%d]    ", i);

	printf("\n      ↓from \n");

	for (int i = 0; i < V; i++)
	{
		printf("\t[%d]", i);
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

void floydWarshall(int graph[][V])
{
	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}


int main()
{
	int graph[V][V] =
	{
		{ 0, 8, 4, 5, 5 },
		{ 7, 0, 6, 2, 2 },
		{ 3, 2, 0, 3, 7 },
		{ 7, 3, 7, 0, 1 },
		{ 3, 7, 4, 2, 0 },
	};

	floydWarshall(graph);
	system("pause");
	return 0;
}
