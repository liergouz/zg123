
#include <ansi.h>
#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

// ���������ɶ�������
void SAVE_BINARY() { }


// ��������ս����������
void not_fight_die( object me, object who, int damage )    // ���� me Ϊ NULL
{
        object map, owner, item,pet;
        string name;
        int z, x, y, p;

        if( get_effect(who, EFFECT_CHAR_DREAM) ) set_effect_2(who, EFFECT_CHAR_DREAM, 1, 1 );    // ����(�ж�)

        if( who->add_hp( -damage ) > 0 ) return;

        who->set_hp(0);

        if( get_effect(who, EFFECT_CHAR_IMMORTAL) ) return;    // ����֮��(����)

        if( who->is_npc() )    // NPC ����
        {
//              send_user( get_scene_object_2(who, USER_TYPE), "%c%d%c%d", 0x5f, getoid(who), get_d(who), objectp(me) ? getoid(me) : 0 );
		if ( who->is_trainer() )
        	{
        		return ;	
        	}
		if ( who->is_pet() )
		{
			NPC_PET_D->pet_die(me,who,2);
			return ;
		}
                if( me )
                {
                        who->win_bonus(me);
                        if( !objectp(who) ) return;    // �Ӹ�����(����ɾ��)
                }
                
		if(who->get("I_need_reflash")) {	//	�����������󶨵㸴��� add by cjxx
			map = get_map_object(get_z(who));
			if(map) {
				map->add("reflash_next",({ to_int(who->get_start_place()) }));
			}
		}
                who->remove_from_scene(FALL_ACT);    // �������ض���
                destruct(who);
        }
        else    // ��Ҵ���
        {
                if( me ) me->stop_fight();
                who->stop_fight();
		if ( get_effect(who, EFFECT_MAGIC_CARD) ) 
			MAGIC_CARD_D->into_effect(who);
                z = get_z(who);    // ���䳡��ս��
		map = get_map_object(z);
		if ( map && map->is_pvp() )
		{
			//PVP����
			who->set_die(6);    // �������ض���
		}
                else if( z < 885 )
                {
                        who->set_die(1);    // �������ض���
                }
                else if( z == 885 || z==891 )    // ���䳡
                {
                        who->set_die(5);    // �������ض���
                        send_user(who, "%c%s", '!', "��������ˣ�");
                }
                else    // ս��
                {
			if ( map && map->is_changping() )
			{
				//��ƽ֮ս
				send_user( who, "%c%s", '!', HIR "�����ˣ�15 ��󽫻��Զ����" );
				who->set_die(9);    // �������ض���
				if ( me )
				{	
					if ( me->is_user() || ((owner=me->get_owner())&&owner->is_user()) )
		                        	"npc/88/8800"->kill_player_bonus(me,who);	//����
		                        else
						write_user( who, HIR "����%sɱ���ˣ�", me->get_name() );                        	
				}
			}
                        else if( objectp( item = present("�ػ��", who, 1, MAX_CARRY) ) )
                        {
                                item->add_amount(-1);

                                who->set_die(9);    // �������ض���
                                send_user( who, "%c%s", '!', HIR "�����ˣ�15 ��󽫻��Զ����" );
                        }
                        else
                        {
                                who->set_die(5);    // �������ض���
                                send_user(who, "%c%s", '!', "����ɱ���ˣ�");
                        }
                }
                if ( (pet=who->get("showbeast") ) && pet->is_pet() )
			NPC_PET_D->pet_die(me,who,3);
        }
}

