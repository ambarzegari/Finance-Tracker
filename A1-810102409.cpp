#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Category
{
    string name;
    map<string, vector<int>> SubCategory;
};

vector<Category> NEW_CATEGORY(vector<Category> Cat)
{
    string line;
    string CategoryName;
    string SubcategoryName;
    cin >> CategoryName;

    Category NewCategory;
    NewCategory.name = CategoryName;
    NewCategory.SubCategory["sundries"];

    getline(cin, line);

    while (line.size() > 0)
    {
        SubcategoryName = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1) - 1);
        line = line.substr(SubcategoryName.size() + 1, 1000);
        NewCategory.SubCategory[SubcategoryName];
        SubcategoryName = "";
    }

    Cat.push_back(NewCategory);

    return Cat;
}

vector<Category> ADD_EXPENSE(vector<Category> Cat)
{

    string Input;
    string CategoryName;
    string SubCategoryname;

    int amount;

    cin >> Input;
    cin >> amount;

    if (Input.find("/") != string::npos)
    {
        CategoryName = Input.substr(0, Input.find("/"));
        SubCategoryname = Input.substr(Input.find("/") + 1, 1000);

        for (int i = 0; i < Cat.size(); i++)
        {
            if (Cat[i].name == CategoryName)
            {
                for (map<string, vector<int>>::iterator it = Cat[i].SubCategory.begin(); it != Cat[i].SubCategory.end(); it++)
                {
                    if (it->first == SubCategoryname)
                    {
                        it->second.push_back(amount);
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < Cat.size(); i++)
        {
            if (Cat[i].name == Input)
            {
                Cat[i].SubCategory["sundries"].push_back(amount);
            }
        }
    }
    return Cat;
}

vector<Category> REPORT(vector<Category> Cat)
{

    map<string, int> Total;
    int SumAmountCat = 0;
    int SumAmountSubCat = 0;

    for (int i = 0; i < Cat.size(); i++)
    {

        for (map<string, vector<int>>::iterator it = Cat[i].SubCategory.begin(); it != Cat[i].SubCategory.end(); it++)
        {

            for (int j = 0; j < it->second.size(); j++)
            {
                if (j == 0)
                {
                    Total[it->first];
                }
                SumAmountSubCat = SumAmountSubCat + it->second[j];
            }
            Total[it->first] = SumAmountSubCat;

            SumAmountCat = SumAmountCat + SumAmountSubCat;
            SumAmountSubCat = 0;
        }

        cout << "category: " << Cat[i].name << "\n";
        cout << "Total expenses: " << SumAmountCat << "\n";
        cout << "Subcategories expenses:" << "\n";

        for (map<string, vector<int>>::iterator it = Cat[i].SubCategory.begin(); it != Cat[i].SubCategory.end(); it++)
        {

            if (it->first != "sundries")
            {
                cout << "    - " << it->first << ": " << Total[it->first] << "\n";
            }
            SumAmountSubCat = 0;
        }

        if (i != Cat.size() - 1)
        {
            cout << "----------" << "\n";
        }

        Total.clear();
        SumAmountCat = 0;
    }

    cout << "**********" << "\n";

    return Cat;
}

vector<Category> REMOVE_EXPENSE(vector<Category> Cat)
{
    string Input;
    string CategoryName;
    string SubCategoryname;


    cin >> Input;

    if (Input.find("/") != string::npos)
    {
        CategoryName = Input.substr(0, Input.find("/"));
        SubCategoryname = Input.substr(Input.find("/") + 1, 1000);

        for (int i = 0; i < Cat.size(); i++)
        {
            if (Cat[i].name == CategoryName)
            {
                for (map<string, vector<int>>::iterator it = Cat[i].SubCategory.begin(); it != Cat[i].SubCategory.end(); it++)
                {
                    if (it->first == SubCategoryname)
                    {
                        it->second.pop_back();
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < Cat.size(); i++)
        {
            if (Cat[i].name == Input)
            {
                Cat[i].SubCategory["sundries"].pop_back();
            }
        }
    }
    return Cat;
}

int main()
{
    system("clear");

    vector<Category> Cat;
    string input;

    while (cin >> input)
    {
        system("clear");

        if (input == "new_category")
        {
            Cat = NEW_CATEGORY(Cat);
        }
        else if (input == "add_expense")
        {
            Cat = ADD_EXPENSE(Cat);
        }
        else if (input == "remove_expense")
        {
            Cat = REMOVE_EXPENSE(Cat);
        }

        else if (input == "report")
        {
            Cat = REPORT(Cat);
        }
    }

    return 0;
}