//http://wenku.baidu.com/view/f3020044336c1eb91a375d7d.html
#include<stdio.h>
#include <unistd.h>

int chessboard[15][15]={{0}};
int right_point,left_point,up_point,down_point,right_down_point,right_up_point,left_down_point,left_up_point;
int company_wight[15][15]={{0}};
int pepole_weight[15][15]={{0}};
int maxij[10]={0};
int globle=0;

void printf_chessboard()
{
	int i,j;
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			printf("%d  ",chessboard[i][j]);
		}
		printf("\n");
	}
}

int whowin(int fivechess_line[15][15],int i,int j,int k)
{
	//int i,j;
	int right,left,up,down,right_down,right_up,left_down,left_up;
	
	right=check_right(fivechess_line,i,j,k);
	left=check_left(fivechess_line,i,j,k);
	up=check_up(fivechess_line,i,j,k);
	down=check_down(fivechess_line,i,j,k);
	right_down=check_rightdown(fivechess_line,i,j,k);
	left_down=check_leftdown(fivechess_line,i,j,k);
	right_up=check_rightup(fivechess_line,i,j,k);
	left_up=check_leftup(fivechess_line,i,j,k);
	
	if(right+left>=4)
		{
			return 1;
		}
	else if(up+down>=4)
		{
			return 1;
		}
	else if(right_up+left_down>=4)
		{
			return 1;
		}
	else if(left_up+right_down>=4)
		{
			return 1;
		}
		
	return 0;
		
}

int check_leftup(int leftup_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j-x>=0 && i-x>=0)
	{
		if (leftup_check[i-x][j-x]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				left_up_point=leftup_check[i-x][j-x];
				break;
			}
		x++;
	}
	
	return counter;
}

int check_rightup(int rightup_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j+x<15 && i-x>=0)
	{
		if (rightup_check[i-x][j+x]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				right_up_point=rightup_check[i-x][j+x];
				break;
			}
		x++;
	}
	
	return counter;
}

int check_leftdown(int leftdown_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j-x>=0 && i+x<15)
	{
		if (leftdown_check[i+x][j-x]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				left_down_point=leftdown_check[i+x][j-x];
				break;
			}
		x++;
	}
	
	return counter;
}

int check_rightdown(int rightdown_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j+x<15 && i+x<15)
	{
		if (rightdown_check[i+x][j+x]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				right_down_point=rightdown_check[i+x][j+x];
				break;
			}
		x++;
	}
	
	return counter;
}


int check_right(int right_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j+x<15)
	{
		if (right_check[i][j+x]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				right_point=right_check[i][j+x];
				break;
			}
		x++;
	}
	
	return counter;
}

int check_left(int left_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j-x>=0)
	{
		if (left_check[i][j-x]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				left_point=left_check[i][j-x];
				break;
			}
		x++;
	}
	
	return counter;
}

int check_up(int up_check[15][15],int i,int j,int k)
{
	int counter=0;
	int y;
	
	y=1;
	while(y<5 && i-y>=0)
	{
		if (up_check[i-y][j]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				up_point=up_check[i-y][j];//..............
				break;
			}
		y++;
	}
	
	return counter;

}



int check_down(int down_check[15][15],int i,int j,int k)
{
	int counter=0;
	int y;
	
	y=1;
	while(y<5 && i+y<15)
	{
		if (down_check[i+y][j]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				down_point=down_check[i+y][j];//..............
				break;
			}
		y++;
	}
	return counter;	
}
/*
int mysqrt(int k)
{
	int i;
	
	for(i=1;i<k;i++)
	{
		if(i*i>k-100 && i*i<k+100)
			{
				return i;
			}
	}
	
	return 1;
}
*/
int calculate(int one_direction,int second_diection,int one_direction_score,int two_direction_score)
{
	if(one_direction+second_diection>=4)
		return 200;//成5
	else if(one_direction+second_diection==3)
		{
			if(one_direction_score==0 && two_direction_score==0)
				return 90;//活四
			else if((one_direction_score==0 && two_direction_score!=0) || (two_direction_score==0 && one_direction_score!=0) )
				return 15;//死四
		}
	else if(one_direction+second_diection==2)
		{
			if(one_direction_score==0 && two_direction_score==0)
				return 40;//活三				
			else if((one_direction_score==0 && two_direction_score!=0) || (two_direction_score==0 && one_direction_score!=0) )
				return 13;//死三
		}
	else if(one_direction+second_diection==1)
		{
			if(one_direction_score==0 && two_direction_score==0)
				return 8;//活二
			else if((one_direction_score==0 && two_direction_score!=0) || (two_direction_score==0 && one_direction_score!=0))
				return 2;//死二
		}
		
	return 0;
}

