using namespace std;

#include "kursa4.h"


//�������� �� ������ � ������� ��� ������� ��-��
#define TITLE	0
#define ISBN	1
#define YEAR	2
#define PAGES	3
#define NAME	4

string value;
std::vector<string> books; //��� ������ ���� ������ ����������� �� .csv
std::stringstream buffer; //��� �� � �� ����������������� ����
std::string contents;


//���������� �� �������� �����
//
void sortByTitle()
{
	btree<std::string> tree(&books); //�������������� ������
	for (int idx=TITLE; idx<books.size(); idx+=5 )
    	tree.root=tree.push( tree.root,books[idx],idx-TITLE );  //��������� � ���� �����
	tree.listLKR(); //������� ������
}

//���������� �� ISBN
//

void sortByISBN()
{
	btree<std::string> tree(&books);
	for (int idx=ISBN; idx<books.size(); idx+=5 )
    	tree.root=tree.push( tree.root,books[idx],idx-ISBN ); 
	tree.listLKR();
}

//���������� �� ���� �������
//

void sortByYear()
{
	btree<int> tree(&books);
	for (int idx=YEAR; idx<books.size(); idx+=5 )
    	tree.root=tree.push( tree.root,atoi( books[idx].c_str()),idx-YEAR );
	tree.listLKR();
}

//���������� �� ���������� �������
//

void sortByPages()
{
	btree<int> tree(&books);
	for (int idx=PAGES; idx<books.size(); idx+=5 )
    	tree.root=tree.push( tree.root,atoi( books[idx].c_str()),idx-PAGES ); 
	tree.listLKR();
}

//���������� �� ������
//

void sortByAuthor()
{
	btree<std::string> tree(&books);
	for (int idx=NAME; idx<books.size(); idx+=5 )
    	tree.root=tree.push( tree.root,books[idx],idx-NAME ); 
	tree.listLKR();
}

int main()
{

        char	c;
	int	i;

	//��������� ������ �� .csv � ������ � ����� � ������
	std::ifstream in("primer.csv");
	buffer << in.rdbuf();
	contents=buffer.str();
	for( int idx=0; idx<contents.size(); idx++ )
	{
	        c=contents[idx];
		if( c==';' || c=='\n') //������ � .csv ��������� ������� ; � ��������� ������
		{
			books.push_back(value);
			value.clear();
		}
		else value.push_back(c);
	}

	//���� ������ ��������� ����������� ������
	//
	for(;;)
	{
		cout<<"[1]Sort by title [2]Sort by ISBN [3]Sort by year [4]Sort by pages [4]Sort by author\n";
		i=0;
		cin>>i;
		switch(i)
		{
			case 1:
				sortByTitle();
				break;
			case 2:
				sortByISBN();
				break;
			case 3:
				sortByYear();
				break;
			case 4:
				sortByPages();
				break;
			case 5:
				sortByAuthor();
				break;

		};
	}
	return 0;
}
