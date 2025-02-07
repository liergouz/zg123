
#include <npc.h>

inherit NPC;

private static int Level0 = 1;          // �ȼ�(����)
private static int Level2 = 1;          // �ȼ�(����)

// �������Ƿ����
int is_zombie() { return 1; }           // ҽ��ɱ��

// ��������ȡ�ٻ�������
int get_zombie_type() { return ZOMBIE_TYPE_3; }     // �ж�����

// -------------------------------------------------------------


// ��������ȡ�ȼ�����
int get_level_0() { return Level0; }

// ���������õȼ�����
int set_level_0( int point ) { return Level0 = point; }

// ��������ȡ�ȼ�����
int get_level_2() { return Level2; }

// ���������õȼ�����
int set_level_2( int point ) { return Level2 = point; }

// -------------------------------------------------------------

// ��������ȡ������(��ֵ)
int get_ap_0() 
{ 
        if( !get_owner() ) return get_ap();
        return range_value( get_ap() - 35, 0, get_ap() );
}

// ��������ȡ�������(��ֵ)
int get_dp_0() 
{ 
        if( !get_owner() ) return get_dp();
        return range_value( get_dp() - 35, 0, get_dp() );
}

// ��������ȡ��������(��ֵ)
int get_cp_0() 
{ 
        if( !get_owner() ) return get_cp();
        return range_value( get_cp() - 35, 0, get_cp() );
}

// ��������ȡ��������(��ֵ)
int get_pp_0() 
{ 
        if( !get_owner() ) return get_pp();
        return range_value( get_pp() - 35, 0, get_pp() );
}

// -------------------------------------------------------------

// �������жϿ���ս��
int can_fight( object who ) 
{ 
        if( MAP_D->is_inside_battle( get_z( this_object() ) ) ) 
                return NPC_COMRADE_D->can_fight( this_object(), who ); 
        else    return NPC_SLAVE_D->can_fight( this_object(), who ); 
}

// ���������Խ���ս��
int can_be_fighted( object who ) 
{ 
        if( MAP_D->is_inside_battle( get_z( this_object() ) ) ) 
                return NPC_COMRADE_D->can_be_fighted( this_object(), who ); 
        else    return NPC_ATTACK_D->can_be_fighted( this_object(), who ); 
}

// ��������·����(����֮�е���)
void heart_beat_walk() { NPC_SLAVE_D->heart_beat_walk( this_object() ); }

// �������ӳ������Ƴ�
varargs void remove_from_scene( int rm_pf, int rm_pf_2 )
{
        object me, owner;

        ::remove_from_scene(rm_pf, rm_pf_2);

        me = this_object();
        if( owner = me->get_owner() ) 
        {
        	send_user( owner, "%c%c%d", 0x2c, 0, getoid(me) );    // �����ٻ�������
        }
}
