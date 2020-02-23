#include<stdio.h>
#include<string.h>
#include<stdbool.h>
 
int atoi(char *str)//convert a string to an int 
	{
	if (*str == '\0')return 0;
	int res = 0;		// Initialize result
	int sign = 1;		// Initialize sign as positive
	int i = 0;			// Initialize index of first digit
	if (str[0] == '-')
		{
		sign = -1;
		i++;  			// Also update index of first digit
		}
	for (; str[i] != '\0'; ++i)
		{
		if ( str[i] <= '0' || str[i] >= '9')return 0;	// If string contain character it will terminate
		res = res*10 + str[i] - '0';
		}
	return sign*res;
	}
float atof(char * ptr)//convert a string to a float
	{
	float x = 0;
	float i = 10;
	bool flag = false;
	bool m = false;
	while(*ptr != '\0')
		{
		if(flag)
			{
			if(*ptr < 48 || *ptr > 57)
				{
				ptr++;
				continue;
				}
			x += (*ptr - 48) / i;
			i*=10;
			}
		else
			{
			if(*ptr == 46)flag = true;
			if(*ptr == 45)m = true;
			if(*ptr < 48 || *ptr > 57)
				{
				ptr++;
				continue;
				}
			x *= 10;
			x += (*ptr - 48);
			}
		ptr++;
		}
		if(m)x *= (-1);
	return x;
	}
void processCommand(char* buffer){
	float paralist[3] = {0,0,0};   //paramters list (x, y, z) 
	int cmd;                       //command number eg: the 0 in "G0", the 1 in "G1" ...
	char* ptr = strtok(buffer," ");//Split String into tokens separeted by 1 space
								   //eg: "G1 X1 Y1" becomes "G1", "X1", "Y1"
	cmd = atoi(ptr+1);             //Convert command to an int eg: "1"--->1
	ptr = strtok(NULL," ");        //Skip the G/M command to avoid implicit conditions 
	while(ptr != NULL)             //While the token is not empty 
		{
		switch(*ptr)
			{
			case 'X':
				paralist[0] = atof(ptr+1);
				break;
			case 'Y':
				paralist[1] = atof(ptr+1);
				break;
			case 'Z':
				paralist[2] = atof(ptr+1);
				break;
			}
		ptr = strtok(NULL," ");    //move to the next token
		}
	// look for commands that start with 'G'
	if(buffer[0] == 'G')
		{   
		switch(cmd) 
			{
			case  0://  move in a line
				printf("processign in mode G0\n");	
				if(paralist[2] >= 0)printf("setting the Z axe\n");
				printf("going to: (%f, %f, %f)\n", paralist[0], paralist[1], paralist[2]);
				//to do: add here a function that moves the sterpper from current position
				//to the parametres list (x, y, z) make sure to move the z axes first!!!
				break;
			case  1://  move in a line
				printf("processign in mode G1\n");	
				if(paralist[2] >= 0)printf("setting the Z axe\n");
				printf("going to: (%f, %f, %f)\n", paralist[0], paralist[1], paralist[2]);
				//to do: add here a function that moves the sterpper from current position
				//to the parametres list (x, y, z) make sure to move the z axes first!!!
				break;
			}
		}
	else if(buffer[0] == 'M')
		{   
		switch(cmd) 
			{
			case  0:
				printf("processign in mode M0\n");	
				if(paralist[2] >= 0)printf("setting the Z axe\n");
				printf("going to: (%f, %f, %f)\n", paralist[0], paralist[1], paralist[2]);
				//to do: add here a function that moves the sterpper from current position
				//to the parametres list (x, y, z) make sure to move the z axes first!!!
				break;
			case  1:
				printf("processign in mode G1\n");	
				if(paralist[2] >= 0)printf("setting the Z axe\n");
				printf("going to: (%f, %f, %f)\n", paralist[0], paralist[1], paralist[2]);
				//to do: add here a function that moves the sterpper from current position
				//to the parametres list (x, y, z) make sure to move the z axes first!!!
				break;
			}
		}
	}







int main()
	{
	char x[90] = "G1 X1 Y1 Z1";
	char* c = x;
	processCommand(c);
	
	return 0;
	}
