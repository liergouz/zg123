
#include <effect.h>

// ��������ȡ����(����)
string get_loop_faint_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_FAINT) )
                return sprintf( "ѣ�Σ�\n��������ѣ��״̬���޷������κζ�����\n" );
        else if( get_effect(me, EFFECT_CHAR_FAINT_2) )
                return sprintf( "ѣ�Σ�\n��������ѣ��״̬���޷������κζ�����\n" );
        else if( get_effect(me, EFFECT_SLEEP) )   
        	return sprintf( "���ԣ�\n�����������״̬���޷������κζ�����\n���˺���ָ��ж���\n" );
        else if( get_effect(me, EFFECT_CHAR_NO_MOVE) )   
        	return sprintf( "�����ƶ���\n�����������״̬���޷��ƶ���\n����ʹ�õ��߷�����\n" );        	
        else
        return sprintf( "ѣ��\n" );
}

// ��������ȡ����(����)
string get_loop_no_pf_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_NO_PF) )
                return sprintf( "��ħ��\n�����޷�ʹ���κγ��л��߷�����\n" );
        else    return sprintf( "��ħ\n" );
}

// ��������ȡ����(����)
string get_loop_slow_desc( object me )
{
	if( get_effect(me, EFFECT_CHAR_SLOW) )
                return sprintf( "�ӻ���\n�����ƶ��ٶȱ��� 50����\n" );
        else    return sprintf( "�ӻ�\n" );
}

// ��������ȡ����(����)
string get_loop_lazy_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_LAZY) )
                return sprintf( "������\n�����������ƶ��ٶȾ����� 50����\n" );
        else    return sprintf( "����\n" );
}

// ��������ȡ����(����)
string get_loop_dream_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_DREAM_1) )
                return sprintf( "���Σ�\n�����޷������������ܹ���������ʹ���κμ��ܡ�����ʹ�õ��ߡ�����ܵ����������ϻָ�����״̬��\n" );
        else    return sprintf( "����\n" );
}

// ��������ȡ����(����)
string get_loop_chaos_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_CHAOS) )
                return sprintf( "���ң�\n������������ʱʧ�ء�\n" );
        else    return sprintf( "����\n" );
}

// ��������ȡ����(����)
string get_loop_wound_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_WOUND) )
                return sprintf( "���ˣ�\n������������������������½� 30����\n" );
        else    return sprintf( "����\n" );
}

// ��������ȡ����(����)
string get_loop_blood_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_BLOOD) )
                return sprintf( "��Ѫ��\n����ÿ 2 ���½���Ѫ��\n" );
        else    return sprintf( "��Ѫ\n" );
}

// ��������ȡ����(����)
string get_loop_blind_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_BLIND) )
                return sprintf( "ʧ����\n�������߷�Χ��СΪ��߰˸�Χ�����������½� 50����\n" );
        else    return sprintf( "ʧ��\n" );
}

// ��������ȡ����(����)
string get_loop_burn_desc( object me )
{
        if( get_effect(me, EFFECT_USER_BURN) )
                return sprintf( "���գ�\n����12�����޷�ʹ�÷����ָ���Ѫ��" );
        else    return sprintf( "����\n" );
}

// ��������ȡ����(����)
string get_loop_king_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_KING) )
                return sprintf( "����ɢ��ǿ��\n�������е����������� 45����\n" );
        else    return sprintf( "����ɢ��ǿ\n" );
}

// ��������ȡ����(����)
string get_loop_king_2_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_KING_2) )
                return sprintf( "����ɢ�����ã�\n������Ѫ����������Ϊ 1��\n" );
        else    return sprintf( "����ɢ������\n" );
}

// ��������ȡ����(����)
string get_loop_suppress_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_SUPPRESS) )
                return sprintf( "���÷�����\n�������д��������ܵķ����޷�ʹ�á�\n" );
        else    return sprintf( "���÷���\n" );
}
