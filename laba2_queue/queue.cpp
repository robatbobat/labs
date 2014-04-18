using namespace std;

#include "queue.h"

int main()
{
	cQueue queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);
	queue.push(99);


	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();

return 0;
}