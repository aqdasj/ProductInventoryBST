//this is main.h file
#include "product.h"

const int MAX {100};

int main ()
{
        table my_table;
        char choice;
        do {
                cout <<"   Menu choice   " << endl;
                cout <<"1. Add new products " << endl;
                cout <<"2. Display the products added" << endl;
		cout <<"3. remove the product by title" << endl;
		cout <<"4. peek at the product by title" << endl;
		cout <<"5. display products with a price range" << endl;
		cout <<"6. display the height of the tree" << endl;
                cout <<"9. Exit " << endl;

                cout << "Please enter your choice form the menus above: ";
                cin >> choice;
                cin.ignore(MAX, '\n');
  
		if(choice == '1') {
                        product new_product;

                        new_product.title = new char[MAX];
                        new_product.description = new char[MAX];
                        new_product.category= new char[MAX];
                        new_product.type= new char[MAX];
                        new_product.sellerID = new char[MAX];
                        new_product.shopName= new char[MAX];
                        
                        cout << "Enter product title: ";
                        cin.get(new_product.title, MAX, '\n');
                        cin.ignore(MAX, '\n');

                        cout << "Enter product description: ";
                        cin.get(new_product.description, MAX, '\n');
                        cin.ignore(MAX, '\n');
                        
                        cout << "Enter the catgory: ";
                        cin.get(new_product.category, MAX, '\n');
                        cin.ignore(MAX, '\n');

                        cout << "Enter the type: ";
                        cin.get(new_product.type, MAX, '\n');
                        cin.ignore(MAX, '\n');

                        cout << "Enter the sellerID: ";
                        cin.get(new_product.sellerID, MAX, '\n');
                        cin.ignore(MAX, '\n');

                        cout << "Enter the shopName: ";
                        cin.get(new_product.shopName, MAX, '\n');
                        cin.ignore(MAX, '\n');

                        cout <<"Enter the price: ";
                        cin >> new_product.price;
                        cin.ignore(MAX, '\n');

                        cout <<"Enter the quantity: ";
                        cin >> new_product.quantity;
                        cin.ignore(MAX, '\n');

			cout << "Enter if the product is sold(0 for yes, 1 for no): ";
                        cin >> new_product.sold;
                        cin.ignore(MAX,'\n');

                        if(my_table.add(new_product.title, new_product)) {
                                cout << "Everything was added successfully." << endl;
                        } else {
                                cout <<"failed to add the all the products." << endl;
                        } 
		}else if(choice == '2') {

                        cout <<"Display all product:";
                        my_table.displayall();
                }else if(choice == '3') {
			char title_test[MAX];

			cout << "Enter the title you want to remove: ";
			cin.get(title_test, MAX, '\n');
			cin.ignore(MAX,'\n');
			
			if(my_table.remove(title_test)) {
				cout << "You have removed a title" << endl;
			} else {
				cout << "You have not removed a title" << endl;
			}
		}else if (choice == '4') {
			char title_peek[MAX];

			product product_found;
			
			cout << "Enter the title of the product to peek: ";
			cin.get(title_peek, MAX, '\n');
			cin.ignore(MAX, '\n');

			if(my_table.peek(title_peek, product_found)) {
				
				cout << "Peek the products" ;
				cout << "Title: " << product_found.title << endl;
				cout << "description: " << product_found.description << endl;
				cout << "category: " <<product_found.category << endl;
				cout << "type: " << product_found.type << endl;
				cout << "price: " << product_found.price << endl;
				cout << "quantity: " << product_found.quantity << endl;
				cout << "seller ID: " << product_found.sellerID << endl;
				cout << "shop name: " << product_found.shopName<< endl;
				cout << "Sold: " << product_found.sold << endl;
			}else {
				cout << "No product found with the title "<< endl;
			}
		} else if( choice == '5') {
			int low = 0;
			int high = 0;
			cout << "please enter the lowest price limit: ";
			cin >> low;
			cout << "please ente the higher price limit: ";
			cin >> high;

			int count = my_table.display_by_price(low, high);
			cout << count << " products displayed with the price range. " << endl;
		} else if (choice =='6'){
			int tree_height = my_table.height();
			cout << "the height of the tree is: " << tree_height << endl;
		} else{
                        cout <<"you are exiting"<< endl;
		}
        } while (choice != '9');

        return 0;
}
