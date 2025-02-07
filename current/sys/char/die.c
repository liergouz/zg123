
#include <ansi.h>
#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

// 函数：生成二进制码
void SAVE_BINARY() { }


// 函数：非战斗死亡处理
void not_fight_die( object me, object who, int damage )    // 允许 me 为 NULL
{
        object map, owner, item,pet;
        string name;
        int z, x, y, p;

        if( get_effect(who, EFFECT_CHAR_DREAM) ) set_effect_2(who, EFFECT_CHAR_DREAM, 1, 1 );    // 梦游(中断)

        if( who->add_hp( -damage ) > 0 ) return;

        who->set_hp(0);

        if( get_effect(who, EFFECT_CHAR_IMMORTAL) ) return;    // 不死之身(不死)

        if( who->is_npc() )    // NPC 处理
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
                        if( !objectp(who) ) return;    // 加个保险(请勿删除)
                }
                
		if(who->get("I_need_reflash")) {	//	加入了死亡后定点复活处理 add by cjxx
			map = get_map_object(get_z(who));
			if(map) {
				map->add("reflash_next",({ to_int(who->get_start_place()) }));
			}
		}
                who->remove_from_scene(FALL_ACT);    // 包含倒地动作
                destruct(who);
        }
        else    // 玩家处理
        {
                if( me ) me->stop_fight();
                who->stop_fight();
		if ( get_effect(who, EFFECT_MAGIC_CARD) ) 
			MAGIC_CARD_D->into_effect(who);
                z = get_z(who);    // 比武场、战场
		map = get_map_object(z);
		if ( map && map->is_pvp() )
		{
			//PVP死亡
			who->set_die(6);    // 包含倒地动作
		}
                else if( z < 885 )
                {
                        who->set_die(1);    // 包含倒地动作
                }
                else if( z == 885 || z==891 )    // 比武场
                {
                        who->set_die(5);    // 包含倒地动作
                        send_user(who, "%c%s", '!', "您被打败了！");
                }
                else    // 战场
                {
			if ( map && map->is_changping() )
			{
				//长平之战
				send_user( who, "%c%s", '!', HIR "您死了，15 秒后将会自动复活。" );
				who->set_die(9);    // 包含倒地动作
				if ( me )
				{	
					if ( me->is_user() || ((owner=me->get_owner())&&owner->is_user()) )
		                        	"npc/88/8800"->kill_player_bonus(me,who);	//奖励
		                        else
						write_user( who, HIR "您被%s杀死了！", me->get_name() );                        	
				}
			}
                        else if( objectp( item = present("回魂符", who, 1, MAX_CARRY) ) )
                        {
                                item->add_amount(-1);

                                who->set_die(9);    // 包含倒地动作
                                send_user( who, "%c%s", '!', HIR "您死了，15 秒后将会自动复活。" );
                        }
                        else
                        {
                                who->set_die(5);    // 包含倒地动作
                                send_user(who, "%c%s", '!', "您被杀死了！");
                        }
                }
                if ( (pet=who->get("showbeast") ) && pet->is_pet() )
			NPC_PET_D->pet_die(me,who,3);
        }
}

// 函数：敌人死亡处理
void is_enemy_die( object me, object who, int damage )    // 注意：有可能 me = NULL
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


        if( get_effect(who, EFFECT_CHAR_DREAM) ) set_effect_2(who, EFFECT_CHAR_DREAM, 1, 1 );    // 梦游(中断)
        if( who->is_npc() )    // NPC 处理
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
                if( get_effect(who, EFFECT_NPC_0531_1) )    // 被魅惑状态
                {
                        set_effect(who, EFFECT_NPC_0531_1, 1);
                }

                if( (who->get_enemy()==0 || damage >= who->get_max_damage() ) && who->get_action_mode()!=0 ) who->init_enemy_damage(me, damage);    // 记录最强伤害(NPC)
