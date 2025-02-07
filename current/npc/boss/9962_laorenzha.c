/*----------------------------------------------------------------*\
	���ƣ�NPC -- ������
	���ߣ���cjxx ����������ϻ�������װ��
	���ʣ��ר��PK�ý����� BOSS 
\*----------------------------------------------------------------*/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>

inherit NPC;

#define _DEBUG(str) 		  ;//if(objectp(find_char("-1"))) tell_user(find_char("1"),str);

private string *familys = ({"�һ�Դ","��ɽ","������","����","éɽ","����ɽ","������"});		//	�������ԣ�����ʱʹ��
private int rand_say_time =0;			//	���˵����ʱ��
private int auto_jump_time=0;			//	˲���ƶ���ʱ��

int summon_slave( object me );			//	�ٻ��۵Ĵ���
void drop_items( object me, object who );	//	������������

int cannot_enter_city() {
	return 1;
}

//	���캯��
void create() {
	set_name("������");
	set_char_picid(9962);
	set_level(80);
	set_char_type(FIGHTER_TYPE);
	set("birthday",time());
	setup();
}

//	�ص�:�ж��Ƿ���Թ���
int can_fight( object who ) { 
        object owner;
        string leader, id;
	if( who->is_die() ) {
		set_enemy(0);
		return 0;
	}
	if( who->is_npc() && objectp(owner = who->get_owner()) ) {
		who = owner;
	}
	if( who->is_npc() ) {
		set_enemy(0);
		return 0;
	}
	return ::can_fight(who);
}

//	�ص����ж��Ƿ���Ա�����
int can_be_fighted( object who ) { 
        object owner;
        string leader, id;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) {
		who = owner;
	}
	if( who->is_npc() ) {
		set_enemy(0);
		return 0;
	}
	return ::can_be_fighted(who);
}

//	�ص�����������
void heart_beat_walk() {
	object me,enemy;
	me    = this_object();
	enemy = get_enemy();
	if(objectp(enemy)) {
		if(gone_time(rand_say_time) >= 30 ) {
			rand_say_time = time();
			if(random(2)) {
				switch(random(6)) {
					default:
					case 0:
						SAY_CMD->say(me,"����Ұ����Ұ����ҿ��㻹��򣡳����ҵķ�ɽ��۽ţ�");
						break;
					case 1:
						SAY_CMD->say(me,"��ѽ!���ϵı���̫����,���ò�����!�ס���˭�Ľ�װ����?");						
						break;
					case 2:
						SAY_CMD->say(me,"����,ʡʡ��,����������è�Ĺ�����ɱ��,������100�������������㡭��");
						break;
					case 3:
						SAY_CMD->say(me,"����ѽ!����ѽ!�㵹�Ǵ���ѽ!");
						break;						
					case 4:
						SAY_CMD->say(me,"�ҿ�!���º��ְ�!����ҷ������飬�����ҵ�éɽ��Ӱ��!");
						break;						
					case 5:
						SAY_CMD->say(me,"��,���˴��������������������,���Ӷ��Ӿ���!��,�ֵ�,�㵹���õ�����!");
						break;			
				}
			}
		}
		if(enemy->is_die()) {
			set_enemy(0);
		}
	}
	return ::heart_beat_walk();
}

//	�ص����Զ�ս��
//void auto_fight( object who ) {}
//	�ص�����λ���� -- �����ĳ�ʱ�������ں����ⲿ�����ֹ����������������
void reset() {
        if( gone_time( get("birthday") ) >= 3600 &&  !objectp(get_enemy())) {
        	_DEBUG("ʱ�䵽�����볡��");
                remove_from_scene();
                destruct( this_object() );
        }
}

