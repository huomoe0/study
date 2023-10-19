#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
const static int INF = 0x3f3f3f3f;


class Goods       //��Ʒ
{
	friend class ShopManage;
	friend struct cmp;
public:
	Goods(int, string, double, double, int, string, string);
	virtual string Classify() = 0;
protected:
	int m_id;
	string m_name;
	double m_inprice;
	double m_outprice;
	int m_inventory;
	string m_manufacturer;
	string m_brand;
	static int maxid;
};
class Cosmetics : public Goods   //��ױƷ
{
public:
	Cosmetics(int, string, double, double, int, string, string);
	virtual string Classify();
};
class Food : public Goods        //ʳƷ
{
public:
	Food(int, string, double, double, int, string, string);
	virtual string Classify();
};
class Commodity : public Goods   //����Ʒ
{
public:
	Commodity(int, string, double, double, int, string, string);
	virtual string Classify();
};
class Drink : public Goods       //����
{
public:
	Drink(int, string, double, double, int, string, string);
	virtual string Classify();
};

class Note
{
public:
	Note(int id, string name, int number, double price);
	int m_noteid;
	int m_goodsid;
	string m_name;
	int m_number;
	double m_price;
	static int maxid;
};
class ShopManage
{
public:
	ShopManage();

	void Sale(); //����

	void GoodsManage(); //��Ʒ����
	void Add(); //�����Ʒ
	int Query(); //��ѯ
	void Delete(); //ɾ��

	void Record(); //��¼
	void Modify(Goods*); //�޸�
	
	void Count(); //���ͳ��

	void Load(); //���ļ�
	void Save(); //�������ļ�
	
	static void Information(vector<Goods*>&, string = ""); //�����Ʒ��Ϣ
	static void Information(vector<Note>&); //�����־��Ϣ
	static void Information(Goods*);

	void Menu(); //�˵�
private:
	vector<Goods*> m_Goods;
	vector<Note> m_Note;
};

int ChooseInt(int l, int r = INF,string msg = "");
