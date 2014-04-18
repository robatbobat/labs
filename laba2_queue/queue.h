#include <iostream>
#include <string>

#define null 0

class cQueue
{
private:
	struct	body
	{
		body* next;
		body* prev;
		int element;
	};

public:
	cQueue()
	{
		start=null;
		end=null;
	}
	~cQueue()
	{
         	while(start)
		{
			end=start->next;
			delete start;
			start=end;
		}
	}

	void pop()
	{
		if( start==null ) std::cout<<"empty queue\n";
		else
		{
			std::cout<<start->element<<'\n';
			end=start->next;
			delete start;
			start=end;
		}
	}

	void push(int value)
	{
		body* temp=new body;
		temp->element=value;
		temp->next=null;
		if( start==null )
		{
			start=temp;
			end=temp;
		}
		else
		{
			end->next=temp;
			end=temp;
		}		
	}


	body* start;
	body* end;

};