//	�ص����ؼ��������� -- �˺����μ� npc/task/8210.c �����ͬ������
int perform_action(object who) {
	int rate;
	object me = this_object();
	if( get_z(who)!= get_z(me) || !inside_screen_2(me, who) || distance_between(me,who)> get_max_seek()+2) {
		return 0;	
	}
	rate  = random(100);
	switch(me->get("robber.type")) {
		default:			
		case 1:		//	���������
			if ( rate < 5 ) {
				return PF_FILE_03483->perform_action_npc(me, who);
			} else if ( rate < 17 ) {
				return PF_FILE_02512->perform_action_npc(me, who);
			} else if ( rate < 20 ) {
				return PF_FILE_02416->perform_action_npc(me, who);
			}
			break;
		case 2:		//	������ͷ���
			if ( rate < 8 ) {
				return PF_FILE_02216->perform_action_npc(me, who);
			} else if ( rate < 16 ) {
				return PF_FILE_02313->perform_action_npc(me, who);
			} else if ( rate < 24 ) {
				return PF_FILE_02314->perform_action_npc(me, who);			
			}
			break;
		case 3:		//	�߷��������
			if( get_effect(me, EFFECT_CHAR_NO_PF) ) {
				return 0;
			}
			if ( get_effect(me, EFFECT_CHAR_CHANGE) < 1) {
				PF_FILE_04251->cast_done_npc(me);			
			}
			if ( rate < 70 ) {
				return PF_FILE_04231->perform_action_npc(me, who);
			} else if ( rate < 90 ) {
				return PF_FILE_04232->perform_action_npc(me, who);
			} else if ( rate < 97 ) {
				return PF_FILE_04234->perform_action_npc(me, who);
			} else {
				return PF_FILE_04243->perform_action_npc(me, who);
			}
			break;
		case 4:		//	��Ѫ
			if( !me->get_perform("03173") ) {
				PF_FILE_03173->perform_action_npc(me,who);
			}
			if ( rate < 5 ) {
				return PF_FILE_02118->perform_action_npc(me, who);
			} else if ( rate < 13 ) {
				return PF_FILE_02114->perform_action_npc(me, who);
			} else if ( rate < 25 ) {
				return PF_FILE_02115->perform_action_npc(me, who);
			}
			break;
		case 5:		//	��Ѫ������߷���
			if( !me->get_effect(me, EFFECT_USER_HURT) ) {
				PF_FILE_03632->cast_done_npc(me);
			}
			if ( rate < 10 ) {
				return PF_FILE_02616->perform_action_npc(me, who);
			} else if ( rate < 20 ) {
				return PF_FILE_02615->perform_action_npc(me, who);			
			}
			break;
		case 6:		//	ǿ�����ٻ�
			summon_slave(me);
			if( get_effect(me, EFFECT_CHAR_NO_PF) ) {
				return 0;
			}
			if ( rate < 6 ) {
				return PF_FILE_04143->perform_action_npc(me, who);
			} else if ( rate < 12 ) {
				return PF_FILE_04144->perform_action_npc(me, who);
			} else if ( rate < 15 ) {
				return PF_FILE_04145->perform_action_npc(me, who);
			}
			break;
	}
	return 0;
}

//	�ص���ս���м�״̬��ɱ����һ������ʱ��
void stop_fight() {
	object enemy = get_enemy();
	_DEBUG("ɱ����һ�����ˣ������ڼ�Ѫ");	
	if ( enemy && enemy->get_hp()==0 )
		add_hp(50000);
	::stop_fight();		
}

