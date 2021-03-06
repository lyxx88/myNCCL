#include<stdio.h>

int chessboard[15][15]={{0}};
int one_direction[5]={3},two_direction[5]={3};
int weight_onechess;
int ppi,ppj;
int pointonei;
int pointonej;
int pointtwoi;
int pointtwoj;
int step;


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
	int one_count,two_count;
	
	one_count=check_one(fivechess_line,i,j,0,1,k);
	two_count =check_two(fivechess_line,i,j,0,-1,k);	
	if(one_count+two_count>=4)
		{
			return 1;
		}
		
	one_count=check_one(fivechess_line,i,j,-1,0,k);
	two_count =check_two(fivechess_line,i,j,1,0,k);
	if(one_count+two_count>=4)
		{
			return 1;
		}
		
	one_count=check_one(fivechess_line,i,j,1,1,k);
	two_count =check_two(fivechess_line,i,j,-1,-1,k);
	if(one_count+two_count>=4)
		{
			return 1;
		}
		
	one_count=check_one(fivechess_line,i,j,-1,1,k);
	two_count =check_two(fivechess_line,i,j,1,-1,k);
	if(one_count+two_count>=4)
		{
			return 1;
		}
	
	return 0;
		
}


int check_one(int all_check[15][15],int i,int j,int l,int r,int k) //5 7 0 1 1
{
	int counter=0;
	int coun=0;
	int prl,prr;
	int onei,twoj;
	int begin;
	
	prl=l;
	prr=r;
	onei=i;
	twoj=j;
	
	
//	printf("debug information check_one i+l=%d j+r=%d\n ",onei+prl,twoj+prr);	//5 8 
	while(coun<5 && twoj+prr<15 && onei+prl<15 && twoj+prr>=0 && onei+prl>=0)
	{
//		printf("debug information check_one 1 i+l=%d j+r=%d\n ",onei+prl,twoj+prr);
		if (all_check[onei+prl][twoj+prr]==k)
			{
				counter=counter+1;
			}
		else
			{
				//记住第一个为空点的位置
				pointonei=onei+prl;
				pointonej=twoj+prr;
				break;
			}
		coun++;
		onei=onei+prl;
		twoj=twoj+prr;
	}
	
//	printf("debug information counter=%d\n",counter);
	
	coun=0;
	prl=l;
	prr=r;
	onei=i;
	twoj=j;
	begin=0;
	//right_point
	while(coun<5 && twoj+prr<15 && onei+prl<15 && twoj+prr>=0 && onei+prl>=0 && (all_check[onei+prl][twoj+prr]==0 || all_check[onei+prl][twoj+prr]==k))
	{
//		printf("debug information check_one 2 i+l=%d j+r=%d\n ",onei+prl,twoj+prr);
		if (all_check[onei+prl][twoj+prr]==0)
			{
				one_direction[begin]=0;
				begin++;
			}
		else if(all_check[onei+prl][twoj+prr]==k && coun>counter)
			{
				one_direction[begin]=k;
				begin++;
			}
			
		coun++;
		onei=onei+prl;
		twoj=twoj+prr;
	}
	/*
	for(coun=0;coun<5;coun++)
	{
		printf("debug information one_direction[%d]=%d\n",coun,one_direction[coun]);
	}
	*/
	return counter;
}

int check_two(int all_check[15][15],int i,int j,int l,int r,int k)
{
	int counter=0;
	int coun=0;
	int prl,prr;
	int onei,twoj;
	int begin;
	
	prl=l;
	prr=r;
	onei=i;
	twoj=j;

	while(coun<5 && twoj+prr<15 && onei+prl<15 && twoj+prr>=0 && onei+prl>=0)
	{
		if (all_check[onei+prl][twoj+prr]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				pointtwoi=onei+prl;
				pointtwoj=twoj+prr;
				break;
			}
		coun++;
		onei=onei+prl;
		twoj=twoj+prr;
	}
	
	//printf("debug information counter=%d\n",counter);
	coun=0;
	prl=l;
	prr=r;
	onei=i;
	twoj=j;
	begin=0;
	//right_point
	while(coun<5 && twoj+prr<15 && onei+prl<15 && twoj+prr>=0 && onei+prl>=0 && (all_check[onei+prl][twoj+prr]==0 || all_check[onei+prl][twoj+prr]==k))
	{
		if (all_check[onei+prl][twoj+prr]==0)
			{
				two_direction[begin]=0;
				begin++;
			}
		else if(all_check[onei+prl][twoj+prr]==k && coun>counter)
			{
				two_direction[begin]=k;
				begin++;
			}
			
		coun++;
		onei=onei+prl;
		twoj=twoj+prr;
	}
	/*
	for(coun=0;coun<5;coun++)
	{
		printf("debug information two_direction[%d]=%d\n",coun,two_direction[coun]);
	}
	*/
	return counter;
}

