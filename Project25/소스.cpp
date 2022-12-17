#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class DVD {
private:
	string title;//제목
	int cost;//대여비
	string supervisor;//감독이름
	static int DVD_num;//DVD번호
	int d_state;//대여상태
	int count;//대여된 횟수
	int who_rent;
public:
	DVD() {
		title = "등록대기중";
		cost = 0;
		supervisor = "무명";
		d_state = 0;
		count = 0;
		who_rent = -1;
	}
	DVD(string title, int cost, string supervisor) {
		this->title = title;
		this->cost = cost;
		this->supervisor = supervisor;
		d_state = 0;
		count = 0;
		who_rent = -1;
	}
	void init_DVD(DVD *D) {//초기 DVD 설정
		ifstream f("DVD.txt");
		string title;
		string super;
		int cost;
		int popular, lend;
		while (!f.eof()) {
			f >> title;
			f >> cost;
			f >> super;
			f >> popular;
			f >> lend;
			D[DVD_num].setTitle(title);
			D[DVD_num].setCost(cost);
			D[DVD_num].setSuper(super);
			D[DVD_num].count = popular;
			D[DVD_num].who_rent = lend;
			DVD_num++;
		}
	}
	int getWho_rent() { return who_rent; }
	string getTitle() { return title; }
	int getCost() { return cost; }
	string getSuper() { return supervisor; }
	int getDVD_num() { return DVD_num; }
	int getD_state() { return d_state; }
	int getCount() { return count; }
	void setCost(int cost) { this->cost = cost; }
	void setTitle(string title) { this->title = title; }
	void setSuper(string super) { supervisor = super; }
	void setCount() { count++; }
	void add_DVD(DVD *D) {
		ofstream in("DVD.txt", ios::app );
		string title;
		int cost;
		string super;
		cout << "추가할 DVD 이름과 가격, 감독이름 입력: " << endl;
		cin >> title >> cost >> super;
		D[DVD_num].setTitle(title);
		D[DVD_num].setCost(cost);
		D[DVD_num].setSuper(super);
		in << title << " " << cost << " " << super << " " << count << " " << who_rent << endl;
		DVD_num++;
		ifstream fp("DVD.txt");
		string ptitle;
		string psuper;
		int pcost;
		int ppopular, plend;
		while (!fp.eof()) {
			fp >> ptitle;
			fp >> pcost;
			fp >> psuper;
			fp >> ppopular;
			fp >> plend;
			D[DVD_num].setTitle(ptitle);
			D[DVD_num].setCost(pcost);
			D[DVD_num].setSuper(psuper);
			D[DVD_num].count = ppopular;
			D[DVD_num].who_rent = plend;
			//DVD_num++;
		}
	}
	void set_whoRent(int who_rent) { this->who_rent = who_rent; }
	void setD_state(int d_state) { this->d_state = d_state; }
	string search_DVD(DVD *D) {
		string title;
		int select = 1;
		cout << "===================DVD 검색===================" << endl;
		cout << "검색하실 DVD 이름을 입력하세요: ";
		cin >> title;
		cout << endl;
		for (int i = 0; i < D->DVD_num; i++) {
			if (D[i].getTitle() == title) {
				cout << "***검색결과***" << endl;
				cout << D[i].getTitle() << ", 감독: " << D[i].getSuper() << endl;
				cout << "대여비: " << D[i].getCost() << "원" << endl;
				cout << "대여(가능=0/불가능=1): " << D[i].getD_state() << endl;
				return D[i].getTitle();
			}
		}
		cout << "*검색 결과를 찾을 수 없습니다." << endl;
		return "abc";
	}

	friend void print_DVD(DVD *D) {
		cout << "===================DVD List===================" << endl;
		for (int i = 0; i < D->DVD_num-1; i++) {
			cout << "Title: " << D[i].title << endl;
			cout << "Cost: " << D[i].cost << endl;
			cout << "Supervisor: " << D[i].supervisor << endl;
			cout << "Rental (possible=0/impossible=1): " << D[i].d_state << endl;
			cout << "Popularity: " << D[i].count << endl;
			cout << endl;
		}
	}
};
int DVD::DVD_num = 0;

class login_p {
public:
	string name;
	int p_num;
	int log;
	int num;
};

