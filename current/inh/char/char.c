
#include <cmd.h>
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <city.h>

inherit DBASE_F;

private static int Type;                // �������
private static int PicId;               // ��������
private static int PhotoId;             // ����ͷ��

private int Gender;                     // �Ա�
private int NoFight;                    // ��ս��־(��ȫ��)
private string StartPlace;              // ���ӳ���

private static int Ride;		// ���

// ����������ʶ����
int is_char() { return 1; }

// ��������ȡ�����ʶ(���� find_char ����)
string get_char_id() { return sprintf( "%x#", getoid( this_object() ) ); }    // �漰̫�㣬��ֹ�Ķ�

// -------------------------------------------------------------

// ��������ȡ����״̬
int get_char_action() { return DEFAULT_ACT; }

// ��������ȡ�������
int get_char_type() { return Type; }

// �����������������
int set_char_type( int type )
{
        if( Type != type ) send_user( get_scene_object_2( this_object(), USER_TYPE ), "%c%c%d%c", 0x3d, 1, getoid( this_object() ), type );
        return Type = type;
}

// ��������ȡ��������
int get_char_picid() { return PicId; }

// ������������������
int set_char_picid( int id ) { return PicId = id; }

// ��������ȡ��������
int get_char_photoid() { return PhotoId>0?PhotoId:PicId; }

// ������������������
int set_char_photoid( int id ) { return PhotoId = id; }

// ��������ȡ�Ա��־
int get_gender() { return Gender; }

// �����������Ա��־
int set_gender( int flag ) { return Gender = flag; }

// ��������ȡ��ս��־
int get_no_fight() { return NoFight; }

// ���������ý�ս��־
int set_no_fight( int flag ) { return NoFight = flag; }

// ��������ȡ���
int get_ride() { return Ride; }

// �������������
int set_ride( int flag ) { return Ride = flag; }

// ��������ȡ���߳���
string get_start_place() { return StartPlace; }

// �������������߳���
string set_start_place( string place ) { return StartPlace = place; }

// -------------------------------------------------------------

// ����������������(NPC)
int to_front( int d )
{
        object me = this_object();

        d = range_value(d, 1, 8);

        if( get_d(me) != d )
        {
                set_d(me, d);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%d%c", 0x5e, getoid(me), get_d(me) );
        }

        return d;
}

// ������������������
int to_front_xy( int x1, int y1 )
{
        return to_front( get_front_xy( get_x( this_object() ), get_y( this_object() ), x1, y1 ) );
}

// ���������ñ˴�����
void to_front_eachother( object who )
{
        // to_front_xy( get_x(who), get_y(who) );

        switch( to_front( get_front_xy( get_x( this_object() ), get_y( this_object() ), get_x(who), get_y(who) ) ) )
        {
       case 1 : who->to_front(5);  break;
       case 2 : who->to_front(6);  break;
       case 3 : who->to_front(7);  break;
       case 4 : who->to_front(8);  break;
       case 5 : who->to_front(1);  break;
       case 6 : who->to_front(2);  break;
      default : who->to_front(3);  break;
       case 8 : who->to_front(4);  break;
        }
}

// -------------------------------------------------------------

string get_short();
int get_hp_cent();
int get_walk_speed();

