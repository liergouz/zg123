
// 自动生成：/make/npc/make8014

#include <npc.h>
#include <city.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

void do_enter();
void do_record();

// 函数：获取人物造型
int get_char_picid() { return 0050; }

// 函数：构造处理
void create()
{
        set_name("楚国守卫");
        set_city_name("楚国");

        set_2( "talk", ([
                "enter"         : (: do_enter :),
                "record"	: (: do_record :),
        ]) );
        set("out", 11);
        set("in", 13);

        setup();
}

string get_master() { return CITY_CHU->get_master(); }
string get_master_2() { return CITY_CHU->get_master_2(); }
string get_master_3() { return CITY_CHU->get_master_3(); }

void do_look( object who ) { GUARDER_D->do_look( who, this_object() ); }

void do_enter() { GUARDER_D->do_enter( this_player(), this_object() ); }

void do_record() { GUARDER_D->do_record( this_player(), this_object() ); }
