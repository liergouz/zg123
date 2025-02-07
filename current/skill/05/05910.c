
// �ٻ�����  TIPS:[PF_CALL]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0591
#define THIS_PERFORM    05910
#define PF_START       "05910"
#define PF_NAME        "���ٻ�"

#define SKILL_LEVEL     1
#define SUB_MP          0


// ��������ȡ����Ч��
int get_cast_seal() { return 9101; }    // ��ֽ����

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "��" PF_NAME "�ݷ��ٻ����ٻ����%s%d ������\n",
                level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{

	object * user, soldier, * zombie;
	int flag = 0;
	int i, size;
	if (who->get_owner()!=me)
        {
                printf( ECHO "�Է����������ٻ����" );
                return 1;
        }	
        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        if( objectp( soldier = me->get("soldier") ) )
        {
        	if (who==soldier) 
        	{
        		me->set("soldier", 0);
        		flag=1;
        	}
        }
        if(     flag==0 && arrayp( zombie = me->get("zombie") ) 
        &&      arrayp( zombie = filter_array( zombie - ({ 0 }), (: $1->get_owner() == $2 :), me ) )    // ����ѱ�Ĺ�
        &&    ( size = sizeof(zombie) ) )    // zombie -= ({ 0 })
        {        
        	for( i = 0; i < size; i ++ ) if( soldier = zombie[i] ) 
        	{
        		if (who==soldier) 
        		{
        			zombie -= ({ who });
        			me->set("zombie", zombie);
        			flag=1;
        			break;
        		}
        	}
        }
	if (flag==1)
	{
		send_user( get_scene_object_2(soldier, USER_TYPE), "%c%w%w%w%c%c%c", 0xff, get_x(who), get_y(who), 9414, 1, OVER_BODY, PF_STOP );
		send_user(me, "%c%c%d", 0x2c, 0, getoid(who));
		who->remove_from_scene();
		destruct(who);
	}

        return 1;
}

// ��������������
int cast_done( object me )
{
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        return 2;    // ִ�гɹ�
}


// ��������ȡ�ؼ�����
int get_perform_type() { return ON_CHAR; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
