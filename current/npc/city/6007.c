
// 自动生成：/make/npc/make8007

#include <npc.h>
#include <city.h>

#define DIPLOMAT_D      "/inh/city/diplomat"

inherit OFFICER;

void do_relation( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5102; }

// 函数：构造处理
void create()
{
        set_name("楚国使节");
	set_real_name("屈原");
        set_city_name("楚国");

        set_2( "talk", ([
                "relation"      : (: do_relation :),
        ]) );

        setup();
}

string get_master() { return CITY_CHU->get_master(); }
string get_master_2() { return CITY_CHU->get_master_2(); }
string get_master_3() { return CITY_CHU->get_master_3(); }

void do_look( object who ) { DIPLOMAT_D->do_look( who, this_object() ); }

void do_relation( string arg ) { DIPLOMAT_D->do_relation( this_player(), this_object(), arg ); }
