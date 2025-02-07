#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 11; }
void do_welcome(string arg);
void do_accept(string arg);

// 函数：构造处理
void create()
{
        set_name("传送兔妖");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who)
{
	int id;
	object me=this_object();
	id = getoid(me);
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("传送兔妖：\n     这位侠士，你好，我是这里最善良最可爱的妖怪：兔妖。如果你想回周国的话，小妖我可以送你回去哦，如果你要查询现在这里你们的清怪率的话，我可以告诉你呀。怎么样我很好，很善良吧？\n"ESC"请送我回周国！\ntalk %x# welcome.1\n"ESC"现在我们的清怪率是多少？\ntalk %x# welcome.2\n"ESC"离开",id,id,));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,j,tId;
       	object who, map;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
		who->add_to_scene(80,258,158);
        	break;
        case 2:
        	tId = who->get_team_id();
        	map = TEAM_D->get_copy_scene(tId,COPY_MIRROR);
		if ( !map )
			return ;
		i = map->get("copy_npc_die");
		j = map->get("copy_npc_amount");
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("传送兔妖：\n    你们现在的清怪率是%d。想要发现王者的残魂的话，清怪率需要达到85。\n"ESC"离开",i*100/j));
        	break;
        }

}
