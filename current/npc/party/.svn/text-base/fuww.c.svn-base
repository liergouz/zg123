
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 8111; }

// 函数：构造处理
void create()
{
        set_name("福哇哇");
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	string result,cmd;
	int i=random(8);
        switch(i)
        {
	        case 0:
			cmd="哇哇哇哇～～看不见下雪了～～～哇哇～";
		break;
	        case 1:
			cmd="哇哇哇哇～～我的压岁钱怎么这么少？";
		break;
	        case 2:
			cmd="哇哇哇哇～～新年到处放爆竹，好可怕哦～～";
		break;
		case 3:
			cmd="哇哇哇哇～～神仙爷爷只给了我很少礼物～～";
		break;
		case 4:
			cmd="哇哇哇哇～～我就是要哭，我就是要哭～～～";
		break;
		case 5:
			cmd="哇哇哇哇～～～～～";
		break;
		case 6:
			cmd="哇哇哇哇～～我是新年福娃娃中的福哇哇，悲观的福哇哇，哇哇～～";
		break;
		case 7:
			cmd="哇哇哇哇～～明～月～几～时～有，把～酒～问～青～天。哇～～";
		break;
	}
        result = get_name() + "：\n    "+cmd+"\n"+
       		ESC "确定\nCLOSE\n";
        send_user( who, "%c%c%w%s", ':', 3, 8111, result );  
}
