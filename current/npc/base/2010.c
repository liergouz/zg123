
// 自动生成：/make/npc/make0010

#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_goto( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5410; }

// 函数：构造处理
void create()
{
        set_name("驿站老板");
	set_real_name("游腾");
        set_city_name("韩国");

        set_2( "talk", ([
                "goto"    : (: do_goto :),
        ]));

        setup();
}

// 函数：对话处理
void do_look( object who )
{
	"/sys/task/travel"->do_look(this_object(), who);        
}

// 函数：移动处理
void do_goto( string  arg )
{
	"/sys/task/travel"->do_goto(this_object(), this_player(), arg);     
}