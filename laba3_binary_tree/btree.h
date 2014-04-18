#include <iostream>
#include <string>

#define null 0

class btree
{
private:
	struct	node
	{
		string key;
		string data;
		node* left;
		node* right;
		void print()
		{
			std::cout<<key<<' '<<data<<'\n';
		}
	};

public:
	node* root;

	btree()
	{
		root=null;
	}
	void push( string KEY,string DATA ){ push( &root,KEY,DATA ); }
	void push( node** pptr,string KEY,string DATA )
	{
		node* tmp=new node;
		tmp->key=KEY;
		tmp->data=DATA;

		if( (*pptr)==null )
		{
			tmp->left=null;
			tmp->right=null;
			(*pptr)=tmp;

		}
		else
		{
			if( KEY <= (*pptr)->key )
			{
				push( &(*pptr)->left,KEY,DATA );
			}
			else push( &(*pptr)->right,KEY,DATA );
		}

	}
	void listKLR(){ std::cout<<"list Root->Left->Right:\n"<<'\n'; listKLR( root ); std::cout<<"---------------------------\n";}
	void listKLR( node* ptr )
	{
		if( ptr != null )
		{
			ptr->print();
			if( ptr->left != null ) listKLR( ptr->left );
			if( ptr->right != null ) listKLR( ptr->right );
		}
	}

	void listLKR(){ std::cout<<"list Left->Root->Right:\n"<<'\n'; listLKR( root ); std::cout<<"---------------------------\n";}
	void listLKR( node* ptr )
	{
		if( ptr != null )
		{
			if( ptr->left != null ) listLKR( ptr->left );
			ptr->print();			
			if( ptr->right != null ) listLKR( ptr->right );
		}
	}
	void listLRK(){ std::cout<<"list Left->Right->Root:\n"<<'\n'; listLRK( root ); std::cout<<"---------------------------\n";}
	void listLRK( node* ptr )
	{
		if( ptr != null )
		{
			if( ptr->left != null ) listLRK( ptr->left );
			if( ptr->right != null ) listLRK( ptr->right );
			ptr->print();			
		}
	}
	void erase( string KEY )
	{
		node* tmp=root;
		node* parent;
		while ( tmp!= null && tmp->key != KEY)
                {
                    parent=tmp;

                    if ( KEY > tmp->key )
                    {
                        tmp = tmp->right;
                    }
                    else
                    {
                        tmp = tmp->left;
                    }
                }
		if( tmp==null ){ std::cout<<"->not found: "; return; }
		else if(tmp==root)
		{
	                if (tmp->right == null && tmp->left == null)
		        {
				root = null;
		        }
	                else if (tmp->left == null)
	                {
	                	root = tmp->right;
	                }
	                else if (tmp->right == null)
	                {
	                	root = tmp->left;
	                }
	                else
	                {
	                	node* t = tmp->right;                   
	                    	while (t->left != null)
	                    	{
	                        	tmp = t;
		                        t = t->left;
	        	        }
	                	if (t != tmp->right)
	                 	{
	                        	tmp->left = t->right;
	                        	t->right = root->right;
	                    	}
		                t->left = root->left;
	        	        root = t;
	        	}
		}
	        else
        	{
                	if (tmp->right == null && tmp->left == null)
	                {
        		        if (parent->right == tmp) parent->right = null;
        		        else parent->left = null;
	                }
                else if (tmp->left == null)
                {
                	if (parent->right == tmp) parent->right = tmp->right;
                	else parent->left = tmp->right;
                }
                else if (tmp->right == null)
                {
                	if (parent->right == tmp) parent->right = tmp->left;
                	else parent->left = tmp->left;
                }
                else
                {
                	parent = tmp;
                	node* t = tmp->right;

	                while (t->left != null)
        	        {
                	        parent = t;
                        	t = t->left;
	                }

        	        if (t != tmp->right)
                	{
	                        tmp->left = t->right;
        	                t->right = parent->right;
	                }

        	        t->left = parent->left;
                	parent = t;
                	}
            	}
		std::cout<<"erase: "<<KEY<<'\n';
	}
	node* find( node** pptr,string KEY )
	{
		node* t;

		if( (*pptr) == null ) return null;
		if( (*pptr)->key == KEY ) return (*pptr);
		t=find( &(*pptr)->left,KEY );
		if( t != null ) return t;
		t=find( &(*pptr)->right,KEY );
		if( t != null ) return t;
		return null;
	}
};
