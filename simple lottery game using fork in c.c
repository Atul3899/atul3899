#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main()
{
	fflush(stdin);
	srand(time(0));
	int no_child,status;
	pid_t pid,mypid;
	printf("No. of person\n");
	scanf("%d",&no_child);
	int win[1000];
	for(int i=0;i<no_child;i++)
		win[i]=0;
	int c_pid;
	for(int i=0;i<no_child;i++)
	{
		pid = fork();

		if(pid == 0)
		{
			mypid=getpid();
			srand(mypid);
			//win[i]=mypid;
			exit(mypid);
		}
		else 
		{
			wait(&status);
			win[i] = pid;
		}
	}
	int L_input,flag=0;
	printf("Available Lottery Numbers are\n");
	 for(int i=0;i<no_child;i++)
        {
		printf("%X \n",win[i]);
        }
	printf("Enter Your Lottery Number: ");
	scanf("%x",&L_input);
	for(int i=0;i<no_child;i++)
	{
		if(win[i]==L_input)
			flag++;
	}
	while(flag==0)
	{
		printf("Invalid Input\nEnter a valid Input: ");
		scanf("%X",&L_input);
		for(int i=0;i<no_child;i++)
		{
			if(win[i]==L_input)
				flag++;
		}
	}
	int w=rand()%no_child;
	if(win[w]==L_input)
		printf("Congratulation! You win\n");
	else
		printf("You lose, The Winner is: %X\n",win[w]);
	return 0;
}
