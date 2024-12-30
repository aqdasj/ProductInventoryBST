// Aqdas Juya , 12/19/2024 , ajuya@pdx.edu ,  program # 4, cs 163
#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
using namespace std;
// this is the struct to hold all the product information:
struct product {
	char * title;
	char * description;
	char * category;
	char * type;
	int price;
	int quantity;
	char * sellerID;
	char * shopName;
	int sold;

	product();
	~product();
};
// // This struct holds all the product information:
struct node {
	product data;
	node * left;
	node * right;

	node();
	~node();
};
// this is the class table with the prototypes: 
class table {
	public:
		table();
		~table();


		int add(const char* title, const product& add_product);
		int displayall() const;
		int remove(const char * title);
		int peek(const char * title, product& found);

		int display_by_price(int low, int high) const;
		int height() const;

	private:
		node * root;


		int add_recursive(node *& root, const char* title, const product & add_product);
		int displayall_recursive(node * root) const;
		int remove_recursive(node *& root, const char *title);
		int peek_recursive(node * root, const char * title, product & found) const;

		int display_by_price_recursive(node * root, int low, int high) const;
		int hight_recursive(node * root) const;
		void remove_all_recursive(node *& root);
};	
