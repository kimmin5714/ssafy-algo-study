#include <stdio.h>
#include <stdlib.h>

int region[101][101];

int findnum(int n, int h){
	int k=0,m=0,group=0,tmp=0;
	int x, y;
	int** arr= (int**)malloc(sizeof(int*)*(n)); //alloc mem for arrCopy
	for(k=0;k<n;k++){
		arr[k] = (int*)malloc(sizeof(int)*(n));
	}
	
	//union find
	for(k=0;k<n;k++){
		for(m=0;m<n;m++){
			if(region[k][m]<=h) { //flood
				arr[k][m]=-1;
			} else{ //not flood
				
				if(k>0 && (arr[k-1][m]>-1)){
					x = arr[k-1][m];
					while(arr[k-1][m]!=x){
						x = arr[x/n][x%n]; //get parent idx
					}	
				}else{
					x=-1;
				}
				if(m>0 && (arr[k][m-1]>-1)){
					y = arr[k][m-1];
					while(arr[k][m-1]!=y){
						y = arr[y/n][y%n]; //get parent idx
					}	
				} else{
					y=-1;
				}
				
				if(x>-1 && y> -1){
					if(x<y){
						arr[k][m] = x;
						arr[y/n][y%n] = x;			
					} else{
						arr[k][m] = y;
						arr[x/n][x%n] = y;	
					}
				} else if(x>-1){
					arr[k][m] = x;
				}else if(y>-1){
					arr[k][m] = y;
				} else{
					arr[k][m]=k*n+m;
				}
				/*
				
	
				if(k>0 && (arr[k-1][m]>-1) && m>0 && (arr[k][m-1]>-1)){
					
					while(arr[k-1][m]!=x){
						x=g[x];
					}
					if(arr[k-1][m]>arr[k][m-1]){
						arr[k][m] = arr[k][m-1];
						tmp = arr[k-1][m];
						arr[tmp/n][tmp%n] = arr[k][m-1];		
					} else{
						arr[k][m] = arr[k-1][m];
						tmp = arr[k][m-1];
						arr[tmp/n][tmp%n] = arr[k-1][m];	
					}
				} else if(k>0 && (arr[k-1][m]>-1) ){
					arr[k][m] = arr[k-1][m];			
				} else if(m>0 && (arr[k][m-1]>-1)){
					arr[k][m] = arr[k][m-1];
				} else{
					arr[k][m]=k*n+m;
				}
				*/
			}//end else
		}//end for:m
	}//end for:k
	
	//count num of the safezoneGroup 
	group=0;
	for(k=0;k<n;k++){
		for(m=0;m<n;m++){
			if(arr[k][m]==(k*n+m)){
				group++;
			}
		}
	}
	//free mem
	for(k=0;k<n;k++){
		free(arr[k]);
	}
	free(arr);
	return group;
}//func findnum end

int main() {
	int n,i=0,j=0;
	int height=0,groupN=0,groupMax=0;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){ //init
		for(j=0;j<n;j++){
			scanf("%d", &region[i][j]);
			if(height<region[i][j]){
				height = region[i][j];
			}
		}
	}
	
    for(i=0;i<height;i++){//flood height++
    	groupN = findnum(n, i);
		if(groupMax<groupN){
			groupMax = groupN;
		}
	}
	printf("%d",groupMax);
	return 0;
}
