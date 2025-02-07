#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 2111; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("陵墓石狮");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
//        set_head_color(0x39eb);
        setup();
}

void do_look(object who)
{
	int id,level;
	object me=this_object();

	id = getoid(me);
	level = who->get_level();
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("拉动这个石狮子上的机关的话，我就可以回到上层陵墓了。现在要拉动这个机关回到上一层陵墓吗？\n"ESC"回到上一层\ntalk %x# welcome.55\n"ESC"取消",id,));
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
		tId = who->get_team_id();
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_TOMB1);
        		if ( !map )
        			return ;
        		nXy = map->get("entrance2");
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "传送中……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;
	}
}
