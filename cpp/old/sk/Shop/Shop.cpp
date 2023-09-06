#include "Shop.h"
using namespace std;

string Cls[] = { "", "��ױƷ","ʳƷ", "����Ʒ" ,"����" };

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


string Cosmetics::Classify(){return "��ױƷ";}
string Food::Classify() { return "ʳƷ"; }
string Commodity::Classify() { return "����Ʒ"; }
string Drink::Classify() { return "����"; }

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
	cout << "1.��ױƷ 2.ʳƷ 3.����Ʒ 4.���� 0.����\n";
	int c = ChooseInt(0, 4),pos;
	if (c == 0)	return;

	Information(m_Goods,Cls[c]);

	cout << "��������Ʒ����: ";
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
				cout << "��ѡ����Ʒ���: ";
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
		
		cout << "�����빺������: ";
		c = ChooseInt(0);
		if (c <= v[pos]->m_inventory)
		{
			cout << "����ɹ�\n";
			Note t(v[pos]->m_id,v[pos]->m_name, c, v[pos]->m_outprice);
			m_Note.push_back(t);
			v[pos]->m_inventory -= c;
		}
		else cout << "��治��\n";
	}
	else cout << "δ�ҵ�����Ʒ\n";
}


void ShopManage::Load()
{
	fstream fs("goods.txt", ios::in);
	if (!fs) //��ʧ��
	{
		fstream t("goods.txt", ios::out); //�����ļ�
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
	if (!fs) //��ʧ��
	{
		fstream t("note.txt", ios::out); //�����ļ�
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
	cout << "���"  << "\t���" << "\t����" << "\t����"  << "\t�ۼ�"
		<< "\t���" << "\t����" << "\tƷ��"  << endl;

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
	cout << "���" << "\t���" << "\t����" << "\t����" << "\t�ۼ�"
		<< "\t���" << "\t����" << "\tƷ��" << endl;

	cout << v->Classify() << "\t" << v->m_id << "\t" << v->m_name << "\t" << v->m_inprice << "\t"
		<< v->m_outprice << "\t" << v->m_inventory << "\t" << v->m_manufacturer << "\t" << v->m_brand << endl;
}

void ShopManage::Information(vector<Note>& v)
{
	cout << "��¼\t��Ʒ\t����\t����\t�۸�" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].m_noteid << "\t" << v[i].m_goodsid << "\t" << v[i].m_name << "\t"
			<< v[i].m_number << "\t" << v[i].m_price << endl;
	}
}

int ShopManage::Query()
{
	cout << "1.��Ʒ��� 2.��Ʒ���� 3.��������" << endl;
	int c = ChooseInt(1, 3, "������: "), count = 0;

	string t;
	cout << "�������ѯ����: ";
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
	
	if (count == 0)	cout << "��¼������!\n";
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
	cout << "ѡ��ͳ������ 1.���� 2.�ۼ� 3.����� 4.�������� 0.����\n";
	int c = ChooseInt(0,4);
	if (c == 0)	return;

	cmp cm(c);
	sort(m_Goods.begin(), m_Goods.end(), cm);

	Information(m_Goods);

	cout << "�ܹ�" << m_Goods.size() << "����Ʒ" << endl;

}



void ShopManage::Record()
{
	cout << "��ѡ��ͳ������ 1.�۸� 2.���� 0.����\n";
	int c = ChooseInt(0, 2);
	if (c == 0)	return;

	cmp cm(c);
	sort(m_Note.begin(), m_Note.end(), cm);

	if (m_Note.size() > 0)
	{
		Information(m_Note);
		cout << "�ܹ�" << m_Note.size() << "����¼" << endl;

		do
		{
			cout << "1.�˻� 0.����\n";
			c = ChooseInt(0, 1);

			if (c == 1)
			{
				cout << "������Ҫ�˻��ļ�¼���: ";
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
				if (count)	cout << "�˻��ɹ�\n";
				else cout << "δ�ҵ���¼\n";
			}
		} while (c);
	}
	else cout << "��¼Ϊ��\n";
}

void ShopManage::Delete()
{
	cout << "��ѡ��Ҫɾ������Ʒ���" << endl;
	cout << "1.��ױƷ 2.ʳƷ 3.����Ʒ 4.���� 0.����\n";
	int c = ChooseInt(0, 4);
	if (c == 0)	return;

	Information(m_Goods, Cls[c]);

	cout << "������Ҫɾ������Ʒ���: ";
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
	if (count)	cout << "ɾ���ɹ�\n";
	else cout << "����Ʒ������\n";
}

void ShopManage::Modify(Goods* goods)
{
	int c = 0;
	do
	{
 		Information(goods);
		cout << "ѡ��Ҫ�޸ĵ���: \n";
		cout << "1.���� 2.���� 3.�ۼ� 4.��Ʒ��� 5.���� 6.Ʒ�� 0.�˳�\n";
		c = ChooseInt(0, 6);
		if (c == 0)	return;
		else
		{
			cout << "������: ";
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
		cout << "1.�����Ʒ 2.��ѯ��Ʒ 3.ɾ����Ʒ 0.����\n";
		c = ChooseInt(0, 3, "��ѡ����: ");

		if (c == 1)	Add();
		else if (c == 2)
		{
			int count = Query();
			do
			{
				cout << "�������޸���Ʒ(����0�˳�): ";
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
	cout << "1.��ױƷ 2.ʳƷ 3.����Ʒ 4.����\n";
	int c = ChooseInt(1, 4, "��ѡ�����: ");

	cout << "����������: ";
	cin >> name;
	cout << "���������: ";
	cin >> ip;
	cout << "�������ۼ�: ";
	cin >> op;
	cout << "��������: ";
	cin >> inventory;
	cout << "�����볧��: ";
	cin >> manufacturer;
	cout << "������Ʒ��: ";
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
	cout << "              1.����\n";
	cout << "              2.��Ʒ����\n";
	cout << "              3.�۳�ͳ��\n";
	cout << "              4.���ͳ��\n";
	cout << "              0.�˳�������\n";
	cout << "***************************************\n";
}