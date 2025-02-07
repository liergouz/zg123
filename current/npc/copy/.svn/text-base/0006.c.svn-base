#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 0450; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("逃亡的苦役");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        set_head_color(0x39eb);
        setup();
}

void do_look(object who)
{
	int id,level;
	object me=this_object();

	id = getoid(me);
	level = who->get_level();
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    这里就是地狱似的骊山陵墓了。如果你想要离开的话，我可以带你回翠华山啊……你现在要离开这里吗？\n"ESC"离开骊山陵墓\ntalk %x# welcome.55\n"ESC"取消",id,));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy;
       	object who, item,map;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 55:
        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "传送中……");
	        who->set_2("travel.z", 82);
	        who->set_2("travel.p", 136117);
	        set_effect(who, EFFECT_TRAVEL, 6);
		break;
	}
}
