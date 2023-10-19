#include "Shop.h"
using namespace std;

string Cls[] = { "", "化妆品","食品", "日用品" ,"饮料" };

Goods::Goods(int id, string name, double ip, double op, int inventory, string manufacturer, string brand)
{
	m_id = id; m_name = name; m_inprice = ip; m_inventory = inventory; m_manufacturer = manufacturer;
	m_brand = brand; m_outprice = op;
}
Cosmetics::Cosmetics(int id, string name, double ip, double op, int inventory, string manufacturer, string brand)
	: Goods(id,name, ip, op,inventory, manufacturer, brand){}
Food::Food(int id, string name, double ip, double op, int inventory, string manufacturer, string brand)
	: Goods(id, name, ip, op, inventory, manufacturer, brand) {}
Commodity::Commodity(int id, string name, double ip, double op, int inventory, string manufacturer, string brand)
	: Goods(id, name, ip, op, inventory, manufacturer, brand) {}
Drink::Drink(int id, string name, double ip, double op, int inventory, string manufacturer, string brand)
	: Goods(id, name, ip, op, inventory, manufacturer, brand) {}


string Cosmetics::Classify(){return "化妆品";}
string Food::Classify() { return "食品"; }
string Commodity::Classify() { return "日用品"; }
string Drink::Classify() { return "饮料"; }

Note::Note(int id, string name, int number, double price)
{
	m_goodsid = id, m_name = name, m_number = number, m_price = price, m_noteid = maxid++;
}

int Note::maxid = 10000;
int Goods::maxid = 10000;

int ChooseInt(int l, int r, string msg)
{
	string s;
	while (1)
	{
		cout << msg;
		cin >> s;
		int flag = 0;
		for (int i = 0; i < s.size(); i++)	
			if (s[i] < '0' && s[i] > '9')
			{
				flag = 1; break;
			}
		if (flag)	continue;
		int t = 0;
		for (int i = 0; i < s.size(); i++)	t = t * 10 + s[i] - '0';
		if (t >= l && t <= r)	return t;
		else continue;
	}
}

ShopManage::ShopManage() {}

void ShopManage::Sale()
{
	cout << "1.化妆品 2.食品 3.日用品 4.饮料 0.返回\n";
	int c = ChooseInt(0, 4),pos;
	if (c == 0)	return;

	Information(m_Goods,Cls[c]);

	cout << "请输入商品名称: ";
	string tmp;
	cin >> tmp;


	vector<Goods*> v;
	for (int i = 0; i < m_Goods.size(); i++)
		if (m_Goods[i]->m_name == tmp && m_Goods[i]->Classify() == Cls[c])
			v.push_back(m_Goods[i]);
	Information(v);

	if (v.size() != 0)
	{
		if (v.size() == 1)	pos = 0;
		else if (v.size() > 1)
		{
			while (1)
			{
				cout << "请选择商品编号: ";
				int t;
				cin >> t;
				int flag = 0;
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i]->m_id == t)
					{
						flag = 1; pos = i; break;
					}
				}
				if (flag == 1)	break;
			}
		}
		
		cout << "请输入购买数量: ";
		c = ChooseInt(0);
		if (c <= v[pos]->m_inventory)
		{
			cout << "购买成功\n";
			Note t(v[pos]->m_id,v[pos]->m_name, c, v[pos]->m_outprice);
			m_Note.push_back(t);
			v[pos]->m_inventory -= c;
		}
		else cout << "库存不足\n";
	}
	else cout << "未找到该商品\n";
}


void ShopManage::Load()
{
	fstream fs("goods.txt", ios::in);
	if (!fs) //打开失败
	{
		fstream t("goods.txt", ios::out); //创建文件
		t.close();
		fs.open("goods.txt", ios::in);
	}
	int id, inventory;
	double ip,op;
	string name,manufacturer, brand, cls;

	while (fs >> cls >> id >> name >> ip >> op >> inventory >> manufacturer >> brand)
	{
		Goods* p;
		if (cls == Cls[1])	p = new Cosmetics(id, name, ip, op, inventory, manufacturer, brand);
		else if (cls == Cls[2])	p = new Food(id, name, ip, op, inventory, manufacturer, brand);
		else if (cls == Cls[3])	p = new Commodity(id, name, ip, op, inventory, manufacturer, brand);
		else if (cls == Cls[4])	p = new Drink(id, name, ip, op, inventory, manufacturer, brand);
		m_Goods.push_back(p);
		Goods::maxid = Goods::maxid < id ? id : Goods::maxid;
	}
	fs.close();

	fs.open("note.txt", ios::in);
	if (!fs) //打开失败
	{
		fstream t("note.txt", ios::out); //创建文件
		t.close();
		fs.open("note.txt", ios::in);
	}
	while (fs >> id >> name >> inventory >> op)
	{
		m_Note.push_back({ id, name,inventory,op }); 
		Note::maxid = Note::maxid < id ? id : Note::maxid;
	}
	fs.close();
}

