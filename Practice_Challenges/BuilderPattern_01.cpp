#include<iostream>
#include<memory>
using namespace std;

class Meal
{
private:
	string mainDish;
	string sideDish;
	string drink;
public:
	//COnstructor and Destructor
	Meal(){ }
	virtual ~Meal(){ }

	//Setters
	void SetMainDish(string main) { mainDish = main; }
	void SetSideDish(string sides) { sideDish = sides; }
	void SetDrinks(string drinkItem) { drink = drinkItem; }

	//Getters

	string GetMainDish() const { return mainDish; }
	string GetSideDish() const { return sideDish; }
	string GetDrinks() const { return drink; }

	//Methods
	void ShowMeal() const {
		cout << "Meal contains below items " << endl;
		cout << "Main Dish : " << GetMainDish() << endl;
		cout << "Side Dish : " << GetSideDish() << endl;
		cout << "Drinks : " << GetDrinks() << endl;
	}
};


class MealBuilder
{
public:
	std::unique_ptr<Meal> meal;

public:
	MealBuilder(){ }
	virtual ~MealBuilder(){ }

	virtual void createMainDish() = 0;
	virtual void createSideDish() = 0;
	virtual void CreateDrinks() = 0;

	virtual std::unique_ptr<Meal> GetMeal() = 0;
};

class SouthIndianMealBuilder : public MealBuilder
{
public:
	SouthIndianMealBuilder()
	{
		meal = make_unique<Meal>();
	}
	~SouthIndianMealBuilder(){ }

	//Impl
	void createMainDish() { if(meal != nullptr) meal->SetMainDish("Rice"); }
	void createSideDish() { if (meal != nullptr) meal->SetSideDish("Sambar"); }
	void CreateDrinks() { if (meal != nullptr) meal->SetDrinks("ButterMilk"); }
	std::unique_ptr<Meal>  GetMeal() { return move(meal); }
};

class NorthIndianMealBuilder : public MealBuilder
{
public:
	NorthIndianMealBuilder()
	{
		meal = make_unique<Meal>();
	}
	~NorthIndianMealBuilder(){ }

	//Impl
	void createMainDish() { if (meal != nullptr) meal->SetMainDish("Roti"); }
	void createSideDish() { if (meal != nullptr) meal->SetSideDish("Veg Kadai"); }
	void CreateDrinks() { if (meal != nullptr) meal->SetDrinks("Lassi"); }

	std::unique_ptr<Meal> GetMeal() { return move(meal); }
};

class Server
{
public:
	//unique_ptr<Meal> TakeOrderAndSupplyMeal(std::unique_ptr<MealBuilder>& pBuilder)
	//{
	//	pBuilder->createMainDish();
	//	pBuilder->createSideDish();
	//	pBuilder->CreateDrinks();
	//	return move(pBuilder->GetMeal());
	//}

	unique_ptr<Meal> TakeOrderAndSupplyMeal(MealBuilder& builder) {
		builder.createMainDish();
		builder.createSideDish();
		builder.CreateDrinks();
		return builder.GetMeal();
	}

};

int main()
{
	//std::unique_ptr<Server> spServer = make_unique<Server>();
	//std::unique_ptr<MealBuilder> spMealBuilder = make_unique<NorthIndianMealBuilder>();
	//if (spServer != nullptr)
	//{
	//	std::unique_ptr<Meal> spMeal = spServer->TakeOrderAndSupplyMeal(move(spMealBuilder));
	//	spMeal->ShowMeal();

	//}

	std::unique_ptr<Server> server = std::make_unique<Server>();

	//NorthIndianMealBuilder northBuilder;
	//auto meal1 = server.TakeOrderAndSupplyMeal(northBuilder);
	//meal1->ShowMeal();

	//SouthIndianMealBuilder southBuilder;
	//auto meal2 = server.TakeOrderAndSupplyMeal(southBuilder);
	//meal2->ShowMeal();

	std::unique_ptr<MealBuilder> southMealBuilder = std::make_unique<SouthIndianMealBuilder>();
	std::unique_ptr<Meal> meal = server->TakeOrderAndSupplyMeal(*southMealBuilder);
	meal->ShowMeal();



	return 0;
}