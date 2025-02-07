#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 6; }
// 有自己的do_look函数
int is_self_look() { return 1; }
// 函数：获取人物造型
int get_char_picid() { return 5403; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("巨兽岛神医");
        set_city_name("新手村");

        set_2( "good", ([
                "01" : "/item/91/9100",
                "02" : "/item/91/9101",
                "03" : "/item/91/9110",
                "04" : "/item/91/9111",
                "05" : "/item/stuff/0106",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 42);
	result = sprintf("%s：\n    这岛上怪物被人给施了妖法，使得它们高人三尺，一点也不惧怕人类，你可要备足药品再去探险～！\n", me->get_name() );
	result = result + sprintf( ESC "交易\nlist %x#\n" ESC "我只是随便看看\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%s", ':', result );

}
/*
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {

	}
}
*/	  