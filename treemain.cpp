#include <iostream>
#include"tree.h"
using namespace std;

int main() {
	
	tree t1;		//takes integer values only. 	
	t1.createTreeLevel();
	t1.displayTreeLevel();
	t1.displayTreePost();
	return 0;
}
