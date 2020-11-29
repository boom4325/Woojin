#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int sero = 0;
int count = 0;
int visited[MAX_VERTICES][MAX_VERTICES];



void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertx(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType* g)
{
	printf("   ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", i);
	printf("\n");
	for (int i = 0; i < g->n; i++) {
		printf("%d  ", i);
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

int dfs_mat(GraphType* g, int v)
{
	int w;
	count += 1;
	visited[sero][v] = TRUE;

	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[sero][w]) {
			dfs_mat(g, w);
		}
	}
	return count;
}
void delete_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}


void search_bridge(GraphType* g) {

	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[i][j] == 1) {
				delete_edge(g, i, j);		
				int count_dfs = dfs_mat(g, 1);
				sero++;
				count = 0;
				if (count_dfs != g->n)
					printf("%d-%d는 브리지입니다.\n", i, j);
				insert_edge(g, i, j);
			}
		}
	}

}

void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 10; i++) {
		insert_vertx(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 5, 7);
	insert_edge(g, 5, 6);
	insert_edge(g, 6, 7);
	insert_edge(g, 7, 8);
	insert_edge(g, 7, 9);
	
	print_adj_mat(g);
	search_bridge(g);

	

	free(g);
}