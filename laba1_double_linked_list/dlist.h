#include <iostream>
#include <string>

#define null 0

class cList
{
private:
	struct	body
	{
		body* next;
		body* prev;
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
	void list_elements_forward()
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
                //for(body* idx=end; idx!=null; idx=idx->prev)
		body* idx=end;
		while(idx)
                {
                        std::cout<<idx->element<<' ';
			idx=idx->prev;
                }
                std::cout<<'\n';
        }

	void push(int value)
	{
		body* temp=new body;
		temp->element=value;
		temp->next=null;
		if( start==null )
		{
			temp->prev=null;
		        start=temp;
			end=temp;
		 	return;
		}
		temp->prev=end;
		end->next=temp;
		end=temp;
		
	}

	void insert_before(int value,int key)
	{
		if( start == null )
		{
			push(value);
		 	return;
		}

	 	body* temp=new body;
		temp->element=value;
		temp->next=null;
		
		body* idx=start;
		body* prev=null;
		for(idx; idx!=null; idx=idx->next)
                {
                        if(idx->element==key) break;
			prev=idx;
                }
		if(idx==null)
		{
			push(value);
		 	return;
		}
		if(prev==null)
		{
			temp->prev=null;
			temp->next=start;
			start->prev=temp;
			start=temp;
			return;
		}
		temp->prev=prev;
		temp->next=idx;
		idx->prev=temp;
		prev->next=temp;
	}

	void insert_past(int value,int key)
	{
		if( start == null )
		{
		        push(value);
		 	return;
		}

	 	body* temp=new body;
		temp->element=value;
		temp->next=null;
		
		body* idx=start;
		body* prev=null;
		for(idx; idx!=null; idx=idx->next)
                {
                        if(idx->element==key) break;
			prev=idx;
                }
		if(idx==null)
		{
			push(value);
		 	return;
		}
		temp->prev=idx;
		temp->next=idx->next;
		if(idx->next!=null)idx->next->prev=temp;
		else end=temp;
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
				if(prev==null)
				{
					start=idx->next;
					start->prev=null;
				}
				else
				{
					if(idx->next!=null)
					{
						idx->next->prev=prev;
						prev->next=idx->next;
					}		
					else
					{
						prev->next=null;
						end=prev;
					}
					
				}
				delete idx;
				return;
			}
			prev=idx;
                }
		
	}

	body* start;
	body* end;

};
