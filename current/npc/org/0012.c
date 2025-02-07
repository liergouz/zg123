
#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>

inherit OFFICER;
inherit SAVE_F;
//inherit "/inh/char/group";

void do_info( string arg );
void do_savings( string arg );

// ��������ȡ��������
int get_char_picid() { return 5301; }

// ���������촦��
void create()
{
        object me = this_object();
        int time;        
        
        set_name( "�ʷ�����" );

        set_2( "talk", ([
                "info"          : (: do_info :),
                "savings"       : (: do_savings :),
        ]) );

        setup();
}

void do_look( object who ) { "/sys/sys/manager"->do_look_4( who, this_object() ); }
void do_info( string arg ) { "/sys/sys/manager"->do_info_4( this_player(), this_object(), arg ); }
void do_savings( string arg )
{
	object target;
	target = this_object()->get("orgnpc");
	if (!objectp(target)) return;
	"/sys/city/manager"->do_savings( this_player(), target, arg );
}