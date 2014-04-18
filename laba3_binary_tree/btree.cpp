using namespace std;

#include "btree.h"

int main()
{
	btree tree;


	tree.push( "Ivanov A","2891" );
	tree.push( "Petrov B","2894" );
	tree.push( "Sidorov C","2893" );
	tree.push( "Kuznecov D","2894" );
	tree.push( "Sokolov E","2893" );
	tree.push( "Astahov J","2890" );
	tree.push( "Morozov F","2894" );
	tree.push( "Volkov G","2895" );
	tree.push( "Pavlov H","2894" );
	tree.push( "Vasiliev I","2897" );

	tree.listLKR();
	tree.listKLR();
	tree.listLRK();

	tree.erase("Sokolov E");
	tree.listLKR();

return 0;
}