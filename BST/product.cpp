//// Aqdas Juya , 11/21/2024 , ajuya@pdx.edu ,  program # 3, cs 13 
// this is the function.cpp file
#include "product.h"


product:: product() {
	title = nullptr;
	description = nullptr;
	category = nullptr;
	type = nullptr;
	price = 0;
	quantity = 0;
	sellerID = nullptr;
	shopName = nullptr;
	sold= 0;
}
product::~product() {
	delete[] title;
	title = nullptr;
	delete[] description;
	description = nullptr;
	delete[] category;
	category = nullptr;
	delete[] sellerID;
	sellerID = nullptr;
	delete[] shopName;
	shopName = nullptr;
}

node::node() {
	left = nullptr;
	right = nullptr;
}
node::~node() {
	delete right;
	right = nullptr;
	delete left;
	left = nullptr;
}

table::table(){
	root = nullptr;
}
table::~table(){
	remove_all_recursive(root);

}

void table::remove_all_recursive(node *& root){
	if(!root){
		return;
	}

	remove_all_recursive(root-> left);
	remove_all_recursive(root -> right);

	delete root;
	root = nullptr;
}

int table::add(const char* title, const product& add_product){
	if(!title) {
		return 0;
	}
	return add_recursive(root, title, add_product);
}

int table::add_recursive(node *& root, const char* title, const product & add_product){
	if(!root) {
		root = new node;

		root -> data.title = new char[strlen(add_product.title) + 1];
		strcpy(root -> data.title, add_product.title);

		root ->data.description= new char[strlen(add_product.description) + 1];
		strcpy(root->data.description, add_product.description);

                root -> data.category= new char[strlen(add_product.category) + 1];
                strcpy(root -> data.category, add_product.category);

                root ->data.type = new char[strlen(add_product.type) + 1];
                strcpy(root->data.type, add_product.type);

		root -> data.price = add_product.price;
		root -> data.quantity = add_product.quantity;

		root -> data.sellerID= new char[strlen(add_product.sellerID) + 1];
                strcpy(root -> data.sellerID, add_product.sellerID);

                root ->data.shopName = new char[strlen(add_product.shopName) + 1];
                strcpy(root->data.shopName, add_product.shopName);

		root->data.sold = add_product.sold;

		root -> left = nullptr;
		root -> right = nullptr;

		return 1;
	}
	int position = strcmp(title, root -> data.title);
	if (position< 0) {
		return add_recursive(root -> left, title, add_product);
	}else {
		return add_recursive(root -> right, title, add_product);
	}
}

int table::displayall() const{
	if(!root) {
		return 0;
	}
	return displayall_recursive(root);


}
int table::displayall_recursive(node * root) const{

	if(!root) {
		return 0;
	}
	displayall_recursive(root -> left);

	cout <<"\nproduct is title: " << root -> data.title << endl;
	cout <<"product is description: " << root -> data.description << endl;
	cout <<"product is category: " << root -> data.category << endl;
	cout <<"product is type: " << root -> data.type << endl;
	cout <<"product is price: " << root -> data.price << endl;
	cout <<"product is quantity: " << root -> data.quantity<< endl;
	cout <<"product is seller ID: " << root -> data.sellerID << endl;
	cout <<"product is shop name: " << root -> data.shopName << endl;
	cout <<"Is the product sold or not: " << root -> data.sold << endl;
	
	displayall_recursive(root-> right);
	return 1; 
}

int table::remove(const char * title){
	if(!title) return 0;
	return remove_recursive(root, title);
}
int table::remove_recursive(node *& root,const char *title){

	if (!root) {
		return 0;
	}
	int now = strcmp(title, root -> data.title);
	if(now < 0) {
		return remove_recursive(root -> left, title);
	}else if(now > 0) {
		return remove_recursive(root -> right, title);
	}else {
		if(!root -> left && ! root -> right) {
			delete root;
			root = nullptr;
		} else if (!root -> left) {
			node *temp = root;
			root = root -> right;
			delete temp;
		} else if (!root -> right) {
			node * temp = root;
			root = root -> left;
			delete temp;
		} else {
			node * found = root;
			node * current = root -> right;

			while (current -> left ) {
				found = current;
				current = current -> left;
			}

			root -> data = current -> data;

			if(found -> left == current) {
				found -> left = current -> right;
			} else {
				found -> right = current -> right;
			}
		}
		return 1;
	}
}
int table::peek(const char * title, product& found){
	if( !title){
		return 0;
	}
	return peek_recursive(root, title, found);

}

int table::peek_recursive(node * root, const char * title, product & found) const{
	if(!root) {
		return 0;
	}

	int now = strcmp(title, root-> data.title);

	if(now < 0) {
		return peek_recursive(root -> left, title, found);
	}else if( now > 0) {
		return peek_recursive(root-> right, title, found);
	} else {
		found = root -> data;
		return 1;
	}
}

int table::display_by_price(int low, int high) const{
	if(!root) {
		return 0;
	}
	return display_by_price_recursive(root, low, high);
}

int table::display_by_price_recursive(node * root, int low, int high) const{

	if(root == nullptr) {
		return 0;

	}

	int count = 0;

	count += display_by_price_recursive(root -> left, low, high);
	if(root -> data.price >= low && root -> data.price <= high){
		cout << "title: " << root -> data.title<< endl
		     << "description: " << root -> data.description <<endl
		     << "category: " << root -> data.category << endl
		     << "type: " << root -> data.type << endl
		     << "price: " << root -> data.price << endl
		     << "quantity: " << root -> data.quantity<< endl
		     << "seller ID: " << root -> data.sellerID << endl
		     << "shop name: " << root -> data.shopName << endl
		     << "sold: " << root -> data.sold << endl;
		count ++;
	}
	count += display_by_price_recursive(root -> right, low, high);
	return count;
}

int table::height() const{
	if(root == nullptr) {
		return 0;
	}
	return hight_recursive(root);
}

int table::hight_recursive(node * root) const{
	if(root == nullptr) {
		return 0;
	}

	int left_height = hight_recursive(root -> left);
	int right_height = hight_recursive(root -> right);

	if(left_height > right_height) {
		return 1+ left_height;
	} else {
		return 1 + right_height;
	}
}
