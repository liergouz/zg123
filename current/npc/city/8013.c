
// 自动生成：/make/npc/make8012

#include <npc.h>
#include <city.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

void do_out();
void do_record();

// 函数：获取人物造型
int get_char_picid() { return 9390; }

// 函数：构造处理
void create()
{
        set_name("周国守卫");
        set_city_name("周国");

        set_2( "talk", ([
                "out"           : (: do_out :),
                "record"	: (: do_record :),
        ]) );
        set("in", 13);
        set("out", 11);

        setup();
}

string get_master() { return CITY_ZHOU->get_master(); }
string get_master_2() { return CITY_ZHOU->get_master_2(); }
string get_master_3() { return CITY_ZHOU->get_master_3(); }

void do_look( object who ) { GUARDER_D->do_look_2( who, this_object() ); }

void do_out() { GUARDER_D->do_out( this_player(), this_object() ); }

void do_record() { GUARDER_D->do_record( this_player(), this_object() ); }