//                if ( me->get_enemy()==0) me->set_enemy(who);

                if( objectp( owner = who->get_owner() ) && owner != me && owner->is_user() && me->is_user() )    // PK 状态设定
                {
/*
                        if( owner->get_char_type() == PK_TYPE )
                        {
                                // 攻击 PK 状态玩家
                        }
                        else if( owner->is_pker() < 3 )    // 进入 PK 状态
                        {
                                me->set_char_type( PK_TYPE );    // 主动ＰＫ状态
                                set_effect(me, EFFECT_USER_PK, 120);
                        }
                        else    // 进入 PK 红名状态
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

                if( get_effect(who, EFFECT_CHAR_IMMORTAL) )    // 不死之身(不死)
                {
                        who->set_hp(0);
                        who->stop_fight();
                        me->stop_fight();

                        return;
                }

//              send_user( get_scene_object_2(who, USER_TYPE), "%c%d%c%d", 0x5f, getoid(who), get_d(who), getoid(me) );

                if( soldier = who->get("soldier") )    // 死亡清空召唤兽
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
                // 此时已经死亡，将死亡的职责归于之前的持续攻击目标上
                owner = who->get_enemy_4();
                if (objectp(owner) && who->can_be_fighted(owner) && owner->can_fight(who) ) me = owner;

                if( objectp( owner = me->get_owner() ) && owner->is_user() )
                {
                	
			me->set_action(me->get_next_action());
                        NPC_SLAVE_D->find_enemy(me);    // 寻找敌人
                }

		if ( who->is_pet() )
		{
			NPC_PET_D->pet_die(me,who,1);
			return ;
		}
                who->win_bonus(me);
                if( !objectp(who) ) return;    // 加个保险(请勿删除)

                // 加上召唤兽删除处理
                owner = who->get_owner();
                if (owner) send_user(owner, "%c%c%d", 0x2c, 0, getoid(who));
                	
		if(who->get("I_need_reflash")) {	//	加入了死亡后定点复活处理 add by cjxx
			map = get_map_object(get_z(who));
			if(map) {
				map->add("reflash_next",({ to_int(who->get_start_place()) }));
			}
		}
                who->remove_from_scene(FALL_ACT);    // 包含倒地动作
                destruct(who);
        }
        else    // 玩家处理
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
                // 比武场、战场
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
                if( get_z(me) < 885 && me->is_user() )    // PK 状态设定
                {
/*
                        if( who->get_char_type() == PK_TYPE )
                        {
                                // 攻击 PK 状态玩家
                        }
                        else if( who->is_pker() < 3 )    // 进入 PK 状态
                        {
                                me->set_char_type( PK_TYPE );    // 主动ＰＫ状态
                                set_effect(me, EFFECT_USER_PK, 120);
                        }
                        else    // 进入 PK 红名状态
                        {
                                set_effect(me, EFFECT_USER_PK_RED, 120);
                        }
*/
                }

//              who->init_enemy_damage(me, damage);    // 记录最近伤害(玩家) -- 已取消
		// 受到攻击，隐身会消失
		if( get_effect(who, EFFECT_CHAR_INVISIBLE) )
		{
			set_effect_2( who, EFFECT_CHAR_INVISIBLE, 1, 1 );
		}
                if( who->get_skill(SKILL_0317) >= 1 )    // 护体金罡－集气
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
                if( who->get_skill(SKILL_0348) >= 1 )    // 护体金罡－集气
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

                if( get_effect(who, EFFECT_CHAR_IMMORTAL) ) return;    // 不死之身(不死)
		if ( (pet=who->get("showbeast") ) && pet->is_pet() )	//宠物也死亡
			NPC_PET_D->pet_die(who,pet,3);
