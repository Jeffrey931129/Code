#include<stdio.h>
#include<crtdbg.h>
#include "game.h"
// Program entry point
// Returns program exit code.
int main(int argc, char **argv) 
{
	printf("game\n");
	game_create();
	_CrtDumpMemoryLeaks();
	// printf("Yeah! You just end you game with no error perhaps.")
	return 0;
}
