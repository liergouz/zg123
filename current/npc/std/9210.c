
#include <equip.h>

inherit OFFICER;

// ������ֲ��ʶ��
int is_plant() { return 1; }

void do_look( object who ) { "/inh/job/farmer"->do_look_1( who, this_object() ); }
void do_plant( string arg ) { "/inh/job/farmer"->do_plant( this_player(), this_object(), arg ); }

// ����������ͷ������
void set_head_code_2( int code ) 
{ 
        object *user;

        code += 40;  set_head_code(code);
        user = get_scene_object_2( this_object(), USER_TYPE );
        if( user ) send_user( user, "%c%d%w%d", 0x7e, getoid( this_object() ), code, 0);
}

// ���������촦��
void create()
{
        object me = this_object();

        set_name( "" );    // ����ũ��
        set_gender(1);

        set_2( "talk", ([
                "plant"         : (: do_plant :),
        ]));
        set_armor_code(X_JOBS);
        set_head_code_2(0);

        setup();

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // �������
        set_heart_loop(me, 300);    // ѭ����������������
        me->heart_beat();
        set_heart_beat(1);
}

// ��������������
void heart_beat() { }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object me, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ�����봦��
{
        if( me->get("plant") )
        {
                if( me->add("time", -1) < 0 )
                {
                        me->remove_from_scene();
                        destruct(me);
                }
        }
        else 
        {
                me->set("plant", random(4) + 1);

                if( me->get("time") >= 10 ) me->set_head_code_2(5);
                else me->set_head_code_2( me->get("plant") );
        }
}
