#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 853; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("无双宫守卫");
//        set_2( "talk", ([
//                 "welcome"         : (: do_welcome :),
//        ]) );
        setup();
}

void do_look(object who) { __FILE__->do_look_call(this_object(),who); }

void do_look_call(object me,object who)
{
	string org_name;
	
	org_name = WUSHUANG->get_occupy_org();
	
	if ( !sizeof(org_name) )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    现在无双城正处于无人占领的状态。\n"ESC"离开",me->get_name()));
		return ;		
	}
	if ( WUSHUANG->check_war_time() == 1 )
	{
		if ( org_name == who->get_org_name() )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    现在正是攻城时间，请好好保护宫殿，不要被敌帮派抢夺了！\n"ESC"离开",me->get_name()));
		else 
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    来者何人！？我要叫守卫了！\n"ESC"离开",me->get_name()));
	}
	else 
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    无双宫为"HIR"%s"NOR"禁地，非本帮的闲杂人等一律禁止进入！！\n"ESC"离开",me->get_name(),org_name));
}

