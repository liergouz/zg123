
// 自动生成：/make/npc/make8020
#include <ansi.h>
#include <npc.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 0450; }

// 函数：师父识别
int is_master() { return 1; }

// 函数：师父识别(武教头)
int is_basic_master() { return 2; }

int is_self_look() { return 1; }

// 函数：小贩识别
int is_seller() { return 1; }

// 函数：构造处理
void create()
{
        set_name("齐国工匠");
        set_real_name("机关21~40");
        set_city_name("齐国");
        set_2( "good", ([
                "01" : "/item/product/66007",
                "02" : "/item/product/66008",
                "03" : "/item/product/66009",
                "04" : "/item/product/66010",
                "05" : "/item/product/66011",
                "06" : "/item/product/66012",
                "07" : "/item/product/66013",
                "08" : "/item/product/66014",
//                "09" : "/item/product/66015",
                "10" : "/item/product/66016",
                "11" : "/item/product/66017",                
        ]) );
	set_skill(0660, 39);
        setup();
}

void do_look( object who )
{
        object me = this_object();
        send_user( who, "%c%c%w%s", ':', 3, 0450, 
        	sprintf("%s：\n    %s\n" 
	       	ESC "学习技能\nlearn ? %s\n" 
	       	ESC "购买机关技能等级21-40级的配方\nlist %s\n"
        	ESC "关闭\nCLOSE\n", 
        	me->get_name(), "/quest/word"->get_country_word(this_object()), me->get_char_id(), me->get_char_id() ) );
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 2 ); }
