
#include <equip.h>

inherit OFFICER;

void do_look( object who ) { "/inh/job/farmer"->do_look_2( who, this_object() ); }
void do_fish( string arg ) { "/inh/job/farmer"->do_fish( this_player(), this_object(), arg ); }

// ���������촦��
void create()
{
        set_name( "" );    // �������
        set_gender(1);

        set_2( "talk", ([
                "fish"          : (: do_fish :),
        ]));

        setup();
}

// ��������ȡװ������
int get_armor_code() { return X_JOBS; }

// ��������ȡͷ������
int get_head_code() { return 30; }
