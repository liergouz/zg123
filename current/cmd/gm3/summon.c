
#include <ansi.h>

#define SUMMON_LOG      "gm/summon.txt"         // �ٻ���־�ļ�

// �����������
int main1( object me, string arg )
{
	object who;
        int z, x, y, x0, y0, p;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

	if( !arg ) 
        {
                send_user( me, "%c%c%d%s", '?', 16, 10, sprintf( "�������������\n\n������Է������֣ɣģ�\n"
                        ESC "summon %%s\n" ) );
                return 1;
        }

	if( !( who = find_any_char(arg) ) )
        {
                notify( "���޷��ҵ�����ˡ�" );
		return 1;
        }
        else if( !clonep(who) )
        {
                notify( "�޷��ٻ�������" );
		return 1;
        }
        else if( who == me )
        {
                notify( "�������Լ�ץ�Լ���" );
		return 1;
        }

        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
        {
                x = p / 1000;  y = p % 1000;
                who->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0), 40971, 0, 40971, 0 );
                tell_user( me, HIY "������%s�������", who->get_name() );
                write_user( who, HIY "%s�������������", me->get_name() );

                if( userp(who) ) log_file( "gm/gm3.dat", sprintf( "%s %s ���� %s(%s)�� %d (%d,%d)��\n", 
                        short_time(), me->get_id(), who->get_name(), who->get_id(), z, x, y ) );

		return 1;
        }
        else 
        {
                notify( who->get_name() + "�����������" );
		return 1;
        }

        return 1;
}

int main( object me, string arg )
{
	int i,size;
	string *player;
	
        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }
        player = explode(arg,",");
        if ( (size=sizeof(player)) == 0 )
        {
        	main1(me,arg);	
        	return 1;
        }
        for(i=0;i<size;i++)
        {
        	main1(me,player[i]);
        }
        return 1;
}