int defend(int defend_borad[15][15],int i,int j)
{
	int one_count,two_count;
	int m;
	int flag=1;
	//FILE *fp;
	
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	//right left
	one_count=check_one(defend_borad,i,j,0,1,1);
	two_count =check_two(defend_borad,i,j,0,-1,1);
	flag=calculate(one_count,two_count,1,i,j);
	
	//printf("debug information defend one_count=%d,two_count=%d, flag=%d\n",one_count,two_count,flag);
	/*fp=fopen("/opt/nccl/log.txt","a+");
	if(fp!=NULL)
		{
			fprintf(fp,"debug information defend one_count=%d,two_count=%d, flag=%d\n",one_count,two_count,flag);
		}
	fclose(fp);
	*/
	if(flag==2)
		{
			return 2;
		}
	
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=check_one(defend_borad,i,j,-1,0,1);
	two_count =check_two(defend_borad,i,j,1,0,1);
	flag=calculate(one_count,two_count,1,i,j);
	
	if(flag==2)
		{
			return 2;
		}
		
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=check_one(defend_borad,i,j,1,1,1);
	two_count =check_two(defend_borad,i,j,-1,-1,1);
	flag=calculate(one_count,two_count,1,i,j);
	
	if(flag==2)
		{
			return 2;
		}
	
	for(m=0;m<3;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=check_one(defend_borad,i,j,-1,1,1);
	two_count =check_two(defend_borad,i,j,1,-1,1);
	flag=calculate(one_count,two_count,1,i,j);
	
	if(flag==2)
		{
			return 2;
		}	
		
		return flag;
}

int calculate(int one_direction_count,int second_diection_count,int k,int i,int j)
{
	int flag=1;
	
	switch(one_direction_count+second_diection_count)
	{
		case 3:
			if(one_direction[0]==0 && two_direction[0]==0)
				{
					chessboard[pointonei][pointonej]=2;
					//fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
					//step++;
					//fflush(stdout);
					
					flag= 2;
					return flag;
					break;
				}
			else if (one_direction[0]==0 || two_direction[0]==0)
				{
					if(one_direction[0]==0)
						{
							chessboard[pointonei][pointonej]=2;
							//fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
							//step++;
							//fflush(stdout);
							flag= 2;
							return flag;
							break;
						}
				
				 if(two_direction[0]==0)
					{
						chessboard[pointtwoi][pointtwoj]=2;
						//fprintf(stdout, "step %d : %d %d\n", step++, pointtwoi, pointtwoj);
						//step++;
						//fflush(stdout);
						flag= 2;
						return flag;
						break;
					}
				}
				break;
		case 2:
		//	printf("debug information one_direction_count+second_diection_count=%d\n ",one_direction_count+second_diection_count);
			if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k)
				{//_***_*
					chessboard[pointonei][pointonej]=2;
					fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
					step++;
					fflush(stdout);
					flag= 2;
					return flag;
					break;
				}
					
				
			if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k)
			{//*_***_
				chessboard[pointtwoi][pointtwoj]=2;
				//fprintf(stdout, "step %d : %d %d\n", step++, pointtwoi, pointtwoj);
				//step++;
				//fflush(stdout);
				flag= 2;
				return flag;
				break;
			}
				
			
		 if(one_direction[0]==0 && two_direction[0]==0)
			{//_***_
				chessboard[pointonei][pointonej]=2;
				fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
				step++;
				fflush(stdout);
				flag= 2;
				return flag;
				break;				
			}
			/*
			if(one_direction[0]==0 || two_direction[0]==0)
			{//
				chessboard[pointonei][pointonej]=2;
				flag= 2;
				return flag;
				break;				
			}
			*/
			break;
			
		case 1:
			if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k && one_direction[2]==k)
				{//_**_**
					chessboard[pointonei][pointonej]=2;
					/*
					fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
					step++;
					fflush(stdout);
					*/
					flag= 2;
					break;
				}
			
			
			if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k && two_direction[2]==k)
				{//**_**_
					chessboard[pointtwoi][pointtwoj]=2;
					//fprintf(stdout, "step %d : %d %d\n", step++, pointtwoi, pointtwoj);
					//step++;
					//fflush(stdout);
					flag= 2;
					break;
				}
			
			
			if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k && one_direction[2]==0)
				{//_**_*_
					chessboard[pointonei][pointonej]=2;
					//fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
					//step++;
					//fflush(stdout);
					flag= 2;
					break;
				}
			
			
			if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k && two_direction[2]==0)
				{//_*_**_
					chessboard[pointtwoi][pointtwoj]=2;
					//fprintf(stdout, "step %d : %d %d\n", step++, pointtwoi, pointtwoj);
					//step++;
					//fflush(stdout);
					flag= 2;
					break;
				}
				
			case 0:
				if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k && one_direction[2]==k && one_direction[3]==k )
				{//_*_**_
					chessboard[pointonei][pointonej]=2;
					//fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
					//step++;
					//fflush(stdout);
					flag= 2;
					break;
				}
			
			
			if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k && two_direction[2]==k && two_direction[3]==k)
				{//_*_**_
					chessboard[pointtwoi][pointtwoj]=2;
					//fprintf(stdout, "step %d : %d %d\n", step++, pointtwoi, pointtwoj);
					//step++;
					//fflush(stdout);
					flag= 2;
					break;
				}
				
				if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k && one_direction[2]==k && one_direction[3]==0 )
				{//_*_**_
					chessboard[pointonei][pointonej]=2;
					/*
					fprintf(stdout, "step %d : %d %d\n", step++, pointonei, pointonej);
					step++;
					fflush(stdout);
					*/
					flag= 2;
					break;
				}
			
			
			if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k && two_direction[2]==k && two_direction[3]==0)
				{//_*_**_
					chessboard[pointtwoi][pointtwoj]=2;
					/*
					fprintf(stdout, "step %d : %d %d\n", step++, pointtwoi, pointtwoj);
					step++;
					fflush(stdout);
					*/
					flag= 2;
					break;
				}
			
		deflaut:
 
      break;
		
	}
	
	return flag;

}


