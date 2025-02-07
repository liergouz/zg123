
#include <ansi.h>
#include <skill.h>
#include <action.h>

#define THIS_PERFORM    00021
#define PF_NAME        "�ƿ�ʬ��"

#define SUB_MP          10

// ��������ȡ����
string get_desc( object me ) 
{ 
        return "��" PF_NAME "��\n�ƿ�������ҵ�ʬ�塣\n"; 
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z, p, mp;

        if( !who->is_die() )
        {
                send_user(me, "%c%s", '!', "��ֻ�ܰ�ʬ���ƿ���");
                return 1;
        }

        z = get_z(who);  x = get_x(who);  y = get_y(who);

        if( distance_between(who, me) > 1 )
        {
                send_user(me, "%c%s", '!', "������ʬ��̫Զ�ˡ�");
                return 1;
        }

        mp = SUB_MP;    // С��׼�� level

        if( me->get_mp() < mp )
        {
                send_user( me, "%c%s", '!', sprintf( "�ƿ�ʬ����Ҫ %d �㷨����", mp ) );
                return 1;
        }
        me->add_mp(-mp);

        switch( get_d(me) )
        {
       case 1 : x ++;         break;
       case 2 : x ++;  y --;  break;
      default :        y --;  break;
       case 4 : x --;  y --;  break;
       case 5 : x --;         break;
       case 6 : x --;  y ++;  break;
       case 7 :        y ++;  break;
       case 8 : x ++;  y ++;  break;
        }

        if( get_block(z, x, y) & IS_CHAR_BLOCK ) return 1;

        who->add_to_scene( z, x, y, get_d(who) );

        write_user( me, ECHO "����" + who->get_name() + "�ƿ���" );
        write_user( who, ECHO "%s(%d)�����ƿ���", me->get_name(), me->get_number() );

        return 1;
}

// ��������ȡָ������
int get_perform_type() { return ON_CHAR_7; }

// �������ܷ�ʹ��ָ��
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
