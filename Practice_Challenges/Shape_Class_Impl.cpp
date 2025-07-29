//Shape class implementation -  system design practice

#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Point2D
{
private:
	double m_x, m_y;

public:
	Point2D(double x, double y) :m_x(x), m_y(y){ }
	~Point2D() {}
	void setX(const int x) { m_x = x; }
	void setY(const int y) { m_y = y; }

	double GetX() const { return m_x; }
	double GetY() const { return m_y; }

	void Print() const 
	{
		cout << "X = " << m_x << " Y = " << m_y << " ";
	}

	friend ostream& operator<<(ostream& out, const Point2D& point);
};

ostream& operator<<(ostream& out, const Point2D& point)
{
	out <<" (X = "<< point.GetX() << ", " <<"Y = " << point.GetY() << ")" <<" ";
	return out;
}

class IShape
{
private:

public:
	IShape(){ }
	virtual ~IShape() {}

	virtual void Draw() const = 0;
};

class Line :public IShape
{
private:
	Point2D p1, p2;

public:
	//Line(Point2D point1, Point2D point2): p1(point1), p2(point2){ }
	
	//Pass Point2D by const reference to avoid unnecessary copies:
	Line(const Point2D& point1, const Point2D& point2) : p1(point1), p2(point2) {}

	~Line(){ }
	void Draw() const
	{
		cout <<"Line is drawn from  point" << p1 <<"to point" << p2 << endl;
	}
};

class Rectangle :public IShape
{
private:
	Point2D p1, p2, p3, p4;

public:
	//Pass Point2D by const reference to avoid unnecessary copies:
	Rectangle(const Point2D& point1, const Point2D& point2, const Point2D& point3, const Point2D& point4) : p1(point1), p2(point2), p3(point3), p4(point4) {}
	~Rectangle() {}
	void Draw() const
	{
		cout << "Rectangle is drawn using  points" << p1 << ", " << p2 <<"," << p3<<", "<<p4<< endl;
	}
};

//Values are scoped inside the enum name
//Can not be implicitely converted to int
enum class ShapeType
{
	Line, 
	Rectangle
};


//Values are injected into the enclosing scope
// Con be implicitely converted to int
//enum ShapeType
//{
//	Line,
//	Rectangle
//};

class IShapeFactory
{
public:
	IShapeFactory(){ }
	~IShapeFactory(){ }
	//virtual std::unique_ptr<IShape> Create(ShapeType type, vector<Point2D>& listOfPoints) = 0;
	virtual std::unique_ptr<IShape> Create(vector<Point2D>& listOfPoints) = 0;
};

class LineFactory :public IShapeFactory
{
public:
	LineFactory(){ }
	~LineFactory(){ }
	std::unique_ptr<IShape> Create(vector<Point2D>& listOfPoints)
	{
		std::unique_ptr<IShape> linePtr = nullptr;
		if (listOfPoints.size() == 2)
		{
			linePtr = make_unique<Line>(listOfPoints[0], listOfPoints[1]);

		}
		return linePtr;
	}
};

class RectangleFactory :public IShapeFactory
{
public:
	RectangleFactory() {}
	~RectangleFactory() {}
	std::unique_ptr<IShape> Create(vector<Point2D>& listOfPoints)
	{
		std::unique_ptr<IShape> rectPtr = nullptr;
		if (listOfPoints.size() == 4)
		{
			rectPtr = make_unique<Rectangle>(listOfPoints[0], listOfPoints[1], listOfPoints[2], listOfPoints[3]);

		}
		return rectPtr;
	}
};

int main()
{
	Point2D p1(2.5, 3.5);
	Point2D p2(4.5, 5.5);
	//IShape* lineShape = new Line(p1, p2);
	//lineShape->Draw();
	//delete lineShape;

	//Make use of smart pointers
	/*std::unique_ptr<IShape> lineShape = make_unique<Line>(p1, p2);
	lineShape->Draw();*/

	//Using factory method
	std::vector<Point2D> listOfPointsForLine = { p1, p2 };
	//IShapeFactory* shapeFactory = new lineFactory();
	std::unique_ptr<IShapeFactory> shapeFactory = make_unique<LineFactory>();
	std::unique_ptr<IShape> linePtr = shapeFactory->Create(listOfPointsForLine);
	linePtr->Draw();

	Point2D p3(7.5, 3.5);
	Point2D p4(9.5, 5.5);
	/*IShape* rectShape = new Rectangle(p1, p2, p3, p4);
	rectShape->Draw();
	delete rectShape;*/

	//Using smart pointers
	/*std::unique_ptr<IShape> rectShape = make_unique<Rectangle>(p1, p2, p3, p4);
	rectShape->Draw();*/


	//Using factory
	//delete shapeFactory;
	//shapeFactory = new RectangleFactory();
	std::unique_ptr<IShapeFactory> shapeFactory_rect = make_unique<RectangleFactory>();
	std::vector<Point2D> listOfPointsForRectangle = { p1, p2, p3, p4 };
	std::unique_ptr<IShape> rectPtr = shapeFactory_rect->Create(listOfPointsForRectangle);
	rectPtr->Draw();

	return 0;
}