int weight_calculate(int one_direction_count,int second_diection_count,int k,int i,int j)
	{
		int score=0;
		
		switch(one_direction_count+second_diection_count)
			{
		case 3:
			if(one_direction[0]==0 && two_direction[0]==0)
				{//_****_				
					score=score+500;				
				}
		  if(one_direction[0]==0 && two_direction[0]!=0)
				{//$****_
					score=score+100;
					//break;
				}
				
			if(one_direction[0]!=0 && two_direction[0]==0)
				{//_****$
					score=score+100;
					//break;
				}
//				break;
		case 2:
			//printf("debug information one_direction_count+second_diection_count=%d\n ",one_direction_count+second_diection_count);
			if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k)
				{//_***_*
					score=score+400;
				}			
			else if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k)
				{//*_***_
					score=score+400;
				}
				
			
		 else if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]!=k && one_direction[1]!=0)
			{//$_***_
				score=score+250;
			}
			
		else if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]!=k && two_direction[1]!=0)
			{//_***_$
				score=score+250;
			}
			
		else if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==0 && two_direction[1]==0)
			{//__***__
				score=score+300;
			}
		
		else if(one_direction[0]!=0 && two_direction[0]==0 && one_direction[0]!=k && two_direction[1]==0)
			//$***_
				score=score+30;
		else if(one_direction[0]==0 && two_direction[0]!=0 && one_direction[1]==0 && two_direction[0]!=k)
			//$***_
				score=score+30;
		else 
				score=score+10;	
		break;
			
		case 1:
			if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k && one_direction[2]==k)
				{//_**_**
					score=score+350;
				}
			
			
			else if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k && two_direction[2]==k)
				{//**_**_
					score=score+350;
				}
			
			
		 else if(one_direction[0]==0 && two_direction[0]==0 && one_direction[1]==k && one_direction[2]==0)
				{//_**_*_
					score=score+200;
				}
			
			
		 else if(one_direction[0]==0 && two_direction[0]==0 && two_direction[1]==k && two_direction[2]==0)
				{//_*_**_
					score=score+200;
				}
		 else if(one_direction[0]==0 && two_direction[0]==0)
				{//_**_
					score=score+50;
				}
		else
				score=score+5;
	
		deflaut:
 			score=score+1;
      break;
		
	}	
		return score;
	}