// ������������������
void is_enemy_die( object me, object who, int damage )    // ע�⣺�п��� me = NULL
{
        object map, owner, soldier, *zombie, item, oldcity,pet, orgnpc;
        string name;
	string result, leader;
	object *team;
	int level2, exp2, exp;        
        int i, size, p, x, y, z, oldz, level, point, yuan, ride, time;
        if( !me )
        {
                not_fight_die(me, who, damage);
                return;
        }


        if( get_effect(who, EFFECT_CHAR_DREAM) ) set_effect_2(who, EFFECT_CHAR_DREAM, 1, 1 );    // ����(�ж�)
        if( who->is_npc() )    // NPC ����
        {
        	if ( who->is_trainer() )
        	{
        		return ;	
        	}
        	if ( who->is_christmas() && (who->get("attack") < 15+random(10)) )
        	{
        		who->add("attack",1);
        		"sys/party/christmas"->away_user(who,me);
        		return;
        	}
                if( get_effect(who, EFFECT_NPC_0531_1) )    // ���Ȼ�״̬
                {
                        set_effect(who, EFFECT_NPC_0531_1, 1);
                }

                if( (who->get_enemy()==0 || damage >= who->get_max_damage() ) && who->get_action_mode()!=0 ) who->init_enemy_damage(me, damage);    // ��¼��ǿ�˺�(NPC)
//                if ( me->get_enemy()==0) me->set_enemy(who);

                if( objectp( owner = who->get_owner() ) && owner != me && owner->is_user() && me->is_user() )    // PK ״̬�趨
                {
/*
                        if( owner->get_char_type() == PK_TYPE )
                        {
                                // ���� PK ״̬���
                        }
                        else if( owner->is_pker() < 3 )    // ���� PK ״̬
                        {
                                me->set_char_type( PK_TYPE );    // �����У�״̬
                                set_effect(me, EFFECT_USER_PK, 120);
                        }
                        else    // ���� PK ����״̬
                        {
                                set_effect(me, EFFECT_USER_PK_RED, 120);
                        }
*/
                }
                
		CHAR_FIGHT_D->set_enmity(me,who,damage/3*2);
		
                if( who->add_hp( -damage ) > 0 ) return;
                if (who->no_die() ) return;

//              me->stop_fight();
//              who->set_hp(0);
//              who->stop_fight();

                if( get_effect(who, EFFECT_CHAR_IMMORTAL) )    // ����֮��(����)
                {
                        who->set_hp(0);
                        who->stop_fight();
                        me->stop_fight();

                        return;
                }

//              send_user( get_scene_object_2(who, USER_TYPE), "%c%d%c%d", 0x5f, getoid(who), get_d(who), getoid(me) );

                if( soldier = who->get("soldier") )    // ��������ٻ���
                {
                        soldier->remove_from_scene(FALL_ACT);
                        destruct(soldier);
                }
                if( arrayp( zombie = who->get("zombie") ) && ( size = sizeof(zombie) ) )
                {
                        for( i = 0; i < size; i ++ ) if( zombie[i] )
                        {
                                zombie[i]->remove_from_scene(FALL_ACT);
                                destruct( zombie[i] );
                        }
                }
                // ��ʱ�Ѿ���������������ְ�����֮ǰ�ĳ�������Ŀ����
                owner = who->get_enemy_4();
                if (objectp(owner) && who->can_be_fighted(owner) && owner->can_fight(who) ) me = owner;

                if( objectp( owner = me->get_owner() ) && owner->is_user() )
                {
                	
			me->set_action(me->get_next_action());
                        NPC_SLAVE_D->find_enemy(me);    // Ѱ�ҵ���
                }

		if ( who->is_pet() )
		{
			NPC_PET_D->pet_die(me,who,1);
			return ;
		}
                who->win_bonus(me);
                if( !objectp(who) ) return;    // �Ӹ�����(����ɾ��)

                // �����ٻ���ɾ������
                owner = who->get_owner();
                if (owner) send_user(owner, "%c%c%d", 0x2c, 0, getoid(who));
                	
		if(who->get("I_need_reflash")) {	//	�����������󶨵㸴��� add by cjxx
			map = get_map_object(get_z(who));
			if(map) {
				map->add("reflash_next",({ to_int(who->get_start_place()) }));
			}
		}
                who->remove_from_scene(FALL_ACT);    // �������ض���
                destruct(who);
        }
        else    // ��Ҵ���
        {
        	ride = who->get_ride();
        	if (ride>0)
        	{
        		if (damage>=300)
        		{
        			if (random100()<30) ride = 0;
        		}
        		else
        		if (damage>200)
        		{
        			if (random100()<20) ride = 0;
        		}        
        		else
        		if (damage>100)
        		{
        			if (random100()<10) ride = 0;
        		}     
        		if (ride==0)
        		{
        			who->set_ride(0);
        			who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
        		}     				        		
        	}
                // ���䳡��ս��
                if( soldier = who->get("soldier") )    
                {
                	if (soldier->get_enemy()==0 && soldier->get_action_mode()!=0 )
                	{
				soldier->init_heart_beat_idle();
	                        soldier->auto_fight(me);
				soldier->set_enemy(me);
				soldier->set_main_enemy(me);
				soldier->set_fight_time(time());

			}
                }
                if( arrayp( zombie = who->get("zombie") ) && ( size = sizeof(zombie) ) )
                {
                        for( i = 0; i < size; i ++ ) if( zombie[i] )
                	{
                		if (zombie[i]->get_enemy()==0 && zombie[i]->get_action_mode()!=0 )
                		{
					zombie[i]->init_heart_beat_idle();
		                        zombie[i]->auto_fight(me);
					zombie[i]->set_enemy(me);
					zombie[i]->set_main_enemy(me);
					zombie[i]->set_fight_time(time());
				}
			}
                }
		if ( (pet=who->get("showbeast") ) && pet->is_pet() )
                {
                	if (pet->get_enemy()==0 && pet->get_action_mode()!=0  )
                	{
				pet->init_heart_beat_idle();
	                        pet->auto_fight(me);
				pet->set_enemy(me);
				pet->set_main_enemy(me);
				pet->set_fight_time(time());
			}
                }	
                if( get_z(me) < 885 && me->is_user() )    // PK ״̬�趨
                {
/*
                        if( who->get_char_type() == PK_TYPE )
                        {
                                // ���� PK ״̬���
                        }
                        else if( who->is_pker() < 3 )    // ���� PK ״̬
                        {
                                me->set_char_type( PK_TYPE );    // �����У�״̬
                                set_effect(me, EFFECT_USER_PK, 120);
                        }
                        else    // ���� PK ����״̬
                        {
                                set_effect(me, EFFECT_USER_PK_RED, 120);
                        }
*/
                }

//              who->init_enemy_damage(me, damage);    // ��¼����˺�(���) -- ��ȡ��
		// �ܵ��������������ʧ
		if( get_effect(who, EFFECT_CHAR_INVISIBLE) )
		{
			set_effect_2( who, EFFECT_CHAR_INVISIBLE, 1, 1 );
		}
                if( who->get_skill(SKILL_0317) >= 1 )    // ����������
                {
                        point = who->add_damage_count(damage);
                        yuan = who->get_yuan();

                        if( point >= yuan * 20 + 30 * (100 + who->get_level()) / 100 )
                        {
                                who->set_damage_count(0);
                                if( who->add_yuan(1) != yuan ) send_user( who, "%c%d%w%c%c%c", 0x6f, getoid(who), 31711, 1, OVER_BODY, PF_ONCE );
                        }
                }
                else
                if( who->get_skill(SKILL_0348) >= 1 )    // ����������
                {
                        point = who->add_damage_count(damage);
                        yuan = who->get_yuan();

                        if( point >= yuan * 40 + 60 * (100 + who->get_level()) / 100 )
                        {
                                who->set_damage_count(0);
                                if( who->add_yuan(1) != yuan ) send_user( who, "%c%d%w%c%c%c", 0x6f, getoid(who), 31711, 1, OVER_BODY, PF_ONCE );
                        }
                }
                if(who->add_hp(-damage) >0) {return;}
                who->set_hp(0);
                who->stop_fight();
                me->stop_fight();

                if( get_effect(who, EFFECT_CHAR_IMMORTAL) ) return;    // ����֮��(����)
		if ( (pet=who->get("showbeast") ) && pet->is_pet() )	//����Ҳ����
			NPC_PET_D->pet_die(who,pet,3);
//              send_user( get_scene_object_2(who, USER_TYPE), "%c%d%c%d", 0x5f, getoid(who), get_d(who), getoid(me) );
		if ( get_effect(who, EFFECT_MAGIC_CARD) ) 
			MAGIC_CARD_D->into_effect(who);
                z = get_z(who);    // ���䳡��ս��
                map = get_map_object( get_z(who)) ;
                if ( me->get_enemy_die_process() )	//ע��Ҫ�ҵ���Ҫ�����NPC
                {
                	me->on_enemy_die(who);
                	return ;	
                }
                if (who->get_save_2("mastertask.type")==10 && me && me->get("user")==who->get_number() &&get_file_name(me)=="/npc/task/master_5" )
                {
			me->fight_over(who,me);
        		return;
                }
		if (map && map->get_client_id()==804&& map->is_virtual_scene() && me && get_file_name(me)=="/npc/01/0030")
		{
		        who->set_char_action(DIE_ACT);
		        send_user( get_scene_object_2(who, USER_TYPE), "%c%c%d%c", 0x3d, 2, getoid(who), 1 );
		        who->set_hp(1);
			map->begin_fight_die();
			return ;
		}
                if (who->get_save_2("masterfight.status")==1 && map && map->is_virtual_scene() && me && get_file_name(me)=="/npc/90/app_fight" )
                {
                        oldz = get_z(who);
                        oldcity = get_map_object(oldz);
                        send_user( who, "%c%s", ':', sprintf("%s��\n�㻹������������ս�ɡ�", me->get_name(), ) );
		        z = who->get_2("masterfight.z");
                	x = who->get_2("masterfight.x");
        	        y = who->get_2("masterfight.y");
		        if( !( p = get_valid_xy( z, x, y, IS_CHAR_BLOCK ) ) )
                        {
                                MAP_D->add_to_void(who);
                                return;
                        }
        	        x = p / 1000;  y = p % 1000;
	                who->add_to_scene(z, x, y, 3);
        		NEWBIE->destruct_virtual_map(oldcity, oldz);
        		return;
                }
                // add by cjxx -- one way of set die out of this function
                if(functionp(me->get_when_enemy_dead())) {
                	evaluate(me->get_when_enemy_dead(),who);
                	return;
                }               	
                // add end
                if (who->get_save_2("master_hide") && me->is_master_hide_task())
		{
			"sys/task/master"->hide_task_die(who);
			return;
		}
                if ( map && map->is_virtual_scene() && map->is_scum_map() )
		{
			"npc/party/scum2"->scum_die(map,who);
		        who->set_hp(1);
        		return;
		}
                if ( map && map->is_virtual_scene() && map->is_qixi_map() )
		{
			"npc/party/spirit"->scum_die(map,who);
		        who->set_hp(1);
        		return;
		}
		if ( map->is_pvp() && 
			( me->is_user() || ((owner=me->get_owner())&&owner->is_user()) ) )
		{
			//PVP����
			who->set_die(6);    // �������ض���
                        write_user( who, HIR "����%sɱ���ˣ�", me->get_name() );
			return ;
		}
		if ( map->is_changping() )
		{
			//��ƽ֮ս
			send_user( who, "%c%s", '!', HIR "�����ˣ�15 ��󽫻��Զ����" );
			who->set_die(9);    // �������ض���
			if ( me->is_user() || ((owner=me->get_owner())&&owner->is_user()) )
                        	"npc/88/8800"->kill_player_bonus(me,who);	//����
                        else
				write_user( who, HIR "����%sɱ���ˣ�", me->get_name() );                        	
			return ;
		}
                if( z < 885 || map->is_org_map() || map->is_copy_scene() || map->is_wushuang() )
                {
                        if( soldier = who->get("soldier") )    // ��������ٻ���
                        {
                                soldier->remove_from_scene(FALL_ACT);
                                destruct(soldier);
                        }
                        if( arrayp( zombie = who->get("zombie") ) && ( size = sizeof(zombie) ) )
                        {
                                for( i = 0; i < size; i ++ ) if( zombie[i] )
                                {
                                        zombie[i]->remove_from_scene(FALL_ACT);
                                        destruct( zombie[i] );
                                }
                        }

                        if( me->is_npc() )
                        {
                                if( objectp( owner = me->get_owner() ) && owner != who && owner->is_user() )
                                {
//                                        owner->add_pk(1);    // ���� PK ��־
                                }
                                else    me->lose_bonus(who);
                        }
                        else
                        {
//                                me->add_pk(1);    // ���� PK ��־
                        }

                        if( objectp( map = get_map_object( get_z(who) ) ) )
                        {
                                name = map ? map->get_name() : "������ͼ";
//                                CHAT_D->rumor_channel( 0, sprintf( HIM "��˵%s��%s��%sɱ���ˡ�", who->get_name(), name, me->get_name() ) );
                	}
                	if (me)
                        	name = me->get_name();
                        else
                        	name = "������";
                        // ����Ǳ����ɱ���ģ������л���Ӱ��
/*                        
                        if( objectp( owner = me->get_owner() ) && owner->is_user() ) who->set_save("userkill",1);
                        else
                        if ( me->is_user()  ) who->set_save("userkill",1);
*/                        
                        who->set_die(1);    // �������ض���
                        write_user( who, HIR "����%sɱ���ˣ�", name );
                }
                else if( map->get_client_id() == 885 || map->get_client_id()==891 )    // ���䳡
                {
                        who->set_die(5);    // �������ض���
                        send_user(who, "%c%s", '!', "����" + me->get_name() + "����ˣ�");
                        write_user(me, ECHO "����%s(%d)����ˣ�", who->get_name(), who->get_number() );
                }
                else    // ս��
                {
                        if( objectp( item = present("�ػ��", who, 1, MAX_CARRY) ) )
                        {
                                item->add_amount(-1);
                                who->set_die(9);    // �������ض���
                                tell_user( who, HIR "����" + me->get_name() + "ɱ���ˣ�" );
                                send_user( who, "%c%s", '!', HIR "�����ˣ��ػ����Ч��15 ��󽫻��Զ����" );
                        }
                        else
                        {
                                who->set_die(5);    // �������ض���
                                send_user(who, "%c%s", '!', "����" + me->get_name() + "ɱ���ˣ�");
                                tell_user(me, sprintf("����%s(%d)ɱ���ˣ�", who->get_name(), who->get_number() ) );
                                name = me->get_org_name();
                                if (name=="") return;
                                orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
				if (!objectp(orgnpc)) return;
				orgnpc->add_wood(who->get_level()/5);
				tell_user( me, sprintf("��������%s��Ϊ���ɻ����%d��ľ�ġ�", who->get_name(), who->get_level()/5) );
				
			        if( (leader=me->get_leader()) && arrayp( team = me->get_team() ) && sizeof(team) > 1 )
			        {
			                team = NPC_NPC_D->correct_bonus_team(team);
			                size = sizeof(team);
			        }
			        else    size = 1;
			        level = who->get_level();
			        exp = NPC_ENERGY_D->get_exp_bonus(level);    // ���ȡֵ
			         
			        if( size > 1 )    // ����
			        {
			                for( i = 0; i < size; i ++ ) if( team[i] )
			                {
			                        level2 = level - team[i]->get_level();
			                        exp2 = exp*(10+size-1)/10;
			                        exp2 = NPC_NPC_D->correct_exp_bonus(level, level2, exp2) * team[i]->get_online_rate() / 100;  
			                        if (exp2<1) exp2 = 1;
			                        team[i]->add_exp(exp2);
						NPC_SLAVE_D->add_slave_exp(team[i], exp2);
						NPC_PET_D->fight_bonus(team[i],who,size,0,0);
			                        team[i]->add_log("&battle", exp2);
						team[i]->add_log("#battle", 1);                        	
			                }
			        }
			        else    // ����
			        {
			                level2 = level - me->get_level();
			                exp2 = NPC_NPC_D->correct_exp_bonus(level, level2, exp) * me->get_online_rate() / 100;  
			                me->add_exp(exp2);
			                NPC_SLAVE_D->add_slave_exp(me, exp2);
					NPC_PET_D->fight_bonus(me,who,1,0,0);
			
			                me->add_log("&battle", exp2);                
			                me->add_log("#battle", 1);
			        }				
                        }
                }

                
        }
}
