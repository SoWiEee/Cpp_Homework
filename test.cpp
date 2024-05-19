#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class DArray{
private:
    int size, used;
    double *arr;  // dynamic array

public:
    // constructor
    DArray(): arr(nullptr), size(0), used(0){}
    DArray(double *a, int size_val, int used_val){
        size = size_val;
        used = used_val;
        arr = new double[size_val];
		// copy array element
		for (int i = 0; i < used_val; i++) {
			arr[i] = a[i];
		}
		delete[] a;
    }
    DArray(int size_val){
        arr = new double[size_val];
        size = size_val;
        used = 0;
    }

    // accessor
	int get_size() const {
		return size;
	}
	int get_used() const {
		return used;
	}

    // muator
    void set_size(int s){
        size = s;
    }
    void set_used(int u){
        used = u;
    }

    // add new element
	void addElement(double element) {
		if (!(size == used)) {
			arr[used] = element;
			used ++;
		}
		else{
            cout << "[X] The array is full!" << endl;
        }
	}

    // overload function
    DArray operator+(DArray &arr){  // FINISH!!
        int new_used = 0;
        int new_size = this->size + arr.size;
        double *a = new double[new_size];   // temp array

        // add obj1 element to new
        for(int i = 0; i < this->size; i++){
            a[new_used] = this->arr[i];
			new_used++;
        }
        // add obj2 element to new
        for(int i = 0; i < arr.get_size(); i++){
            a[new_used] = arr.arr[i];
			new_used++;
        }
        return DArray(a, new_size, new_used);
    }

    double& operator[](int index){
        // should validate!
        return arr[index];
    }
};

// display last element
void showLastElement(DArray& arr){
    if (arr.get_used() > 0){
        cout << arr[arr.get_size()-1];
    }else{
        cout << "[X] The object don't have any element!" << endl;
    }
}

int main(void){
    double num;
    DArray firstPFA(5);
	DArray secondPFA(10);
	DArray thirdPFA;

    // input hint
    cout << "[*] Enter 2 double for firstPFA" << endl;
    for(int i = 0; i < 2; i++){
        cout << "Enter a double=> ";
        cin >> num;
        firstPFA.addElement(num);
    }
    cout << "[*] Enter 4 double for secondPFA" << endl;
    for(int i = 0; i < 4; i++){
        cout << "Enter a double=> ";
        cin >> num;
        secondPFA.addElement(num);
    }

    thirdPFA = firstPFA + secondPFA;
    thirdPFA.set_size(thirdPFA.get_used()*2);

    cout << "[*] Info of thirdPFA" << endl;
    cout << "size: " << thirdPFA.get_size() << endl;
    cout << "used: " << thirdPFA.get_used() << endl;
    cout << "list: ";
    for (int i = 0; i < thirdPFA.get_used(); i++) {
		cout << thirdPFA[i];
		if (i != thirdPFA.get_used())
			cout << " ";
	}
    cout << "last element: ";
    showLastElement(thirdPFA);

    system("pause");
    return 0;
}

