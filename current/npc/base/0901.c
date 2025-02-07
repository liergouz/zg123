#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <effect.h>

inherit OFFICER;

void do_goto( string arg );
void do_welcome( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5205; }

// 函数：构造处理
void create()
{
        set_name("巨兽岛传送人");
        set_city_name("巨兽岛");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me=this_object();
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    最近来这里探险的人越来越多，可总是来的多、回的少，这位客官小心为妙啊～！\n"ESC"麻烦送我回周国吧\ntalk %x# welcome.23\n"ESC"离开",me->get_name(),getoid(me)));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who, item;     
        string result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 23:
        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "传送中……");	                
                who->set_2("travel.z", 80);
                who->set_2("travel.p", 330118);
                who->set_2("travel.money", 0);
                set_effect(who, EFFECT_TRAVEL, 3);
		break;
	}		
}
