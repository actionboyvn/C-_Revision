#include <iostream>
#include <map>
#include <set>
#include "CTable.h"
#include "CTreeStatic.h"
#include "CTreeDynamic.h"
#include "CMySmartPointer.h"
#include "CBTree.h"
#include "BinarySearchTree.h"
#include <chrono>
#include <thread>
#define SQR(a) a*a
using namespace std;

//TASK 1
void v_task1_1() {
	int i_size = 10;
	int* pi_tab;
	pi_tab = new int[i_size];
	for (int i = 0; i < i_size; i++)
		*(pi_tab + i) = i + 5;
	for (int i = 0; i < i_size; i++)
		cout << pi_tab[i] << ' ';
	delete[] pi_tab;
}
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
	if (iSizeX < 0 || iSizeY < 0 || *piTable != nullptr)
		return false;
	*piTable = new int*[iSizeX];
	for (int i = 0; i < iSizeX; i++)
		(*piTable)[i] = new int[iSizeY];
	return true;
}
bool b_dealloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
	if (iSizeX < 0 || iSizeY < 0 || *piTable == nullptr) {
		cout << "Fail";
		return false;
	}
	for (int i = 0; i < iSizeX; i++)
		delete[] (*piTable)[i];
	delete[] (*piTable);
	return true;
}
void v_task1_2() {
	int** pi_table = nullptr;
	cout << "Allocation: " << b_alloc_table_2_dim(&pi_table, 3, 5) << endl;
	cout << "Deallocation: " << b_dealloc_table_2_dim(&pi_table, 3, 5);
}
void v_mod_tab(CTable* pcTab, int iNewSize) {
	pcTab->bSetNewSize(iNewSize);
}
void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.bSetNewSize(iNewSize);
}
void v_task1_3() {
	CTable c_tab1;
	CTable c_tab2("tab2", 5);
	CTable* c_tab2_clone = c_tab2.pcClone();
	delete c_tab2_clone;
	c_tab2.bSetNewSize(7);
	cout << c_tab2.iGetSize();	
}

//TASK 2
void v_task2() {
	CTable c_tab_0, c_tab_1, c_tab_2;
	c_tab_0.bSetNewSize(3);
	c_tab_0.vSetValueAt(0, 5);
	c_tab_0.vSetValueAt(1, 6);
	c_tab_0.vSetValueAt(2, 7);

	c_tab_1.bSetNewSize(2);
	c_tab_1.vSetValueAt(0, 1);
	c_tab_1.vSetValueAt(1, 2);

	c_tab_2 = c_tab_0 + c_tab_1;
	c_tab_2.vPrint();
}

//TASK 3
void v_task3() {
	CTreeStatic c_tree;
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(3);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(4);

	c_tree.vPrintTree();
	cout << endl;	
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << endl;
	c_tree.bMoveSubtree(c_tree.pcGetRoot()->pcGetChild(1), c_tree.pcGetRoot()->pcGetChild(0));
	c_tree.vPrintTree();
	cout << endl;

	//cout << c_tree.iGetTreeHeight(c_tree.pcGetRoot());

	CTreeDynamic<int>* c_tree_dynamic = new CTreeDynamic<int>();
	c_tree_dynamic->pcGetRoot()->vAddNewChild();
	c_tree_dynamic->pcGetRoot()->vAddNewChild();
	c_tree_dynamic->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree_dynamic->pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree_dynamic->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_dynamic->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_dynamic->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(3);
	c_tree_dynamic->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(4);

	c_tree_dynamic->vPrintTree();
	cout << endl;
	c_tree_dynamic->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << endl;
	c_tree_dynamic->bMoveSubtree(c_tree_dynamic->pcGetRoot()->pcGetChild(1), c_tree_dynamic->pcGetRoot()->pcGetChild(0));
	c_tree_dynamic->vPrintTree();
	cout << endl;
	delete c_tree_dynamic;
}

//TASK 5
void v_task5_1() {
	int* pi_val = new int(5);	
	CMySmartPointer<int> c_my_pointer(pi_val), c_my_pointer2;
	c_my_pointer2 = c_my_pointer;
	//cout << c_my_pointer2.iGetCount() << c_my_pointer.iGetCount() << endl;
	c_my_pointer.vResetSmartPointer();
	c_my_pointer2.vResetSmartPointer();
	//cout << c_my_pointer2.iGetCount()  << c_my_pointer.iGetCount() << endl;
}
CTable cCreateTable() {
	CTable c_result;
	c_result.bSetNewSize(5);
	return move(c_result);
}
void v_task5_2() {
	//CTable c_tab = cCreateTable();
	CTable c_tab1;
	CTable c_tab2;
	c_tab2.vSetName("Tab2");
	c_tab1 = (c_tab2);
}

