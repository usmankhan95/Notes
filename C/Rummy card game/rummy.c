#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) 
{
        int players = atoi(argv[1]); 
	char deck[52][4]; 
	int i, k, j, pid; 
	int rummyDeclared = 0; 
	int card_count; 

	if (players > 5 || players < 3) 
	{
                printf("%d is not the allowed number of players, min is 3 and max is 5\n", players); 
		exit(1); 
	}
        
        for (i = 0; i < argc - 2; i++)
	{
                strcpy(deck[i], argv[i+2]); 
	} 
	
	char **hand[players]; 
	for(i=0;i<players;i++) 
	{ 
		card_count = 52/players;
            
        	if(52%players != 0 && i <= 52*players)
                	
			card_count++;
        
        	hand[i] = malloc(sizeof(char*)*card_count);
            
		for(j=i, k=0; j<52; j+=players, k++) 
	  	{
                	hand[i][k] = malloc(sizeof(char)*4); 
			strcpy(hand[i][k], deck[j]);
	  	} 
	} 
	
	for (i = 0; i < players; i++) 
	{ 
		pid = fork(); 
		if (pid < 0) 
		{
            		printf("Fork Failed\n"); 
			exit(1);
		} 
		else if (pid == 0) 
		{  
			card_count = 52/players;
			char *hand_string; 
			char *set_string;
			char *run_string;
	
			if(52%players != 0 && i <= 52*players) 
			card_count++;
                    
        		printf("Child %d, pid %d:  I have %d cards\n", i+1, getpid(), card_count); 
	
			for(k=0;k<card_count;k++)
			{
				if(hand[i][k] == NULL)
					continue;
				sprintf(hand_string, "%s %s", hand_string, hand[i][k]);
				
			}
			
	
			printf("Child %d, pid %d: %s\n", i+1, getpid(), hand_string);
			
			for(k=0;k<card_count;k++)
			{
				 for(j=0;j<card_count;j++)
                                {
                                        if(hand[k][1] == hand[j][1])
                                        {

                                                sprintf(set_string, "%s", set_string, hand[k]);
                                               
                                        }
                                }

			}

			printf("Child %d, pid %d: set <%s>\n", i+1, getpid(), set_string);
				
			break; 
			exit(0); 
	
		}   
        } 
 	
	while(wait(NULL) > 0);

 }
