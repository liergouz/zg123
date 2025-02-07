
#include <skill.h>
#include <item.h>
#include <action.h>
#include <effect.h>

class Health
{
        int Point;                              // ��ǰ��ֵ
        int MaxPoint;                           // �����ֵ
}

private class Health HP = new( class Health );  // ��������("hp", "hp%")
private class Health MP = new( class Health );  // ��������("mp", "mp%")

private static int HP_Cent;                     // ��Ѫ����(ע�⣺0/50��50/50)

private int AP0, AP;                            // ������("ap", "ap%")
private int DP0, DP;                            // �������("dp")
private int CP0, CP;                            // ��������("cp", "cp%")
private int PP0, PP;                            // ��������("pp", "pp%")
private int SP;                                 // ��Ų����("sp")

private int MaxYuan = 1, Yuan = 1;              // Ԫ������

private int DamageCount;                        // �ۻ��˺�  // ����������

private int Poison;                             // �ж�����
private int Poison2;                            // �ж�����(����)

private int Die;                                // ������־

int get_login_flag();
int get_skill( int skill );

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
        object *team;
        int i, size;
        int old_hp_cent = HP_Cent;
        if( get_login_flag() == 2 ) return HP->Point;    // δ׼������
        point = range_value( point, -1, HP->MaxPoint );
        if (point<1 && get_effect(me, EFFECT_CHAR_IMMORTAL)) point = 1;
        if( HP->Point != point && get_login_flag() > 1 ) send_user(me, "%c%c%w", 0x3d, 20, point);
        HP_Cent = ( point < 1 || HP->MaxPoint < 1 ) ? 0 : point * 50 / HP->MaxPoint;
        if( old_hp_cent != HP_Cent && get_login_flag() > 1 ) 
        {                
                send_user( get_scene_object_2(me, USER_TYPE), "%c%d%c", 0x2a, getoid(me), HP_Cent );
        }
        HP->Point = point;
        if (me->get_leader())
        {
        	team = me->get_team();
        	size = sizeof(team);
        	if (size>0)
        	{
        		for (i=0;i<size;i++)
        		{
        			if (team[i])
        				send_user( team[i], "%c%c%d%w%w", 0x54, 3, me->get_number(), me->get_hp(), me->get_max_hp() );
        		}
        	}
        }
        return HP->Point; 
}

// ���������õ�ǰ�ͣ�
int set_mp( int point ) 
{ 
        object me = this_object();
        object *team;
        int i, size;        
        if( get_login_flag() == 2 ) return MP->Point;    // δ׼������
        point = range_value( point, 0, MP->MaxPoint );
        if( MP->Point != point && get_login_flag() > 1 ) send_user(me, "%c%c%w", 0x3d, 22, point);
        MP->Point = point; 
        if (me->get_leader())
        {
        	team = me->get_team();
        	size = sizeof(team);
        	if (size>0)
        	{
        		for (i=0;i<size;i++)
        		{
        			if (team[i])
        				send_user( team[i], "%c%c%d%w%w", 0x54, 4, me->get_number(), me->get_mp(), me->get_max_mp() );
        		}
        	}
        }                
        return MP->Point;
}

// �������������ȣ�
int set_max_hp( int point ) 
{ 
        object me = this_object();
        int old_hp_cent = HP_Cent;
        point = range_value(point, 1, MAX_NUMBER);
        if( point < HP->Point ) HP->Point = point;
        if( HP->MaxPoint != point && get_login_flag() > 1 ) send_user(me, "%c%c%w", 0x3d, 21, point);
        HP_Cent = ( HP->Point < 1 ) ? 0 : HP->Point * 50 / point;
        if( old_hp_cent != HP_Cent && get_login_flag() > 1 ) send_user( get_scene_object_2(me, USER_TYPE), "%c%d%c", 0x2a, getoid(me), HP_Cent );
        return HP->MaxPoint = point;
}

