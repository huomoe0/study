#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
using namespace std;
typedef struct node
{
    bool sign;
    int data;
    node* l, *r;

    node()
    {
        l = r = nullptr;
        sign = 0;
    }

}* Tree;
map<string,int> mp;
map<int ,int> np;
map<int, char> sg;

// add(sub(13,10),sub(13,10))
int expressionToTree(Tree &tree, string &exp, int idx) //返回结束后所处下标
{
    int t = idx;
    while (isalpha(exp[t])) t++;
    string s = exp.substr(idx,t-idx);
    tree = new node;
    tree->sign = 1, tree->data = mp[s];
    //开始取第一个操作数
    t++;
    if(isalpha(exp[t]))
    {
        t = expressionToTree(tree->l, exp, t) + 1;

    }
    else
    {
        int data = 0;
        while (isdigit(exp[t])) data = data*10 + exp[t] - '0', t++;
        tree->l = new node;
        tree->l->data = data;
    }
    //判断有没有第二个操作数
    if(exp[t] == ')')   return t;

    //开始取第二个操作数
    t++;
    if(isalpha(exp[t]))
    {
        t = expressionToTree(tree->r, exp, t) + 1;
    }
    else
    {
        int data = 0;
        while (isdigit(exp[t])) data = data*10 + exp[t] - '0', t++;
        tree->r = new node;
        tree->r->data = data;
    }
    return t;
}

int last_print(Tree &tree, string &str, int &priority)
{

    if(tree == NULL)    return 0;
    if(tree->l == NULL && tree->r == NULL)
    {
        stringstream ss;
        ss << tree->data;
        ss >> str;
        return tree->data;
    }
    if(tree->sign == 1)  priority = np[tree->data];

    string l, r;
    int a,b;
    a = last_print(tree->l,str,priority);
    if(tree->l->sign == 1 && priority < np[tree->data]) l =  "(" + str + ")";
    else l = str;

    if(tree->r != NULL)
    {
        b = last_print(tree->r, str, priority);
        if(tree->r->sign == 1 && priority < np[tree->data]) r =  "(" + str + ")";
        else r = str;
    }

    if(sg[tree->data] == '^')   str = l + "^2";
    else if(sg[tree->data] == '~')
    {
        if(l[0] == '-') str = l.substr(1);
        else str = "-" + l;
    }
    else
    {
        str = l + " " + sg[tree->data] + " " + r;
    }




    if(tree->sign==0) return tree->data;
    switch (tree->data)
    {
        case '+':
            return a + b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case 2: //doubleMe
            return 2*a;
        case 1:
            return -a;

    }
}



int main()
{
    mp["add"] = '+', mp["sub"] = '-', mp["muti"] = '*', mp["div"] = '/', mp["doubleMe"] = 2, mp["neg"] = 1;
    np['+']=1,np['-']=1,np['*']=2,np['/']=2,np[2]=3,np[1]=3;
    sg['+'] = '+',sg['-'] = '-',sg['*'] = '*',sg['/'] = '/',sg[2] = '^',sg[1] = '~';
    fstream fs("question.txt", ios::in);
    fstream fout("answer.txt", ios::out);
    string exp;
    while (getline(fs, exp))
    {
        Tree tree;
        expressionToTree(tree, exp, 0);
        int pro;
        string  s;
        int res = last_print(tree,s,pro);
        fout << s << " = " << res << "\n";
    }
    return 0;
}