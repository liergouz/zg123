
// 自动生成：/make/npc/make8005

#include <npc.h>
#include <city.h>

#define RESIDENT_D      "/inh/city/resident"

inherit OFFICER;

void do_enter( string arg );
void do_leave( string arg );
void do_shutup( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5102; }

// 函数：构造处理
void create()
{
        set_name("魏国户籍官");
        set_city_name("魏国");

        set_2( "talk", ([
                "enter"         : (: do_enter :),
                "leave"         : (: do_leave :),
                "shutup"        : (: do_shutup :),
        ]) );

        setup();
}

string get_master() { return CITY_WEI->get_master(); }
string get_master_2() { return CITY_WEI->get_master_2(); }
string get_master_3() { return CITY_WEI->get_master_3(); }

void do_look( object who ) { RESIDENT_D->do_look( who, this_object() ); }

void do_enter( string arg ) { RESIDENT_D->do_enter( this_player(), this_object(), arg ); }
void do_leave( string arg ) { RESIDENT_D->do_leave( this_player(), this_object(), arg ); }
void do_shutup( string arg ) { RESIDENT_D->do_shutup( this_player(), this_object(), arg ); }