int weight_chess(int find_chess[15][15],int i,int j,int whoplay)
{
	int right,left,up,down,right_down,right_up,left_down,left_up;
	int weight_all=0;
	
	
	right=check_right(find_chess,i,j,whoplay);
	left=check_left(find_chess,i,j,whoplay);
	up=check_up(find_chess,i,j,whoplay);
	down=check_down(find_chess,i,j,whoplay);
	right_down=check_rightdown(find_chess,i,j,whoplay);
	left_down=check_leftdown(find_chess,i,j,whoplay);
	right_up=check_rightup(find_chess,i,j,whoplay);
	left_up=check_leftup(find_chess,i,j,whoplay);
	
	weight_all=weight_all+calculate(right,left,right_point,left_point);//此子横着的棋型得分
	weight_all=weight_all+calculate(up,down,up_point,down_point);//此子竖线的棋型得分
	weight_all=weight_all+calculate(right_down,left_up,right_down_point,left_up_point);//此子右上方棋型得分
	weight_all=weight_all+calculate(right_up,left_down,right_up_point,left_down_point);//此子右下方棋型得分
	
	return weight_all;
}

void who_play(int analysis_chess[15][15],int whoplay)
{
	int i,j;	
	int max;
	int maxi,maxj;
	
	if(whoplay==2)
		{
			max=company_wight[0][0];//........
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
					{
						if(analysis_chess[i][j] != 1 && analysis_chess[i][j] != 2)
							{
								company_wight[i][j]=company_wight[i][j]+weight_chess(analysis_chess,i,j,whoplay);
								if(company_wight[i][j]>max)
									{
										max=company_wight[i][j];
										maxi=i;
										maxj=j;
									}
							}
					}
			}
		}
	else
		{
			max=pepole_weight[0][0];
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
					{
						if(analysis_chess[i][j] != 1 && analysis_chess[i][j] != 2)
							{
								pepole_weight[i][j]=pepole_weight[i][j]+weight_chess(analysis_chess,i,j,whoplay);
								if(pepole_weight[i][j]>max)
									{
										max=pepole_weight[i][j];
										maxi=i;
										maxj=j;
									}
							}
					}
			}
		}

	//printf("debug information %d,%d han shu li de weizhi\n",maxi,maxj);	
	analysis_chess[maxi][maxj]=whoplay;
	maxij[globle++]=maxi;
	maxij[globle++]=maxj;
	
}

