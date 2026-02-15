#include <stdio.h>
#include <ctype.h>

char Ask()
{
	char re, RE;
	while (1)
	{
		printf("Would you like to use the calculator again? [Y/N]\n>");
		scanf(" %c",&re);
		RE=toupper(re);
		while(getchar()!='\n');
		
		if(RE=='Y' || RE=='N')
		{
			return(RE); 
		}
		else
		{
			printf("Invalid Input. Please Try again.\n\n");
			continue;
		}
	}
	
}

void inputnum(float num[], int size)
{
	int i;
	for(i=0; i<size; i++)
		{
			while(1)
			{
				printf("Enter number %d: ", i+1);
				if(scanf("%f", &num[i]) !=1)
				{
					while(getchar() !='\n');
					continue;
				}
				else
				{
					break;
				}
			}
		}
}


int main()
{
	int choice;
	char RE;
	float res, num[2];
	while(1)
	{
			while(1)
			{
				printf("Please select an operation\n[1]Addition [2]Subtraction [3]Multiplication [4]Division [5]Exit Program\n>");
				if (scanf("%d", &choice) !=1)
				{
					while(getchar() !='\n');
					printf("Invalid input. Please try again.\n\n");
					continue;
				}
				else if(choice>0 && choice<5)
				{
					break;
				}
		
				else if(choice==5)
				{
					printf("Thank you for using my calculator.");
				return 0;
				}
				else
				{
					printf("Invalid input. Please try again.\n\n");
					continue;
				}
			}
			
			inputnum(num,2);
			switch(choice)
			{
				case 1:
					res=num[0]+num[1];
					printf("The sum is %.2f\n", res);
					break;
					
				case 2:
					res=num[0]-num[1];
					printf("The difference is %.2f\n", res);
					break;
					
				case 3:
					res=num[0]*num[1];
					printf("The product is %.2f\n", res);
					break;
					
				case 4:
					if(num[1]==0)
					{
						printf("That can't happen. Please try again.\n");
						break;
					}
					
					res=num[0]/num[1];
					printf("The quotient is %.2f\n", res);
					break;
			}
			
			RE=Ask();
			if(RE=='Y')
			{
				continue;
			}
			else if(RE=='N')
			{
				printf("Thanks for using my calculator");
				return 0;
			}
	}
}
