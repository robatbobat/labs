#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>

#define null 0

template< class KEY_TYPE >

class btree
{
public:
	struct	node // структура узла дерва
	{
		int height;
		node* left;
		node* right;
		node( KEY_TYPE k,int IDX ){ idx=IDX; key = k; left = 0; right = 0; height = 1; }
		KEY_TYPE key; // ключ по которому идет поиск
		int	idx; //смещение по буферу с записями
	};

	node*	root;
	int	lines;
	vector <string> *pBooks; //указатель на буфер где хранятся все записи

	btree( vector <string> *p ) //инициализируем дерево,обнуляем корень
	{
		pBooks=p;
		root=null;
	}

	// возвращаем высоту заданного в ptr узла или 0
	int getHeight( node* ptr )  
	{
		if( ptr != null ) return ptr->height;
		return 0;
	}

	// вычисляем высоту узла ptr?
	// берем высоту левого и правого,сравниваем,тот что больше+1 и есть высота
	void putHeight( node* ptr )
	{
		int l = getHeight(ptr->left);
		int r = getHeight(ptr->right);
		if( l>r ) ptr->height=l+1;
		else ptr->height=r+1;
	}

	//возвращем разницу в высоте между левым и правым поддеревом
	//по ней ориентируемся есть ли перегруз и надо ли вращать в ту или иную сторону
	int diff( node* ptr ) 
	{
	    return getHeight(ptr->right)-getHeight(ptr->left);
	}

	//в случае если разница в весе поддеревьев равна 2 или -2 то вращаем вправо или влево соответственно
	//возможные варианты:   o  o    o   o
	//                     /    \  /     \
	//                    /     /   \     \
	//
	node* rotateLR(node* ptr)
	{
		putHeight(ptr);
		if( diff(ptr)==2 )
		{
			if( diff(ptr->right) < 0 ) ptr->right = rotateR(ptr->right); 
			return rotateL(ptr);
		}
		if( diff(ptr)==-2 )
		{
			if( diff(ptr->left) > 0  )
		        ptr->left = rotateL(ptr->left);
		        return rotateR(ptr);
		}
		return ptr;
	}
	
	//разворот вправо
	node* rotateR( node *ptr )
	{
		node* q = ptr->left;
		ptr->left = q->right;
		q->right = ptr;
		putHeight(ptr);
		putHeight(q);
		return q;
	}

	//влево
	node* rotateL( node *ptr )
	{
		node* p = ptr->right;
		ptr->right = p->left;
		p->left = ptr;
		putHeight(ptr);
		putHeight(p);
		return p;
	}

	//добавление нового ключа
	node* push(node* ptr, KEY_TYPE KEY,int IDX )
	{
		if( ptr==null ) return new node(KEY,IDX);
		if( KEY<ptr->key ) ptr->left = push(ptr->left,KEY,IDX);
		else ptr->right = push(ptr->right,KEY,IDX);

		//проверка на нарушение разницы в весе
		return rotateLR(ptr);
	}

	//отображение списка книг
	//
	void listLKR(){ listLKR( root ); lines=0; }
	void listLKR( node* ptr )
	{
		if( ptr != null )
		{
			if( ptr->left != null ) listLKR( ptr->left );
//			lines=ptr->print( lines);
			if( lines<20)
			{
				cout<< pBooks->operator[](ptr->idx+1)<<'\t';
				cout<< pBooks->operator[](ptr->idx+2)<<'\t';
				cout<< pBooks->operator[](ptr->idx+3)<<'\t';
				cout<< pBooks->operator[](ptr->idx+4)<<'\t';
				cout<< pBooks->operator[](ptr->idx+0)<<'\n';
			}
			else
			{
				cout<<" -- press ENTER key --\n";
				while(cin.get() != '\n' ){}
				lines=0; system("CLS");
			}

			if( ptr->right != null ) listLKR( ptr->right );
		}
	}
	//удаление узла из дерева
	void erase( KEY_TYPE KEY )
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
	//поиск узла по ключу
	node* find( node** pptr,KEY_TYPE KEY )
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
