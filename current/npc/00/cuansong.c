#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <effect.h>
inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5302; }

void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�������ţ��Ĵ�����");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));   
        setup();
}

// �������Ի�����
void do_look( object who )
{
        int status;
        object me = this_object();
        status = who->get("xiannv.status");
        send_user( who, "%c%c%w%s", ':', 3, 5302,
        	sprintf("%s��\n    �ҿ��԰���ӵ�ǰλ��˲���Ƶ�����λ�ã����Ƿ������ԣ�\n"
                ESC "ȷ��\ntalk %x# welcome.1\n"
                ESC "ȡ��\nCLOSE\n", me->get_name(), getoid(me) ) );

}

// �������Ի�����
void do_welcome( string arg )
{
	int p;
	int x0,y0,z,x,y;
	object who = this_player();
	
	z = 1;
	if ( random(2) )
	{
		x0 = 304;
		y0 = 126;
	}
	else
	{
		x0 = 205;
		y0 = 183;
	}	
        if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
        {
                x = p / 1000;  y = p % 1000;

//                me->set_login_flag(2);    // ��ת����
//                set_invisible(who, 1);
//                set_effect(who, EFFECT_USER_LOGIN, 4);
//
                who->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );

                tell_user( who, "��ȥ��: %d (%d, %d)��", z, x, y );
		return ;
        }

}