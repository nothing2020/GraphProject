#include<stdio.h>
#define INF 32767

int tu[50][3];

int numberOfEdges(char name[]);
int numberOfVertices(char name[]);
int freemanNetworkCentrality(char name[]);
int closenessCentrality(char name[]);
double maxc(int A[50][50], int n);
int ri(char name[]);