int main(void)
{
	int i,j,k,who;
	int total_count;
	int maxcompall,maxcompi,maxcompj,maxppall,maxppi,maxppj;

	chessboard[8][7]=1;
	chessboard[8][6]=2;
	printf_chessboard();
	
	
	printf("who play the first chess ,1=pp,2=cpmputer");
	scanf("%d",&who);
	printf("who= %d\n",who);
	if(who==1)
			total_count=3;
	else
			total_count=2;
	
	printf("debug information %d,%d\n",total_count,total_count%2);
	while(1)
	{
		if(total_count%2==1)
		{
			printf("pepole play:\n");
			//......
			//printf("put the chess\n");	
			do
			{
				printf("pepole input\n");
				scanf("%d %d",&i,&j);
				
				//printf("debug information i=%d,j=%d ,chessboard[i][j]=%d\n",i,j,chessboard[i][j]);
				/*
				if((fp=fopen("/opt/test/log2.txt","r"))!= NULL)
						{
							fscanf(fp, "%d", &i); 
							fscanf(fp, "%d", &j);
						}
				fclose(fp);*/
			}while(chessboard[i][j]==1 || chessboard[i][j]==2);
				
			chessboard[i][j]=1;
			
			printf_chessboard();
			
			if (whowin(chessboard,i,j,1)==1)
			{
				printf("pepole win\n");
				return 0;
			}
		}
		else
		{
			printf("computer play\n");
			
			globle=0;
			who_play(chessboard,2,1);//.......,...1.........
			who_play(chessboard,1,1);//...........1........
			who_play(chessboard,2,2);//.......................
			who_play(chessboard,1,2);//.......................
			who_play(chessboard,2,3);//.......................

			maxcompall=0;//...........
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					if(company_wight[i][j]>maxcompall)
						{
							maxcompall=company_wight[i][j];
							maxcompi=i;
							maxcompj=j;
						}
				}
			}
								
			maxppall=0;//.............
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					if(pepole_weight[i][j]>maxppall)
						{
							maxppall=pepole_weight[i][j];
							maxppi=i;
							maxppj=j;
						}
				}
			}
			
		//	printf("debug information comp %d,%d\n",maxcompi,maxcompj);	
		//	printf("debug information pp   %d,%d\n",maxppi,maxppj);	
			//printf("debug information comp %d,%d\n",maxij[0],maxij[1]);	
			//printf("debug information pp   %d,%d\n",maxij[2],maxij[3]);
			//printf("debug information pp   %d,%d\n",maxij[4],maxij[5]);
					
			if(maxcompall>=100000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxij[6]][maxij[7]]=0;
					chessboard[maxij[8]][maxij[9]]=0;
					chessboard[maxcompi][maxcompj]=2;
					
					/*fp=fopen("/opt/test/log.txt","w+");
					if(fp!=NULL)
						{
							fprintf(fp,"%d %d\n",maxcompi,maxcompj);
						}
						fclose(fp);
					
					for(i=0;i<10;i++)
					{
						printf("debug information calculate the place %d\n",maxij[i]);
					}
					printf("debug information calculate the finally place %d,%d \n",maxcompi,maxcompj);
					*/
					printf_chessboard();
			//printf("debug information computer win");	
				if (whowin(chessboard,maxcompi,maxcompj,2)==1)
					{
						printf("computer win");
				
						return 0;
					}
				}
			else if(maxppall>=100000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxij[6]][maxij[7]]=0;
					chessboard[maxij[8]][maxij[9]]=0;
					chessboard[maxppi][maxppj]=2;
					
					/*fp=fopen("/opt/test/log.txt","w+");
					if(fp!=NULL)
						{
							fprintf(fp,"%d %d\n",maxppi,maxppj);
						}
						fclose(fp);
					
					for(i=0;i<10;i++)
					{
						printf("debug information calculate the place %d\n",maxij[i]);
					}
					printf("debug information calculate the finally place %d,%d \n",maxppi,maxppj);
					*/
					printf_chessboard();
			//printf("debug information computer win");	
			if (whowin(chessboard,maxppi,maxppj,2)==1)
			{
				printf("computer win");
			
				return 0;
			}
				}
			else if(maxcompall>=20000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxij[6]][maxij[7]]=0;
					chessboard[maxij[8]][maxij[9]]=0;
					chessboard[maxcompi][maxcompj]=2;
					
					/*fp=fopen("/opt/test/log.txt","w+");
					if(fp!=NULL)
						{
							fprintf(fp,"%d %d\n",maxcompi,maxcompj);
						}
						fclose(fp);
					
					for(i=0;i<10;i++)
					{
						printf("debug information calculate the place %d\n",maxij[i]);
					}
					printf("debug information calculate the finally place %d,%d \n",maxcompi,maxcompj);
					*/
					printf_chessboard();
			//printf("debug information computer win");	
			if (whowin(chessboard,maxcompi,maxcompj,2)==1)
			{
				printf("computer win");
				
				return 0;
			}
				}
			else if(maxppall>=20000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxij[6]][maxij[7]]=0;
					chessboard[maxij[8]][maxij[9]]=0;
					chessboard[maxppi][maxppj]=2;
					
					/*fp=fopen("/opt/test/log.txt","w+");
					if(fp!=NULL)
						{
							fprintf(fp,"%d %d\n",maxppi,maxppj);
						}
						fclose(fp);
					
					for(i=0;i<10;i++)
					{
						printf("debug information calculate the place %d\n",maxij[i]);
					}
					printf("debug information calculate the finally place %d,%d \n",maxppi,maxppj);
					*/
					printf_chessboard();
			//printf("debug information computer win");	
			if (whowin(chessboard,maxppi,maxppj,2)==1)
			{
				printf("computer win");
				
				return 0;
			}
				}
			else
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxij[6]][maxij[7]]=0;
					chessboard[maxij[8]][maxij[9]]=0;
					chessboard[maxcompi][maxcompj]=2;
					
					/*fp=fopen("/opt/test/log.txt","w+");
					if(fp!=NULL)
						{
							fprintf(fp,"%d %d\n",maxcompi,maxcompj);
						}
						fclose(fp);
					
					for(i=0;i<10;i++)
					{
						printf("debug information calculate the place %d\n",maxij[i]);
					}
					printf("debug information calculate the finally place %d,%d \n",maxcompi,maxcompj);
					*/
					printf_chessboard();
					//printf("debug information computer win");	
					if (whowin(chessboard,maxcompi,maxcompj,2)==1)
						{
							printf("computer win\n");
							
							return 0;
						}
				}
			
			
				
			for(i=0;i<10;i++)
			{
				maxij[i]=0;
			}
				
			//globle=0;
			
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					pepole_weight[i][j]=0;
					company_wight[i][j]=0;
				}
			}	
			
			
		}
					
		total_count++;
		
		if(total_count==224)
		{
			printf("no place to paly ,game over , draw");
			return 0;
		}
		//sleep(3);
	}

}