// �������������ͣ�
int set_max_mp( int point ) 
{ 
        object me = this_object();
        point = range_value(point, 1, MAX_NUMBER);
        if( point < MP->Point ) MP->Point = point;
        if( MP->MaxPoint != point && get_login_flag() > 1 ) send_user(me, "%c%c%w", 0x3d, 23, point);
        return MP->MaxPoint = point;
}

// ����������ǰ�ȣ�
int add_hp( int point ) 
{ 
	object me = this_object();
	if (me->get_save("no_hurt"))
	{
		if (point<0) return get_hp();
	}
	if (point<0) "/quest/help"->send_help_tips(me, 47);
	return set_hp( HP->Point + point ); 
}

// ����������ǰ�ͣ�
int add_mp( int point ) 
{ 
	object me = this_object();
	if (get_effect_3(me, EFFECT_DOUBLE_USE) && point<0)
		point *= 2;	
	return set_mp( MP->Point + point ); 
}

// �������������ȣ�
int add_max_hp( int point ) { return set_max_hp( HP->MaxPoint + point ); }

// �������������ͣ�
int add_max_mp( int point ) { return set_max_mp( MP->MaxPoint + point ); }

// -------------------------------------------------------------

// ��������ȡ������(��ֵ)
int get_ap_0() { return range_value(AP - 35, 10, AP); }

// ��������ȡ�������(��ֵ)
int get_dp_0() { return range_value(DP - 35, 10, DP); }

// ��������ȡ��������(��ֵ)
int get_cp_0() { return range_value(CP - 35, 5, CP); }

// ��������ȡ��������(��ֵ)
int get_pp_0() { return range_value(PP - 35, 8, PP); }
/*
// ��������ȡ������(��ֵ)
int get_ap_0() { return AP0; }

// ��������ȡ�������(��ֵ)
int get_dp_0() { return DP0; }

// ��������ȡ��������(��ֵ)
int get_cp_0() { return CP0; }

// ��������ȡ��������(��ֵ)
int get_pp_0() { return PP0; }

// ����������������(��ֵ)
int set_ap_0( int point ) { return AP0 = range_value(point, 0, AP); }

// �����������������(��ֵ)
int set_dp_0( int point ) { return DP0 = range_value(point, 0, DP); }

// ���������÷�������(��ֵ)
int set_cp_0( int point ) { return CP0 = range_value(point, 0, CP); }

// ���������÷�������(��ֵ)
int set_pp_0( int point ) { return PP0 = range_value(point, 0, PP); }
*/
// ��������ȡ������
int get_ap() { return AP; }

// ��������ȡ�������
int get_dp() { return DP; }

// ��������ȡ��������
int get_cp() { return CP; }

// ��������ȡ��������
int get_pp() { return PP; }

// ��������ȡ��Ų����
int get_sp() 
{
	object who= this_object();
	if( get_effect(who, EFFECT_MAGIC_4243) ) return SP * 3;  // ����״̬����ʱ����2������
	return SP; 
}

// ����������������
int set_ap( int point ) 
{
        object me = this_object();
        if( point < 1 ) point = 1;
        if( AP != point && get_login_flag() > 1 ) 
        {
                AP = point;
                send_user(me, "%c%c%w%w", 0x3d, 24, get_ap_0(), point);
                send_user(me, "%c%c%s", 0x3d, 35, USER_RANK_D->get_rank(me) );
                me->delete_title("X");
                me->add_title("X");
                return point;
        }
        return AP = point;
}

// �����������������
int set_dp( int point ) 
{
        object me = this_object();
        if( point < 10 ) point = 10;
        if( DP != point && get_login_flag() > 1 ) 
        {
                DP = point;
                send_user(me, "%c%c%w%w", 0x3d, 25, get_dp_0(), point);
                return point;
        }
        return DP = point;
}

