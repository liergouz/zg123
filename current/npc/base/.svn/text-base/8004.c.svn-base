
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 3; }

// 函数：获取人物造型
int get_char_picid() { return 5404; }

// 有自己的do_look函数
int is_self_look() { return 1; }

void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("武器店老板");
        set_city_name("周国");

        set_2( "good", ([
                "01" : "/item/74/1020",
                "02" : "/item/74/1030",
                "03" : "/item/74/1040",
                "06" : "/item/75/1020",
                "07" : "/item/75/1030",
                "08" : "/item/75/1040",

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
	"/quest/help"->send_help_tips(who, 39);
	result = sprintf("%s：\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	result += sprintf(ESC "哪里有适合我的武器？\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	result += sprintf( ESC "交易\nlist %x#\n" ESC "我只是随便看看\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
}

void do_welcome( string arg )
{
        object me = this_object();
        "/npc/base/0004"->do_welcome2(me, "99");
}