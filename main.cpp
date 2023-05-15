#include"administrator.h"
#include"member.h"
#include"guest.h"
#include"collection.h"
#include"Menu.h"
#include<iostream>
#include<string>
using namespace std;

bool isAdminLoggedIn = false;
bool isMemberLoggedIn = false;
bool isRegistered = false;

bool mem1 = false;
bool mem2 = false;
bool mem3 = false;

Book createBook(Book &b) {
	string title_b;
	string serial;
	string author;
	int pageNum;
	int freePage;
	string cate;
	cout << "Enter the information of book: " << endl; 
	cout << "Title: "; cin.ignore(); getline(cin, title_b); b.setTitle(title_b);
	cout << "Serial number: ";  getline(cin, serial); b.setSerial(serial);
	cout << "Author name: "; getline(cin, author); b.setAuthorName(author);
	cout << "Page number: "; cin >> pageNum; b.setPageNumber(pageNum);
	cout << "Free page number: "; cin >> freePage; b.setFreePage(freePage);
	cout << "Category: "; cin.ignore(); getline(cin, cate); b.setCategory(cate);
	b.setAvailability(true);
	cout << "Finish adding book." << endl;
	return b;
}
void createCol(Collection& c) {
	string name_c;
	int ID_c;
	cout << "Enter the name of the collection: "; 
	cin.ignore();
	getline(cin, name_c);
	cout << "Enter the ID of the collection: ";
	cin >> ID_c;
	c.setName(name_c);
	c.setID(ID_c);
	cout << "Finish adding collection." << endl;
}
void admin_login() {
	Administrator admin1("admin1", "123456");
	Administrator admin2("admin2", "654321");
	if (!isAdminLoggedIn) {

		string username, password;
		cout << "Username: " << endl;
		cin >> username;
		cout << "Password: " << endl;
		cin >> password;

		if (admin1.login(username, password) || admin2.login(username, password)) { 
			//a.setName(username);
			//a.setPassWord(password);
			cout << "Admin login successful.\nNow you can use other options in Admin window." << endl;
			isAdminLoggedIn = true;
		}
		else {
			cout << "Admin login failed. Wrong username or password." << endl;
		}
	}
	else {
		cout << "You are already logged in." << endl;
	}
}
Member member1("member1", "123456");
Member member2("member2", "654321");
Member member3("member3", "456789");
void member_login(bool &mem1, bool&mem2, bool &mem3) {
	

	if (!isMemberLoggedIn) {
		string username, password;
		cout << "Username: " << endl;
		cin >> username;
		cout << "Password: " << endl;
		cin >> password;

		if (member1.login(username, password) ) {
			//m.setName(username);
			//m.setPassWord(password);
			cout << "Member login successful.\nNow you can use other options in Member window." << endl;
			isMemberLoggedIn = true;
			mem1 = true;
		}
		else if (member2.login(username, password)) {
			cout << "Member login successful.\nNow you can use other options in Member window." << endl;
			isMemberLoggedIn = true;
			mem2 = true;
		}
		else if (isRegistered && username == "member3" && password == "456789") {
			//m.setName(username);
			//m.setPassWord(password);
			cout << "Member login successful.\nNow you can use other options in Member window." << endl;
			isMemberLoggedIn = true;
			mem3 = true;
		}
		else {
			cout << "Member login failed.Wrong username or password." << endl;
		}
	}
	else {
		cout << "You are already logged in." << endl;
	}
}
void switchCase(Member& m, actionType aT, vector<Book> &bList, vector<Collection> &cList, int &check) {
	switch (aT) {
	case borrow_Member: {
		m.borrowBook(bList);
		break;
	}
	case return_Member: {
		m.returnBook(bList);
		break;
	}
	case reading_Member: {
		m.read_M(bList);
		break;
	}
	case subscribe_Member: {
		m.subcribe(cList);
		break;
	}
	case unsubscribe_Member: {
		m.unsubcribe();
		break;
	}
	case displaySubCol_Member: {
		m.displayCollectionSubcribed();
		break;
	}
	case displayBorrow_Member: {
		m.displayBookBorrow();
		break;
	}
	case search_T_M: {
		m.searchByTitle(bList);
		break;
	}
	case search_S_M: {
		m.searchBySerial(bList);
		break;
	}
	case member_logout_action: {
		isMemberLoggedIn = false;
		//m.setName("");
		//m.setPassWord("");
		cout << "Member logged out." << endl;
		check = 1;
		mem1 = false;
		mem2 = false;
		mem3 = false;
		break;
	}
	default:
		break;
	}
}

