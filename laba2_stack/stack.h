#include <iostream>
#include <string>

#define null 0

class cStack
{
private:
	struct	body
	{
		body* next;
		body* prev;
		int element;
	};

public:
	cStack()
	{
		start=null;
		end=null;
	}
	~cStack()
	{
         	while(end)
		{
			start=end->next;
			delete end;
			end=start;
		}
	}

	void pop()
	{
		if( end==null ) std::cout<<"empty stack\n";
		else
		{
			std::cout<<end->element<<'\n';
			start=end->next;
			delete end;
			end=start;
		}
	}

	void push(int value)
	{
		body* temp=new body;
		temp->element=value;
		if( end==null )
		{
			temp->next=null;
			end=temp;
		}
		else
		{
			temp->next=end;
			end=temp;
		}		
	}


	body* start;
	body* end;

};
