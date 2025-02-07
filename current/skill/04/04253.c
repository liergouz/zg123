
// ����Զ�̼���  TIPS:[PF_CAST]  ����

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <action.h>

#define THIS_SKILL      0425
#define THIS_PERFORM    04253
#define PF_START       "04253"
#define PF_NAME        "˲���ƶ�"

#define SKILL_LEVEL     22
#define TIME_INTERVAL   12
#define SUB_MP          40

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������22��\n    ˲���ƶ�������˲���ƶ�����Ұ��Χ�ڵ�ָ���ص㡣";
        result = sprintf(HIC"%s\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ˲���ƶ�������˲���ƶ�����Ұ��Χ�ڵ�ָ���ص㡣", 
        	PF_NAME, SKILL_LEVEL, SUB_MP, TIME_INTERVAL );
        return result;	
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z, x0, y0, d;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� level

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                x = get_x(who);  y = get_y(who);
        }
/*      else if( objectp( who = me->get_enemy_2() ) && inside_screen_2(me, who) )
        {
                x = get_x(who);  y = get_y(who);
        }       */
        else
        {
                z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);    // ����Ҫ�õ� x0, y0

                if( !inside_screen(x0, y0, x, y) ) return 1;
                if( !objectp( who = get_xy_object(z, x, y, CHAR_TYPE) ) && !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) ) 
                {
                        if( !inside_map(z, x, y) ) return 1;    // ����Ƿ�
                        if( get_block(z, x, y) & IS_CHAR_BLOCK ) return 1;    // �޷����
                        if( !from_to( z, x0, y0, x - x0, y - y0, MAP_BLOCK ) ) return 1;    // �޷���Խ

                        me->set_perform( PF_START, time() );
                        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );

                        me->add_to_scene( z, x, y, me->to_front_xy(x, y) );
                        send_user( me, "%c%w%w%w%c%c%c", 0x4f, x0, y0, 3421, 1, OVER_BODY, PF_ONCE );    // ����ָ��

                        me->add_mp(-mp);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 9);
                        me->add_2("go_count.count2",9);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );

                        return 1;
                }
        }

        return 1;
}

// ��������������
int cast_done( object me )    // ��Ŀ��ʱ
{
        string arg;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

//      return 1;    // �򵽿յ�

        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_XY2; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        int interval;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, PF_NAME );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 9, 0);
}
