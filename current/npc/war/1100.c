#include <ansi.h>
#include <city.h>
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <cmd.h>

inherit BADMAN;

int weapon;

int is_war_npc() {return 1;}

int is_caster;

// ���������촦��
void create()
{
        set_name("��ħʿ��");
	set_level(20);
        set_max_hp(100);  set_max_mp(0);
        set_ap(400);  set_dp(300);
        set_cp(  0);  set_pp(300);
        set_sp(0);

        set_walk_speed(3);  set_attack_speed(15);
        set_max_seek(4);
	set_char_picid(10);
	set_walk_step(1);
	set("no_correct_exp", 1);
        setup();

        set_char_type(FIGHTER_TYPE);    // ��������
}

int is_caster() 
{ 
	return is_caster;
}

int set_caster(int flag) {return is_caster = flag;}	

// ��������ȡװ������
int get_weapon_code() { return weapon; }

// ��������ȡװ������
int set_weapon_code(int flag) { return weapon = flag; }

// �������ؼ���������
int perform_action( object who ) 
{ 
	if (get_weapon_code()==UNARMED && is_caster()==0) return 0;
	if (get_weapon_code()==THROWING) return PF_FILE_01611->perform_action_npc( this_object(), who );
	return PF_FILE_04232->perform_action_npc( this_object(), who );
}


// ��������������
void win_bonus( object who ) { __FILE__ ->win_bonus2( this_object(), who ); }