// ���������÷�������
int set_cp( int point ) 
{
        object me = this_object();
        if( point < 5 ) point = 5;
        if( CP != point && get_login_flag() > 1 ) 
        {
                CP = point;
                send_user(me, "%c%c%w%w", 0x3d, 26, get_cp_0(), point);
                send_user(me, "%c%c%s", 0x3d, 35, USER_RANK_D->get_rank(me) );
                me->delete_title("X");
                me->add_title("X");
                return point;
        }
        return CP = point;
}

// ���������÷�������
int set_pp( int point ) 
{
        object me = this_object();
        if( point < 8 ) point = 8;
        if( PP != point && get_login_flag() > 1 ) 
        {
                PP = point;
                send_user(me, "%c%c%w%w", 0x3d, 27, get_pp_0(), point);
                return point;
        }
        return PP = point;
}

// ������������Ų����
int set_sp( int point ) 
{
        object me = this_object();
        if( point < 1 ) point = 1;
        if( SP != point && get_login_flag() > 1 ) send_user(me, "%c%c%w", 0x3d, 28, point);
        return SP = point;
}

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

// -------------------------------------------------------------

// ��������ȡ��ǰԪ��
int get_yuan() { return Yuan; }

// ��������ȡ���Ԫ��
int get_max_yuan() { return MaxYuan; }

// ���������õ�ǰԪ��
int set_yuan( int point ) 
{
        point = range_value( point, 0, MaxYuan );
        if( Yuan != point && get_login_flag() > 1 ) send_user( this_object(), "%c%c%c", 0x3d, 30, point );
        return Yuan = point;
}

// �������������Ԫ��
int set_max_yuan( int point ) 
{
        point = range_value( point, 1, MAX_NUMBER );
        if( point < Yuan ) Yuan = point;
        if( MaxYuan != point && get_login_flag() > 1 ) send_user( this_object(), "%c%c%c", 0x3d, 31, point );
        return MaxYuan = point;
}

// ����������ǰԪ��
int add_yuan( int point ) 
{ 
	object me = this_object();
	if (get_effect_3(me, EFFECT_DOUBLE_USE) && point<0)
		point *= 2;		
	return set_yuan( Yuan + point ); 
}

// �������������Ԫ��
int add_max_yuan( int point ) { return set_max_yuan( MaxYuan + point ); }

// -------------------------------------------------------------

// ��������ȡ�ۻ��˺�
int get_damage_count() { return DamageCount; }

// �����������ۻ��˺�
int set_damage_count( int point ) { return DamageCount = range_value(point, 1, MAX_NUMBER); }

// �����������ۻ��˺�
int add_damage_count( int point ) { return set_damage_count( DamageCount + point ); }

// ��������ȡ�ж�����
int get_poison() { return Poison; }

// ��������ȡ�ж�����(����)
int get_poison_2() { return Poison2; }

// �����������ж�����
int set_poison( int point ) { return Poison = range_value(point, 1, MAX_NUMBER); }

// �����������ж�����(����)
int set_poison_2( int point ) { return Poison2 = range_value(point, 1, MAX_NUMBER); }

// �����������ж�����
int add_poison( int point ) { return set_poison( Poison + point ); }

// �����������ж�����(����)
int add_poison_2( int point ) { return set_poison_2( Poison2 + point ); }

// -------------------------------------------------------------

// ��������ȡ������־
int is_die() { return Die; }