int weight_chess(int find_chess[15][15],int i,int j,int whoplay)
{
	int one_count,two_count;
	int weight_onechess=0;
	int m;

	weight_onechess=0;
	one_count=0;
	two_count=0;
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	/*for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}*/
	one_count=0;
	two_count=0;
	one_count=check_one(find_chess,i,j,0,1,whoplay);
	two_count =check_two(find_chess,i,j,0,-1,whoplay);
	weight_onechess=weight_calculate(one_count,two_count,whoplay,i,j);	
	
	//up down
	one_count=0;
	two_count=0;
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=check_one(find_chess,i,j,1,0,whoplay);
	two_count =check_two(find_chess,i,j,-1,0,whoplay);
	weight_onechess=weight_onechess+weight_calculate(one_count,two_count,whoplay,i,j);
	//
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=0;
	two_count=0;
	one_count=check_one(find_chess,i,j,-1,1,whoplay);
	two_count =check_two(find_chess,i,j,1,-1,whoplay);
	weight_onechess=weight_onechess+weight_calculate(one_count,two_count,whoplay,i,j);
	
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=0;
	two_count=0;
	one_count=check_one(find_chess,i,j,-1,-1,whoplay);
	two_count =check_two(find_chess,i,j,1,1,whoplay);
	weight_onechess=weight_onechess+weight_calculate(one_count,two_count,whoplay,i,j);
	
	return weight_onechess;
}

void attack(int attack_chess[15][15])
{
	int i,j;
	int m,n;	
	int ppwight,computerwight;
	int max;
	int maxi,maxj;
	int flag=1;
	int company_wight[15][15]={{0}};

	for(i=0;i<15;i++)
		{
			for(j=0;j<15;j++)
				{
					company_wight[i][j]=0;
				}
		}
		
	for(i=0;i<15;i++)
		{
			
			for(j=0;j<15;j++)
				{
					if(attack_chess[i][j]==0)
						{
							attack_chess[i][j]=2;//在此点下子
		
							ppwight=0;
							computerwight=0;
							m=0;
							n=0;
							//计算所有棋子的得分
							for(m=0;m<15;m++)
							{
								for(n=0;n<15;n++)
									{
								//判断这个子的权重
										if(attack_chess[m][n] == 2 && attack_chess[m-1][n]!=2 && attack_chess[m][n-1] != 2 && attack_chess[m-1][n-1] != 2 && attack_chess[m+1][n-1] != 2)
											{
												computerwight=computerwight+weight_chess(attack_chess,m,n,2);
											}
										else if(attack_chess[m][n] == 1 && attack_chess[m-1][n]!=1 && attack_chess[m][n-1] != 1 && attack_chess[m-1][n-1] != 1 && attack_chess[m+1][n-1] != 1)
											{
												ppwight=ppwight+weight_chess(attack_chess,m,n,1);												
											}
													
									}
								}
							attack_chess[i][j]=0;
							company_wight[i][j]=computerwight-ppwight;						
						}					
				}			
		}
				
	maxi=0;
	maxj=0;												
	max=company_wight[0][0];
	for(i=0;i<15;i++)
		{
			for(j=0;j<15;j++)
				{
					if(company_wight[i][j]>max)
						{
							max=company_wight[i][j];
							maxi=i;
							maxj=j;
							//printf("debug information maxi=%d,maxj=%d, max=%d\n",i,j,max);
						}
				}
		}
										
	attack_chess[maxi][maxj]=2;
	/*
	fprintf(stdout, "step %d : %d %d\n", step++, maxi, maxj);
	step++;
	fflush(stdout);	
	*/
	if (whowin(chessboard,maxi,maxj,2)==1)
		{
			printf("compter win\n");
			exit(0) ;
		}
}