//-----------------------------------------Զ�̵���-------------------------------------//
//	�ص���ս��ʤ����Ľ�������
void win_bonus(object who) {
	__FILE__->win_bonus_callout(this_object(), who);
}
//	win_bonus �ĵ��ú��� -- ����BOSS �������Ʒ������Ϣ
void win_bonus_callout(object me, object who) {
	_DEBUG(sprintf("DEBUG -- Z-%d X-%d Y-%d ��������ɱ����",get_z(me),get_x(me),get_y(me)));
	drop_items(me,who);
}
//	������������
void drop_items( object me, object who ) {
	int i,x,y,z,p,count;
	string *item_info;
	object item;
	_DEBUG("��ʼ����������Ʒ");
	z = get_z(me);
	x = get_x(me);
	y = get_y(me);
	//	�м��ʳ�����Ʒ��1��80��120�������λ��ɫװ����������������100
	if(random(10000) <= 100) {
		for(i=0,count=0;i<100;i++) {
			if(p  = get_valid_xy(z,x,y,IS_ITEM_BLOCK)) {
				item_info = WEAPON_FILE->get_family_equip(familys[random(7)],0,(random(5)+8)*10,HEAD_TYPE+random(6));
				item = new(item_info[random(sizeof(item_info))]);
				if(!item) {
					continue;
				}
				ITEM_EQUIP_D->init_equip_prop_3(item);
				item->add_to_scene(z,p/1000,p%1000);
				item->set("time",time());
				if(++count>=1) {
					break;
				}				
			}
		}		
	}	
	//	�м��ʳ�����Ʒ��1��100��120�������λ��ɫװ����100
	if(random(10000) <= 100) {
		for(i=0,count=0;i<100;i++) {
			if(p  = get_valid_xy(z,x,y,IS_ITEM_BLOCK)) {
				item_info = WEAPON_FILE->get_family_equip(familys[random(7)],0,(random(3)+10)*10,HEAD_TYPE+random(6));
				item = new(item_info[random(sizeof(item_info))]);
				if(!item) {
					continue;
				}
				ITEM_EQUIP_D->init_equip_prop_1(item);
				item->add_to_scene(z,p/1000,p%1000);
				item->set("time",time());
				if(++count>=1) {
					break;
				}
			}
		}
	}
	//	�س���Ʒ -- 1��50��120�������λ��ɫװ��������������
	for(i=0,count=0;i<100;i++) {
		if(p = get_valid_xy(z,x,y,IS_ITEM_BLOCK)) {
			item_info = WEAPON_FILE->get_family_equip(familys[random(7)],0,(random(8)+5)*10,HEAD_TYPE+random(6));
			item = new(item_info[random(sizeof(item_info))]);
			if(!item) {
				continue;
			}
			ITEM_EQUIP_D->init_equip_prop_3(item);
			item->add_to_scene(z,p/1000,p%1000);
			item->set("time",time());
			if(++count>=1) {
				break;
			}
		}
	}
	//	�س���Ʒ -- 31��30��120�������λ��ɫװ��
	for(i=0,count=0;i<100;i++) {
		if(p = get_valid_xy(z,x,y,IS_ITEM_BLOCK)) {
			item_info = WEAPON_FILE->get_family_equip(familys[random(7)],0,(random(10)+3)*10,HEAD_TYPE+random(6));
			item = new(item_info[random(sizeof(item_info))]);
			if(!item) {
				continue;
			}
			ITEM_EQUIP_D->init_equip_prop_1(item);
			item->add_to_scene(z, p/1000,p %1000);
			item->set("time",time());
			if(++count>=31) {
				break;
			}
		}
	}
	//	�س���Ʒ -- 25 �� 10000 ��Ϸ��
	for(i=0,count=0;i<100;i++) {
		if(p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)) {
                        item = new( "/item/std/0001" );
                        item->set_value(10000);
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set( "time", time());
			if(++count>=25) {
				break;
			}
		}
	}	
	//	�س���Ʒ -- 43��30��120�������λ��ɫװ��
	for(i=0,count=0;i<100;i++) {
		if(p = get_valid_xy(z,x,y,IS_ITEM_BLOCK)) {
			item_info = WEAPON_FILE->get_family_equip(familys[random(7)],0,(random(10)+3)*10,HEAD_TYPE+random(6));
			item = new(item_info[random(sizeof(item_info))]);
			if(!item) {
				continue;
			}
			// �˾�ȥ����ȥ�������Ŀ����� ITEM_EQUIP_D->init_equip_prop(item);
		        item->add_to_scene(z, p / 1000, p % 1000);
		        item->set( "time", time() );
			if(++count>=43) {
				break;
			}
		}
	}
}
//	�ٻ��� -- ����Ϊ 5 �� �˺����μ� npc/task/8210.c ��ͬ������
int summon_slave( object me ) {
        object npc;
        string arg;
        int z, x, y, x0, y0, p;
        int level, cp, pp, i, size;
	if ( me->get("robber.slave") >= 5 ) {
		return 0;
	}
        level = me->get_level()-5;
        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( p = get_valid_xy(z, x0 + random(3) - 1, y0 + random(3) - 1, IS_CHAR_BLOCK) ) {
                npc = new( "/npc/boss/9962_dashou" );
		if ( !objectp(npc) ) {
			return;
		}
		npc->set("level", level);
		NPC_ENERGY_D->init_level(npc, level);
		if ( random(2) ) {
			npc->set_char_picid(52);
		} else {
			npc->set_char_picid(201);
		}
                npc->set_walk_speed(6);
                npc->set_attack_speed(15);	
                npc->set_max_seek(8);                	
                npc->add_max_hp(100);    // С��׼�� me
		npc->add_hp(100);
		npc->add_dp(level);
		npc->add_pp(level);		
                npc->set_owner(me);		
		npc->set_char_type(FIGHTER_TYPE);
                x = p / 1000;  y = p % 1000;
                npc->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );
                send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE ); 
                me->add("robber.slave", 1);
                npc->set("robber.id",sprintf( "%x#", getoid(me)) );
                NPC_SLAVE_D->find_enemy(npc);    // Ѱ�ҵ���
        }
        return 1;    // ִ�гɹ�
}