//Binary Tree with struct
void v_binary_tree() {
	CBtree c_btree;
	c_btree.psGetRoot()->vAddLeft();
	c_btree.psGetRoot()->vAddRight();

	c_btree.psGetRoot()->psGetRight()->vAddLeft();
	c_btree.psGetRoot()->psGetRight()->psGetLeft()->vAddLeft();
	
	cout << c_btree.iGetTreeHeight(c_btree.psGetRoot());
	//c_btree.vPrintTree(c_btree.psGetRoot());
}

//Binary Search Tree with insertion, deletetion and search operations
void v_bst() {
	BinarySearchTree tree;
	tree.insert(20);
	tree.insert(30);
	tree.insert(9);
	tree.insert(8);
	tree.insert(12);
	//tree.preOrder(tree.getRoot());
	//cout << endl;
	tree.remove(30);
	cout << tree.getTreeHeight(tree.getRoot());
	//tree.preOrder(tree.getRoot());
}

bool myCmp(const int& a, const int& b) {
	return a > b;
}
struct myCmp2 {
	bool operator()(const int& a, const int& b) const {
		return a > b;
	}
};
//Dictionaries
void v_dictionaries() {
	//map<int, int, myCmp2> my_map;
	map<int, int, decltype(myCmp)*> my_map(myCmp);
	//map<int, int>::iterator it;
	my_map[3] = 5;
	my_map.insert({ 4, 6 });
	for (auto it = my_map.begin(); it != my_map.end(); ++it)
		cout << it->first << ' ' << it->second << endl;

	set<int> my_set;
	my_set.insert(15);
	my_set.insert(22);
	for (auto v : my_set)
		cout << v << endl;
}

class Animal {
public:
	Animal() {
		color = "default";
		weight = 0;
	}
	Animal(string sColor, double dWeight) {
		color = sColor;
		weight = dWeight;
	}
	virtual ~Animal() {
		cout << "Animal destructor called\n";
	}
	void printColorAndWeight() {
		cout << "Color: " << color << ", weight = " << weight << endl;
	}
	virtual void speak() = 0;
protected:
	string color;
	double weight;
};

class Dog : public Animal {
public:
	Dog() : Animal() {};
	Dog(string sColor, double dWeight, string sBreed) : Animal(sColor, dWeight) {
		breed = sBreed;
	}
	~Dog() {
		cout << "Dog destructor called\n";
	}
	string getBreed() {
		return breed;
	}
	void speak() {
		cout << "Woof woof!";
	}
private:
	string breed;
};

//Class inheritance
void v_inheritance() {
	/*
	Dog my_dog("white", 5.5, "Yorkshire");
	my_dog.printColorAndWeight();
	cout << my_dog.getBreed();*/
	Animal* my_animal = new Dog("black", 6.6, "Ahihi");
	my_animal->printColorAndWeight();
	delete my_animal;
}

double compute(double x) {
	double res = 0;
	for (int i = 0; i < 10000000; i++)
		res += sin(x + i);
	return res;
}
void compute2(double x, double& res) {
	res = 0;
	for (int i = 0; i < 10000000; i++)
		res += sin(x + i);
}
//Multithreading
void v_multithreading() {
	vector<double> inputs = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<double> results1;
	vector<double> results2(inputs.size());
	//Single thread
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < inputs.size(); i++)
		results1.push_back(compute(inputs[i]));
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Results: ";
	for (int i = 0; i < inputs.size(); i++)
		cout << results1[i] << ' ';
	cout << endl;
	cout << "Computational time 1: " << duration / 1000.0 << 's' << endl;

	//Multiple threads
	vector<thread*> threads;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < inputs.size(); i++) {
		thread* new_thread = new thread(compute2, inputs[i], ref(results2[i]));
		threads.push_back(new_thread);
	}
	for (auto thread : threads)
		thread->join();
	stop = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Results: ";
	for (int i = 0; i < inputs.size(); i++)
		cout << results2[i] << ' ';
	cout << endl;
	cout << "Computational time 2: " << duration / 1000.0 << 's' << endl;
}

class MyClass {
	static int object_count;
public:
	int m;
	static int getCount() {
		return object_count;
	}
};
int MyClass::object_count = 5;
//Define
void v_define() {	
	cout << MyClass::getCount();
}
int main() {
	//v_task1_1();
	//v_task1_2();
	//v_task1_3();
	//v_task2();
	//v_task3();		
	//v_task5_1();
	//v_task5_2();
	//v_binary_tree();	
	//v_bst();
	//v_dictionaries();
	//v_inheritance();
	//v_multithreading();
	v_define();
	return 0;
}