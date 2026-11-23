#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void inputItems(vector<string> &pro_name, vector<string> &pro_type,
                vector<double> &pro_price, vector<int> &pro_stocks) {
  int count = 0, stock;
  bool isRunning = true;
  string name, type;
  double price;
  while (isRunning) {
    cout << "How many items do you want to add? ";
    cin >> count;

    if (count < 0) {
      cout << "Input again!!";
    } else {
      for (int i = 1; i <= count; i++) {
        cout << "================= ITEM " << i << " =================\n";
        cout << "   Enter item name   :  ";
        cin >> name;
        cout << "   Enter item type   :  ";
        cin >> type;
        cout << "   Enter item price  : $";
        cin >> price;
        cout << "   Enter item stock  :  ";
        cin >> stock;

        pro_name.push_back(name);
        pro_type.push_back(type);
        pro_price.push_back(price);
        pro_stocks.push_back(stock);
      }
      if (count == 1) {
        cout << "Item Added Seccesfully! \n";
      } else {
        cout << "Items Added Seccesfully! \n";
      }
      isRunning = false;
    }
  }
}

void displayItems(vector<string> &pro_name, vector<string> &pro_type,
                  vector<double> &pro_price, vector<int> &pro_stocks) {
  cout << "============================== CAFE MENU "
          "==============================\n";
  cout << "No.\tItem Name\t\tType\t\tPrice\t\tStock\n";
  cout << "--------------------------------------------------------------------"
          "---\n";

  for (int i = 0; i < (int)pro_stocks.size(); i++) {
    cout << (i + 1) << "\t" << pro_name[i] << "\t\t\t" << pro_type[i] << "\t\t$"
         << fixed << setprecision(2) << pro_price[i] << "\t\t" << pro_stocks[i]
         << endl;
  }

  cout << "===================================================================="
          "===\n";
}

void FoundItem(int i, vector<string> &pro_name, vector<string> &pro_type,
               vector<double> &pro_price, vector<int> &pro_stocks) {
  cout << "Name   : " << pro_name[i] << endl;
  cout << "Type   : " << pro_type[i] << endl;
  cout << "Price  : $" << fixed << setprecision(2) << pro_price[i] << endl;
  cout << "Stock  : " << pro_stocks[i] << endl;
  cout << "=================================\n";
}

void searchItems(vector<string> &pro_name, vector<string> &pro_type,
                 vector<double> &pro_price, vector<int> &pro_stocks) {
  bool isRunning = true;
  while (isRunning) {
    int option;
    cout << "\n1. Search by name\n";
    cout << "2. Search by type\n";
    cout << "3. Search by price\n";
    cout << "4. Search by stock\n";
    cout << "5. Back\n";
    cout << "Enter search option : ";
    cin >> option;

    bool isFound = false;

    switch (option) {
    case 1: {
      string name;
      cout << "Enter item name : ";
      cin >> name;
      for (int i = 0; i < (int)pro_stocks.size(); i++) {
        if (name == pro_name[i]) {
          isFound = true;
          cout << "========== Item found ===========\n";
          FoundItem(i, pro_name, pro_type, pro_price, pro_stocks);
        }
      }
      break;
    }
    case 2: {
      string type;
      cout << "Enter item type : ";
      cin >> type;
      for (int i = 0; i < (int)pro_stocks.size(); i++) {
        if (type == pro_type[i]) {
          isFound = true;
          cout << "======= Item found ========\n";
          FoundItem(i, pro_name, pro_type, pro_price, pro_stocks);
        }
      }
      break;
    }
    case 3: {
      double price;
      cout << "Enter item price : $";
      cin >> price;
      for (int i = 0; i < (int)pro_stocks.size(); i++) {
        if (price == pro_price[i]) {
          isFound = true;
          cout << "======= Item found ========\n";
          FoundItem(i, pro_name, pro_type, pro_price, pro_stocks);
        }
      }
      break;
    }
    case 4: {
      int stock;
      cout << "Enter item stock : ";
      cin >> stock;
      for (int i = 0; i < (int)pro_stocks.size(); i++) {
        if (stock == pro_stocks[i]) {
          isFound = true;
          cout << "======= Item found ========\n";
          FoundItem(i, pro_name, pro_type, pro_price, pro_stocks);
        }
      }
      break;
    }
    case 5:
      isRunning = false;
      continue;
    default:
      cout << "Invalid Option!!!!\n";
      continue;
    }

    if (!isFound) {
      cout << "\n\nItem not found!!!\n";
    }
  }
}

void checkString(vector<string> &pro_name, int index, string newName) {

  if (newName != "0") {
    pro_name[index] = newName;
  }
}

void checkDouble(vector<double> &pro_price, int index, double newPrice) {

  if (newPrice != 0) {
    pro_price[index] = newPrice;
  }
}

