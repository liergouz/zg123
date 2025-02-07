
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
        set_city_name("周国");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me=this_object();
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    据说在遥远的东海岸，有一个渔民出海打鱼，发现了一片神奇的陆地，上面有很多鲜为人知的秘密！你想去那里探险吗？\n"ESC"去巨兽岛探险\ntalk %x# welcome.23\n"ESC"离开",me->get_name(),getoid(me)));
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
		p = 166148;
        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "传送中……");	                
                who->set_2("travel.z", 549);
                who->set_2("travel.p", p);
                who->set_2("travel.money", 0);
                set_effect(who, EFFECT_TRAVEL, 3);
		break;
	}		
}
