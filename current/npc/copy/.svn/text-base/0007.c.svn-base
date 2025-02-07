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
        set_name("机关石狮");
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
	object me=this_object(),map;

	id = getoid(me);
	map = me->get("map");
	if ( !map )
		return ;
	if ( map->get("open_gate") == 0 )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"这个石狮上面有一处明显的机关，而通往下层陵墓的门也被紧紧关闭着。石狮的头顶上刻这几个字：“开启石狮要到制俑工房”，看来要打开机关石狮后面的门，就要先到"HIR"制俑工房"NOR"去看一趟。\n"ESC"离开");
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("现在只要拉动这个石狮子上的机关我就可以进入下一层陵墓了，下一层陵墓里面应该会遇到更强的敌人，现在要进入下一层陵墓吗？\n"ESC"进入下一层\ntalk %x# welcome.77\n"ESC"取消",id,));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy, level;
       	object who, item,map;
       	string legend;
        who = this_player();
        flag = to_int(arg);
        level = who->get_level();
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 77:
        	map = me->get("map");
		if ( !map )
			return ;
		if ( map->get("open_gate") == 0 )
			return ;
		tId = who->get_team_id();
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_TOMB2);
        		if ( !map )	//创建副本
        		{
        			map = "sys/copy/tomb"->new_copy_tomb2(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance1");
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "传送中……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;
	}
}


