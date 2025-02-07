
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_work();

// 函数：获取人物造型
int get_char_picid() { return 5601; }

// 函数：构造处理
void create()
{
        set_name( "工头" );

        set_2( "talk", ([
                "work"          : (: do_work() :),
        ]));

        setup();
}

// 函数：对话处理
void do_look( object who )
{
        string cmd = sprintf( "talk %x# work\n", getoid( this_object() ) );

        if( who->get_strength() >= 20 )
                more_look_menu( who, get_name() + sprintf("：\n噢？这位%s愿意帮我的忙吗？这可是义务劳动，还愿意做吗？\n" ,NPC_RANK_D->get_respect_2(who))+
                        ESC "没问题。\n" + cmd +
                        ESC "再见。\nCLOSE\n" );
//        if( who->get_strength() >= 10 )
//                more_look_menu( who, get_name() + "：\n我这里有些体力活，你有兴趣干吗？\n" 
//                        ESC "工作。(需 10 点体力)\n" + cmd +
//                        ESC "离开。\nCLOSE\n" );                        
        else    more_look_menu( who, get_name() + "：\n今天你累成这样，还是回家休息吧。\n" );
}

// 函数：工作处理
void do_work()
{
	TASK_WORKER_D->begin_work(this_player(),NEWBIE_WORK);
}