int main() {
	vector<Collection> cList;
	//vector<Book> bList;
	Collection Sample(1, "Sample");

	vector<Book> bList = {
		Book("Fairy Tail", "12345", "John Smith", 100, 20, "Fiction", true, true),
		Book("Universe", "23456", "Stephen Hawking", 150, 30,"Science" , true, true),
		Book("Japanese Tradtions","34567" ,"Yamato", 80, 10, "Culture", true, true)
	};

	for (int i = 0; i < bList.size(); i++) {
		Sample.addBook(bList[i]);
	}
	cList.push_back(Sample);
	// moi user co mot menu rieng de display
	Menu* mainMenu = new Menu("Main Menu", "The access main Menu", default_action);
		Menu* adminMenu = new Menu("Admin", "Admin Window", admin);
		Menu* memberMenu = new Menu("Member", "Member window", member);
		Menu* guestMenu = new Menu("Guest", "Guest window", guest);
		Menu* exitProgram = new Menu("Exit", "Exit window", exit_action);

		mainMenu->addSubMenu(adminMenu);
		mainMenu->addSubMenu(memberMenu);	
		mainMenu->addSubMenu(guestMenu);
		mainMenu->addSubMenu(exitProgram);

			

			Menu* adminLoginMenu = new Menu("Admin Login", "Admin Login Window", admin_login_action);
			Menu* adminLogoutMenu = new Menu("Admin logout", "Admin Logout Window", admin_logout_action);
			Menu* add_A = new Menu("Add Book", "Admin - Add book", add_Admin);
			Menu* remove_A = new Menu("Remove Book", "Admin - Remove book", remove_Admin);
			Menu* show_A = new Menu("Show Book", "Admin - Show book", show_Admin);
			Menu* hide_A = new Menu("Hide Book", "Admin - Hide book", hide_Admin);
			Menu* edit_A = new Menu("Edit Book", "Admin - Edit book", edit_Admin);
			Menu* display_A = new Menu("Display Book", "Admin - Display book", display_Admin);
			Menu* CreateCol_A = new Menu("Create collection", "Admin - Create collection", CreateCol_Admin);
			Menu* DeleteCol_A = new Menu("Delete collection", "Admin - Delete collection", DeleteCol_Admin);
			Menu* AddBookToCol_A = new Menu("Add book to collection", "Admin - Add book to collection", AddBToCol_Admin);
			Menu* RemoveBookFromCol_A = new Menu("Remove book from collection", "Admin - Remove book from collection", RemoveBCol_Admin);
			Menu* showCol_A = new Menu("Show collection", "Admin - Show all collection", showCol_Admin);
			Menu* search_Serial_A = new Menu("Search Serial", "Search by Serial", search_S_A);
			Menu* search_Title_A = new Menu("Search Title", "Search by Title", search_T_A);
		    //Them ham show collection

			adminMenu->addSubMenu(adminLoginMenu);
			adminMenu->addSubMenu(adminLogoutMenu);
			adminMenu->addSubMenu(add_A);
			adminMenu->addSubMenu(remove_A);
			adminMenu->addSubMenu(show_A);
			adminMenu->addSubMenu(hide_A);
			adminMenu->addSubMenu(edit_A);
			adminMenu->addSubMenu(CreateCol_A);
			adminMenu->addSubMenu(DeleteCol_A);
			adminMenu->addSubMenu(AddBookToCol_A);
			adminMenu->addSubMenu(RemoveBookFromCol_A);
			adminMenu->addSubMenu(showCol_A);
			adminMenu->addSubMenu(search_Serial_A);
			adminMenu->addSubMenu(search_Title_A);
			adminMenu->addSubMenu(exitProgram);

			Menu* memberLoginMenu = new Menu("Member Login", "Member Login Window", member_login_action);		
			Menu* memberLogoutMenu = new Menu("Member Logout", "Member Logout Window", member_logout_action);
			Menu* read_M = new Menu("Reading", "Member - Reading", reading_Member);
			Menu* borrow_M = new Menu("Borrow Book", "Member - Borrow book", borrow_Member);
			Menu* return_M = new Menu("Return Book", "Member - Return book", return_Member);
			Menu* subscribe_M = new Menu("Subscribe collection", "Member - Subscribe collection", subscribe_Member);
			Menu* unsubscribe_M = new Menu("Unsubscribe collection", "Member - Unsubscribe collection", unsubscribe_Member);
			Menu* displaySubCol_M = new Menu("Display subcribed collection", "Member - Display subcribed collection", displaySubCol_Member);
			Menu* dispalyBorrow_M = new Menu("Dispaly borrow book", "Member - Dispaly borrow book", displayBorrow_Member);
			Menu* search_Serial_M = new Menu("Search Serial", "Search by Serial", search_S_M);
			Menu* search_Title_M = new Menu("Search Title", "Search by Title", search_T_M);

			memberMenu->addSubMenu(memberLoginMenu);
			memberMenu->addSubMenu(memberLogoutMenu);
			memberMenu->addSubMenu(read_M);
			memberMenu->addSubMenu(borrow_M);
			memberMenu->addSubMenu(return_M);
			memberMenu->addSubMenu(subscribe_M);
			memberMenu->addSubMenu(unsubscribe_M);
			memberMenu->addSubMenu(displaySubCol_M);
			memberMenu->addSubMenu(dispalyBorrow_M);
			memberMenu->addSubMenu(search_Serial_M);
			memberMenu->addSubMenu(search_Title_M);
			memberMenu->addSubMenu(exitProgram);

			Menu* Register_G = new Menu("Register ", "Guest - Register as a member", Register_Guest);
			Menu* Reading_G = new Menu("Reading ", "Guest - Reading", Reading_Guest);
			Menu* search_Serial_G = new Menu("Search Serial", "Search by Serial", search_S_G);
			Menu* search_Title_G = new Menu("Search Title", "Search by Title", search_T_G);

			guestMenu->addSubMenu(Register_G);
			guestMenu->addSubMenu(Reading_G);
			guestMenu->addSubMenu(search_Serial_G);
			guestMenu->addSubMenu(search_Title_G);
			guestMenu->addSubMenu(exitProgram);

	Menu* currentMenu = mainMenu;
	//currentMenu->displayMenu();
	Administrator a;
	Member m;
	Guest g;

	member1.Samplesubscribe(Sample);
	member2.Samplesubscribe(Sample);
	member3.Samplesubscribe(Sample);

	while (true) {
		int check = 0;
		system("cls");
		currentMenu->displayMenu();
			
		switch (currentMenu->getAction())
		{
		case default_action:
			///
			break;
		case admin: {
			cout << "Please login with ADMIN account if you have not logged-in." << endl;
			break;
		}
		case admin_login_action: {
			admin_login();
			break;
		}
		case add_Admin:
		case remove_Admin:
		case hide_Admin:
		case show_Admin:
		case edit_Admin:
		case CreateCol_Admin:
		case DeleteCol_Admin:
		case AddBToCol_Admin:
		case RemoveBCol_Admin:
		case showCol_Admin:
		case search_S_A:
		case search_T_A:
		case admin_logout_action: {
			if (!isAdminLoggedIn) {
				cout << "Please login as an Administrator to access this feature." << endl;
				break;
			}
			else {							
				switch (currentMenu->getAction()) {
				case add_Admin: {
					Book b;
					createBook(b);
					a.add(b, bList);
					break;
				}
				case remove_Admin: {
					a.remove(bList);
					break;
				}
				case hide_Admin: {
					a.hide(bList);
					break;
				}
				case show_Admin: {
					a.show(bList);
					break;
				}
				case edit_Admin: {
					a.edit(bList);
					break;
				}
				case CreateCol_Admin: {
					a.createCollection( cList);
					break;
				}
				case DeleteCol_Admin: {
					a.deleteCollection(cList);
					break;
				}
				case AddBToCol_Admin: {
					a.addToCol(bList, cList);
					break;
				}
				case RemoveBCol_Admin: {
					a.removeFromCol(cList);
					break;
				}
				case showCol_Admin: {
					a.showCol(cList);
					break;
				}
				case search_S_A: {
					a.searchBySerial(bList);
					break;
				}
				case search_T_A: {
					a.searchByTitle(bList);
					break;
				}
				case admin_logout_action: {
					isAdminLoggedIn = false;
					a.setName("");
					a.setPassWord("");
					
					check = 1;
					currentMenu = mainMenu;
					break;
				}
				default:
					break;
				}
				break;
			}
		}
		case member: {
			cout << "Please login with MEMBER account if you have not logged-in." << endl;
			break;
		}
		case member_login_action: {
			
			member_login(mem1, mem2, mem3);
			break;
		}
		case borrow_Member:
		case return_Member:
		case reading_Member:
		case subscribe_Member:
		case unsubscribe_Member:
		case displaySubCol_Member:
		case displayBorrow_Member:
		case search_T_M:
		case search_S_M:
		case member_logout_action: {
			if (!isMemberLoggedIn) {
				cout << "Please login as a Member to access this feature." << endl;				
			}
			else {
				actionType aT = currentMenu->getAction();
				if (mem1) switchCase(member1, aT, bList, cList, check);
				else if (mem2) switchCase(member2, aT, bList, cList, check);
				else switchCase(member3, aT, bList, cList, check);							
			}
			break;
		}
				
		case Register_Guest: {
			g.Register();
			isRegistered = true;
			break;
		}
		case Reading_Guest: {
			g.read_G(Sample);
		}
		case search_T_G: {
			g.searchByTitle(bList);
			break;
		}
		case search_S_G: {
			g.searchBySerial(bList);
		}
		case exit_action: {
			cout << "Thank you for using our Library!" << endl;
			return(0);
			break;
		}
		default:
			break;
		}
		if (check == 1) {
			currentMenu = mainMenu;
		}
		if(check == 0) {
			int opt = currentMenu->prompOption();
			currentMenu = currentMenu->getSubMenu(opt);
		}
	}
}