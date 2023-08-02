#include <stdio.h>
#include <stdlib.h>

int mov[5][2] = {{0,0},{-1,0},{1,0},{0,1},{0,-1}};

typedef struct shark{
	int v;
	int d;
	int s;
}shark;

struct shark state[100][100];
//struct shark deck[100][100];
int main(){
	int r,c,m,got=0;
	int vel=0, dir=0, size=0;
	int i,j,ni,nj,k,p,t;
	struct shark** deck;
	//struct shark** state;
	scanf("%d %d %d", &r, &c, &m);
	deck = (struct shark**)malloc(sizeof(struct shark*)*r);
	for(i=0;i<r;i++){
		deck[i] = (struct shark*)malloc(sizeof(struct shark)*c);
		for(j=0;j<c;j++){
			deck[i][j].s=0;
		}
	} //alloc mem & init
	
	for (k= 0; k <m; k++){
		scanf("%d %d %d %d %d", &i, &j, &vel, &dir,&size);
		deck[i-1][j-1].v = vel;
		deck[i-1][j-1].d = dir;
		deck[i-1][j-1].s = size;		 
	}

	for(k=0;k<c;k++){
		//copy;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				state[i][j] = deck[i][j];
				deck[i][j].s=0;
			}
		}

		//catch shark
		for(p=0;p<r;p++){
			if(state[p][k].s>0){
				got+=state[p][k].s;
				state[p][k].s=0;
				break;
			}
		} 
	
		//move sharks
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(state[i][j].s>0){
					ni= i + mov[state[i][j].d][0] * state[i][j].v;
					if(ni<0){
						t =(-1*ni);
						if((t/(r-1))%2==0){
							ni=t%(r-1);
						} else{
							ni=r-1-t%(r-1);
						}
						
					} else if(ni>=r){
						t = (ni-(r-1));
						if((t/(r-1))%2==0){
							ni=r-1-(t%(r-1));
						} else{
							ni=t%(r-1);
						}
					}
					nj= j + mov[state[i][j].d][1] * state[i][j].v;
					if(nj<0){
						t =(-1*nj);
						if((t/(c-1))%2==0){
							nj=t%(c-1);
						} else{
							nj=c-1-t%(c-1);
						}
						
						if(((-1*nj)/(c-1))%2==0){
							nj=t;
						} else{
							nj=c-t;
						}
					} else if(nj>=c){
						t = (nj-(c-1));
						if((t/(c-1))%2==0){
							nj=c-1-(t%(c-1));
						} else{
							nj=t%(c-1);
						}
					}
					if(deck[ni][nj].s <state[i][j].s){
						deck[ni][nj].s = state[i][j].s;
						deck[ni][nj].d = state[i][j].d;
						deck[ni][nj].v = state[i][j].v;		
					}
					state[i][j].s = 0;		
				} //end if :existanceChk
			}//end for:j
		}//end for:i
		//copy to state
	} //end for:k
	
	printf("%d\n",got);
	for(i=0;i<r;i++){
		free(deck[i]);
		//free(state[i]);
	}
	free(deck);
	//free(state);
	return 0;
}