void who_play(int analysis_chess[15][15])
{
	int i,j;
	int m,n;	
	int ppwight,computerwight;
	int max;
	int maxi,maxj;
	int flag=1;
	int one_count,two_count;
	
	for(i=0;i<15;i++)
		{
			for(j=0;j<15;j++)
				{
					if(analysis_chess[i][j]==0)
						{
							analysis_chess[i][j]=2;//在此点下子
							
							one_count=0;
							two_count=0;	
							one_count=check_one(analysis_chess,i,j,0,1,2);
							two_count =check_two(analysis_chess,i,j,0,-1,2);

							if(one_count+two_count==4)
								{
									/*
									fprintf(stdout, "step %d : %d %d\n", step++, i, j);
									step++;
									fflush(stdout);	
									*/
									printf_chessboard();
									printf("computer win\n");
									exit (0);
								}
							
							one_count=0;
							two_count=0;		
							one_count=check_one(analysis_chess,i,j,1,0,2);
							two_count =check_two(analysis_chess,i,j,-1,0,2);

							if(one_count+two_count==4)
								{
									/*
									fprintf(stdout, "step %d : %d %d\n", step++, i, j);
									step++;
									fflush(stdout);
									*/
									printf_chessboard();
									printf("computer win\n");
									exit (0);
								}
								
							one_count=0;
							two_count=0;	
							one_count=check_one(analysis_chess,i,j,-1,1,2);
							two_count =check_two(analysis_chess,i,j,1,-1,2);

							if(one_count+two_count==4)
								{
									/*
									fprintf(stdout, "step %d : %d %d\n", step++, i, j);
									step++;
									fflush(stdout);
									*/
									printf_chessboard();
									printf("computer win\n");
									exit (0);
								}
							
							one_count=0;
							two_count=0;	
							one_count=check_one(analysis_chess,i,j,-1,-1,2);
							two_count =check_two(analysis_chess,i,j,1,1,2);

							if(one_count+two_count==4)
								{
									/*
									fprintf(stdout, "step %d : %d %d\n", step++, i, j);
									step++;
									fflush(stdout);
									*/
									printf_chessboard();
									printf("computer win\n");
									exit (0);
								}	
								
							analysis_chess[i][j]=0;
							}
						}
					}	
							
			/*没有成5的地方,则开始防守*/		
			//printf("debug information flag=%d\n",flag);			
			flag=defend(analysis_chess,ppi,ppj);
							
			/*如果没有需要防守的,则开始进攻*/
			
			if(flag==1)
				{
				//	printf("debug information  attack ");
					attack(analysis_chess);
				}
			
}

main(int how,char* who[])
{
	int pi,pj,k;
	int total_count;
	int maxcompall,maxcompi,maxcompj,maxppall,maxppi,maxppj;
	char p;
	
	p=*who[1];
	//chessboard[8][7]=1;
	//chessboard[8][6]=2;
	printf_chessboard();

	printf("play the first chess ,1=pp,2=cpmputer\n");
	//scanf("%d",&who);
	printf("p= %c\n",p);
	if(p=='1')
		//...
		{
			total_count=3;
		}
	else
		//....
		{
			total_count=2;
		}
	
	
	step=1;
	printf("debug information %d,%d\n",total_count,total_count%2);
	while(1)
	{
		if(total_count%2==1)
		{
			printf("pepole play:\n");	
			do
			{
				printf("the place have chess, pepole input:\n");
				scanf("%d %d",&pi,&pj);
				
			}while(chessboard[pi][pj]==1 || chessboard[pi][pj]==2);
				
			chessboard[pi][pj]=1;
			//ppwight[0]=weight_chess(chessboard,i,j,1);//这个点的八个方向的权重，包含**__*等情况
			ppi=pi;
			ppj=pj;
			
			printf_chessboard();
			
			if (whowin(chessboard,pi,pj,1)==1)
			{
				printf("pepole win\n");
				return 0;
			}
		}
		else
		{
			printf("computer play\n");
			
			if(total_count==2)
				{
					chessboard[7][7]=2;
					/*
					fprintf(stdout, "step %d : %d %d\n", step++, 7, 7);
					step++;
					fflush(stdout);
					*/
				}
			else if(total_count==4)
				{
					chessboard[ppi][ppj+1]=2;
					printf("debug information");
					/*
					fprintf(stdout, "step %d : %d %d\n", step++, ppi, ppj+1);
					step++;
					fflush(stdout);
					*/
				}
				
				else
					{
						who_play(chessboard);
					}
			printf_chessboard();

		}
		total_count++;
		
		if(total_count==224)
		{
			printf("no place to paly ,game over , draw");
			return 0;
		}
	}
		//sleep(3);
}

