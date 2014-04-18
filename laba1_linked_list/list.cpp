using namespace std;

#include "list.h"

int main()
{
	cList list;

	list.push(10);
	list.push(20);
	list.push(30);
	list.push(40);
	list.push(50);
	list.push(99);
	list.list_elements();

	list.insert_before(1,10);
	list.insert_before(5,20);
	list.insert_before(90,99);
	list.list_elements();

	list.insert_past(25,20);
	list.insert_past(2,40);
	list.insert_past(100,99);
	list.list_elements();

	list.delete_element(20);
	list.delete_element(100);
	list.delete_element(99);
	list.delete_element(1);
	list.list_elements();

return 0;
}