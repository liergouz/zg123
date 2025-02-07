
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 8112; }

// 函数：构造处理
void create()
{
        set_name("福哈哈");
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
			cmd="哈哈哈哈～～春天真暖和～～";
		break;
	        case 1:
			cmd="哈哈哈哈～～新年到处爆竹声声，真热闹～～";
		break;
	        case 2:
			cmd="哈哈哈哈～～新年到了～～赶快去神仙爷爷哪里领取礼物吧～～";
		break;
		case 3:
			cmd="哈哈哈哈～～新年到处乐洋洋，大家也应该开开心心～～";
		break;
		case 4:
			cmd="哈哈哈哈～～我好开心哦～～";
		break;
		case 5:
			cmd="哈哈哈哈～～我是新年福娃娃中的福哈哈～～乐观的福哈哈～～^_^。";
		break;
		case 6:
			cmd="哈哈哈哈～～人～有～悲～欢～离～合，月～有～阴～晴～残～缺。哈哈～。";
		break;
		case 7:
			cmd="哈哈哈哈～～新年到了，你领了压岁钱了吗？";
		break;
	}
        result = get_name() + "：\n    "+cmd+"\n"+
       		ESC "确定\nCLOSE\n";
        send_user( who, "%c%c%w%s", ':', 3, 8112, result );  
}

