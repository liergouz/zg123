
// ����Զ�̼���  TIPS:[PF_CAST]  ����

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <equip.h>
#include <cmd.h>

#define BASIC_SKILL     0501
#define THIS_SKILL      0511
#define THIS_PERFORM    05114
#define PF_START       "05114"
#define PF_NAME        "��������"

#define SKILL_LEVEL     13
#define TIME_INTERVAL   2
#define SUB_MP          ( 80 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 20 * 80 )
#define ADD_HP		( 50 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 20 * 100 )
#define ADD_MP		( 80 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 20 * 160 )

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������13��\n    ҽ��ϵ�ķ���������һ����������ҡ���������ҿɻָ�50����Ѫ��80�㷨����";
        cur_level = (level - SKILL_LEVEL)/20 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ҽ��ϵ�ķ���������һ����������ҡ���������ҿɻָ�%d����Ѫ��%d�㷨����\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ����һ����������ҡ���������ҿɻָ�%d����Ѫ��%d�㷨����",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_HP, ADD_MP, cur_level*20+SKILL_LEVEL, ADD_HP+100, ADD_MP+160 );
	return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{        
        int level, mp, z, i, size;
        object *char;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

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
                z = get_z(me);

                if( !inside_screen( get_x(me), get_y(me), x, y ) ) return 1;
                if( !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) ) return 1;

/*              if( !objectp( who = get_xy_object(z, x, y, CHAR_TYPE) ) && !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) ) 
                {
                        me->set_perform( PF_START, time() );
                        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
                        me->set_time( "pf", time() );

                        me->to_front_xy(x, y);
                        user = get_scene_object_2(me, USER_TYPE);
                        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

                        me->add_mp(-mp);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 9);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );

                        return 1;
                }       */
        }
	if(!who->is_user())
	{
		printf( ECHO "���ܶԷ���Ҷ���ʹ�á�" PF_NAME "����" );
		return 1;
	}
        if(who->get_login_flag() < 3 )
        {
                printf( ECHO "�Է���û��׼�������ء�" );
                return 1;
        }
        if( !who->is_die() )
        {
        	z = get_z(who), x = get_x(who), y = get_y(who);
        	char = get_range_object(z, x, y, 2, USER_TYPE);
        	for( i = 0, size = sizeof(char); i < size; i ++ ) 
        	{
        		if( char[i]->is_user() && char[i]->is_die() )
        		{
        			who = char[i];
        			break;
        		}
        	}
        	 if( !who->is_die() )
        	 {
                	printf( ECHO "���ܶԻ���ʹ�á�" PF_NAME "����" );
                	return 1;
                }
        }
	if ("/sys/user/attack"->can_use_help(me, who)==0)
	{				
		printf( ECHO "���޷��ԶԷ�ʹ��" PF_NAME );
		return 1;				
	} 

//      me->set_enemy_2(who);    // Զ��Ŀ������

        me->to_front_xy(x, y);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// ��������������
int cast_done( object me )
{
        object who;
        string arg;
        int level, rate;        

        if( !stringp( arg = me->get_cast_arg() ) || sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        if( !inside_screen_2(me, who) ) return 1;
/*        
        if (who->is_die()==2)
        {
                printf( ECHO "�Է��ѻ�þ�Ԯ��" );
                return 1;
        }        
*/        
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                51141, 1, OVER_BODY, 51142, 1, OVER_BODY, 51143, 1, UNDER_FOOT, 51144, 1, UNDER_FOOT, PF_ONCE );        
        who->set_die(2);
        who->set("pf.05114", me);
        who->set("pf.x", get_x(me));
        who->set("pf.y", get_y(me));        
        DESC_CMD->main(who, "me");
        write_user( me, HIR "����%s(%d)���ѣ����������Ƿ�������ľ�����", who->get_name(), who->get_number() );
        

        me->to_front_eachother(who);

        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_CHAR; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        int interval;
        string name;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL )
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf("%s(%d��)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/20+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0,10, MAGIC_ACT_BEGIN, 0, 5, 0);
}
