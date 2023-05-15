#pragma once
#include<iostream>
#include<vector>
using namespace std;
enum actionType {
	default_action,
	admin,
	admin_login_action,
	admin_logout_action,
	add_Admin,
	remove_Admin,
	show_Admin,
	hide_Admin,
	edit_Admin,
	display_Admin,
	CreateCol_Admin,
	DeleteCol_Admin,
	AddBToCol_Admin,
	RemoveBCol_Admin,
	showCol_Admin,
	member,
	member_login_action,
	member_logout_action,
	reading_Member,
	borrow_Member,
	return_Member,
	subscribe_Member,
	unsubscribe_Member,
	displaySubCol_Member,
	displayBorrow_Member,
	guest,
	Register_Guest,
	Reading_Guest,
	search_S_A,
	search_T_A,
	search_S_M,
	search_T_M,
	search_S_G,
	search_T_G,
	exit_action
};
class Menu {
private:
	string name;
	string description;
	vector<Menu*> subMenu;
	actionType action;
public:
	Menu();
	Menu(string name, string description, actionType action );
	~Menu();

	string getName();
	string getDesc();
	actionType getAction();

	void setName(string);
	void setDecs(string);
	void setAction(actionType );

	void displayMenu();
	void addSubMenu(Menu* m);
	Menu* getSubMenu(int index);
	int prompOption();
};

