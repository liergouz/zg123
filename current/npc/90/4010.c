
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_goto( string arg );

// 函数：获取人物造型
int get_char_picid() { return 9401; }

// 函数：获取门派名称
string get_fam_name() { return "唐门"; }

// 函数：获取升级顺序
int get_fam_order() { return 6; }


// 函数：构造处理
void create()
{
        set_name("唐家家丁");
        set_real_name("传送人");

        set_2( "talk", ([
                "go"   : (: do_goto :),
        ]));

        setup();
}

// 函数：对话处理
void do_look( object who )
{
	"/sys/task/travel"->do_look2(this_object(), who);        
}

// 函数：移动处理
void do_goto( string  arg )
{
	"/sys/task/travel"->do_goto2(this_object(), this_player(), arg);     
}