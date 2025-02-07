#include <ansi.h>
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <city.h>

inherit COMRADE;

// �������Ƿ������ƶ�
int is_moveable() { return 0; }    // ��ֹʹ�� go ����

// �������Ƿ��ܼ�Ѫ
int no_recover() { return 1; }    // ����ʹ�ûָ���Ѫ�ķ���

int no_die() {return 1;}

// �������������(����֮�е���)
void follow_user() { }    // ��ֹ�������

// ���������촦��
void create()
{
        set_name( "������" );
        set_char_picid(9901);    // ����ȱʡ����

     	set_max_hp(50000);  set_max_mp(0);
        set_ap( 500);  set_dp(300);  
        set_cp(  0);  set_pp(300);  
        set_sp(0);
        set_attack_speed(15);
        set_hp(get_max_hp());
        setup();

        set_char_type(FIGHTER_TYPE);
}

// ���������õȼ�
void set_level( int point )
{
        switch( point )
        {
      default : set_max_hp(50000);  set_max_mp(0);
                set_ap( 500);  set_dp(300);  
                set_cp(  0);  set_pp(300);  
                set_sp(0);
                set_attack_speed(15);
                break;
       case 1 : 
       		set_char_picid(9902);
       		set_name( "ľ����" );
       		set_max_hp(80000);  set_max_mp(0);
                set_ap(700);  set_dp(480);  
                set_cp(  0);  set_pp(480);  
                set_sp(0);
                set_attack_speed(15);
                break;
       case 2 : 
       		set_char_picid(9903);
       		set_name( "ʯ����" );
       		set_max_hp(150000);  set_max_mp(0);
                set_ap(900);  set_dp(680);  
                set_cp(  0);  set_pp(550);  
                set_sp(0);
                set_attack_speed(15);
                break;
       case 3 : 
       		set_char_picid(9904);
       		set_name( "�߼�����" );
       		set_max_hp(300000);  set_max_mp(0);
                set_ap(1300);  set_dp(1000);  
                set_cp(  0);  set_pp(890);  
                set_sp(0);
                set_attack_speed(10);
                break;                
        }        
}

// ��������ȡװ������
int get_weapon_code() { return THROWING; }

// �������ؼ���������
int perform_action( object who ) { return __FILE__ ->perform_action_npc( this_object(), who ); }

// �����������
int perform_action_npc( object me, object who )
{
        int x, y;

        x = get_x(who);  y = get_y(who);
        if( !inside_screen_2(me, who) ) return 0;
        if (me->get_hp()==1) return 0;

        me->to_front_xy(x, y);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 0, get_d(me), getoid(who) );

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( who->get_char_id() );

        return 1;
}

// ��������������
int cast_done_npc( object me )
{
        object who, owner;
        string arg;
        int z, x0, y0, x1, y1;
        int ap, damage;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 10120, 1, OVER_BODY, PF_ONCE );

        // CHAR_FIGHT_D->throwing_done(me, who, HIT_NORMAL);    // ���¸����� CHAR_FIGHT_D ##########

        if( !who || !who->can_be_fighted(me) || !me->can_fight(who) ) return 1;

        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);  x1 = get_x(who);  y1 = get_y(who);

        if( !inside_screen_2(me, who) ) return 1;
        if( !from_to(z, x0, y0, x1 - x0, y1 - y0, MAP_BLOCK ) ) return 1;
        CHAR_FIGHT_D->throwing_done(me, who, HIT_NORMAL);
/*
        ap = me->get_ap();

        me->to_front_xy(x1, y1);

        if( who->is_npc() )
        {
                if( who->get_enemy_4() == me ) 
                        who->set_attack_time( time() );    // ͬһ���ˣ����³���ʱ��
                else if( gone_time( who->get_attack_time() ) > 5 )
                {
                        who->set_enemy_4(me);
                        who->set_attack_time( time() );    // ��ͬ���ˣ����³�������
                }
                if( !who->get_max_damage() ) who->init_enemy_damage(me, 0);    // ��¼��ǿ�˺�(NPC)
        }

        damage = ap - ap * 100 / 10 / 100;

	if (who->is_user()) owner = who;
	else owner = who->get_owner();
        if (owner) send_user( owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage, get_d(who), getoid(me), HIT_NORMAL, 2 );

        if( who->is_user() ) CHAR_FIGHT_D->wear_down(who);    // ���м����;�

        CHAR_DIE_D->is_enemy_die(me, who, damage);
        if( me->get_hp() < 1 ) CHAR_DIE_D->is_enemy_die(who, me, 0);
*/
        return 2;    // ִ�гɹ�
}

// ��������������
void win_bonus( object who ) {  }

// �������жϿ���ս��
int can_fight( object who ) 
{ 
	object me = this_object();	
        if( me->get_no_fight() ) return 0;
        if( me == who ) return 0;    // ��ֹ�����Լ�	
        if (who->is_npc())
        {
        	if (who->get_char_type()==OFFICER_TYPE) return 0;
        	if (who->get_owner()) who = who->get_owner();        	
        }
        if (me->get_hp()==0) return 0;
        if (who->is_npc()) return 1;
        return 0; 
}

// ���������Խ���ս��
int can_be_fighted( object who ) 
{        
        if (who->is_npc()) return 1;
        return 0; 
}


// ������������������
void heart_beat_walk( )    // ÿ 0.1 �봦��
{
        object map, who, *see, *char, me;
        string cmd;
        int z, x, y, x1, y1, dx, p, p2;
        int walk, seek, flag, *dir, i, size;
	me = this_object();
        if(     get_effect(me, EFFECT_CHAR_BUSY)
        ||      get_effect(me, EFFECT_CHAR_FAINT)
        ||      get_effect(me, EFFECT_SLEEP)
        ||      get_effect(me, EFFECT_CHAR_FAINT_2)
        ||      get_effect(me, EFFECT_CHAR_FREEZE) ) 
                return;

        if( !me->get_action() ) return;

        if( who = me->get_main_enemy() )    // �������˹���(����Ҫ�ĵ���)
                me->set_enemy(who);
        else
        if (!me->get_enemy())
        {        	
                z = get_z(me);  x = get_x(me);  y = get_y(me);
                seek = me->get_max_seek();

                char = get_range_object(z, x, y, seek, USER_TYPE) + get_range_object(z, x, y, seek, CHAR_TYPE);    // ����ɼ���Χ

                
                see = filter_array( char, (: $2->can_fight($1) :), me );    // ���ڲ�ͬ����    // get_org_name() ���ִ�����

                if( objectp(who = get_near_char(see, z, x, y) ) ) 
                {		           	
                	me->auto_fight(who);
                }
        }

        if( gone_time( me->get_attack_time() ) > 10 ) me->init_enemy_damage(0, 0);    // ����˺�״̬

        z = get_z(me);  x = get_x(me);  y = get_y(me);

        if( objectp( who = me->get_enemy() ) )
        {
                if( who->is_die() )
                {
                        me->set_enemy(0); 
                }
                else
                if (distance_between(me, who)>10)
                {
                        me->set_enemy(0); 
                }                
        }
}