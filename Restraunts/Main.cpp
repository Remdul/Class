#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class MenuItem
{
public:
    MenuItem();
    MenuItem(const string &init_name, double init_price);
    string foodname;
    double foodprice;
};

class Restraunt
{
public:
    Restraunt();
    Restraunt(string, int, vector<MenuItem>);
    int rating;
    map<string, MenuItem> menu;
    string type;
    string name;
    double averageMenuPrice();
    string ratingScheme();
};

class YalpRestraunts
{
public:
    YalpRestraunts();
    map <string, Restraunt> Restraunts;
    void findFood();
    void listRestraunts();
};

MenuItem::MenuItem(const string &init_name, double init_price)
{
    foodname = init_name;
    foodprice = init_price;
}

Restraunt::Restraunt(string restrauntName, int restrauntRating, vector<MenuItem> restrauntMenuItems)
{
    for (auto Menu_Item : restrauntMenuItems)
    {
        menu[Menu_Item.foodname] = Menu_Item;
    }
    rating = restrauntRating;
    name = restrauntName;
}
void YalpRestraunts::findFood()
{

}
void YalpRestraunts::listRestraunts()
{
    int i = 0;
    for (i = 0; i < )
}
double Restraunt::averageMenuPrice()
{
    double total = 0.0;
    for (auto & itor : menu)
    {
        total += itor.second.foodprice;
    }
    return total / menu.size();
}
string Restraunt::ratingScheme()
{

    return "no";
}
void populateData(YalpRestraunts &yalp)
{
    vector<MenuItem> arbysMenu;
    arbysMenu.push_back(MenuItem("Roast Beef", 5.00));
    arbysMenu.push_back(MenuItem("Milkshake", 1.25));
    yalp.Restraunts["Arbys"]        = Restraunt("Arbys", 5, arbysMenu);

    vector<MenuItem> burgerkingMenu;
    burgerkingMenu.push_back(MenuItem("Burger", 5.25));
    burgerkingMenu.push_back(MenuItem("Milkshake", 2.00));
    yalp.Restraunts["BurgerKing"]        = Restraunt("BurgerKing", 4, burgerkingMenu);

    vector<MenuItem> mcdonaldsMenu;
    mcdonaldsMenu.push_back(MenuItem("Burger", 6.50));
    yalp.Restraunts["McDonalds"]    = Restraunt("McDonalds", 1, mcdonaldsMenu);

    vector<MenuItem> wendysMenu;
    wendysMenu.push_back(MenuItem("Burger", 3.74));
    wendysMenu.push_back(MenuItem("Milkshake", 2.30));
    yalp.Restraunts["Wendys"]       = Restraunt("Wendys", 2, wendysMenu);
}

int main()
{
    YalpRestraunts yalp;
    populateData(yalp);


    return 0;
}
