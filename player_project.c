#include<stdio.h>	//header files
#include<string.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct player 	//player structure
{
    int jersey_no;		//members of structure
	int runs;
	int wickets;
	int matched_played;
    char name[20];
} player;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void store(player*,int);	//function declaration
void display(player*,int);
void search(player*,int);
void update(player*,int);
void deletee(player*,int);
void topthree(player*,int);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main()
{
    int input;		//for switch case(menu driven)
	int repeat; 	//for repeat the menu 
	int num;		//to declaire the structure type array size
    printf("Enter how many players are playing: ");
    scanf("%d",&num);
    player arr[num];	//structure type array size 
    do 
	{
		//Menu 
        printf("1.Store the Data.\n");
        printf("2.Print the Data.\n");
        printf("3.Search the Data.\n");
        printf("4.update the Data.\n");
        printf("5.Remove the Data.\n");
        printf("6.Top three Player.\n");

        scanf("%d",&input);

        switch(input) 
		{
        case 1:
            store(arr,num);		//function call for store player details
            break;

        case 2:
            display(arr,num);	//function call for display player details
            break;

        case 3:
            search(arr,num);	//function call for search player and display all information
            break;
            
        case 4:
			update(arr,num);	//function call for update player 
			break; 
			
		case 5:
			deletee(arr,num);	//function call for delete player information 
			break;	   
		
		case 6:
			topthree(arr,num); 
			break;
			
        default:
            printf("Invalid operation");	// for invalid  input
            break;
        }

        printf("\n\nDo you want to continue press 1 || for exit press 0\n");
        scanf("%d",&repeat);
    
	} while(repeat==1);	//for repeat the loop

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void store (player* ptr,int t)
{
    int i;
    printf("Enter the %d players details\n",t);
    for(i=0; i<t; i++) 
	{
        printf("\n\nEnter player jersey number: ");
        scanf("%d",&ptr[i].jersey_no);
        
        printf("\n\nEnter player name: ");
        scanf("%s",&ptr[i].name);
        
        printf("\n\nEnter player runs: ");
        scanf("%d",&ptr[i].runs);
        
        printf("\n\nEnter wickets taken by player: ");
        scanf("%d",&ptr[i].wickets);
        
        printf("\n\nEnter matched by player: ");
        scanf("%d",&ptr[i].matched_played);

        
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display(player* ptr,int t)	//function defination for display player details
{
    int i;	//for the itration of for loop
    for(i=0; i<t; i++) 
	{
        printf("\n\nThe player Jersey Number: %d\n",ptr[i].jersey_no);
        printf("The player Name: %s\n",ptr[i].name);
        printf("The Runs made by player: %d\n",ptr[i].runs);
        printf("The Wickets taken by player: %d\n",ptr[i].wickets);
        printf("The number of matches played by player: %d\n",ptr[i].matched_played);

    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void search(player* ptr,int t)	//function defination for search player and display all information
{
    int input;	//for switch case
		
    printf("1.Search the player by its Jersey Number.\n");
    printf("2.Search the player by its Name\n");
    scanf("%d",&input);

    switch(input) 
	{

    	case 1: 
		{
        	int i;		//for the itration of for loop
			int flag=0; //for check the condition mention if if()statement
			int num;	//for accept the jersey number
        	printf("\nEnter the player jersey number: ");
        	scanf("%d",&num);
        	for(i=0; i<t; i++) 
			{
            	if(ptr[i].jersey_no==num) 
				{
                	flag=1;
                	break;
            	}
        	}
        	if(flag==1) 
			{
            	printf("\nThe player jersey number %d is matched at index %d",ptr[i].jersey_no,i);
        	} 
			else 
			{
            	printf("\nThe player jersey number is not matched");
        	}
        break;
    	}

    	case 2: 
		{
        	int i;			//for the itration of for loop
			int flag=0;		//for check the condition mention if if()statement
        	char search[20];	//for accept the player name to search
        	fflush(stdin);		//to flush the buffer
        	printf("\nEnter the player name to search: ");
        	scanf("%s",search);
        	for(i=0; i<t; i++) 
			{
            	if(strcmp(ptr[i].name,search)==0) 
				{
                	flag=1;
                	break;
            	}
        	}
        	if(flag==1)
			{
        		printf("\nThe player %s is matched at index %d",ptr[i].name,i);	
			}
            
			else
			{
				printf("The player name is not matched\n");
			}   
        break;

    	}

    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void update(player* ptr,int t)
{
		int i;		//for the itration of for loop
		int flag=0;	//for check the condition mention if if()condition
		int num;	//for accept the player jersey number 
		int choice;	//for the choice in if() condition
        printf("\nenter the player jersey number: ");
        scanf("%d",&num);
        for(i=0; i<t; i++) 
		{
            if(ptr[i].jersey_no==num) 
			{
                flag=1;
                break;
            }
        }
        if(flag==1) 
		{
   			printf("\n1.update player runs.\n");
			printf("2.update player wickets\n");
			printf("3.update player mateches playes\n");
			printf("Enter the number: ");
			scanf("%d",&choice);
			
			if(choice==1)
			{
			printf("enter the player runs\n");
			scanf("%d",&ptr[i].runs);
			printf("\n\nThe player Jersey Number: %d\n",ptr[i].jersey_no);
       		printf("The player Name: %s\n",ptr[i].name);
        	printf("The Runs made by player: %d\n",ptr[i].runs);
        	printf("The Wickets taken by player: %d\n",ptr[i].wickets);
        	printf("The number of matches played by player: %d\n",ptr[i].matched_played);
			}
			else if(choice==2)
			{
			printf("enter wickets taken by player\n");
			scanf("%d",&ptr[i].wickets);
			printf("\n\nThe player Jersey Number: %d\n",ptr[i].jersey_no);
       		printf("The player Name: %s\n",ptr[i].name);
        	printf("The Runs made by player: %d\n",ptr[i].runs);
        	printf("The Wickets taken by player: %d\n",ptr[i].wickets);
        	printf("The number of matches played by player: %d\n",ptr[i].matched_played);					 
			}
			else if(choice==3)
			{
			printf("enter number of matches played by \n");
			scanf("%d",&ptr[i].matched_played);
			printf("\n\nThe player Jersey Number: %d\n",ptr[i].jersey_no);
       		printf("The player Name: %s\n",ptr[i].name);
        	printf("The Runs made by player: %d\n",ptr[i].runs);
        	printf("The Wickets taken by player: %d\n",ptr[i].wickets);
        	printf("The number of matches played by player: %d\n",ptr[i].matched_played);	
			}
		} 
		else 
		{
            printf("\nThe player jersey number is not matched");
		}	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deletee(player* ptr,int t)	//function call for delete player information 
{
	int i; 		//for the itration of outer for loop
	int j;		//for the itration of inner for loop
	int player;	//for accept the player jersey number 
	int flag=0;	//for check the condition mention if if()condition
	printf("Enter Player jersey number to delete player details\n");
	scanf("%d",&player);
	for(i=0;i<t;i++)
	{
		if(ptr[i].jersey_no==player)
		{
		
		
			j=i;
		while(j<t-1)
		{
			ptr[j]=ptr[j+1];
			j++;
		}
	
		t--;
		flag=1;
		break;
		}
	}
	if(flag==1)
	{
		printf("The player INFORMATION has been removed successfully.\n");
		for(i=0;i<t;i++)
		{
			
		printf("\n\nThe player Jersey Number: %d\n",ptr[i].jersey_no);
        printf("The player Name: %s\n",ptr[i].name);
        printf("The Runs made by player: %d\n",ptr[i].runs);
        printf("The Wickets taken by player: %d\n",ptr[i].wickets);
        printf("The number of matches played by player: %d\n",ptr[i].matched_played);
		}
	}
	else
	{
		printf("\n\nInvalid entry -- try again.\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void topthree(player* ptr,int t) 
{
  
  int choice;
  printf("\n1.Top three players by runs");
  printf("\n2.Top three players by wickets");
  printf("\nselect above option: ");
  scanf("%d", & choice);

switch (choice) 
  {

  	case 1: 
  	{
    	int top1, top2, top3,i;
    	top1=ptr[0].runs;
    	top2=ptr[0].runs;
    	top3=ptr[0].runs;
    
    
		for(i=0;i<t;i++)
    	{
    		if(top1<ptr[i].runs)
    		{
    			top3=top2;
    			top2=top1;
    			top1=ptr[i].runs;
			}
		
			else if(top2<ptr[i].runs)
			{
				top3=top2;
				top2=ptr[i].runs;
			}
			else if(top3<ptr[i].runs)
			{
				top3=ptr[i].runs;
			}
		}
	
			printf("\n\nTop Three Run Scorer are: ");
	
			for(i=0;i<t;i++)
			{
				if(top1==ptr[i].runs)
				{	
					printf("\n1.The highest run scorer is %s with %d runs.",ptr[i].name,ptr[i].runs);
				}	
			}
	
			for(i=0;i<t;i++)
			{
				if(top2==ptr[i].runs)
				{
					printf("\n2.Second in the list is %s with %d runs.",ptr[i].name,ptr[i].runs);
				}	
			}
	
			for(i=0;i<t;i++)
			{
				if(top3==ptr[i].runs)
				{
					printf("\n3.%s rounds off the top three with a total of %d runs.",ptr[i].name,ptr[i].runs);
				}
			}
  		
	}break;
  
    case 2: 
	{
    	int top1, top2, top3,i;
    	top1=ptr[0].wickets;
    	top2=ptr[0].wickets;
    	top3=ptr[0].wickets;
    	
		for(i=0;i<t;i++)
    	{	
    		if(top1<ptr[i].wickets)
    		{
    			top3=top2;
    			top2=top1;
    			top1=ptr[i].wickets;
			}
		
			else if(top2<ptr[i].wickets)
			{
				top3=top2;
				top2=ptr[i].wickets;
			}
			else if(top3<ptr[i].wickets)
			{
				top3=ptr[i].wickets;
			}
			
		}
	
		printf("\n\nTop Three with wickets are: ");	
			for(i=0;i<t;i++)
			{
				if(top1==ptr[i].wickets)
				{
					printf("\n1.The highest wickets taken by is %s with %d wickets.",ptr[i].name,ptr[i].wickets);
				}	
			}
	
			for(i=0;i<t;i++)
			{
				if(top2==ptr[i].wickets)
				{
					printf("\n2.Second in the list is %s with %d wickets.",ptr[i].name,ptr[i].wickets);
				}	
			}
	
			for(i=0;i<t;i++)
			{
				if(top3==ptr[i].wickets)
				{
					printf("\n3.%s rounds off the top three with a total of %d wickets.",ptr[i].name,ptr[i].wickets);
				}	
			}  
  		
	}break;


	}
}

