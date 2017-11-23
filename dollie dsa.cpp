//dollie juneja 16csu112
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ROW 5
#define COL 5
struct Point{
	int x;
	int y;
};
struct passenger
{
	char name[50];
	int s;
	int e;
	struct Point pt_src;
	struct Point pt_end;
	int dist;
};
struct queue{
	int x;
};
int board[ROW][COL]  = {{1, 1, 1, 1, 1},
						{1 ,1, 1, 1, 1},
						{1, 1, 1, 1, 1},
						{1, 1, 1, 1, 1},
						{1, 1, 1, 1, 1}};
int display[ROW][COL]=	{{1  ,  2  ,  3  ,  4  ,  5},
						{6  ,  7  ,  8  ,  9  ,  10},
						{11  ,  12  ,  13  ,  14  ,  15},
						{ 16  ,  17  ,  18  ,  19  ,  20},
						{21  ,  22  ,  23  ,  24  ,  25}};					
int distance(struct passenger src,struct passenger dest){
	int x=0,y=0;
	x=abs(src.pt_src.x-dest.pt_src.x);
	y=abs(src.pt_src.y-dest.pt_src.y);
	return x+y;
	
}

int distance_end(struct passenger src,struct passenger dest){
	int x=0,y=0;
	x=abs(src.pt_end.x-dest.pt_end.x);
	y=abs(src.pt_end.y-dest.pt_end.y);
	return x+y;
	
}

void locations(int board[5][5])
{
	printf("\t\t\t\t      Data Structure and Algorithm\n\n\n");
    printf("\t\t\t\t  TRAVEL ROUTE PLANNER FOR SHARED CABS \n\n\n");
    printf("Choose a locations numbered from 1 to 25 as below\n");
    
	printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
    printf("\t\t\t  %c   |  %c   |  %c   |  %c   |  %c \n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5] );
    printf("\t\t\t  %c   |  %c   |  %c   |  %c   |  %c \n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5] );
    printf("\t\t\t  %c   |  %c   |  %c   |  %c   |  %c \n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5] );
    printf("\t\t\t  %c   |  %c   |  %c   |  %c   |  %c \n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5] );
    printf("\t\t\t  %c   |  %c   |  %c   |  %c   |  %c \n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5] );
    
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
    
    printf("\t\t\t  01  |  02  |  03  |  04  |  05  \n");
    printf("\t\t\t  06  |  07  |  08  |  09  |  10  \n");
    printf("\t\t\t  11  |  12  |  13  |  14  |  15  \n");
    printf("\t\t\t  16  |  17  |  18  |  19  |  20  \n");
    printf("\t\t\t  21  |  22  |  23  |  24  |  25  \n"); 
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
 

}
void move(struct passenger car_loc,struct passenger dest){
	int x1,y1,x2,y2,i;
	x1=car_loc.pt_src.x;
	y1=car_loc.pt_src.y;
	
	x2=dest.pt_src.x;
	y2=dest.pt_src.y;
	while(1){
		if(x1!=x2){
			if(x1>x2){
				x1--;
				printf("%d ",display[x1][y1]);
			}
			else if(x1<x2){
				x1++;
				printf("%d ",display[x1][y1]);
			}
		}
		else if(y1!=y2){
			if(y1>y2){
				y1--;
				printf("%d ",display[x1][y1]);
			}
			else if(y1<y2){
				y1++;
				printf("%d ",display[x1][y1]);
			}
		}
			if(x1==x2 && y1==y2){

				printf("Picked  Up ");//%s ",dest.name);
				break;
			}
	}
}

void move_drop(struct passenger car_loc,struct passenger dest){
	int x1,y1,x2,y2,i;
	x1=car_loc.pt_end.x;
	y1=car_loc.pt_end.y;
	
	x2=dest.pt_end.x;
	y2=dest.pt_end.y;
	while(1){
		if(x1!=x2){
			if(x1>x2){
				x1--;
				printf("%d ",display[x1][y1]);
			}
			else if(x1<x2){
				x1++;
				printf("%d ",display[x1][y1]);
			}
		}
		else if(y1!=y2){
			if(y1>y2){
				y1--;
				printf("%d ",display[x1][y1]);
			}
			else if(y1<y2){
				y1++;
				printf("%d ",display[x1][y1]);
			}
		}
			if(x1==x2 && y1==y2){

				printf("Dropped  ",dest.name);
				break;
			}
	}
}

int main() 
{
	struct passenger a[5];
	struct passenger car_loc,min,car_loc_end;
	struct Point pt_min;
	
	
	FILE *fptr;
	int i,j,k,l, board[5][5]={' '};
	locations(board);
	fptr=fopen("file.txt","wb");
	for (i=0;i<5;++i) 
	{
		fflush(stdin);
		printf("\nEnter name of %d passenger: ",i+1);

		
		printf("Enter starting location: ");
		scanf("%d",&a[i].s);

		a[i].s--;
		int j,k;
		a[i].pt_src.y=a[i].s%5;
		a[i].pt_src.x=a[i].s/5;
		
		board[a[i].pt_src.x][a[i].pt_src.y]='#';
		
		
		printf("Enter ending location: ");

		scanf("%d",&a[i].e);
		a[i].e--;
		a[i].pt_end.y=a[i].e%5;
		a[i].pt_end.x=a[i].e/5;
		board[a[i].pt_end.x][a[i].pt_end.y]='X';
	}
	locations(board);
	
	pt_min.x=0;
	pt_min.y=0;
	car_loc=a[0];
	
	
	printf("\n ");
	
	
	for(i=0;i<4;i++){
		car_loc=a[i];
		for(j=i;j<5;j++){
			a[j].dist=distance(car_loc,a[j]);	
		}
		
		for(k=i;k<4;k++){
			for(l=k+1;l<5;l++){
				if(a[k].dist>a[l].dist){
					min=a[l];
					a[l]=a[k];
					a[k]=min;
				}
			}
		}
		move(a[i],a[i+1]);
		printf("\n ");
	
	}
	
	car_loc_end.e=car_loc.s;
	for(i=0;i<4;i++){
	
		for(j=i;j<5;j++){
			a[j].dist=distance_end(car_loc,a[j]);	
		}
		
		for(k=i;k<4;k++){
			for(l=k+1;l<5;l++){
				if(a[k].dist>a[l].dist){
					min=a[l];
					a[l]=a[k];
					a[k]=min;
				}
			}
		}
		move_drop(a[i],a[i+1]);
		printf("\n ");
		car_loc=a[i+1];
	}
	
	
	
	
	
	fwrite(a,sizeof(a),1,fptr);
	fclose(fptr);
	
	fclose(fptr);
}