// ����������������־
// ������0 ���1 ������2 ���˽�ȣ�9 ս������
int set_die( int flag )
{
        object *char, me, who, *inv;
        int z, x, y, x1, y1, p;
        int pk, i, k, n, size;

        me = this_object();
        "/quest/help"->send_help_tips(me, 13);
	if ( me->get_perform("05016#"))
	{		
		me->set_perform("05016#", 0);
		me->set_perform("05016", 0);
        	send_user( me, "%c%w%w%c", 0x81, 5016, 0, EFFECT_GOOD );
        	send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 5016, 0, EFFECT_GOOD );
		USER_ENERGY_D->count_cp(me);
	}
        switch( flag )
        {
       case 1 : // ��������״̬

                if( is_player(me) )    // ��Ҷ�������
                {
                        pk = me->get_pk();
                        z = get_z(me);  x = get_x(me);  y = get_y(me);

                        if( pk < 1 ) k = random(3) + 1;
                        else k = pk * ( random(4) + 2 );
/* �Ȳ�������
                        for( i = 0; i < k; i ++ )    // ���µ���
                        {
                                inv = all_inventory(me, 1, MAX_CARRY);
                                if( !( size = sizeof(inv) ) ) break;

                                if( !( p = get_valid_xy(z, x + random(3) - 1, y + random(3) - 1, IS_ITEM_BLOCK ) ) ) continue;

                                x1 = p / 1000;  y1 = p % 1000;

                                n = random(size);
                                if( inv[n]->get_no_drop() || inv[n]->get_no_get() || inv[n]->get_no_give() ) continue;

                                inv[n]->remove_from_user();
                                inv[n]->add_to_scene(z, x1, y1);
                        }
*/
                        p = random(1000);

                        if( pk < 1 )
                        {
                                if( p < 5 ) k = 2;
                                else if( p < 50 ) k = 1;
                                else k = 0;
                        }
                        else if( pk < 6 )
                        {
                                if( p < pk * 20 ) k = random(3) + 2;
                                else if( p < pk * 100 ) k = 1;
                                else k = 0;
                        }
                        else 
                        {
                                if( p < pk * 100 ) k = random(7) + 1;
                                else if( p < pk * 100 ) k = 1;
                                else k = 0;
                        }
                        if (me->get_save("userkill")==0)
                        {
	                        inv = me->get_all_equip(me);    // �����;ö� 10%			
	                        if( objectp( inv[0] ) ) inv[0]->add_lasting( - inv[0]->get_max_lasting() / 10 );
	                        if( objectp( inv[1] ) ) inv[1]->add_lasting( - inv[1]->get_max_lasting() / 10 );
	                        if( objectp( inv[2] ) ) inv[2]->add_lasting( - inv[2]->get_max_lasting() / 10 );
	                        if( objectp( inv[3] ) ) inv[3]->add_lasting( - inv[3]->get_max_lasting() / 10 );
	                        if( objectp( inv[4] ) ) inv[4]->add_lasting( - inv[4]->get_max_lasting() / 10 );
	                        if( objectp( inv[5] ) ) inv[5]->add_lasting( - inv[5]->get_max_lasting() / 10 );
	                        if( objectp( inv[6] ) && inv[6]->get_item_type() == ITEM_TYPE_TALISMAN ) 
	                        {
	                        	if (inv[6]->get_item_number()!=10001023 && inv[6]->get_item_number()!=10001024 )
	                        		inv[6]->add_lasting( - inv[6]->get_max_lasting() / 10 );
	                        }
			}	                       
                }

                if( objectp( who = me->get_quest("escort.robber#") ) && who->is_escort_robber() )
                {
                        who->win_bonus(me);    // ���������
                        who->remove_from_scene();
                        destruct(who);
                }

                me->set_cast_file(0);    // ��������ؼ�
                me->set_cast_arg("");

                char = get_scene_object_2(me, USER_TYPE);
                send_user( char, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );    // ����ʩ������
                send_user( char, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                        41100, 1, UNDER_FOOT, 42100, 1, UNDER_FOOT, PF_STOP );    // ��������Ч��  get_cast_seal()

                me->set_perform_file(0);    // ����Ƿ��ؼ�
//                me->init_perform_dbase();    // �������ؼ�

                CHAR_CHAR_D->stop_loop_perform(me);    // �жϳ���Ч��
                CHAR_CHAR_D->stop_loop_perform_4(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_loop_perform_5(me);    // �жϳ���Ч��(���)
                CHAR_CHAR_D->stop_loop_perform_9(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_poison_effect(me);    // �ж϶�ҩЧ��

                me->set_char_action(DIE_ACT);

//                set_effect(me, EFFECT_USER_DIE, 600);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%c%d%c", 0x3d, 2, getoid(me), flag );

                break;

       case 5 : // ���䳡��ս������״̬

                me->set_cast_file(0);    // ��������ؼ�
                me->set_cast_arg("");

                char = get_scene_object_2(me, USER_TYPE);
                send_user( char, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );    // ����ʩ������
                send_user( char, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                        41100, 1, UNDER_FOOT, 42100, 1, UNDER_FOOT, PF_STOP );    // ��������Ч��  get_cast_seal()

                me->set_perform_file(0);    // ����Ƿ��ؼ�
//                me->init_perform_dbase();    // �������ؼ�

                CHAR_CHAR_D->stop_loop_perform(me);    // �жϳ���Ч��
                CHAR_CHAR_D->stop_loop_perform_4(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_loop_perform_5(me);    // �жϳ���Ч��(���)
                CHAR_CHAR_D->stop_loop_perform_9(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_poison_effect(me);    // �ж϶�ҩЧ��

                me->set_char_action(DIE_ACT);

                set_effect(me, EFFECT_USER_DIE_5, 3);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%c%d%c", 0x3d, 2, getoid(me), flag );

                break;
       case 6 : // PVP����

                me->set_cast_file(0);    // ��������ؼ�
                me->set_cast_arg("");

                char = get_scene_object_2(me, USER_TYPE);
                send_user( char, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );    // ����ʩ������
                send_user( char, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                        41100, 1, UNDER_FOOT, 42100, 1, UNDER_FOOT, PF_STOP );    // ��������Ч��  get_cast_seal()

                me->set_perform_file(0);    // ����Ƿ��ؼ�
//                me->init_perform_dbase();    // �������ؼ�

                CHAR_CHAR_D->stop_loop_perform(me);    // �жϳ���Ч��
                CHAR_CHAR_D->stop_loop_perform_4(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_loop_perform_5(me);    // �жϳ���Ч��(���)
                CHAR_CHAR_D->stop_loop_perform_9(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_poison_effect(me);    // �ж϶�ҩЧ��

                me->set_char_action(DIE_ACT);

                send_user( get_scene_object_2(me, USER_TYPE), "%c%c%d%c", 0x3d, 2, getoid(me), flag );

                break;
       case 9 : // ս������״̬(�ػ��)

                me->set_cast_file(0);    // ��������ؼ�
                me->set_cast_arg("");

                char = get_scene_object_2(me, USER_TYPE);
                send_user( char, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );    // ����ʩ������
                send_user( char, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                        41100, 1, UNDER_FOOT, 42100, 1, UNDER_FOOT, PF_STOP );    // ��������Ч��  get_cast_seal()

                me->set_perform_file(0);    // ����Ƿ��ؼ�
//                me->init_perform_dbase();    // �������ؼ�

                CHAR_CHAR_D->stop_loop_perform(me);    // �жϳ���Ч��
                CHAR_CHAR_D->stop_loop_perform_4(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_loop_perform_5(me);    // �жϳ���Ч��(���)
                CHAR_CHAR_D->stop_loop_perform_9(me);    // �жϳ���Ч��(����)
                CHAR_CHAR_D->stop_poison_effect(me);    // �ж϶�ҩЧ��

                me->set_char_action(DIE_ACT);

                set_effect(me, EFFECT_USER_DIE_9, 15);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%c%d%c", 0x3d, 2, getoid(me), flag );

                break;

       case 0 : // ������״̬

                me->set_char_action(DEFAULT_ACT);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%c%d%c", 0x3d, 2, getoid(me), flag );

                break;
        }
        if (flag) me->save_limit_time();
        else me->restore_limit_time();

        return Die = flag;
}
