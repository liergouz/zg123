
// 自动生成：/make/npc/make0007

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// 函数：修理师傅
int is_repairer() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5407; }

// 函数：构造处理
void create()
{
        set_name("修理店老板");
	set_real_name("乔妙");
        set_city_name("赵国");

        setup();
}

// 函数：对话处理
void do_look( object who )
{
	"/quest/help"->send_help_tips(who, 52);
        REPAIR_CMD->main( who, sprintf( "%x#", getoid( this_object() ) ) );
}
