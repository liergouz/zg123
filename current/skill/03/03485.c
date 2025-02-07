
// ���ó�������  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0348
#define THIS_PERFORM    03485
#define PF_START       "03485"
#define PF_TIME        "03485#"
#define PF_NAME        "����һ��"

#define SKILL_LEVEL     30
#define TIME_INTERVAL   180
#define SUB_MP          0

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������30��\n    ������ֵ����70��ʱ��ü��ܲſ�ʹ�á�˲��ָ�����Ԫ����ȡ����ǰ���м��ܵ�ʹ����ȴʱ�䡣";
        result = sprintf(HIC"%s\n" NOR "��������%d��\n��ȴʱ�䣺%d��\n    ������ֵ����70��ʱ��ü��ܲſ�ʹ�á�˲��ָ�����Ԫ����ȡ����ǰ���м��ܵ�ʹ����ȴʱ�䡣",
        	PF_NAME, SKILL_LEVEL, TIME_INTERVAL );
	return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp;
        object *user;
        object file;
        mapping skls;
        string *name;
        int skill, flag;
        int i, size;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // С��׼�� level

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

        if (me->get_hp() >= me->get_max_hp()*7/10)
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ��Ѫ����70����" );
                return 1;        	
        }

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->add_2("go_count.count2",9);
        me->init_perform_dbase();
        if( mapp( skls = me->get_skill_dbase() ) && sizeof(skls) )    // ��ʾ���⼼
        {
                name = sort_array( keys(skls), 1 );
                for( i = 0, size = sizeof(name); i < size; i ++ )
                {
                        skill = to_int( name[i] );
                        if ( ( file = load_object( SKILL->get_skill_file(skill) ) ) && file->get_name() )
                        {
                                file->can_perform(me);
                        }
                }
        }                
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
	me->set_yuan(me->get_max_yuan());
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 32521, 1, OVER_BODY, PF_ONCE );
        return 1;
}

// ��������������
int cast_done( object me )
{
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
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 1, MAGIC_ACT_BEGIN, 0, 9, 0);
}