// ��������ʾ�������(�Է�������)(NPC ר��)
void show_to_user( object who )
{
        object me = this_object();
        int id = getoid(me);
        int type=0;
        if (get_char_picid()) type = get_char_picid();
        if( get_effect(me, EFFECT_MAGIC_4243) ) type = get("pf#4243");

        if( type )
        {
                send_user( who, "%c%c%d%w%w%c%c%c%w%c%c%d%s", 0x69, 128, id,
                        get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(), type,
                        get_hp_cent(), get_walk_speed(), 0, get_short() );
                if (get_head_color())
                {
//                	if (MAIN_D->get_host_type()!=1000)
			if (0)
                		send_user(who, "%c%d%c%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0 );
                	else
                		send_user(who, "%c%d%d%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0 );
                }
        }
        else
        {
//        	if (MAIN_D->get_host_type()!=1000)
		if (0)
	        	send_user( who, "%c%c%d%w%w%c%c%c%c%d%d%w%d%w%c%c%c%c%d%s", 0x69, 0, id,
	                        get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
	                        get_armor_code(), get_armor_color_1(), get_armor_color_2(),
	                        get_head_code(), get_head_color(), get_weapon_code_2(), 0, 0,
	                        get_hp_cent(), get_walk_speed(), 0, get_short() );
		else
	        	send_user( who, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
	                        get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
	                        get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
	                        get_hp_cent(), get_walk_speed(), 0, get_short() );


	}
	if (me->get_id_color()) send_user( who, "%c%d%d", 0x66, id, me->get_id_color());
	if (me->get_ride()) send_user( who, "%c%d%d", 0x62, id, me->get_ride());
        CHAR_CHAR_D->send_loop_perform(me, who);    // ��ʾ����Ч��
        CHAR_CHAR_D->send_loop_perform_2(me, who);    // ��ʾ����ͼ��
}

// ��������ʾ����ҿ�(�½��볡��)(NPC ר��)
varargs void show_to_scene( object *user, int x, int y, int d, int add_pf, int add_pf_2 )
{
        object me = this_object();
        int id = getoid(me);
        int type=0;
        if (get_char_picid()) type = get_char_picid();
        if( get_effect(me, EFFECT_MAGIC_4243) ) type = get("pf#4243");
        if( type )
        {
                if( !add_pf )
                        send_user( user, "%c%c%d%w%w%c%c%c%w%c%c%d%s", 0x69, 128, id,
                                x, y, d, get_char_type(), get_char_action(), type,
                                get_hp_cent(), get_walk_speed(), 0, get_short() );
                else if( !add_pf_2 )
                        send_user( user, "%c%c%d%w%w%c%c%c%w%c%w%c%c%c%d%s", 0x69, 129, id,
                                x, y, d, get_char_type(), get_char_action(), type,
                                get_hp_cent(), add_pf, 1, OVER_BODY, get_walk_speed(), 0, get_short() );
                else    send_user( user, "%c%c%d%w%w%c%c%c%w%c%w%c%c%w%c%c%c%d%s", 0x69, 130, id,
                                x, y, d, get_char_type(), get_char_action(), type,
                                get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, get_walk_speed(), 0, get_short() );

                if (get_head_color())
                {
//                	if (MAIN_D->get_host_type()!=1000) 
			if (0)
                		send_user(user, "%c%d%c%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0 );
                	else 
                		send_user(user, "%c%d%d%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0 );
                }
        }
        else
        {
                if( !add_pf )
                        send_user( user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
                                x, y, d, get_char_type(), get_char_action(),
                                get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
                                get_hp_cent(), get_walk_speed(), 0, get_short() );
                else if( !add_pf_2 )
                        send_user( user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%c%d%s", 0x69, 1, id,
                                x, y, d, get_char_type(), get_char_action(),
                                get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
                                get_hp_cent(), add_pf, 1, OVER_BODY, get_walk_speed(), 0, get_short() );
                else    send_user( user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%w%c%c%c%d%s", 0x69, 2, id,
                                x, y, d, get_char_type(), get_char_action(),
                                get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
                                get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, get_walk_speed(), 0, get_short() );
        }
	if (me->get_id_color()) send_user( user, "%c%d%d", 0x66, id, me->get_id_color());
	if (me->get_ride()) send_user( user, "%c%d%d", 0x62, id, me->get_ride());
        CHAR_CHAR_D->send_loop_perform(me, user);    // ��ʾ����Ч��
        CHAR_CHAR_D->send_loop_perform_2(me, user);    // ��ʾ����ͼ��
}

// ���������볡������(NPC ר��)
varargs void add_to_scene( int z, int x, int y, int d, int add_pf, int add_pf_2, int rm_pf, int rm_pf_2 )
{
        object *user, *npc, who, me;
        int z0, x0, y0;

        me = this_object();

        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);
        remove_block(z0, x0, y0, CHAR_BLOCK);
        user = get_scene_object(z0, x0, y0, USER_TYPE) - ({ me });
        if( !rm_pf )
                send_user( user, "%c%d", 0x78, getoid(me) );
        else if( !rm_pf_2 )
                send_user( user, "%c%d%w%c%c", 0x78, getoid(me), rm_pf, 1, OVER_BODY );
        else    send_user( user, "%c%d%w%c%c%w%c%c", 0x78, getoid(me), rm_pf, 1, OVER_BODY, rm_pf_2, 1, OVER_BODY );

        set_z(me, z);  set_x(me, x);  set_y(me, y);  set_d(me, d);
        set_block(z, x, y, CHAR_BLOCK);
        objectp( who = me->get_owner() ) && who->is_user() ? move_object(me, z, x, y, USER_TYPE) : move_object(me, z, x, y, CHAR_TYPE);

        user = get_scene_object(z, x, y, USER_TYPE);
        show_to_scene(user, x, y, d, add_pf, add_pf_2);

        if( MAP_D->is_inside_safe_zone(z, x, y) )    // ��ȫ���ж�
        {
                me->set_no_fight(1);
        }
        else
        {
                me->set_no_fight(0);
		if (me->get_action_mode()==1)
		{
	                if( objectp( me->get_owner() ) )    // �Զ�ս��
	                {
	                        npc = get_range_object_2(me, 6, CHAR_TYPE);

	                        if( sizeof(npc) )
	                        {
	                                npc->init_heart_beat_idle();
	                                npc->auto_fight(me);
	                        }
	                }
	                else if( who = get_near_object(z, x, y, 6, USER_TYPE) )
	                {
	                        me->auto_fight(who);
	                }
		}
        }

        if( get_effect(me, EFFECT_CHAR_CHAN) ) set_effect(me, EFFECT_CHAR_CHAN, 1);    // �Ƴ�ճ��Ч��       
}

// ������ɾ������ҿ�(�Է��볡��)
void remove_to_user( object who )
{
        send_user( who, "%c%d", 0x78, getoid( this_object() ) );
}

// �������ӳ������Ƴ�
varargs void remove_from_scene( int rm_pf, int rm_pf_2 )
{
        object *user, me, owner;

        me = this_object();

        remove_block( get_z(me), get_x(me), get_y(me), CHAR_BLOCK );        
        user = get_scene_object_2(me, USER_TYPE) - ({ me });
        if( !rm_pf )
                send_user( user, "%c%d", 0x78, getoid(me) );
        else if( !rm_pf_2 )
                send_user( user, "%c%d%w%c%c", 0x78, getoid(me), rm_pf, 1, OVER_BODY );
        else    send_user( user, "%c%d%w%c%c%w%c%c", 0x78, getoid(me), rm_pf, 1, OVER_BODY, rm_pf_2, 1, OVER_BODY );
        if( owner = me->get_owner() )
        {
        	send_user( owner, "%c%c%d", 0x2c, 0, getoid(me) );    // �����ٻ�������
        }
        set_x(me, 0); set_y(me, 0); set_z(me, 0);
}
