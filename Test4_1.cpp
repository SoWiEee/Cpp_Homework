#include <iostream>
#include <string>
using namespace std;

// parnet - 銷售商品
class Sale{
public:
    // constructor
    Sale(): price(0){ item = "" ;}
    Sale(string theItem, double thePrice){
        item = theItem;
        if (thePrice >= 0)
            price = thePrice;
        else{
            cout << "Error: Cannot have a negative price!\n";
            exit(1);    // abort
        }
    }

    // getter & setter
    void setItem(string newItem) { item = newItem; }
    string getItem() const { return item; }
    void setPrice(double newPrice){
        if (newPrice >= 0)
            price = newPrice;
        else{
            cout << "Error: Cannot have a negative price!\n";
            exit(1);    // abort
        }
    }
    double getPrice() const { return price; }

    // 回傳商品價格
    double bill() const { return price; }
    // 回傳價差
    double savings(const Sale& other) const {
        return (bill() - other.bill());
    }

    void PrintInfo(){
        cout << "item : " << getItem() << endl;
        cout << "price : $" << getPrice() << endl;
        cout << "----------------------------------" << endl;
    }
    
private:
    string item;    // 名稱
	double price;   // 價格
};

// overloading
bool operator < (const Sale& first, const Sale& second){
        return (first.bill() < second.bill());
}

// child - 折扣商品
class DiscountSale: public Sale {
public:
    // constructor
    DiscountSale() : Sale(), discount(0){}
    DiscountSale(string theItem, double thePrice, double theDiscount)
        : Sale(theItem, thePrice), discount(theDiscount){}

    void setDiscount(double newDiscount) { discount = newDiscount; }

    double getDiscount() const { return discount; }

    // 回傳打折後的價格
    double bill() const {
        double f = discount / 100;
        return (1-f) * getPrice();
    }

    void PrintInfo(){
        cout << "item : " << getItem() << endl;
        cout << "price : $" << getPrice() << endl;
        cout << "discount : " << getDiscount() << "%" << endl;
        cout << "price after discount : $" << bill() << endl;
        cout << "----------------------------------" << endl;
    }

private:
	double discount;    // 折扣係數
};


int main(void){
	Sale sale("Sport Shoes", 10.0);                               
	DiscountSale discount("Sport Shoes", 12.0, 15);
	DiscountSale discount2("Sport Shoes", 15.0, 35);

    // 找出最便宜的商品
	if(sale < discount && sale < discount2){
		cout << "[*] Sale item is the cheapest.\n\n";
	}
	else if(discount < sale && discount < discount2){
		cout << "[*] Discounted item 1 is the cheapest.\n\n";
	}
	else{
		cout << "[*] Discounted item 2 is the cheapest.\n\n";
	}

	sale.PrintInfo();
	if(discount < sale){
		cout << "Discounted item 1 is cheaper than Sale item.\n";
		cout << "Savings is $" << sale.savings(discount) << endl << endl;
	}
	else{
		cout << "Discounted item 1 is not cheaper than Sale item.\n";
		discount.PrintInfo();	
	}

	if(discount2 < sale){
		cout << "Discounted item 2 is cheaper than Sale item.\n";
		cout << "Savings is $" << sale.savings(discount2) << endl << endl;
	}
	else{
		cout << "Discounted item 2 is not cheaper than Sale item.\n";
		discount2.PrintInfo();	
	}

	system("pause");
	return 0;
}