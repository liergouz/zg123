
#include <skill.h>

private static object Enemy;            // ��������(��������)
private static object Enemy2;           // ��������(������������ҽ����ʩ������)

private static object Enemy5;           // ��������(˳������)    // effect/attack

private static int PerformTime;         // ���⼼׼��ʱ��(���ھ�����ʱ�ۼ�����)

// -------------------------------------------------------------

// ��������ȡ��������
object get_enemy_2() { return Enemy2; }

// ���������ù�������
object set_enemy_2( object who ) 
{ 
        object me = this_object();

        if( objectp(Enemy2) )    // ȡ���������
                send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(Enemy2), 00111, 10, OVER_BODY, PF_STOP );
        if( objectp(who) )    // ��ʾ�������
                send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(who), 00111, 10, OVER_BODY, PF_LOOP );

        return Enemy2 = who; 
}

// ��������ȡ��������
object get_enemy_5() { return Enemy5; }

// ���������÷�������
object set_enemy_5( object who ) { return Enemy5 = who; }

// ��������ȡ�ؼ�׼��ʱ��
int get_perform_enable_time() { return PerformTime; }

// �����������ؼ�׼��ʱ��
int set_perform_enable_time( int time ) { return PerformTime = time; }

// -------------------------------------------------------------

// ������ֹͣս��
void stop_fight()
{
        object me = this_object();
        object soldier, *zombie;
        int i, size;

        if( objectp( soldier = me->get("soldier") ) )    // ֹͣ�ٻ��޹���
        {
                if( soldier->get_enemy() == Enemy ) soldier->set_enemy(0);
        }
        if( arrayp( zombie = me->get("zombie") ) )
        {
                for( i = 0, size = sizeof(zombie); i < size; i ++ ) 
                        if( zombie[i] && ( zombie[i]->get_enemy() == Enemy ) ) zombie[i]->set_enemy(0);
        }

        Enemy = 0;
}
