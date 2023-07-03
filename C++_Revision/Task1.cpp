#include <iostream>
using namespace std;
void v_alloc_table_add_5(int* piTab, int iSize) {
	piTab = new int[iSize];
	for (int i = 0; i < iSize; i++)
		*(piTab + i) = i + 5;
}
void v_test_task1() {
	int *i_tab = new int[3];
	int i_size = 10;
	v_alloc_table_add_5(i_tab, i_size);
	for (int i = 0; i < i_size; i++)
		cout << i_tab[i] << " ";
}