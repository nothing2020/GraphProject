#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "stats.h"
int main (int argc,char **argv)
{
    int edges, vertices;
    double freeman;
	
	 if(argv[1][1] == 'g' || argv[1][2] == 'g'){
        edges = numberOfEdges(argv[2]);
		vertices = numberOfVertices(argv[2]);
		freeman = freemanNetworkCentrality(argv[2]);
		
		
		if(argv[3][2] == 'p'|| argv[3][3] =='h'){
			int u = 0;
			int v = 0;
			int x = 0;
			while(argv[6][x] != '\0'){
				u = u*10 + argv[6][x] - '0';
				x++;
			}
			x = 0;
			while(argv[8][x] != '\0'){
				v = v*10 + argv[8][x] - '0';
				x++;
			}
			int* path = shortestPath(u, v, argv[4], argv[2]);
			int* apath = (int*)malloc(MAXSIZE*sizeof(int));
			
			int d = 0,k;
			k = v;
			apath[d] = v;
			while(path[k] != -1){
				d++;
				apath[d] = path[k];
				k = path[k];
			}
			printf("%d",apath[d]);
			int i;
			for(i = d-1; i >= 0; i--){
				printf(" ->%d",apath[i]);
			}
		} 
		else{
			if(argv[4][0] == 'e'){
			    printf("edges = %d\n", edges);
			}
			else if(argv[4][0] == 'v'){
			    printf("vertices = %d\n", vertices);
			}
			else{
			    printf("freeman = %f\n", freeman);
			}
		}       
	}
	else{
        printf("        ___www___            \n");
        printf("         / O.O \            \n");
        printf("         \__A__/            \n");
        printf("          _| |_              \n");
        printf("        /|     |\            \n");
        printf("        || O O ||            \n");
        printf("        ||__v__||            \n");
    }
	    }
	 return 0;
}















if (strcmp(argc[1], "-j") == 0) {
printf("   蒜头君的真实面貌:\n        );
printf("        ___www___            \n");
printf("         / O.O \            \n");
printf("         \__A__/            \n");
printf("          _| |_              \n");
printf("        /|     |\            \n");
printf("        || O O ||            \n");
printf("        ||__v__||            \n");
}
