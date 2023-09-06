#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
const static int INF = 0x3f3f3f3f;


class Goods       //商品
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
class Cosmetics : public Goods   //化妆品
{
public:
	Cosmetics(int, string, double, double, int, string, string);
	virtual string Classify();
};
class Food : public Goods        //食品
{
public:
	Food(int, string, double, double, int, string, string);
	virtual string Classify();
};
class Commodity : public Goods   //日用品
{
public:
	Commodity(int, string, double, double, int, string, string);
	virtual string Classify();
};
class Drink : public Goods       //饮料
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

	void Sale(); //销售

	void GoodsManage(); //商品管理
	void Add(); //添加商品
	int Query(); //查询
	void Delete(); //删除

	void Record(); //记录
	void Modify(Goods*); //修改
	
	void Count(); //库存统计

	void Load(); //读文件
	void Save(); //保存至文件
	
	static void Information(vector<Goods*>&, string = ""); //输出商品信息
	static void Information(vector<Note>&); //输出日志信息
	static void Information(Goods*);

	void Menu(); //菜单
private:
	vector<Goods*> m_Goods;
	vector<Note> m_Note;
};

int ChooseInt(int l, int r = INF,string msg = "");