void ShopManage::Save()
{
	fstream fs("goods.txt", ios::out);
	string cls;
	for(int i = 0;i < m_Goods.size();i++)
	{
		fs << m_Goods[i]->Classify() << " " <<  m_Goods[i]->m_id << " " << m_Goods[i]->m_name << " "
			<< m_Goods[i]->m_inprice << " " << m_Goods[i]->m_outprice << " " << m_Goods[i]->m_inventory << " "
			<< m_Goods[i]->m_manufacturer << " " << m_Goods[i]->m_brand << endl;
	}
	fs.close();

	fs.open("note.txt", ios::out);
	for(int i = 0;i < m_Note.size();i++)
	{
		fs << m_Note[i].m_goodsid << " " << m_Note[i].m_name << " " << m_Note[i].m_number 
			<< " " << m_Note[i].m_price << endl;
	}
	fs.close();
}

void ShopManage::Information(vector<Goods*> &v, string cls)
{
	if (v.size() == 0)	return;
	cout << "类别"  << "\t编号" << "\t名称" << "\t进价"  << "\t售价"
		<< "\t库存" << "\t厂家" << "\t品牌"  << endl;

	for (int i = 0; i < v.size(); i++)
	{
		if (cls != "" && v[i]->Classify() != cls)	continue;
		cout << v[i]->Classify() << "\t" << v[i]->m_id << "\t" << v[i]->m_name << "\t" << v[i]->m_inprice << "\t"
			<< v[i]->m_outprice << "\t" << v[i]->m_inventory << "\t" << v[i]->m_manufacturer << "\t"
			<< v[i]->m_brand << endl;
	}
}

void ShopManage::Information(Goods* v)
{
	cout << "类别" << "\t编号" << "\t名称" << "\t进价" << "\t售价"
		<< "\t库存" << "\t厂家" << "\t品牌" << endl;

	cout << v->Classify() << "\t" << v->m_id << "\t" << v->m_name << "\t" << v->m_inprice << "\t"
		<< v->m_outprice << "\t" << v->m_inventory << "\t" << v->m_manufacturer << "\t" << v->m_brand << endl;
}

void ShopManage::Information(vector<Note>& v)
{
	cout << "记录\t商品\t名称\t数量\t价格" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].m_noteid << "\t" << v[i].m_goodsid << "\t" << v[i].m_name << "\t"
			<< v[i].m_number << "\t" << v[i].m_price << endl;
	}
}

int ShopManage::Query()
{
	cout << "1.商品类别 2.商品名称 3.生产厂家" << endl;
	int c = ChooseInt(1, 3, "请输入: "), count = 0;

	string t;
	cout << "请输入查询名称: ";
	cin >> t;

	vector<Goods*> v;

	for (int i = 0; i < m_Goods.size(); i++)
	{
		size_t x = 0;
		if (c == 1)	x = m_Goods[i]->Classify().find(t);
		else if(c == 2)	x = m_Goods[i]->m_name.find(t);
		else if(c == 3)	x = m_Goods[i]->m_manufacturer.find(t);
		if (x != string::npos)	v.push_back(m_Goods[i]), count++;
	}
	
	if (count == 0)	cout << "记录不存在!\n";
	else Information(v);
	return count;
}


struct cmp
{
	cmp(int x) { c = x; }
	bool operator()(Goods* a, Goods* b)
	{
		if (c == 1)	return a->m_inprice > b->m_inprice;
		else if(c == 2)	return a->m_outprice > b->m_outprice;
		else if (c == 3)	return a->m_inventory > b->m_inventory;
		return a->m_manufacturer > b->m_manufacturer;
	}
	bool operator()(Note &a, Note &b)
	{
		if (c == 1)	return a.m_price > b.m_price;
		return a.m_number > b.m_number;
	}
	int c;
};
void ShopManage::Count()
{
	cout << "选择统计依据 1.进价 2.售价 3.库存量 4.生产厂家 0.返回\n";
	int c = ChooseInt(0,4);
	if (c == 0)	return;

	cmp cm(c);
	sort(m_Goods.begin(), m_Goods.end(), cm);

	Information(m_Goods);

	cout << "总共" << m_Goods.size() << "个商品" << endl;

}



