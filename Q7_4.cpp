#include <iostream>
#include <vector>

using namespace std;

class HotDogStand {
    public:
        HotDogStand(int ID, int soldOut): ID(ID), soldOut(soldOut){
            totalSold += soldOut;
        }
        // defalut
        HotDogStand() {}
        int getID() { return ID; }
        int getsoldOut(){ return soldOut; }
        static int getTotalSold() { return totalSold; }
        void JustSold() {
            soldOut++;
            totalSold++;
        }

    private:
        int ID;
        int soldOut;
        static int totalSold;

};

// shared variable
int HotDogStand::totalSold = 0;

int main(void) {
	srand(time(NULL));  // set seed
	int i, j;
    
	vector<HotDogStand> HotDogStands(0);

	for (i = 0; i < 3; i++) {
		HotDogStand temp(i + 1, 0);
		HotDogStands.push_back(temp);
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < rand() % 100; j++)
			HotDogStands[i].JustSold();
	}

	cout << "[SOLD OUT AMOUNT]" << endl;
	for (i = 0; i < 3; i++){
        cout << "Stand" << HotDogStands[i].getID() << ": " << HotDogStands[i].getsoldOut() << endl;
    }
		
	cout << "Total: " << HotDogStand::getTotalSold() << endl;

	system("pause");
	return 0;
}