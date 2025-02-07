#include <npc.h>
#include <city.h>
#include <ansi.h>
inherit SAVE_F;
inherit OFFICER;

void do_bonus(string arg);


// 函数：获取人物造型
int get_char_picid() { return 5302; }

// 函数：构造处理
void create()
{
	int i,size,*nTmp;
        set_name("点卡寄售员");

        set_2( "talk", ([
                 "bonus"         : (: do_bonus :),
        ]) );

        setup();
}

void do_look( object who )
{
	__FILE__->do_look_2(who, this_object());
}

void do_look_2( object who, object me )
{
	int id;
	id = getoid(me);
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		me->get_name()+":\n    本人受商铺总管所托，在此为大家点卡寄售作公平之验证，尔可放心将点卡放于本人之手，本人定会按受托人要求公证行事！\n"
		+ sprintf(ESC"寄售注意事项\ntalk %x# bonus.1\n"
		ESC"我来寄售点卡\ntalk %x# bonus.10\n"
		ESC"我来购买点卡\ntalk %x# bonus.20\n"
		ESC"查询我的元宝寄售\nconsign status\n"
		ESC"离开", id, id, id ) );	
}


void do_bonus(string arg)
{
	__FILE__->do_bonus_2(this_player(),this_object(),arg);
}

void do_bonus_2(object me , object who, string arg)
{
	int id, flag;
	string result;
	flag = to_int(arg);
	id = getoid(who);
	switch(flag)
	{
	case 1:
		result = sprintf("%s：\n    寄售者在寄售元宝时须预缴纳1元宝的寄售费用。在点卡成功寄售后，本人可为你提供八小时、十二小时或者二十四小时的寄售服务，超过时间后，你所寄售的点卡还未被购买，本人将你所寄售的元宝作下架处理，被作下架处理的元宝仍为有效，可以再次寄售！\n", who->get_name());
		result += ESC"离开";
		send_user( me, "%c%c%w%s",':', 3, who->get_char_picid(), result );
		break;		
	case 10:
		send_user(me, "%c%c%c", 0x92, 1, 1);
		break;
	case 20:
		result = sprintf("%s：\n    请选择要购买的点卡的金额：\n", who->get_name());
		result += ESC "50元宝\nconsign list 50\n";
		result += ESC "100元宝\nconsign list 100\n";
		result += ESC "200元宝\nconsign list 200\n";
		result += ESC"离开";
		send_user( me, "%c%c%w%s",':', 3, who->get_char_picid(), result );
		break;
	}
}

