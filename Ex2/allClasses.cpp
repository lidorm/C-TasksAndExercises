#include "allClasses.h"


//*************************************************************************************
//point
//*************************************************************************************

//getters
//*******

int Point::getX() const
{
	return this->_x;
}

int Point::getY() const
{
	return this->_y;
}



//setters
//*******

void Point::setX(int x)
{
	this->_x = x;
}

void Point::setY(int y)
{
	this->_y = y;
}

void Point::setPoint(int x, int y)
{
	this->setX(x);
	this->setY(y);
}

void Point::setPoint(const Point & other)
{
	this->setPoint(other.getX(), other.getY());
}

//operstors 
//*********

bool Point::operator==(const Point& other) const
{
	if (_x == other._x && _y == other.getY())
	{
		return true;
	}
	return false;
}

bool Point::operator!=(const Point & other) const
{
	if (this->getX() != other.getX() || this->getX() != other.getY())
		return true;
	return false;
}

Point Point::operator+(int num) const
{
	Point p;
	p.setX(_x + num);
	p.setY(_y + num);
	return p;
}

Point & Point::operator+=(int num)
{
	this->setX(_x + num);
	this->setY(_y + num);

	return *this;
}

Point::operator int() const
{
	return getX() + getY();
}

Point Point::operator+(const Point & other) const
{
	Point p;
	p.setX(this->getX() + other.getX());
	p.setY(this->getY() + other.getY());
	return p;
}

Point Point::operator++(int)
{
	Point p=*this;
	*this += 1;
	return p;
}

Point & Point::operator++()
{
	this->setPoint(this->getX() + 1, this->getY() + 1);
	return *this;
}

 Point operator*(int num, const Point & other)
{
	Point p;
	p.setX(num * other.getX());
	p.setY(num * other.getY());
	return p;
	
}

//**************************************************************************************
//shape
//**************************************************************************************
 int Shape::_totalNumOfShapes = 0;

void Shape::setName(string name)
{
	this->_shapeName = name;
}

void Shape::setCenter(const Point & p)
{
	this->_centerPoint.setPoint(p.getX(), p.getY());
}

string Shape::getName() const
{
	return this->_shapeName;
}

Point Shape::getCenter() const
{
	return this->_centerPoint;
}

void Shape::setShape(string sn, const Point & other)
{
	this->setName(sn);
	this->setCenter((other));

}

int Shape::numOfShapes()
{
	return _totalNumOfShapes;
}

//**************************************************************************************
//Quad
//**************************************************************************************

int Quad::calcArea() const {
	return (int)(_right * _up);
}
int Quad::calcPerimeter() const {
	return (int)(_right + _left + _up + _down);
}
//**************************************************************************************
//Square
//**************************************************************************************

void Square::shiftX(int x)
{
	this->_centerPoint.setX(this->_centerPoint.getX() + x);
}

void Square::shiftY(int y)
{
	this->_centerPoint.setY(this->_centerPoint.getY() + y);
}


//**************************************************************************************
//Circle
//**************************************************************************************

void Circle::setRadius(double r)
{
	this->_radius = r;
}



double Circle::getRadius() const
{
	return this->_radius;
}

int Circle::calcArea() const {
	
	return (int)(PI * ((this->getRadius()) * (this->getRadius())));
}

int Circle::calcPerimeter() const {
	return (int)((2 * PI * (this->getRadius())));
}

Circle operator+(int r, const Circle & other)
{
	Circle c;
	c.setName(other.getName());
	c.setRadius(r + other.getRadius());
	c.setCenter(other.getCenter());

	return c;
}

Circle & Circle::operator=(string name)
{
	this->setName(name);
	return *this;
}

//**************************************************************************************
//ALL shapes
//**************************************************************************************

int allShapes::getSize() const {
	return this->_size;
}

void allShapes::addShape(Shape  *newShape)
{
	int i;
	if (_arr != NULL)
	{
		Shape ** temp = new Shape*[getSize()];

		for (i = 0; i < getSize(); i++)
		{
			temp[i] = _arr[i];
		}

		_arr = new Shape*[getSize() + 1];

		for (i = 0; i < getSize(); i++)
		{
			_arr[i] = temp[i];
		}

		delete[] temp;
	}
	else
	{
		_arr = new Shape*[1];
		i = 0;
	}

	_arr[i] = newShape;
	_size++;
}


void allShapes::removeShape(int index)
{

	//cout << "DELETE SHAPE IN INDEX: " << index << endl;
	delete _arr[index];
	_arr[index] = _arr[getSize() - 1];
	_arr[getSize() - 1] = NULL; // Then, it's okay to delete a NULL in the distructor
	_size--;
}

int allShapes::totalArea() const
{
	int sum = 0;
	for (int i = 0; i < getSize(); i++)
	{
		/*if(_arr[i] != NULL)*/
		   sum += _arr[i]->calcArea();
	}
	return (int)sum;
}

int allShapes::totalPerimeter() const
{
	int sum = 0;
	for (int i = 0; i < getSize(); i++)
	{
		   if (_arr[i] != NULL)
		       sum += _arr[i]->calcPerimeter();
	}
	return (int)sum;
}

int allShapes::totalCircleArea() const {
	int sum = 0;
	for (int i = 0; i < getSize(); i++)
	{
		if (dynamic_cast<Circle*>(this->_arr[i]))
			sum += _arr[i]->calcArea();
	}
	return (int)sum;
}

int allShapes::totalSquarePerimeter() const {
	int sum = 0;
	for (int i = 0; i < getSize(); i++)
	{
		if (dynamic_cast<Square*>(this->_arr[i]))
			sum += _arr[i]->calcPerimeter();
	}
	return (int)sum;
}

allShapes & allShapes:: operator+=(Shape * newS) {
	addShape(newS);
	return *this;
}

Shape * allShapes::operator[](int ind) const {
	return _arr[ind];
}


allShapes allShapes::operator+(const allShapes & other) const
{
	allShapes newallShapes;

		for (int i = 0; i < getSize(); i++)
		{
			newallShapes.addShape(_arr[i]);
		}

		for (int i = 0; i < other.getSize(); i++)
		{
			newallShapes.addShape(other._arr[i]);
		}

		return newallShapes;
}

allShapes::operator int() const
{
		
	return this->getSize();
}