//              send_user( get_scene_object_2(who, USER_TYPE), "%c%d%c%d", 0x5f, getoid(who), get_d(who), getoid(me) );
		if ( get_effect(who, EFFECT_MAGIC_CARD) ) 
			MAGIC_CARD_D->into_effect(who);
                z = get_z(who);    // 比武场、战场
                map = get_map_object( get_z(who)) ;
                if ( me->get_enemy_die_process() )	//注意要找到主要处理的NPC
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
                        send_user( who, "%c%s", ':', sprintf("%s：\n你还是练练再来挑战吧。", me->get_name(), ) );
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
			//PVP死亡
			who->set_die(6);    // 包含倒地动作
                        write_user( who, HIR "您被%s杀死了！", me->get_name() );
			return ;
		}
		if ( map->is_changping() )
		{
			//长平之战
			send_user( who, "%c%s", '!', HIR "您死了，15 秒后将会自动复活。" );
			who->set_die(9);    // 包含倒地动作
			if ( me->is_user() || ((owner=me->get_owner())&&owner->is_user()) )
                        	"npc/88/8800"->kill_player_bonus(me,who);	//奖励
                        else
				write_user( who, HIR "您被%s杀死了！", me->get_name() );                        	
			return ;
		}
                if( z < 885 || map->is_org_map() || map->is_copy_scene() || map->is_wushuang() )
                {
                        if( soldier = who->get("soldier") )    // 死亡清空召唤兽
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
//                                        owner->add_pk(1);    // 增加 PK 标志
                                }
                                else    me->lose_bonus(who);
                        }
                        else
                        {
//                                me->add_pk(1);    // 增加 PK 标志
                        }

                        if( objectp( map = get_map_object( get_z(who) ) ) )
                        {
                                name = map ? map->get_name() : "无名地图";
//                                CHAT_D->rumor_channel( 0, sprintf( HIM "听说%s在%s被%s杀死了。", who->get_name(), name, me->get_name() ) );
                	}
                	if (me)
                        	name = me->get_name();
                        else
                        	name = "无名氏";
                        // 如果是被玩家杀死的，不会有坏的影响
/*                        
                        if( objectp( owner = me->get_owner() ) && owner->is_user() ) who->set_save("userkill",1);
                        else
                        if ( me->is_user()  ) who->set_save("userkill",1);
*/                        
                        who->set_die(1);    // 包含倒地动作
                        write_user( who, HIR "您被%s杀死了！", name );
                }
                else if( map->get_client_id() == 885 || map->get_client_id()==891 )    // 比武场
                {
                        who->set_die(5);    // 包含倒地动作
                        send_user(who, "%c%s", '!', "您被" + me->get_name() + "打败了！");
                        write_user(me, ECHO "您把%s(%d)打败了！", who->get_name(), who->get_number() );
                }
                else    // 战场
                {
                        if( objectp( item = present("回魂符", who, 1, MAX_CARRY) ) )
                        {
                                item->add_amount(-1);
                                who->set_die(9);    // 包含倒地动作
                                tell_user( who, HIR "您被" + me->get_name() + "杀死了！" );
                                send_user( who, "%c%s", '!', HIR "您死了，回魂符生效，15 秒后将会自动复活。" );
                        }
                        else
                        {
                                who->set_die(5);    // 包含倒地动作
                                send_user(who, "%c%s", '!', "您被" + me->get_name() + "杀死了！");
                                tell_user(me, sprintf("您把%s(%d)杀死了！", who->get_name(), who->get_number() ) );
                                name = me->get_org_name();
                                if (name=="") return;
                                orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
				if (!objectp(orgnpc)) return;
				orgnpc->add_wood(who->get_level()/5);
				tell_user( me, sprintf("你消灭了%s，为帮派获得了%d个木材。", who->get_name(), who->get_level()/5) );
				
			        if( (leader=me->get_leader()) && arrayp( team = me->get_team() ) && sizeof(team) > 1 )
			        {
			                team = NPC_NPC_D->correct_bonus_team(team);
			                size = sizeof(team);
			        }
			        else    size = 1;
			        level = who->get_level();
			        exp = NPC_ENERGY_D->get_exp_bonus(level);    // 查表取值
			         
			        if( size > 1 )    // 多人
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
			        else    // 单人
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