class Person {
	string name;
	int p_num;
	int state;
	static int num;
public:
	vector<string> list[3];
	Person() {
		name = " ";
		p_num = 0;
		state = 0;
		vector<string> list[3];
	}
	void Join(string name, int p_num) {
		this->name = name;
		this->p_num = p_num;
		num++;
	}
	void setState(int x) {
		if (x == 1) {
			if (state > 3)
				cout << "대여갯수 초과" << endl;
			else
				state++;
		}
		else
			state--;
	}
	int getNum() { return num; }
	int getState() { return state; }
	string getName() { return name; }
	int  getP_num() { return p_num; }
	void add_DVDlist(string title) {
		list->push_back(title);
	}
	void Person_state(Person *P) {
		string name;
		int p_num;
		cout << "===================회원상태===================" << endl;
		try {
			cout << "회원이름 입력: ";
			cin >> name;
			cout << "패스워드 입력: ";
			cin >> p_num;
			if (cin.fail())
				throw 'a';
			cout << "========빌린 책 목록=======" << endl;
			for (int i = 0; i < P[i].getNum(); i++) {
				if (P[i].getName() == name && P[i].getP_num() == p_num) {
					for (auto p = P[i].list->begin(); p != P[i].list->end(); ++p) {
						cout << i + 1 << "." << *p << endl;
					}
				}
				else
					cout << "빌린 책 없음" << endl;
			}
		}
		catch (char e) {
			cout << "패스워드를 다시 확인해주세요." << endl;
			cin.clear();
			fseek(stdin, 0, SEEK_END);
		}
	}
	void Join(Person* p) {
		string name;
		int p_num;
		int i = 0;
		cout << "===================회원등록===================" << endl;
		try {
			cout << "*Enter your Name: ";
			cin >> name;
			cout << "*Enter your last phone number(4 digits): ";
			cin >> p_num;
			if (cin.fail())
				throw 'a';
			p[num].Join(name, p_num);
			cout << "**Registered Complete!**" << endl;
		}
		catch (char e) {
			cerr << "Error: Not a number" << endl;
			cin.clear();
			fseek(stdin, 0, SEEK_END);
		}
	}
};

int Person::num = 0;
//로그인
int Login(string name, int p_num, Person* p) {
	for (int i = 0; i < p[i].getNum(); i++) {
		if (p[i].getName() == name && p[i].getP_num() == p_num) {
			cout << "Login Complete!" << endl;
			return 1;
		}
	}
	cout << "Login Failed.." << endl;
	return 0;
}
//가입

//로그인 정보반환
login_p Try_login(Person* p) {
	string name;
	int p_num;
	int i = 0;
	try {
		cout << "Enter your Name: ";
		cin >> name;
		cout << "Enter your last phone number(4 digits): ";
		cin >> p_num;
		if (cin.fail())
			throw 'a';
		cout << endl;
		int log = Login(name, p_num, p);
		login_p log_p;
		log_p.name = name;
		log_p.log = log;
		log_p.p_num = p_num;

		return log_p;
	}
	catch (char e) {
		cout << "패스워드를 다시 확인해주세요." << endl;
		cin.clear();
		fseek(stdin, 0, SEEK_END);
	}
}

void Rent_DVD(DVD *D, Person *P) {
	string title = D->search_DVD(D);
	cout << "====================대여하기==================" << endl;
	login_p log_p;
	cout << "대여하기 위해 로그인 해주세요" << endl;
	log_p = Try_login(P);
	if (log_p.log == 1) {
		for (int i = 0; i < D->getDVD_num()-1; i++) {
			if (D[i].getTitle() == title && D[i].getD_state() == 0) {
				D[i].setD_state(1);
				for (int j = 0; j < P[j].getNum(); j++) {
					if (P[j].getName() == log_p.name && P[j].getP_num() == log_p.p_num) {
						P[j].setState(log_p.log);
						P[j].add_DVDlist(title);
						log_p.num = P[j].getNum();
						D[i].setCount();
						cout << "*" << title << "을 대여하였습니다." << endl;
					}
				}
				D[i].set_whoRent(log_p.num);
			}
			else if (D[i].getD_state() == 1)
				cout << "그 DVD는 이미 대여중이라 빌릴 수 없습니다." << endl;
		}

	}
	else
		cout << "로그인 실패로 대여 불가" << endl;
}

