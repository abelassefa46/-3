#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[])
{

	int seg_id;

	int *numFromShared;



	seg_id = shmget (5600, sizeof(int), IPC_CREAT | 0666);

	
	if (seg_id == -1) {

		printf ("Failure to create memory segment");

		exit (1);

	} 

	else

	//printf ("Segment ID is %d\n", seg_id);


	numFromShared = shmat (seg_id, NULL,SHM_RDONLY);

	
	if (numFromShared == (int *) -1) 
	{

		printf ("Failure to attach");

		exit (1);

	}


	//printf("%d\n" , *numFromShared);

	int x = *numFromShared;

	if (x % 2 == 0)
	printf("The value of %d is Even\n",x);
	
	else if (x % 2 != 0)
	printf("The value of %d is Odd\n",x);

	else
	printf("The value of %d is Zero\n",x);

	shmdt (numFromShared);

	shmctl (seg_id, IPC_RMID, 0);

	return 0;

}
