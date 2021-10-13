/* DFS, BFS */
#include <stdio.h>

/* bfs for shortest path between two points */
/* also dijkstra and a light astar */

#define		MAX						6
#define 	ERROR					0
#define		OK						1
#define 	CARDINAL_DIRECTIONS		4
#define		VISITED 				1
#define		NOT_VISITED				0
#define 	ADJACENT 				1
#define		NOT_ADJACENT 			0

int visited[MAX][MAX] = { NOT_VISITED };
int stepmat[MAX][MAX] = { 0 };

//queue variables
int queuex[MAX * MAX + 1];
int queuey[MAX * MAX + 1];
int rear = -1;
int front = 0;
int queueItemCount = 0;

void insert(int datax, int datay) {
   rear++;
   queuex[rear] = datax;
   queuey[rear] = datay;
   queueItemCount++;
}

int peekData(int* tempx, int* tempy) {
	*tempx = queuex[front];
	*tempy = queuey[front];
}

void removeData() {
   queueItemCount--;
   front++;
}

int isQueueEmpty() {
   return queueItemCount == 0;
}

void print_mat(int m[][MAX]) {
	printf("Matrix:\n");

	for(int i = 0; i < MAX; i++) {
		printf("{ ");
		for (int j = 0; j < MAX; j++) {
			printf("%d  ", m[i][j]);
		}
		printf("}\n");
	}
}

void print_helper(int m[][MAX], int initx, int inity, int targetx, int targety) {
	printf("Matrix:\n");

	for(int i = 0; i < MAX; i++) {
		printf("{ ");
		for (int j = 0; j < MAX; j++) {
			if ((initx == i) && (inity == j))
				printf("S  ");
			else if ((targetx == i) && (targety == j))
				printf("X  ");
			else
				printf("%d  ", m[i][j]);
		}
		printf("}\n");
	}
}

int check(int x, int y) {
	if (x < 0)
		return ERROR;

	if (x > 5)
		return ERROR;

	if (y < 0)
		return ERROR;

	if (y > 5)
		return ERROR;

	if (visited[x][y] == VISITED)
		return ERROR;

	return OK;
}

int adjacent(int m[][MAX], int i, int j, int tempx, int tempy) {
	int c = (OK == check(tempx + i, tempy + j));

	if (m[tempx + i][tempy + j] == 0)
		return NOT_ADJACENT;

	if (c) {
		//printf("%d,%d adjacent to %d, %d\n", tempx + i, tempy + j, tempx, tempy);
		return ADJACENT;
	}

	return NOT_ADJACENT;
}

int getAdjUnvisitedVertex(int m[][MAX], int tempx, int tempy, int* newx, int* newy) {
   int i,j;

   for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
         if(adjacent(m, i, j, tempx, tempy) == ADJACENT && (visited[tempx + i][tempy + j] == NOT_VISITED)) {
         	*newx = tempx + i;
         	*newy = tempy + j;
            return OK;
         }
      }
   }

   return ERROR;
}

void dfs(int m[][MAX], int initx, int inity, int targetx, int targety, int steps) {
	int Ex = initx;
	int Ey = inity + 1;

	int Wx = initx;
	int Wy = inity - 1;

	int Sx = initx + 1;
	int Sy = inity;

	int Nx = initx - 1;
	int Ny = inity;

	int nextX[] = {Ex, Wx, Sx, Nx};
	int nextY[] = {Ey, Wy, Sy, Ny};

#ifdef DEBUG
	printf("dFS %d,%d\n", initx, inity);
#endif

	if ((initx == targetx) && (inity == targety))
	{
		printf("Target found in %d steps.\n", steps);
	}

	for (int i = 0; i < CARDINAL_DIRECTIONS; i++) {
		if (OK == check(nextX[i], nextY[i])) {
			visited[nextX[i]][nextY[i]] = VISITED;
			dfs(m, nextX[i], nextY[i], targetx, targety, steps + 1);
		}
	}
}

void bfs(int m[][MAX], int initx, int inity, int targetx, int targety, int steps) {

	int tempx, tempy;
	int newx, newy;
	int i, j;

	if ((initx == targetx) && (inity == targety))
	{
		printf("Target found in %d steps.\n", steps);
	}

	/* mark first node as visited */
	visited[initx][inity] = VISITED;

	insert(initx, inity);
	//printf("Pushed (%d,%d).\n\n", initx, inity);
	stepmat[initx][inity] = 1;

	while(!isQueueEmpty()) {
		//get the unvisited vertex of vertex which is at front of the queue
		peekData(&tempx, &tempy);
		removeData();
		//printf("Popped (%d,%d), steps = %d.\n", tempx, tempy, stepmat[tempx][tempy]);

		//no adjacent vertex found
		while(ERROR != getAdjUnvisitedVertex(m, tempx, tempy, &newx, &newy)) {
			//printf("Pushed (%d,%d) with steps = %d.\n", newx, newy, stepmat[tempx][tempy] + 1);

        	visited[newx][newy] = VISITED;
        	insert(newx, newy);
        	stepmat[newx][newy] = stepmat[newx][newy] + stepmat[tempx][tempy] + 1;

			if ((newx == targetx) && (newy == targety))
			{
				printf("Target found in %d steps.\n", stepmat[newx][newy]);
			}

      	}

		//printf("\n");
	}

	//queue is empty, search is complete, reset the visited flag
   for(i = 0; i < MAX; i++)
   		for (j = 0; j < MAX; j++)
      		visited[i][j] = NOT_VISITED;
}

void main() {

	int a[MAX][MAX] = { { 1, 0, 0, 0, 0, 0 },
						{ 1, 1, 1, 1, 1, 0 },
						{ 0, 1, 0, 0, 1, 0 },
						{ 0, 1, 0, 1, 1, 0 },
						{ 0, 1, 1, 1, 1, 1 },
						{ 0, 1, 1, 0, 0, 1 } };

	int initx = 0;
	int inity = 0;
	int targetx = 5;
	int targety = 5;

	print_helper(a, initx, inity, targetx, targety);

	//dfs(a, initx, inity, targetx, targety, 0);
	bfs(a, initx, inity, targetx, targety, 0);
}