void Return_DVD(DVD *D, Person *P) {
	cout << "반납하기" << endl;
	string title = D->search_DVD(D);
	login_p log_p;
	log_p = Try_login(P);
	if (log_p.log == 1) {
		for (int i = 0; i < D->getDVD_num()-1; i++) {
			for (int i = 0; i < P[i].getNum(); i++) {
				if (P[i].getName() == log_p.name && P[i].getP_num() == log_p.p_num) {
					for (int j = 0; j < D[j].getDVD_num()-1; j++) {
						if (D[j].getTitle() == title) {
							D[j].set_whoRent(-1);
							for (int k = 0; k < P[i].list->size(); k++) {
								if (P[i].list->at(k) == D[j].getTitle())
									P[i].list->erase(P[i].list->begin() + k);
							}
							D[j].setD_state(0);
							cout << title << "을 반납." << endl;
							return;
						}
					}
				}
			}
		}
	}
	else
		cout << "로그인 실패로 반납 불가" << endl;
}
class Manager :public DVD, public Person {
private:
	int password = 3712;
public:
	int in_manager(Manager m, DVD *D, Person *P) {
		int select = 0;
		while (select != 3) {
			cout << "================관리자 모드================" << endl;
			cout << "=                1.DVD 등록               =" << endl;
			cout << "=                2.회원조회               =" << endl;
			cout << "=                  3.종료                 =" << endl;
			cout << "===========================================" << endl;
			cin >> select;
			if (select == 1) {
				D->add_DVD(D);
			}
			else if (select == 2) {
				for (int i = 0; i < P->getNum(); i++) {
					cout << i + 1 << ".회원 이름: " << P[i].getName() << endl;
				}
			}
		}
		cout << "프로그램 종료" << endl;
		return 0;
	}

	void alert_manager(Manager m, DVD *D, Person *P) {
		int pw;
		cout << "관리자 영역에 접근하려면 패스워드를 입력하세요: " << endl;
		cin >> pw;
		if (m.password == pw) {
			cout << "관리자 모드로 전환합니다." << endl;
			in_manager(m, D, P);
		}
		else
			cout << "패스워드가 다릅니다." << endl;
	}
};
int main() {
	int select_menu = 0;
	DVD *D = new DVD[50];
	Person *P = new Person[50];
	Manager M;

	D->init_DVD(D);
	try {
		while (select_menu != 8) {
			cout << "==================DVD 대여소==================" << endl;
			cout << "=            메뉴를 입력하세요(숫자)         =" << endl;
			cout << "=                 1.DVD 목록                 =" << endl;
			cout << "=                 2.DVD 검색                 =" << endl;
			cout << "=                 3.회원등록                 =" << endl;
			cout << "=              4.나의 대출현황               =" << endl;
			cout << "=                 5.대여하기                 =" << endl;
			cout << "=                 6.반납하기                 =" << endl;
			cout << "=            7.관리자 모드로 전환            =" << endl;
			cout << "=                   8.종료                   =" << endl;
			cout << "==============================================" << endl;
			cout << "메뉴를 선택하세요(1~8): ";
			cin >> select_menu;
			if (select_menu > 10 && select_menu < 1)
				throw 0;
			else if (cin.fail())
				throw 'a';

			if (select_menu == 1)
				print_DVD(D);
			else if (select_menu == 2)
				D->search_DVD(D);
			else if (select_menu == 3)
				P->Join(P);
			else if (select_menu == 4)
				P->Person_state(P);
			else if (select_menu == 5)
				Rent_DVD(D, P);
			else if (select_menu == 6)
				Return_DVD(D, P);
			else if (select_menu == 7)
				M.alert_manager(M, D, P);
		}
	}
	catch (int e) {
		cout << "메뉴에 해당하는 숫자로 입력하세요!" << endl;
		cin.clear();
		fseek(stdin, 0, SEEK_END);
	}
	catch (char e) {
		cout << "메뉴에 해당하는 숫자로 입력하세요!" << endl;
		cin.clear();
		fseek(stdin, 0, SEEK_END);

	}
	cout << "DVD 대여 프로그램을 종료합니다." << endl;
	if (select_menu == 8) {
		ofstream in("DVD.txt");
		ofstream pin("Person.txt");
		for (int i = 0; i < D->getDVD_num()-1; i++) {
			in << D[i].getTitle() << " " << D[i].getCost() << " " << D[i].getSuper() << " " << D[i].getCount() << " " << D[i].getWho_rent() << endl;
		}
		for (int i = 0; i < P->getP_num(); i++) {
			pin << P[i].getName() << " " << P[i].getP_num() << " " << P[i].getNum();
			for (auto p = P[i].list->begin(); p != P[i].list->end(); ++p) {
				pin << " " << *p;
			}
			pin << endl;
		}
		return 0;
	}
	return 0;
}