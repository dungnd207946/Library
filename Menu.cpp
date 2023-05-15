#include"Menu.h"

Menu::Menu()
{
	name = "Default Menu";
	description = "Default description";
	action = default_action;
	subMenu.clear();
}

Menu::Menu(string name, string description, actionType action )
{
	this->name = name;
	this->description = description;
	this->action = action;
}

Menu::~Menu()
{
	if (!subMenu.size()) {
		for (int i = 0; i < subMenu.size(); i++) {
			delete subMenu[i];
		}
		subMenu.clear();
	}
}

string Menu::getName()
{
	return name;
}

string Menu::getDesc()
{
	return description;
}

actionType Menu::getAction()
{
	return action;
}

void Menu::setName(string newName)
{
	name = newName;
}

void Menu::setDecs(string newDesc)
{
	description = newDesc;
}


void Menu::setAction(actionType newAction)
{
	action = newAction;
}

void Menu::displayMenu()
{
	cout << "------" << name << "-------" << endl;
	cout << description << endl;
	for (int i = 0; i < subMenu.size(); i++) {
		cout << i + 1 << "." << subMenu[i]->getName() << endl;
	}
	cout << "----------------------------" << endl;
}

void Menu::addSubMenu(Menu* m)
{
	m->subMenu.push_back(this);
	subMenu.push_back(m);
}

Menu* Menu::getSubMenu(int index)
{
	if (index > 0 && index <= subMenu.size()) {
		index--;
		return subMenu[index];
	}
	else { return nullptr; }
}

int Menu::prompOption()
{
	while (true) {
		cout << "Pick an option: ";
		int option;
		cin >> option;
		try {
			if (cin.fail()) {
				throw "Invalid input";
			}
			else if (option < 1 || option > subMenu.size()) {
				throw "Invalid input";
			}
			else {
				return option;
			}
		}
		catch (const char* error) {
			cin.ignore();
			cin.clear();
			cout << "Error: " << error << endl;
		}
	}
}