// ��������������(���߸���)
void win_bonus2( object me, object who )
{
	int * list = ({ 11,12,13,14,15,16,17,18,19,20,21,23,24,25,26,28,29,30,31,32,34,36,37,38,39,40,41,42,43,44,45,46,47,48,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,74,75,76,77,78,79,80,81,82, });
	string name, result, file, owner, id;
	object orgnpc, map, item, leader;
	int z, p, x, y, number, add, rand, i, size, rate;
	int drop = 1;	
        if( who->get_owner() ) who = who->get_owner();
        if( who->is_npc() ) return;	
	"/sys/npc/npc"->win_bonus(me, who);
        id = who->get_leader();
        if (!id) owner = who->get_id();
        else
        {
        	if ( leader = find_player(id ) )
        	{
        		owner = leader->get_id();
		}      
		else
			owner = who->get_id();  		
	} 	
	rand = random(10000);
	rate = who->get_online_rate();
	if (rand<7800*rate/100) return;
	z = get_z(me), x = get_x(me), y = get_y(me);	
	if (rand<8000*rate/100)
	{
		if (random(2))
			file = ARMOR_FILE->get_armor_file_2(me->get_level());
		else
			file = WEAPON_FILE->get_weapon_file_2(me->get_level());		
		item = new (file);
		if (item && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
		{
			if (rand<7900) "/sys/item/equip"->init_equip_prop_1(item);
		        TEAM_D->drop_item(item,who);
		        item->set_user_id(owner);
		        item->set_value( me->get_level()*5 );
		        item->add_to_scene(z, p / 1000, p % 1000);
		        item->set("winner", who);
		        item->set( "time", time() );			
		}
		return;	
	}	
	if (rand<9000*rate/100)
		item = new ("/item/91/9101");
	else
	if (rand<10000*rate/100)
		item = new ("/item/91/9111");
	if (item && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
	{
		if (rand<7900) "/sys/item/equip"->init_equip_prop_1(item);
	        TEAM_D->drop_item(item,who);
	        item->set_user_id(owner);
	        item->set_value( me->get_level()*5 );
	        item->add_to_scene(z, p / 1000, p % 1000);
	        item->set("winner", who);
	        item->set( "time", time() );			
	}			       
	
}

void heart_beat_walk()
{
        object map, who, *see, *char, me, orgnpc;
        string cmd, name;
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

        z = get_z(me);  x = get_x(me);  y = get_y(me);
        // �ж��Ƿ������ת��5
        if( inside_jumpin( z, x, y, 5 ))
        {
        	map = get_map_object(z);
        	if (map)
        	{
        		char = map->get_player_dbase();
        		map->set_damage(map->get_damage()+1);
        		if (sizeof(char))
        		{
        			if (map->get_damage()<=100)
        			{
        				send_user( char, "%c%c%d%s", 0x43, 6, 0, sprintf(CHAT + HIY + "��ħ���ڽ����ƻ������ǵ�ǰ�𺦶�Ϊ��%d/100��", map->get_damage() )  );
        			}
        		}
        		send_user( get_scene_object_2(me, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(me), get_y(me), 32411, 1, OVER_BODY, PF_ONCE );
        		me->remove_from_scene();        		
        		destruct(me);
        		return;
        	}
        }
        if( who = me->get_main_enemy() )    // �������˹���(����Ҫ�ĵ���)
                me->set_enemy(who);
        else
        {
        	if (!me->get_enemy())
        	{
	                seek = me->get_max_seek();	
	                see = get_range_object(z, x, y, seek, USER_TYPE) +  get_range_object(z, x, y, seek, CHAR_TYPE);
	                char = filter_array( see, (: $1->is_war_npc() == 0 :), me );    
	                see = filter_array( char, (: $1->can_fight($2) :), me );    // 
	                if( objectp(who = get_near_char(see, z, x, y) ) ) me->auto_fight(who);
		}	               
        }

        if( gone_time( me->get_attack_time() ) > 10 ) me->init_enemy_damage(0, 0);    // ����˺�״̬

        z = get_z(me);  x = get_x(me);  y = get_y(me);

        if( objectp( who = me->get_enemy() ) )
        {
                if( who->is_die() )
                {
                        me->set_enemy(0);  flag = 1;
                }
                else    me->follow_user();
        }
        else    flag = 1;

        if( flag && objectp( map = get_map_object(z) ) )    // ����ָ��·��
        {
                p = 0;
		p2 = get_jumpin(z, 5);
		p = get_valid_path(z, x, y, p2/1000, p2%1000);
                if( p )    // �ҵ�����·��
                {
                        cmd = sprintf("%d", p);

                        switch( me->get_walk_step() )
                        {
                      default : if( strlen(cmd) > 1 ) cmd = cmd[0..0];  break;
                       case 2 : if( strlen(cmd) > 2 ) cmd = cmd[0..1];  break;
                        }
                        GO_CMD->main_npc(me, cmd);
                }
                else if( sizeof_range_object(z, x, y, 1, CHAR_TYPE) + sizeof_range_object(z, x, y, 1, USER_TYPE) < 9 )    // �������
                {
                        dir = ({ });
                        if( !( get_block(z, x + 1, y    ) & IS_CHAR_BLOCK ) ) dir += ({ 111 });
                        if( !( get_block(z, x + 1, y - 1) & IS_CHAR_BLOCK ) ) dir += ({ 222 });
                        if( !( get_block(z, x    , y - 1) & IS_CHAR_BLOCK ) ) dir += ({ 333 });
                        if( !( get_block(z, x - 1, y - 1) & IS_CHAR_BLOCK ) ) dir += ({ 444 });
                        if( !( get_block(z, x - 1, y    ) & IS_CHAR_BLOCK ) ) dir += ({ 555 });
                        if( !( get_block(z, x - 1, y + 1) & IS_CHAR_BLOCK ) ) dir += ({ 666 });
                        if( !( get_block(z, x    , y + 1) & IS_CHAR_BLOCK ) ) dir += ({ 777 });
                        if( !( get_block(z, x + 1, y + 1) & IS_CHAR_BLOCK ) ) dir += ({ 888 });

                        if( ( size = sizeof(dir) ) && ( p = dir[ random(size) ] ) )    // �ҵ�����·��
                        {
                                cmd = sprintf("%d", p);

                                switch( me->get_walk_step() )
                                {
                              default : if( strlen(cmd) > 1 ) cmd = cmd[0..0];  break;
                               case 2 : if( strlen(cmd) > 2 ) cmd = cmd[0..1];  break;
                                }
                                GO_CMD->main_npc(me, cmd);
                        }
                }
        }

        x = abs( x - get_x(me) );  y = abs( y - get_y(me) );
        walk = ( x > y ) ? x : y;

        if( walk > 0 )
        {
                set_heart_state(me, 0);
                set_heart_count_2(me, 3 * walk + 1);    // walk * 10 / 4
        }
}