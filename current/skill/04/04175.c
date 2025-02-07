
// ����Զ�̼���  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0417
#define THIS_PERFORM    04175
#define PF_START       "04175"
#define PF_NAME        "��������"

#define SKILL_LEVEL     31
#define TIME_INTERVAL	2
#define SUB_MP          150


// ��������ȡ����Ч��
// int get_cast_seal() { return 41100; }    // ��ֽ����

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������31��\n    �����Լ����ٻ��ޣ�����21��21��Χ�ڵ����ж����Ա���ɻ�õ���������Ѫ25������Ѫֵ��";
        result = sprintf(HIC"%s\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    �����Լ����ٻ��ޣ�����21��21��Χ�ڵ����ж����Ա���ɻ�õ���������Ѫ25������Ѫֵ��", 
        	PF_NAME, SKILL_LEVEL, SUB_MP, TIME_INTERVAL );
        return result;	
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( me->get_perform(PF_START) == time() ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

/*      if( !objectp( item = present("��ֽ", me, 1, MAX_CARRY) ) )
        {
                printf( ECHO "�����з�ֽ����ʹ�á�" PF_NAME "����" );
                return 1;
        }       */

        who = me->get("soldier");
        if (!who) return 1;

        if( !who->is_zombie() || who->get_owner() != me )
        {
                printf( ECHO "ֻ�ܶ��Լ����ٻ���ʹ�á�" PF_NAME "����" );
                return 1;
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // Զ��Ŀ������

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
//      send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);
//      item->add_amount(-1);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( who->get_char_id() );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// ��������������
int cast_done( object me )
{
        object who, *all, *team, *user;
        string arg;
        int z, x, y, i, size;
        int level, cp, hp;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( !objectp( who = find_char(arg) ) ) return 1;

        hp = who->get_max_hp();    

	send_user( get_scene_object_2(who, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(who), get_y(who), 9414, 1, OVER_BODY, PF_ONCE );
	send_user(me, "%c%c%d", 0x2c, 0, getoid(who));
	who->remove_from_scene(FALL_ACT);
	destruct(who);	
        all = me->get_team();
        if (all==0) all = ({ me });
        all -= ({ 0 });
        size = sizeof(all);
        z = get_z(me), x = get_x(me), y = get_y(me);
        team = ({ });
        for (i=0;i<size;i++)
        {
        	if (all[i]==me) team += ({ all[i] });
        	else
        	if (z==get_z(all[i])&& abs(x-get_x(all[i]))<9 && abs(y-get_y(all[i]))<9)
        		team += ({ all[i] });
        }
	size = sizeof(team);
	hp /= 4;
	for (i=0;i<size;i++) if (who = team[i])
	{
		if ("/sys/user/attack"->can_use_help(me, who)==0) continue;
	        user = get_scene_object_2(who, USER_TYPE);
	        if (!who->no_recover() && !get_effect_3(who, EFFECT_USER_BURN)) who->add_hp(hp);
	        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 4175, 1, OVER_BODY, PF_ONCE );
	        send_user( user, "%c%d%w", 0x68, getoid(who), -hp );
	        CHAR_FIGHT_D->set_enmity2(me,who,80+hp);
	}   	
        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_ME; }

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
	name = PF_NAME;
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 5, 0);
}
