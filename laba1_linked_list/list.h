#include <iostream>
#include <string>

#define null 0

class cList
{
private:
	struct	body
	{
		body* next;
		int element;
	};

public:
	cList()
	{
		start=null;
		end=null;
	}
	~cList()
	{
         	while(start)
		{
			end=start->next;
			delete start;
			start=end;
		}
	}
	void list_elements()
        {
                if(start==null) std::cout<<"empty list";
                for(body* idx=start; idx!=null; idx=idx->next)
                {
                        std::cout<<idx->element<<' ';
                }
                std::cout<<'\n';
        }

	void list_elements_backward()
        {
                if(start==null) std::cout<<"empty list";
		list_elements_backward( &start );

/*
                for(body* idx=start; idx!=null; idx=idx->next)
                {
                        std::cout<<idx->element<<' ';
                }
                std::cout<<'\n';
*/
        }
	void list_elements_backward( body** ptr)
	{
		if( (*ptr)->next!=null ) list_elements_backward( &(*ptr)->next );
		std::cout<<(*ptr)->element<<' ';
	}

	void push(int value)
	{
		body* temp=new body;
		temp->element=value;
		temp->next=null;
		if( end==null )
		{
		        start=temp;
			end=temp;
		 	return;
		}
		end->next=temp;
		end=temp;
		
	}

	void insert_before(int value,int key)
	{
	 	body* temp=new body;
		temp->element=value;
		temp->next=null;
		
		if( start == null ) 
		{
		        push(value);
		 	return;
		}
		body* idx=start;
		body* prev=null;
		for(idx; idx!=null; idx=idx->next)
                {
                        if(idx->element==key) break;
			prev=idx;
                }
		if(idx==null)
		{
		        prev->next = temp;
		 	return;
		}
		if(prev==null)
		{
			temp->next=start;
			start=temp;
			return;
		}
		temp->next=idx;
		prev->next=temp;
	}

	void insert_past(int value,int key)
	{
	 	body* temp=new body;
		temp->element=value;
		temp->next=null;
		
		if( start == null )
		{
		        push(value);
		 	return;
		}
		body* idx=start;
		body* prev=null;
		for(idx; idx!=null; idx=idx->next)
                {
                        if(idx->element==key) break;
			prev=idx;
                }
		if(idx==null)
		{
		        prev->next = temp;
		 	return;
		}
		temp->next=idx->next;
		idx->next=temp;
	}

	void delete_element(int key)
	{
		if( start==null ) return;

		body* prev=null;
		for(body* idx=start; idx!=null; idx=idx->next)
                {
                        if(idx->element==key)
			{
				if(prev==null)start=idx->next;
				else prev->next=idx->next;
				delete idx;
				return;
			}
			prev=idx;
                }
		
	}

	body* start;
	body* end;

};