void ShopManage::Record()
{
	cout << "请选择统计依据 1.价格 2.数量 0.返回\n";
	int c = ChooseInt(0, 2);
	if (c == 0)	return;

	cmp cm(c);
	sort(m_Note.begin(), m_Note.end(), cm);

	if (m_Note.size() > 0)
	{
		Information(m_Note);
		cout << "总共" << m_Note.size() << "个记录" << endl;

		do
		{
			cout << "1.退货 0.返回\n";
			c = ChooseInt(0, 1);

			if (c == 1)
			{
				cout << "请输入要退货的记录编号: ";
				cin >> c;

				int count = 0;
				for (int i = 0; i < m_Note.size(); i++)
				{
					if (m_Note[i].m_noteid == c)
					{
						

						for (int j = 0; j < m_Goods.size(); j++)
						{
							if (m_Goods[j]->m_id == m_Note[i].m_goodsid)
							{
								count++;
								m_Goods[j]->m_inventory += m_Note[i].m_number;
								m_Note.erase(m_Note.begin() + i, m_Note.begin() + i + 1);
								break;
							}
						}
						
						
						break;
					}
				}
				if (count)	cout << "退货成功\n";
				else cout << "未找到记录\n";
			}
		} while (c);
	}
	else cout << "记录为空\n";
}

void ShopManage::Delete()
{
	cout << "请选择要删除的商品类别" << endl;
	cout << "1.化妆品 2.食品 3.日用品 4.饮料 0.返回\n";
	int c = ChooseInt(0, 4);
	if (c == 0)	return;

	Information(m_Goods, Cls[c]);

	cout << "请输入要删除的商品编号: ";
	int s;
	cin >> s;
	int count = 0;
	for (int i = (int)m_Goods.size()-1; i >= 0 ; i--)
	{
		if (m_Goods[i]->m_id == s && m_Goods[i]->Classify() == Cls[c])
		{
			count++;
			m_Goods.erase(m_Goods.begin() + i, m_Goods.begin() + i+1);
		}
	}
	if (count)	cout << "删除成功\n";
	else cout << "该商品不存在\n";
}

void ShopManage::Modify(Goods* goods)
{
	int c = 0;
	do
	{
 		Information(goods);
		cout << "选择要修改的项: \n";
		cout << "1.名称 2.进价 3.售价 4.商品库存 5.厂家 6.品牌 0.退出\n";
		c = ChooseInt(0, 6);
		if (c == 0)	return;
		else
		{
			cout << "请输入: ";
			if (c == 1) cin >> goods->m_name;
			else if (c == 2)	cin >> goods->m_inprice;
			else if (c == 3)	cin >> goods->m_outprice;
			else if (c == 4)	cin >> goods->m_inventory;
			else if (c == 5)	cin >> goods->m_manufacturer;
			else if (c == 6)	cin >> goods->m_brand;
		}
	} while (c);

}

void ShopManage::GoodsManage()
{
	int c = 0,id;
	do
	{
		cout << "1.添加商品 2.查询商品 3.删除商品 0.返回\n";
		c = ChooseInt(0, 3, "请选择功能: ");

		if (c == 1)	Add();
		else if (c == 2)
		{
			int count = Query();
			do
			{
				cout << "输入编号修改商品(输入0退出): ";
				cin >> id;
				for (int i = 0; i < m_Goods.size(); i++)
				{
					if (m_Goods[i]->m_id == id)	Modify(m_Goods[i]);
				}
			} while (id);
		}
		else if (c == 3)	Delete();
	} while (c);

	
}

void ShopManage::Add()
{
	int inventory,id;
	string name, manufacturer, brand;
	double ip,op;
	Goods* g;
	cout << "1.化妆品 2.食品 3.日用品 4.饮料\n";
	int c = ChooseInt(1, 4, "请选择类别: ");

	cout << "请输入名称: ";
	cin >> name;
	cout << "请输入进价: ";
	cin >> ip;
	cout << "请输入售价: ";
	cin >> op;
	cout << "请输入库存: ";
	cin >> inventory;
	cout << "请输入厂家: ";
	cin >> manufacturer;
	cout << "请输入品牌: ";
	cin >> brand;
	id = ++Goods::maxid;
	if (c == 1)	g = new Cosmetics(id, name, ip,op, inventory, manufacturer, brand);
	else if (c == 2)	g = new Food(id, name, ip, op, inventory, manufacturer, brand);
	else if (c == 3)	g = new Commodity(id, name, ip, op, inventory, manufacturer, brand);
	else if (c == 4)	g = new Drink(id, name, ip, op, inventory, manufacturer, brand);
	m_Goods.push_back(g);
}

void ShopManage::Menu()
{
	cout << "***************************************\n";
	cout << "              1.销售\n";
	cout << "              2.商品管理\n";
	cout << "              3.售出统计\n";
	cout << "              4.库存统计\n";
	cout << "              0.退出并保存\n";
	cout << "***************************************\n";
}