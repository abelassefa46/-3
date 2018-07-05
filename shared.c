#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[])
{

	int seg_id;

	int *num;

	int key = 5600;

	seg_id = shmget (key, sizeof(int), IPC_CREAT | 0666);

	if (seg_id == -1) 
	{

		printf ("Failure to create memory segment");

		exit (1);

	} 

	else

	//printf ("Segment ID is %d\n", seg_id);

	num = shmat (seg_id, NULL, 0);

	if (num == (int *) -1) 
	{

		printf ("Failure to attach");

		exit (1);

	}

	srand(time(NULL));

	int r = rand() % 10;

	*num = r;

	printf("%d\n" , *num);

	shmdt (num);

	//shmctl (seg_id, IPC_RMID, 0);

	return 0;

}