void checkInt(vector<int> &pro_stock, int index, int newStock) {

  if (newStock != 0) {
    pro_stock[index] = newStock;
  }
}

void updateItem(vector<string> &pro_name, vector<string> &pro_type,
                vector<double> &pro_price, vector<int> &pro_stocks) {
  bool isRunning = true;
  while (isRunning) {
    string name, newName, newType;
    double newPrice;
    int newStock;
    bool isFound = false;
    cout << "Enter Item Name to Update (0 to exit): ";
    cin >> name;
    if (name == "0")
      isRunning = false;
    else {
      for (int i = 0; i < (int)pro_stocks.size(); i++) {
        if (name == pro_name[i]) {
          isFound = true;
          cout << "============ OLD INFORMATION =============\n";
          FoundItem(i, pro_name, pro_type, pro_price, pro_stocks);
          cout << "========== UPDATE INFORMATION ==========\n";
          cout << "Enter New Item Name (0 for no update)  : ";
          cin >> newName;
          cout << "Enter New Item Type (0 for no update)  : ";
          cin >> newType;
          cout << "Enter New Item Price (0 for no update) : $";
          cin >> newPrice;
          cout << "Enter New Item Stock (0 for no update) : ";
          cin >> newStock;

          checkString(pro_name, i, newName);
          checkString(pro_type, i, newType);
          checkDouble(pro_price, i, newPrice);
          checkInt(pro_stocks, i, newStock);

          cout << "\n\nItem Updated Successfully\n\n";
        }
      }

      if (!isFound) {
        cout << "\n\nItem not found!!!!\n";
      }
    }
  }
}

void deleteItem(vector<string> &pro_name, vector<string> &pro_type,
                vector<double> &pro_price, vector<int> &pro_stocks) {
  bool isRunning = true;
  while (isRunning) {
    string selectItem;
    bool isFound = false;
    cout << "Enter Item Name to Delete (0 to exit): ";
    cin >> selectItem;

    if (selectItem == "0") {
      isRunning = false;
    } else {
      for (int i = 0; i < (int)pro_stocks.size(); i++) {
        if (selectItem == pro_name[i]) {
          isFound = true;
          cout << "======= Item found ========\n";
          FoundItem(i, pro_name, pro_type, pro_price, pro_stocks);
          pro_name.erase(pro_name.begin() + i);
          pro_type.erase(pro_type.begin() + i);
          pro_price.erase(pro_price.begin() + i);
          pro_stocks.erase(pro_stocks.begin() + i);

          cout << "Item Deleted Seccussfully!!!!!!\n";
        }
      }

      if (!isFound) {
        cout << "\n\nItem not found!!!!\n";
      }
    }
  }
}

int main() {
  vector<string> pro_name;
  vector<string> pro_type;
  vector<double> pro_price;
  vector<int> pro_stocks;

  pro_name.push_back("Cafe");
  pro_type.push_back("Drink");
  pro_price.push_back(2.00);
  pro_stocks.push_back(12);

  pro_name.push_back("Pizza");
  pro_type.push_back("Food");
  pro_price.push_back(5.00);
  pro_stocks.push_back(23);

  pro_name.push_back("Tea");
  pro_type.push_back("Drink");
  pro_price.push_back(1.50);
  pro_stocks.push_back(18);

  pro_name.push_back("Cake");
  pro_type.push_back("Dessert");
  pro_price.push_back(3.50);
  pro_stocks.push_back(8);

  bool isRunning = true;

  while (isRunning) {
    int option;
    cout << "============================================\n";
    cout << "          CAFE MENU MANAGEMENT SYSTEM\n";
    cout << "============================================\n";
    cout << "1. Insert New Item\n";
    cout << "2. Display All Items\n";
    cout << "3. Search Item\n";
    cout << "4. Update Item\n";
    cout << "5. Delete Item\n";
    cout << "6. Exit\n";
    cout << "============================================\n\n";
    cout << "Choose Option: ";
    cin >> option;

    switch (option) {
    case 1:
      inputItems(pro_name, pro_type, pro_price, pro_stocks);
      break;
    case 2: {
      displayItems(pro_name, pro_type, pro_price, pro_stocks);
      break;
    }

    case 3: {
      searchItems(pro_name, pro_type, pro_price, pro_stocks);
      break;
    }

    case 4: {
      updateItem(pro_name, pro_type, pro_price, pro_stocks);
      break;
    }

    case 5: {
      deleteItem(pro_name, pro_type, pro_price, pro_stocks);
      break;
    }

    case 6: {
      cout << "Exit the program!!!";
      isRunning = false;
      break;
    }

    default: {
      cout << "Invalid input!!!\n";
      break;
    }
    }
  }

  return 0;
}
