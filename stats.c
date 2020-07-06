#include<stdio.h>
#include<stdlib.h>
#include "stats.h	

int numberOfEdges(char name[])//numbers of edges
{

    int n = ri(name);
    int a[50][50] = {0};
    int i, j, sum = 0;
    for (i = 0; i < n; i++) {
        a[tu[i][0]][tu[i][1]] = tu[i][2];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0)
                sum++;
        }
    }
    return sum;
}

int numberOfVertices(char name[])//numbers of vertices 
{
    int n = ri(name);
    int i, j;
    int a[50] = {0}, sum = 0;
    for (i = 0; i < n; i++)  {
        if (a[tu[i][0]] == 0)
            a[tu[i][0]]++;
        if (a[tu[i][1]] == 0)
            a[tu[i][1]]++;
    }
    for (i = 0; i < 50; i++) {
        if (a[i] != 0)
            sum++;
    }
    return sum;
}

int freemanNetworkCentrality(char name[]) //return Freeman's Network Centrality 
{
    int n = ri(name);
    int i, j;
    int a, b;
    int sum[50] = {0};
    int max = 0, sum1 = 0;
    int vis[50] = {0};
    for (i = 0; i < n; i = i + 2){
        sum[tu[i][0]]++;
        if (sum[tu[i][0]] > max)
            max = sum[tu[i][0]];
        sum[tu[i][1]]++;
        if (sum[tu[i][1]] > max)
            max = sum[tu[i][1]];

    }
    for (i = 0; i < n; i = i + 2) {
        if (vis[tu[i][0]] == 0) {
            sum1 = sum1 + max - sum[tu[i][0]];
            vis[tu[i][0]] = 1;
        }
        if (vis[tu[i][1]] == 0) {
            sum1 = sum1 + max - sum[tu[i][1]];
            vis[tu[i][1]] = 1;
        }
    }
    int k = numberOfVertices(name);
    return (int)sum1 / ((k - 1) * (k - 2));
}

int closenessCentrality(char name[])//return Closeness Centrality
{
    int m = ri(name);
    int a[50][50] = {0};
    int i, j, k;
    for (i = 0; i < m; i++) {
        a[tu[i][0]][tu[i][1]] = tu[i][2];
    }
    int n = numberOfVertices(name);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 0 && i != j)
                a[i][j] = INF;
        }
    }
    int A[50][50], path[50][50];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = a[i][j];
            if (a[i][j] != 0)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    return maxc(A, n);
}

double maxc(int A[50][50], int n)//Reference from https://www.cl.cam.ac.uk/teaching/1213/L109/stna-lecture3.pdf 
{
    int i, j, sum, min = 10000;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            if (i != j)
                sum = sum + A[i][j];
        }
        if (sum < min)
            min = sum;
    }
    return (double)(n - 1) / min;
}

int ri(char name[])//Reference from https://www.cl.cam.ac.uk/teaching/1213/L109/stna-lecture3.pdf
{
    int i, j, k; char m = 0;
    FILE *fp;
    if ((fp = fopen(name, "r")) == NULL)
        printf("File open error!\n");
    else {
        for (i = 0; m != EOF; i++) {
            k = 0;
            m = fgetc(fp);
            while (1) {
                if (m == '\n' || m == EOF)
                    break;
                else {     
                    tu[i][k] = 0;
                    while (m != ' '&&m != '\n'&&m != EOF) {
                        tu[i][k] = tu[i][k] * 10 + m - '0';
                        m = fgetc(fp);
                    }
                    if (m != '\n'&&m != EOF)
                        m = fgetc(fp);
                }
                k++;
            }
        }
        fclose(fp);
    }
    return i;
}
