//附赠小游戏：

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
    int a = 0, sheng = 20, gong = 10, fang = 10, b, shengm = 20, yao = 0;
    int guais, guaig, qian = 0, c;
    while (a == 0)
    {
        cout << "1.勇者商店" << endl;
        cout << "2.讨伐魔物" << endl;
        cout << "3.角色资料" << endl;
        cout << "请选择..." << endl;
        cout << endl;
        cin >> b;
        if (b == 1)
        {
            cout << "1.装备" << endl;
            cout << "2.药品" << endl;
            cout << "输入0退出" << endl;
            cout << endl;
            cin >> b;
            if (b == 1)
            {
                while (b != 0)
                {
                    cout << "1.武器" << endl;
                    cout << "2.盾牌" << endl;
                    cout << "3.盔甲" << endl;
                    cout << "输入0退出" << endl;
                    cout << endl;
                    cin >> b;
                    if (b == 1)
                    {
                        cout << "1.骑士长剑（+10） 价值：20" << endl;
                        cout << "2.石中剑（+20） 价值40" << endl;
                        cout << "3.魔王的右手（+90） 价值150" << endl;
                        cout << "输入4退出" << endl;
                        cout << endl;
                        cin >> b;
                        if (b == 1 && qian >= 20)
                        {
                            gong = 20;
                            qian -= 20;
                            cout << "自身攻击" << gong << endl;
                        }
                        if (b == 2 && qian >= 40)
                        {
                            gong = 30;
                            qian -= 40;
                            cout << "自身攻击" << gong << endl;
                        }
                        if (b == 3 && qian >= 150)
                        {
                            gong = 100;
                            qian -= 150;
                            cout << "自身攻击" << gong << endl;
                        }
                    }
                    if (b == 2)
                    {
                        cout << "1.皇家盾牌（+10） 价值：20" << endl;
                        cout << "2.永恒堡垒（+20） 价值40" << endl;
                        cout << "3.魔王的左手（+90） 价值150" << endl;
                        cout << "输入4退出" << endl;
                        cout << endl;
                        cin >> b;
                        if (b == 1 && qian >= 20)
                        {
                            fang = 20;
                            qian -= 20;
                            cout << "自身防御" << fang << endl;
                        }
                        if (b == 2 && qian >= 40)
                        {
                            fang = 30;
                            qian -= 40;
                            cout << "自身防御" << fang << endl;
                        }
                        if (b == 3 && qian >= 150)
                        {
                            fang = 100;
                            qian -= 150;
                            cout << "自身防御" << fang << endl;
                        }
                    }
                    if (b == 3)
                    {
                        cout << "1.战争盔甲（+10） 价值：20" << endl;
                        cout << "2.不灭龙甲（+20） 价值40" << endl;
                        cout << "3.魔王的精华（+90） 价值150" << endl;
                        cout << "输入4退出" << endl;
                        cout << endl;
                        cin >> b;
                        if (b == 1 && qian >= 20)
                        {
                            shengm = 20;
                            qian -= 20;
                            cout << "自身生命" << shengm << endl;
                        }
                        if (b == 2 && qian >= 40)
                        {
                            shengm = 30;
                            qian -= 40;
                            cout << "自身生命" << shengm << endl;
                        }
                        if (b == 3 && qian >= 150)
                        {
                            shengm = 100;
                            qian -= 150;
                            cout << "自身生命" << shengm << endl;
                        }
                    }
                }
            }
            if (b == 2)
            {
                cout << "1.快速回复（花费1）" << endl;
                cout << "2.恢复药剂（花费5）*5" << endl;
                cout << "输入0退出" << endl;
                cout << endl;
                cin >> b;
                if (b == 1 && qian >= 1)
                {
                    sheng = shengm;
                    qian--;
                    cout << "自身生命" << sheng << endl;
                }
                if (b == 2 && qian >= 5)
                {
                    yao = yao + 5;
                    cout << "药品数量" << yao << endl;
                }
            }
        }
        else if (b == 2)
        {
            cout << "1.小怪" << endl;
            if (gong >= 15)
            {
                cout << "2.魔头" << endl;
                if (gong >= 20)
                {
                    cout << "3.大魔王" << endl;
                    cout << "输入0退出" << endl;
                    cout << endl;
                    cin >> b;
                }
                else
                {
                    cout << "输入0退出" << endl;
                    cout << endl;
                    cin >> b;
                }
            }
            else
            {
                cout << "输入0退出" << endl;
                cout << endl;
                cin >> b;
            }
            if (b == 1)
            {
                guais = 30;
                guaig = 5;
                c = 5;
                while (guais > 0 && sheng > 0)
                {
                    cout << "1.攻击" << endl;
                    cout << "2.防御（次数" << c << "）" << endl;
                    cout << "3.回复（闪避）" << endl;
                    cout << endl;
                    cin >> b;
                    if (b == 1)
                    {
                        guais = guais - gong;
                        sheng = sheng - guaig;
                        cout << "怪物生命"
                             << "-" << gong << "=" << guais << endl;
                        cout << "自身生命"
                             << "-" << guaig << "=" << sheng << endl;
                    }
                    if (b == 2 && c != 0)
                    {
                        if (fang >= guaig)
                        {
                            guais = guais - (fang - guaig);
                            cout << "怪物生命"
                                 << "-" << fang - guaig << "=" << guais << endl;
                        }
                        else
                        {
                            sheng = sheng - (guaig - fang);
                            cout << "自身生命"
                                 << "-" << guaig - fang << "=" << sheng << endl;
                        }
                        c--;
                    }
                    if (b == 3 && yao > 0)
                    {
                        yao--;
                        sheng = sheng + 20;
                        if (sheng > shengm)
                            sheng = shengm;
                        cout << "药品数量" << yao << endl;
                        cout << "自身生命+20（" << sheng << "）" << endl;
                    }
                    if (sheng <= 0)
                    {
                        cout << "你死了" << endl;
                        break;
                    }
                }
                if (sheng > 0)
                {
                    qian = qian + 2;
                    cout << "金币"
                         << "+2" << endl;
                }
                cout << endl;
            }
            if (b == 2)
            {
                guais = 50;
                guaig = 10;
                c = 7;
                while (guais > 0 && sheng > 0)
                {
                    cout << "1.攻击" << endl;
                    cout << "2.防御（次数" << c << "）" << endl;
                    cout << "3.回复（闪避）" << endl;
                    cout << endl;
                    cin >> b;
                    if (b == 1)
                    {
                        guais = guais - gong;
                        sheng = sheng - guaig;
                        cout << "怪物生命"
                             << "-" << gong << "=" << guais << endl;
                        cout << "自身生命"
                             << "-" << guaig << "=" << sheng << endl;
                    }
                    if (b == 2 && c != 0)
                    {
                        if (fang >= guaig)
                        {
                            guais = guais - (fang - guaig);
                            cout << "怪物生命"
                                 << "-" << fang - guaig << "=" << guais << endl;
                        }
                        else
                        {
                            sheng = sheng - (guaig - fang);
                            cout << "自身生命"
                                 << "-" << guaig - fang << "=" << sheng << endl;
                        }
                        c--;
                    }
                    if (b == 3 && yao > 0)
                    {
                        yao--;
                        sheng = sheng + 20;
                        if (sheng > shengm)
                            sheng = shengm;
                        cout << "药品数量" << yao << endl;
                        cout << "自身生命+20（" << sheng << "）" << endl;
                    }
                    if (sheng <= 0)
                    {
                        cout << "你死了" << endl;
                        break;
                    }
                }
                if (sheng > 0)
                {
                    qian = qian + 10;
                    cout << "金币"
                         << "+10" << endl;
                }
                cout << endl;
            }
            if (b == 3)
            {
                guais = 100;
                guaig = 20;
                c = 15;
                while (guais > 0 && sheng > 0)
                {
                    cout << "1.攻击" << endl;
                    cout << "2.防御（次数" << c << "）" << endl;
                    cout << "3.回复（闪避）" << endl;
                    cout << endl;
                    cin >> b;
                    if (b == 1)
                    {
                        guais = guais - gong;
                        sheng = sheng - guaig;
                        cout << "怪物生命"
                             << "-" << gong << "=" << guais << endl;
                        cout << "自身生命"
                             << "-" << guaig << "=" << sheng << endl;
                    }
                    if (b == 2 && c != 0)
                    {
                        if (fang >= guaig)
                        {
                            guais = guais - (fang - guaig);
                            cout << "怪物生命"
                                 << "-" << fang - guaig << "=" << guais << endl;
                        }
                        else
                        {
                            sheng = sheng - (guaig - fang);
                            cout << "自身生命"
                                 << "-" << guaig - fang << "=" << sheng << endl;
                        }
                        c--;
                    }
                    if (b == 3 && yao > 0)
                    {
                        yao--;
                        sheng = sheng + 20;
                        if (sheng > shengm)
                            sheng = shengm;
                        cout << "药品数量" << yao << endl;
                        cout << "自身生命+20（" << sheng << "）" << endl;
                    }
                    if (sheng <= 0)
                    {
                        cout << "你死了" << endl;
                        break;
                    }
                }
                if (sheng > 0)
                {
                    qian = qian + 100;
                    cout << "金币"
                         << "+100" << endl;
                }
                cout << endl;
            }
        }
        else if (b == 3)
        {
            printf("请稍后");
            for (int i = 1; i <= 5; i++)
            {
                printf(".");
                Sleep(500);
            }
            printf("\n自身资料\n");
            printf("----------------------------------------------\n");
            printf("生命: %d ", sheng);
            printf("攻击: %d\n\n", gong);
            printf("防御: %d ", fang);
            printf("生命上限: %d\n\n", shengm);
            printf("金币: %d ", qian);
            cout << endl
                 << endl;
        }
    }
    return 0;
}