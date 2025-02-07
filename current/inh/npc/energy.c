#include <effect.h>
#include <npc.h>

// NPC ר��

class Health
{
        int Point;                              // ��ǰ��ֵ
        int MaxPoint;                           // �����ֵ
}

private class Health HP = new( class Health );  // ��������(Health)
private class Health MP = new( class Health );  // ��������(Magic)

private int HP_Cent;                     // ��Ѫ����(ע�⣺0/50��50/50)

private int AP0, AP;                            // ������(Attack)
private int DP0, DP;                            // �������(Defence)
private int CP0, CP;                            // ��������(Cast)
private int PP0, PP;                            // ��������(Protect)
private int SP0, SP;                            // ��Ų����(Speed)

private int Poison;                             // �ж�����
private int Poison2;                            // �ж�����(����)

private static int WalkSpeed = WALK_SPEED_4;    // ��·�ٶ�(��)
private static int WalkStep = 1;                // ��·����

private static int AttackSpeed = ATTACK_SPEED_4;// �����ٶ�(��)

private static int MaxSeek = 4;                 // ���������Χ

private static int SmartCaster;                 // �λ�սģʽ

private int Die;                                // ������־

// -------------------------------------------------------------

// ��������ȡ��ǰ�ȣ�
int get_hp() { return HP->Point; }

// ��������ȡ��ǰ�ͣ�
int get_mp() { return MP->Point; }

// ��������ȡ���ȣ�
int get_max_hp() { return HP->MaxPoint; }

// ��������ȡ���ͣ�
int get_max_mp() { return MP->MaxPoint; }

// ��������ȡ��Ѫ����
int get_hp_cent() { return HP_Cent; }

// ���������õ�ǰ�ȣ�
int set_hp( int point ) 
{
        object me = this_object();
        object owner;
        int old_hp_cent = HP_Cent;
        point = range_value( point, -1, HP->MaxPoint );
        HP_Cent = ( point < 1 || HP->MaxPoint < 1 ) ? 0 : point * 50 / HP->MaxPoint;
        if( old_hp_cent != HP_Cent ) send_user( get_scene_object_2(me, USER_TYPE), "%c%d%c", 0x2a, getoid(me), HP_Cent );
        owner = me->get_owner();
        if (owner) send_user(owner, "%c%c%d%c", 0x2c, 3, getoid(me), HP_Cent );
        return HP->Point = point; 
}

// ���������õ�ǰ�ͣ�
int set_mp( int point ) 
{ 
        point = range_value( point, -1, MP->MaxPoint );
        return MP->Point = point; 
}

// �������������ȣ�
int set_max_hp( int point ) 
{ 
	object me = this_object();
        point = range_value(point, 1, MAX_NUMBER);
        HP->MaxPoint = point;
        if (me->get_owner()) ;
        else set_hp(point);
        return point;
}

// �������������ͣ�
int set_max_mp( int point ) 
{ 
	object me = this_object();
        point = range_value(point, 1, MAX_NUMBER);
        if (!me->get_owner()) 
        	MP->Point = point;    // ��������
        return MP->MaxPoint = point;
}

// ����������ǰ�ȣ�
int add_hp( int point ) { return set_hp( HP->Point + point ); }

// ����������ǰ�ͣ�
int add_mp( int point ) { return set_mp( MP->Point + point ); }

// �������������ȣ�
int add_max_hp( int point ) { return set_max_hp( HP->MaxPoint + point ); }

// �������������ͣ�
int add_max_mp( int point ) { return set_max_mp( MP->MaxPoint + point ); }

// -------------------------------------------------------------

// ��������ȡ������(��ֵ)
int get_ap_0() { return AP; }

// ��������ȡ�������(��ֵ)
int get_dp_0() { return DP; }

// ��������ȡ��������(��ֵ)
int get_cp_0() { return CP; }

// ��������ȡ��������(��ֵ)
int get_pp_0() { return PP; }

// ��������ȡ������
int get_ap() 
{ 
	object me = this_object();
	if (get_effect(me, EFFECT_CHAR_WOUND)) return AP * 8 /10;
	return AP; 
}

// ��������ȡ�������
int get_dp() 
{
	int rate; 
	object me = this_object();
	rate = 0;
	if (get_effect(me, EFFECT_CHAR_WOUND)) rate += 20;
	if (get_effect(me, EFFECT_2123_ARMORFALL)) rate += 10;
	return DP*(100-rate)/100; 
}

// ��������ȡ��������
int get_cp() { return CP; }

// ��������ȡ��������
int get_pp() { return PP; }

// ��������ȡ��Ų����
int get_sp() { return SP; }

// ��������ȡ�ж�����
int get_poison() { return Poison; }

// ��������ȡ�ж�����(����)
int get_poison_2() { return Poison2; }

// ����������������
int set_ap( int point ) { return AP = range_value(point, 1, MAX_NUMBER); }

// �����������������
int set_dp( int point ) { return DP = range_value(point, 1, MAX_NUMBER); }

// ���������÷�������
int set_cp( int point ) { return CP = range_value(point, 1, MAX_NUMBER); }

// ���������÷�������
int set_pp( int point ) { return PP = range_value(point, 1, MAX_NUMBER); }

// ������������Ų����
int set_sp( int point ) { return SP = range_value(point, 1, MAX_NUMBER); }

// �����������ж�����
int set_poison( int point ) { return Poison = range_value(point, 1, MAX_NUMBER); }

// �����������ж�����(����)
int set_poison_2( int point ) { return Poison2 = range_value(point, 1, MAX_NUMBER); }

// ����������������
int add_ap( int point ) { return set_ap( AP + point ); }

// �����������������
int add_dp( int point ) { return set_dp( DP + point ); }

// ����������������
int add_cp( int point ) { return set_cp( CP + point ); }

// ����������������
int add_pp( int point ) { return set_pp( PP + point ); }

// ������������Ų����
int add_sp( int point ) { return set_sp( SP + point ); }

// �����������ж�����
int add_poison( int point ) { return set_poison( Poison + point ); }

// �����������ж�����(����)
int add_poison_2( int point ) { return set_poison_2( Poison2 + point ); }

// -------------------------------------------------------------

// ��������ȡ��·����
int get_walk_step() { return WalkStep; }

// ������������·����
int set_walk_step( int point ) { return WalkStep = point; }

// ��������ȡ��·�ٶ�(��)
int get_walk_speed() { return range_value(WalkSpeed, 2, MAX_NUMBER); }

// ������������·�ٶ�(��)
int set_walk_speed( int point ) 
{ 
        object me = this_object();
        send_user( get_scene_object_2(me, USER_TYPE), "%c%c%d%c", 0x3d, 245, getoid(me), point );
        return WalkSpeed = point; 
}

// ��������ȡ�����ٶ�(��)
int get_attack_speed() { return range_value(AttackSpeed, ATTACK_SPEED_1, MAX_NUMBER); }

// ���������ù����ٶ�(��)
int set_attack_speed( int point ) { return AttackSpeed = point; }

// ��������ȡ���������Χ
int get_max_seek() { return MaxSeek; }

// �������������������Χ
int set_max_seek( int point ) { return MaxSeek = point; }

// ��������ȡ�λ�սģʽ
int is_smart_caster() { return SmartCaster; }

// �����������λ�սģʽ
int be_smart_caster( int flag ) { return SmartCaster = flag; }

// ��������ȡ������־
int is_die() { return Die; }

// ����������������־
// ������0 ���1 ������2 ���˽�ȣ�3 ���9 ս������
int set_die( int flag )
{
        return Die = flag;
}