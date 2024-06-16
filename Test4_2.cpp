#include <string>
#include <iostream>
using namespace std;

// parent - 圖案
class Figure{
public:
    // constructor
	Figure(): color(""){} 
	Figure(string theColor): color(theColor){}

    // getter & setter
	void setColorsetColor(string newColor){ color = newColor;}
	string getColor() const { return color; }
	void setRate(double newRate){ rate = newRate; }
	double getRate() const { return rate; }

	virtual void printinfo(){
        cout << "color: " << getColor() << endl;
        cout << "rate: " << getRate() << endl;
    }

    // 計算面積，預設為 0
	virtual double compArea(){ return 0; }
    // 計算周長，預設為 0
	virtual double compPerimeter(){ return 0; }
    // 計算價格
	virtual double compPrice(){ return rate * compArea(); }

private:
	string color;
	double rate;
};


// child - 長方形
class Rectangle : public Figure{
public:
    // constructor
	Rectangle(): Figure(), width(1), height(1){}
	Rectangle(string theColor, double theWidth, double theHeight): Figure(theColor), width(theWidth), height(theHeight){}
    
    // getter & setter
	void setWidth(double newWidth) { width = newWidth; }
	double getWidth() const { return width; }
	void setHeight(double newHeight) { height = newHeight; }
	double getHeight() const { return height; }
	string getClass() const { return "Rectangle"; }

	virtual void printinfo(){
        cout << "class: " << getClass() << endl;
        cout << "color: " << getColor() << endl;
        cout << "width: " << getWidth() << ", height: " << getHeight() <<endl;
        cout << "area: " << compArea() << endl;
        cout << "perimeter: " << compPerimeter() << endl;
        cout << "price: " << compPrice() << ", with rate= " << getRate() << endl;
        cout << "------------------------------------------------" << endl;
    }
    // 計算面積
	virtual double compArea() { return width * height; }
    // 計算周長
	virtual double compPerimeter() { return (width + height) * 2; }
    // 計算價錢
	virtual double compPrice() { return getRate() * compArea(); }

private:
	double height;
	double width;
};


class Point {
public:
    // constructor
	Point(): x(0), y(0){}
	Point(int theX, int theY): x(theX), y(theY){}
    
    // getter & setter
	void setX(int newX) { x = newX; }
	int getX() const { return x; }
	void setY(int newY) { y = newY; }
	int getY() const { return y; }

private:
	int x;
	int y;
};

// child - 圓形
class Circle : public Figure{
public:
    // constructor
	Circle(): Figure(), radius(1), center(0,0){}
	Circle(string theColor, double theRadius, Point theCenter): Figure(theColor), radius(theRadius), center(theCenter){}

    // getter & setter
	void setRadius(double newRadius) { radius = newRadius; }
	double getRadius() const { return radius; }
	void setCenter(Point newCenter) { center = newCenter; }
	Point getCenter() const { return center; }
	string getClass() const { return "Circle"; }

	virtual void printinfo(){
        cout << "class: " << getClass() << endl;
        cout << "color: " << getColor() << endl;
        cout << "center: (" << getCenter().getX() << "," << getCenter().getY() << ")"<< endl;
        cout << "radius: " << getRadius() <<endl;
        cout << "area: " << compArea() << endl;
        cout << "perimeter: " << compPerimeter() << endl;
        cout << "price: " << compPrice() << ", with rate= " << getRate() << endl;
        cout << "------------------------------------------------" << endl;
    }
    // 計算面積
	virtual double compArea() { return radius * radius * 3.14; }
	// 計算周長
    virtual double compPerimeter() { return radius * 2 * 3.14; }
	// 計算價格
    virtual double compPrice() { return getRate() * compArea(); }

private:
	double radius;  // 半徑
	Point center;   // 圓心
};

void listFig(Figure* fig){
	fig -> printinfo();
}

int main(void){
	Figure* f[5];
    
	f[0] = new Rectangle("RED", 10.2, 3.6);
	f[1] = new Rectangle("ORANGLE", 14, 8.1);
	f[2] = new Rectangle("BLUE", 12.8, 60.6);
	f[3] = new Circle("PINK", 10.5, Point(12,20));
	f[4] = new Circle("PURPLE", 6.4, Point(14,3));

	f[0] -> setRate(2.4);
	f[1] -> setRate(2.4);
	f[2] -> setRate(2.4);
	f[3] -> setRate(3.2);
	f[4] -> setRate(3.2);

	for(int i = 0; i < 5; i++){
        listFig(f[i]);
    }
	system("pause");
	return 0;
}